#ifndef ITEM_H
#define ITEM_H

#include <set>
#include <iostream>
#include <iomanip>
#include "Category.h"
#include "Order.h"

class Category;
class Order;

class Item {
	private:
		std::string name;
		Category* category;
		std::set<Order*> ordersList;
		int id;

	public:
		static int lastId;

	public:
		Item(const std::string& name, Category* category);
		~Item();

		const std::string& getName() const;
		int getId();

		void addToOrder(Order* order);
		void removeFromOrder(Order* order);
		void addOrder(Order* order);
		void removeOrder(Order* order);
		void showOrdersList();
		void changeCategory(Category* newCategory);
};

#endif // ITEM_H