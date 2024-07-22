export module Inventory;

import <iostream>;
import <string>;
import <vector>;

export struct Item {
	int id;
	std::string name;
	int quantity;
	double price;

	void display() const;
};

export class Inventory {
private:
	std::vector<Item> items;
	int nextId;

public:
	Inventory();
	void addItem(const std::string& name, int quantity, double price);
	void editItem(int id, const std::string& name, int quantity, double price);
	void deleteItem(int id);
	void displayItems() const;
	Item* searchById(int id) const;
	std::vector<Item> searchByName(const std::string& name) const;
	std::vector<Item> searchByPrice(double price) const;
	std::vector<Item> searchByAvailability() const;
	bool isEmpty() const;
};