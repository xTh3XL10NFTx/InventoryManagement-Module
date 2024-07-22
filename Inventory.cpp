#include <iostream>
#include <algorithm>

import Inventory;

void Item::display() const {
    std::cout << "ID: " << id << ", Name: " << name << ", Quantity: " << quantity << ", Price: " << price << " BGN" << std::endl;
}

Inventory::Inventory() : nextId(1) {}

void Inventory::addItem(const std::string& name, int quantity, double price) {
    Item newItem = { nextId++, name, quantity, price };
    items.push_back(newItem);
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
        return item.id == id;
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
            item.display();
        }
    }
}

Item* Inventory::searchById(int id) const {
    for (const auto& item : items) {
        if (item.id == id) {
            return const_cast<Item*>(&item); // const_cast to return non-const pointer
        }
    }
    return nullptr; // Return null if not found
}

std::vector<Item> Inventory::searchByName(const std::string& name) const {
    std::vector<Item> results;
    for (const auto& item : items) {
        if (item.name.find(name) != std::string::npos) {
            results.push_back(item);
        }
    }
    return results;
}

std::vector<Item> Inventory::searchByPrice(double price) const {
    std::vector<Item> results;
    for (const auto& item : items) {
        if (item.price == price) {
            results.push_back(item);
        }
    }
    return results;
}

std::vector<Item> Inventory::searchByAvailability() const {
    std::vector<Item> results;
    for (const auto& item : items) {
        if (item.quantity > 0) {
            results.push_back(item);
        }
    }
    return results;
}

bool Inventory::isEmpty() const {
    return items.empty();
}