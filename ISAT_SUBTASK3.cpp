#include <iostream>
#include <string>

using namespace std;

const int MAX_ORDERS = 50;

string orderIDs[MAX_ORDERS] = { "ODR001", "ODR002", "ODR003", "ODR004", "ODR005", "ODR006", "ODR007", "ODR008", "ODR009", "ODR010" };
string customerNames[MAX_ORDERS] = { "Ndumiso", "Vuthlari", "Zulfa", "Samkelo", "Lerato", "Nkosi", "Beast", "PaxAfrique", "Sanele", "ProBase" };
int numMagwinyas[MAX_ORDERS] = { 2, 3, 1, 4, 2, 3, 1, 2, 3, 4 };
float totalCost[MAX_ORDERS] = { 10.99, 14.99, 7.77, 19.00, 12.99, 16.99, 9.99, 13.99, 15.99, 20.99 };
int numOrders = 10;  // Set to the number of initially populated orders

void addOrder() {
	if (numOrders < MAX_ORDERS) {
		cout << "Customer Name: ";
		cin >> customerNames[numOrders];
		cout << "Number of Magwinyas: ";
		cin >> numMagwinyas[numOrders];
		cout << "Tptal Cost: R ";
		cin >> totalCost[numOrders];

		// Generate Order ID
		int orderNumber = stoi(orderIDs[numOrders - 1].substr(3)) + 1;
		orderIDs[numOrders] = "ODR" + (orderNumber < 10 ? "00" : (orderNumber < 100 ? "0" : "")) + to_string(orderNumber);

		numOrders++;
		cout << "Order added successfully!" << endl;
	}
	else {
		cout << "Error: Maximum number of  orders (50) exceeded." << endl;

	}
}

void displayOrders() {
	if (numOrders == 0) {
		cout << "No orders available." << endl;
	}
	else {
		cout << "Order Data: " << endl;
		for (int i = 0; i < numOrders; i++) {
			cout << "Order ID: " << orderIDs[i] << endl;
			cout << "Customer Name: " << customerName[i] << endl;
			cout << "Number of Magwinyas: " << numMagwinyas[i] << endl;
			cout << "Total Cost: R " totalCost[i] << endl;
			cout << endl;
		}
	}
}

void findOrder() {
	string orderID;
	cout << "Enter Order ID: ";
	cin >> orderID;

	bool found = false;
	for (int i = 0; i < numOrders; endl; i++) {
		if (orderIDs[i] == orderID) {
			cout << "Order Found: " << endl;
			cout << "Order ID: " << orderIDs[i] << endl;
			cout << "Customer Name: " << customerNames[i] << endl;
			cout << "Number of Magwinyas: " << numMagwinyas[i] << endl;
			cout << "Total Cost: R " << totalCost[i] << endl;
			found = true;
			break;

		}
	}
	if (!found) {
		cout << "Order not fiund." << endl;
	}
}

void calculateTotalRevenue() {
	float totalRevenue = 0;
	for (int i = 0; i < numOrders; i++) {
		if (orderIDs[i] != "0") {
			totalRevenue += totalCost[i]:
		}
	}
	cout << "Total Revenue: R " << totalRevenue << endl;
}

int main() {
	int choice;
	do {
		cout << "Menu: " << endl;
		cout << "1. Add Order: " << endl;
		cout << "2. Display Orders: " << endl;
		cout << "3. Find Order by Order ID: " << endl;
		cout << "4. Calculate Total Revenue: " << endl;
		cout << "5. Exit. " << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			addOrder();
			break;
		case 2:
			displayOrders();
			break;
		case 3:
			findOrder();
			break;
		case 4:
			calculateTotalRevenue();
			break;
		case 5:
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 5);

	return 0;
}