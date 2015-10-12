#ifndef CATEGORY_H
#define CATEGORY_H

#include <set>
#include <iostream>
#include <iomanip>
#include "Item.h"
#include "Exceptions.h"

class Item;

class Category {
	private:
		std::string name;
		std::set<Item*> itemList;

	public:
		Category(const std::string& name);
		~Category();

		void addItem(Item* newItem);
		void removeItem(Item* item);
		void showItemList();
};

#endif // CATEGORY_H