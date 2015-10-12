#include "Order.h"

Order::Order(Customer* customer, Item* item) {
	this->customer = customer;
	addItem(item);
	this->id = lastId;
	lastId += 1;
}
Order::~Order() {
	customer  = NULL;
	std::set<Item*>::iterator it = itemList.begin();

	for ( ; it != itemList.end(); it++ ) {
		(*it)->removeOrder(this);
	}
	itemList.clear();
	lastId -= 1;
	std::cout << "Order #" << id << " deleted" << std::endl;
}
int Order::getId() {
	return id;
}
Customer* Order::getCustomer() {
	return customer;
}
void Order::addItem(Item* item) {
	itemList.insert(item);
	item->addOrder(this);
}
void Order::removeItem(Item* item) {
	itemList.erase(item);
	item->removeOrder(this);
}
void Order::showOrder() {
	std::set<Item*>::iterator it = itemList.begin();

	std::cout << "Order# " << id << ":" << std::endl;

	for ( ; it != itemList.end(); it++ ) {
		std::cout << "--" << (*it)->getName();
		std::cout << ", ID: ";
		std::cout << std::setfill('0') << std::setw(4);
		std::cout << (*it)->getId() << std::endl;
	}
	std::cout << std::endl;
}
int Order::lastId = 1;
