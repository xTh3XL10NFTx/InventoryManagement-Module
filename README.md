# Inventory Management System

Welcome to my Inventory Management System. This repository contains a C++ module designed for managing an inventory. The module provides core functionalities such as adding, editing, deleting, searching, and displaying items.

Additionally, the repository includes an example project that demonstrates how to use the module. The example project illustrates practical use cases and provides a comprehensive guide to the module's capabilities.

## Features

- **Add Items**: Add new items to the inventory with details such as name, quantity, and price.
- **Edit Items**: Modify existing item details including name, quantity, and price.
- **Delete Items**: Remove items from the inventory.
- **Search Items**: Search for items by ID, name, availability, or price.
- **Display Items**: Show all items currently in the inventory.

## Code Usage

The following functions are available in the `Inventory` module, which you can use to manage the inventory:
```cpp
class Inventory {
public:
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
```
For practical examples of how to use these functions, check out the [example project here](https://github.com/xTh3XL10NFTx/InventoryManagement-Module/blob/master/InventoryManagement.cpp).

## Example Usage

Here’s a step-by-step guide on how to use the Inventory Management System:
1. **Add Item**:
   - Select option `1` from the main menu to add a new item.
   - Provide the item name, quantity, and price when prompted.

2. **Edit Item**:
   - Select option `2` to edit an existing item.
   - Choose an item ID from the list and specify the changes (name, quantity, or price).

3. **Delete Item**:
   - Select option `3` to delete an item.
   - Provide the item ID you wish to remove.

4. **Display Items**:
   - Select option `4` to display all items currently in the inventory.

5. **Search Items**:
   - Select option `5` to search for items.
   - Choose from search criteria such as ID, name, availability, or price.

6. **Exit**:
   - Select option `6` to exit the application.

These instructions correspond to the example project linked above, where you can see how these functions are implemented and used in practice.

## Contributing

We welcome contributions to this project! To contribute:

1. **Report Issues**: If you encounter a bug or have a question, please submit an issue in the [issue tracker](#).
2. **Feature Requests**: For feature requests, open a new issue with a detailed description of your proposed change.
3. **Pull Requests**: Fork the repository, make your changes in a separate branch, and submit a pull request. Ensure your code follows standard coding conventions and includes clear documentation.

Thank you for contributing!
