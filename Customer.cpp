#include "Customer.h"

Customer::Customer(const std::string& name) {
	this->name = name;
	id = lastId;
	lastId += 1;
}
Customer::~Customer() {
	std::set<Order*>::iterator it = ordersList.begin();

	for ( ; it != ordersList.end(); it++ ) {
		delete *it;
	}
	ordersList.clear();
	std::cout << "Customer " << name << " deleted" << std::endl;
}

Order* Customer::addOrder(Item* item) {
	Order* newOrder = new Order(this, item);

	ordersList.insert(newOrder);
	item->addOrder(newOrder);
	return newOrder;
}
void Customer::removeOrder(Order* order) {
	ordersList.erase(order);
	delete order;
}
void Customer::addItemToOrder(Item* item, Order* order) {
	order->addItem(item);
	item->addOrder(order);
}
void Customer::removeItemFromOrder(Item* item, Order* order) {
	order->removeItem(item);
	item->removeOrder(order);
}
void Customer::showOrdersList() {
	std::set<Order*>::iterator it = ordersList.begin();

	std::cout << "Orders: of customer " << name << std::endl;

	for ( ; it != ordersList.end(); it++ ) {
		(*it)->showOrder();
	}
	std::cout << std::endl;
}

int Customer::lastId = 1;
