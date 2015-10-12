#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <set>
#include "Order.h"
#include "Item.h"

class Order;
class Item;

class Customer {
	private:
		std::string name;
		int id;
		std::set<Order*> ordersList;

	public:
		static int lastId;

	public:
		Customer(const std::string& name);
		~Customer();

		Order* addOrder(Item* item);
		void removeOrder(Order* order);
		void addItemToOrder(Item* item, Order* order);
		void removeItemFromOrder(Item* item, Order* order);
		void showOrdersList();
};

#endif // CUSTOMER_H