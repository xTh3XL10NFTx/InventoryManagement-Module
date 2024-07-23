#include <iostream>
#include <algorithm>

import Inventory;

void Item::display() const {
    std::cout << "ID: " << id << ", Name: " << name << ", Quantity: " << quantity << ", Price: " << price << " BGN" << std::endl;
}

// initializes nextId to 1, used to generate unique IDs for new items
Inventory::Inventory() : nextId(1) {}

void Inventory::addItem(const std::string& name, int quantity, double price) {
    Item newItem = { nextId++, name, quantity, price }; // create new item with unique ID
    items.push_back(newItem); // add item to the inventory list
    std::cout << "Item added successfully.\n";
}

void Inventory::editItem(int id, const std::string& name, int quantity, double price) {
    for (auto& item : items) {
        if (item.id == id) {
            item.name = name;
            item.quantity = quantity;
            item.price = price;
            return;
        }
    }
    std::cout << "Item with ID " << id << " not found.\n";
}

void Inventory::deleteItem(int id) {
    auto it = std::remove_if(items.begin(), items.end(), [id](const Item& item) {
        return item.id == id; // identify item to remove by ID
        });
    if (it != items.end()) {
        items.erase(it, items.end());
        std::cout << "Item deleted successfully.\n";
    }
    else {
        std::cout << "Item with ID " << id << " not found.\n";
    }
}

void Inventory::displayItems() const {
    if (items.empty()) {
        std::cout << "Inventory is empty.\n";
    }
    else {
        for (const auto& item : items) {
            item.display(); // use item's display method
        }
    }
}

Item* Inventory::searchById(int id) const {
    for (const auto& item : items) {
        if (item.id == id) {
            return const_cast<Item*>(&item); // return to the found item
        }
    }
    return nullptr; // return null if item not found
}

std::vector<Item> Inventory::searchByName(const std::string& name) const {
    std::vector<Item> results;
    for (const auto& item : items) {
        if (item.name.find(name) != std::string::npos) {
            results.push_back(item); // add matching items to results
        }
    }
    return results; // return items or no items
}

std::vector<Item> Inventory::searchByPrice(double price) const {
    std::vector<Item> results;
    for (const auto& item : items) {
        if (item.price == price) {
            results.push_back(item); // add matching items to results
        }
    }
    return results; // return items or no items
}

std::vector<Item> Inventory::searchByAvailability() const {
    std::vector<Item> results;
    for (const auto& item : items) {
        if (item.quantity > 0) {
            results.push_back(item); // add matching items to results
        }
    }
    return results; // return items or no items
}

// example usage: for checking if theres items before opening edit or delete
bool Inventory::isEmpty() const {
    return items.empty(); // Return true if no items in inventory
}