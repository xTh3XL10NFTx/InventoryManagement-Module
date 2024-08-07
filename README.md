# Inventory Management System

Welcome to my Inventory Management System. This repository contains a C++ module designed for managing an inventory. The module provides core functionalities such as adding, editing, deleting, searching, and displaying items.

Additionally, the repository includes an example project that demonstrates how to use the module. The example project illustrates practical use cases and provides a comprehensive guide to the module's capabilities.

## Features

- **Add Items**: Quickly add new items to your inventory with a name, quantity, and price.
- **Edit Items**: Update item details, including name, quantity, and price.
- **Delete Items**: Remove items from your inventory when they are no longer needed.
- **Display Items**: View a comprehensive list of all items in your inventory.
- **Search Functionality**: Find items by ID, name, or price. Filter items based on availability.

## Installation

To get started with the **Inventory Management System**, follow these steps:

1. **Clone the Repository**

    ```bash
    git clone https://github.com/yourusername/inventory-management-system.git
    ```

2. **Navigate to the Project Directory**

    ```bash
    cd inventory-management-system
    ```

3. **Build the Project**

   If you’re using a typical C++ build setup with `CMake`, create a build directory and compile the code:

    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

4. **Run the Application**

    ```bash
    ./InventoryManagementSystem
    ```

## Inventory Module Code Usage

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

#### Method descriptions:

- **`void addItem(const std::string& name, int quantity, double price);`**  
  Adds a new item to the inventory with the specified name, quantity, and price.

- **`void editItem(int id, const std::string& name, int quantity, double price);`**  
  Edits the item with the specified ID, updating its name, quantity, and price.

- **`void deleteItem(int id);`**  
  Deletes the item with the specified ID from the inventory.

- **`void displayItems() const;`**  
  Displays all items currently in the inventory.

- **`Item* searchById(int id) const;`**  
  Searches for an item by its ID and returns a pointer to it.

- **`std::vector<Item> searchByName(const std::string& name) const;`**  
  Searches for items by name and returns a vector of matching items.

- **`std::vector<Item> searchByPrice(double price) const;`**  
  Searches for items by price and returns a vector of matching items.

- **`std::vector<Item> searchByAvailability() const;`**  
  Searches for available items and returns a vector of matching items.

- **`bool isEmpty() const;`**  
  Checks if the inventory is empty and returns a boolean value.

For practical examples of how to use these functions, check out the [example project here](https://github.com/xTh3XL10NFTx/InventoryManagement-Module/blob/master/InventoryManagement.cpp).

## Example Usage

You can run the application to explore the example project. Once launched, interact with it directly through the console. Here’s a quick overview of the available options:
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

## Future Improvements
### Unit Tests
Implementing unit tests is a crucial next step for improving the reliability and maintainability of the Inventory Management System. Unit tests will help ensure that the functions perform as expected and will make it easier to identify and fix bugs.

#### Potential Unit Test Frameworks:

   - Google Test (gtest): A popular C++ testing framework that is easy to integrate and use.
#### Example of a Simple Unit Test:
```cpp
#include <gtest/gtest.h>
#include "Inventory.h"

TEST(InventoryTest, AddItem) {
    Inventory inventory;
    inventory.addItem("Laptop", 10, 999.99);
    auto* item = inventory.searchById(1);
    ASSERT_NE(item, nullptr);
    EXPECT_EQ(item->name, "Laptop");
    EXPECT_EQ(item->quantity, 10);
    EXPECT_DOUBLE_EQ(item->price, 999.99);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

Integrating unit tests into your development workflow will provide numerous benefits, including increased code quality, easier refactoring, and better documentation of the expected behavior of your code.

## Contributing

We welcome contributions to this project! To contribute:

- **Report Issues**
- **Feature Requests**
- **Pull Requests**

Thank you for contributing!

---

   ### **Author**: [Ivelin Tanev](https://github.com/xTh3XL10NFTx)
   #### **Email**: IvelinTanev.IT@gmail.com

---

Happy managing your inventory! 🛒🚀
