import Inventory;
import <iostream>;
import <string>;

using std::cin;
using std::cout;

//prevents errors, example: entering int when required string
template <typename T>
bool getValidInput(T& input) {
	cin >> input;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid input. Please enter a valid value.\n";
		return false;
	}
	return true;
}

void displaySearchMenu() {
	cout << "\nSearch Menu\n";
	cout << "1. Search by ID\n";
	cout << "2. Search by Name\n";
	cout << "3. Show Available\n";
	cout << "4. Search by Price\n";
	cout << "5. Return to Main Menu\n";
	cout << "Enter your choice: ";
}

void displayEditMenu() {
	cout << "\nEdit Menu\n";
	cout << "1. Edit Name\n";
	cout << "2. Edit Quantity\n";
	cout << "3. Edit by Price\n";
	cout << "4. Return to Main Menu\n";
	cout << "Enter your choice: ";
}

void handleSearch(Inventory& inventory) {
	int searchChoice;
	int id;
	std::string name;
	double price;

	do {
		displaySearchMenu();
		if (!getValidInput(searchChoice)) continue;

		switch (searchChoice) {
		case 1:
			cout << "Enter item ID to search: ";
			if (!getValidInput(id)) continue;
			if (Item* item = inventory.searchById(id)) {
				item->display();
			}
			else {
				cout << "Item with ID " << id << " not found.\n";
			}
			break;
		case 2:
			cout << "Enter item name to search: ";
			cin.ignore();
			std::getline(cin, name);
			{
				auto results = inventory.searchByName(name);
				if (results.empty()) {
					cout << "No items found with name " << name << ".\n";
				}
				else {
					for (const auto& item : results) {
						item.display();
					}
				}
			}
			break;
		case 3:
		{
			auto results = inventory.searchByAvailability();
			if (results.empty()) {
				cout << "No available items found.\n";
			}
			else {
				for (const auto& item : results) {
					item.display();
				}
			}
		}
		break;
		case 4:
			cout << "Enter item price to search: ";
			if (!getValidInput(price)) continue;
			{
				auto results = inventory.searchByPrice(price);
				if (results.empty()) {
					cout << "No items found with price $" << price << ".\n";
				}
				else {
					for (const auto& item : results) {
						item.display();
					}
				}
			}
			break;
		case 5:
			cout << "Returning to main menu...\n";
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
		}
	} while (searchChoice != 5);
}

void handleEdit(Inventory& inventory, int id) {
	Item* item = inventory.searchById(id);
	if (!item) {
		cout << "Item with ID " << id << " not found.\n";
		return;
	}

	int editChoice;
	std::string name;
	double price;
	int quantity;

	do {
		displayEditMenu();
		if (!getValidInput(editChoice)) continue;

		switch (editChoice) {
		case 1:
			cout << "Enter new item name: ";
			cin.ignore();
			std::getline(cin, name);
			inventory.editItem(id, name, item->quantity, item->price);
			cout << "Item name changed successfully.\n";
			break;
		case 2:
			cout << "Enter new quantity: ";
			if (!getValidInput(quantity)) continue;
			item->quantity = quantity;
			inventory.editItem(id, item->name, quantity, item->price);
			cout << "Item quantity changed successfully.\n";
			break;
		case 3:
			cout << "Enter new price: ";
			if (!getValidInput(price)) continue;
			item->price = price;
			inventory.editItem(id, item->name, item->quantity, price);
			cout << "Item price changed successfully.\n";
			break;
		case 4:
			cout << "Returning to main menu...\n";
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
		}
	} while (editChoice != 4);
}

int main() {
	Inventory inventory;
	int choice;
	std::string name;
	int id, quantity;
	double price;

	do {
		cout << "\nInventory Management System\n";
		cout << "1. Add Item\n";
		cout << "2. Edit Item\n";
		cout << "3. Delete Item\n";
		cout << "4. Display Items\n";
		cout << "5. Search Items\n";
		cout << "6. Exit\n";
		cout << "Enter your choice: ";
		if (!getValidInput(choice)) continue;


		switch (choice) {
		case 1:
			cout << "Enter item name: ";
			cin.ignore();
			getline(cin, name);
			cout << "Enter quantity: ";
			if (!getValidInput(quantity)) continue;
			cout << "Enter price: ";
			if (!getValidInput(price)) continue;
			inventory.addItem(name, quantity, price);
			break;
		case 2:
			inventory.displayItems();
			if (!inventory.isEmpty()) {
				cout << "Enter item ID to edit: ";
				if (!getValidInput(id)) continue;
				handleEdit(inventory, id);
			}
			break;
		case 3:
			inventory.displayItems();
			if (!inventory.isEmpty()) {
				cout << "Enter item ID to delete: ";
				if (!getValidInput(id)) continue;
				inventory.deleteItem(id);
			}
			break;
		case 4:
			inventory.displayItems();
			break;
		case 5:
			handleSearch(inventory);
			break;
		case 6:
			cout << "Exiting...\n";
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 6);

	return 0;
}