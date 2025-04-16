#include "Admin.h"
#include <iostream>

using namespace std;

Admin::Admin(const string& username, const string& password)
    : User(username, password) {}

void Admin::viewBusRoutes(const vector<BusRoute>& routes) {
    cout << "\nAvailable Bus Routes:" << endl;
    for (const auto& route : routes) {
        route.displayRoute();
    }
}

bool Admin::addBusRoute(vector<BusRoute>& routes) {
    int id;
    string from, to, time;
    double price;
    int seats;
    
    cout << "Enter Route ID: ";
    cin >> id;
    
    // Check if ID already exists
    for (const auto& route : routes) {
        if (route.getRouteId() == id) {
            cout << "Route ID already exists!" << endl;
            return false;
        }
    }
    
    cout << "Enter From location: ";
    cin >> from;
    cout << "Enter To location: ";
    cin >> to;
    cout << "Enter Price: ";
    cin >> price;
    cout << "Enter Time: ";
    cin >> time;
    cout << "Enter number of seats: ";
    cin >> seats;
    
    routes.push_back(BusRoute(id, from, to, price, time, seats));
    cout << "Bus route added successfully!" << endl;
    return true;
}

bool Admin::updateBusRoute(vector<BusRoute>& routes) {
    int id;
    cout << "Enter Route ID to update: ";
    cin >> id;
    
    for (auto& route : routes) {
        if (route.getRouteId() == id) {
            string from, to, time;
            double price;
            int seats;
            
            cout << "Enter new From location: ";
            cin >> from;
            cout << "Enter new To location: ";
            cin >> to;
            cout << "Enter new Price: ";
            cin >> price;
            cout << "Enter new Time: ";
            cin >> time;
            cout << "Enter new number of seats: ";
            cin >> seats;
            
            route = BusRoute(id, from, to, price, time, seats);
            cout << "Bus route updated successfully!" << endl;
            return true;
        }
    }
    
    cout << "Route ID not found!" << endl;
    return false;
}

bool Admin::removeBusRoute(vector<BusRoute>& routes) {
    int id;
    cout << "Enter Route ID to remove: ";
    cin >> id;
    
    for (auto it = routes.begin(); it != routes.end(); ++it) {
        if (it->getRouteId() == id) {
            routes.erase(it);
            cout << "Bus route removed successfully!" << endl;
            return true;
        }
    }
    
    cout << "Route ID not found!" << endl;
    return false;
}

void Admin::adminMenu(vector<BusRoute>& routes) {
    while (true) {
        cout << "\n=== Admin Menu ===" << endl;
        cout << "1. View Bus Routes" << endl;
        cout << "2. Add Bus Route" << endl;
        cout << "3. Update Bus Route" << endl;
        cout << "4. Remove Bus Route" << endl;
        cout << "5. Logout" << endl;
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;
        
        if (choice == 1) {
            viewBusRoutes(routes);
        }
        else if (choice == 2) {
            addBusRoute(routes);
        }
        else if (choice == 3) {
            updateBusRoute(routes);
        }
        else if (choice == 4) {
            removeBusRoute(routes);
        }
        else if (choice == 5) {
            cout << "Logging out..." << endl;
            break;
        }
    }
} 