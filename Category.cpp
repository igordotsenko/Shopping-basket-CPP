#include "Category.h"

Category::Category(const std::string& name) {
	this->name = name;
}
Category::~Category() {
	std::set<Item*>::iterator it = itemList.begin();

	for ( ; it != itemList.end(); it++ ) {
		(*it)->changeCategory(NULL);
	}
	itemList.clear();
	std::cout << "Category " << name << " deleted" << std::endl;
}
void Category::addItem(Item* newItem) {
	itemList.insert(newItem);
}
void Category::removeItem(Item* item) {
	itemList.erase(item);
}
void Category::showItemList() {
	std::set<Item*>::iterator it = itemList.begin();

	std::cout << "Category: " << name << std::endl;

	for ( ; it != itemList.end(); it++ ) {
		std::cout << "--" << (*it)->getName();
		std::cout << ", ID: ";
		std::cout << std::setfill('0') << std::setw(4);
		std::cout << (*it)->getId() << std::endl;
	}
	std::cout << std::endl;
}
