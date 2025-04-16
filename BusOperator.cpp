#include "BusOperator.h"
#include <iostream>

using namespace std;

BusOperator::BusOperator(const string& username, const string& password)
    : User(username, password) {}

void BusOperator::viewBusRoutes(const vector<BusRoute>& routes) {
    cout << "\nAvailable Bus Routes:" << endl;
    for (const auto& route : routes) {
        route.displayRoute();
    }
}

bool BusOperator::updateSeats(vector<BusRoute>& routes, int routeId, int newSeats) {
    for (auto& route : routes) {
        if (route.getRouteId() == routeId) {
            route.setAvailableSeats(newSeats);
            return true;
        }
    }
    cout << "Invalid Route ID!" << endl;
    return false;
}

void BusOperator::operatorMenu(vector<BusRoute>& routes) {
    while (true) {
        cout << "\n=== Bus Operator Menu ===" << endl;
        cout << "1. View Bus Routes" << endl;
        cout << "2. Update Seat Availability" << endl;
        cout << "3. Logout" << endl;
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;
        
        if (choice == 1) {
            viewBusRoutes(routes);
        }
        else if (choice == 2) {
            viewBusRoutes(routes);
            cout << "Enter Route ID to update: ";
            int routeId;
            cin >> routeId;
            
            cout << "Enter new number of available seats: ";
            int newSeats;
            cin >> newSeats;
            
            if (updateSeats(routes, routeId, newSeats)) {
                cout << "Seats updated successfully!" << endl;
            }
        }
        else if (choice == 3) {
            cout << "Logging out..." << endl;
            break;
        }
    }
} 