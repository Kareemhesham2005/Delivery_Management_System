#include <iomanip>
#include <iostream>
#include <string>
#include "../include/DeliverySystem.h"
using namespace std;
using namespace dms;

int readInt(const string &prompt) {
    while (true) {
        cout << prompt;
        string line;
        if (!getline(cin, line)) return -1; // EOF
        try {
            size_t p; int v = stoi(line, &p);
            if (p == line.size()) return v;
        } catch (...) {}
        cout << "Invalid integer, try again.\n";
    }
}

double readDouble(const string &prompt) {
    while (true) {
        cout << prompt;
        string line;
        if (!getline(cin, line)) return 0.0;
        try {
            size_t p; double v = stod(line, &p);
            if (p == line.size()) return v;
        } catch (...) {}
        cout << "Invalid number, try again.\n";
    }
}

int main() {
    DeliverySystem system;
    cout << "Delivery Management System\n";
    while (true) {
        cout << "\nMenu:\n1) List restaurants\n2) Create order\n3) Track order\n4) Change order status\n5) Exit\n";
        int opt = readInt("Choose option: ");
        if (opt == 1) {
            cout << system.listRestaurants() << "\n";
        } else if (opt == 2) {
            cout << system.listRestaurants() << "\n";
            int rid = readInt("Enter restaurant ID: ");
            int itemIdx = readInt("Enter item index (number inside brackets): ");
            double cx = readDouble("Enter customer X (latitude-like): ");
            double cy = readDouble("Enter customer Y (longitude-like): ");
            Point customer{cx, cy};
            string err;
            int oid = system.createOrder(rid - 1, itemIdx - 1, customer, err);
            if (oid < 0) cout << "Failed to create order: " << err << "\n";
            else {
                cout << "Order created with ID " << oid << "\n";
                cout << "Cost: " << fixed << setprecision(2) << system.orders[oid - 1].getTotalCost() << "$\n";
                cout.unsetf(ios::floatfield);
            }
        } else if (opt == 3) {
            int oid = readInt("Enter order ID: ");
            cout << system.describeOrder(oid) << "\n";
        } else if (opt == 4) {
            int oid = readInt("Order ID: ");
            cout << "Status (1=Assigned,2=Delivered,3=Cancelled): ";
            int s = readInt("");
            OrderStatus st = OrderStatus::Assigned;
            if (s==2) st = OrderStatus::Delivered; else if (s==3) st = OrderStatus::Cancelled;
            string err;
            if (!system.changeOrderStatus(oid, st, err)) cout << "Failed: " << err << "\n";
            else cout << "Status updated.\n";
        } else break;
        // Ask user if they want to continue before displaying the menu
        char cont;
        cout << "Do you want to continue? (y/n): ";
        cin >> cont;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer
        if (cont != 'y' && cont != 'Y') break; // Exit loop if user doesn't want to continue
    }
    cout << "Exiting Delivery Management System...\nGoodbye!\n";
    return 0;
}
