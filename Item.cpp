#include "Item.h"

Item::Item(const std::string& name, Category* category) {
	this->name = name;
	this->id = lastId;
	lastId += 1;
	this->category = category;
	this->category->addItem(this);
}
Item::~Item() {
	if ( this->category != NULL ) {
		this->category->removeItem(this);
	}
	ordersList.clear();
	std::cout << "Item " << name << " deleted" << std::endl;
}
const std::string& Item::getName() const {
	return name;
}
int Item::getId() {
	return id;
}
void Item::addToOrder(Order* order) {
	order->addItem(this);
}
void Item::removeFromOrder(Order* order) {
	order->removeItem(this);
}
void Item::addOrder(Order* order) {
	ordersList.insert(order);
}
void Item::removeOrder(Order* order) {
	ordersList.erase(order);
}
void Item::showOrdersList() {
	std::set<Order*>::iterator it = ordersList.begin();

	std::cout << "Orders: " << name << std::endl;

	for ( ; it != ordersList.end(); it++ ) {
		std::cout << "#";
		std::cout << (*it)->getId() << std::endl;
	}
	std::cout << std::endl;
}
void Item::changeCategory(Category* newCategory) {
	if ( newCategory == category ) {
		return;
	}
	if ( newCategory == NULL ) {
		category = NULL;
		delete this;
		return;
	}
	this->category->removeItem(this);
	category = newCategory;
	this->category->addItem(this);
}

int Item::lastId = 1;