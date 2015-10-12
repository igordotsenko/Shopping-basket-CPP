#ifndef ORDER_H
#define ORDER_H

#include <set>
#include <iostream>
#include <iomanip>
#include "Item.h"
#include "Exceptions.h"
#include "Customer.h"

class Item;
class Customer;

class Order {
	private:
		int id;
		Customer* customer;
		std::set<Item*> itemList;

	public:
		static int lastId;

	public:
		Order(Customer* customer, Item* item);
		~Order();

		int getId();
		Customer* getCustomer();

		void addItem(Item* item);
		void removeItem(Item* item);
		void showOrder();
};

#endif // ORDER_H