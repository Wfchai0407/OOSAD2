#include "Passenger.h"
#include <iostream>

using namespace std;

Passenger::Passenger(const string& username, const string& password)
    : User(username, password) {}

void Passenger::viewBusRoutes(const vector<BusRoute>& routes) {
    cout << "\nAvailable Bus Routes:" << endl;
    for (const auto& route : routes) {
        route.displayRoute();
    }
}

bool Passenger::bookBusRoute(vector<BusRoute>& routes, int routeId) {
    for (auto& route : routes) {
        if (route.getRouteId() == routeId) {
            if (route.getAvailableSeats() > 0) {
                route.setAvailableSeats(route.getAvailableSeats() - 1);
                return true;
            }
            cout << "No seats available for this route!" << endl;
            return false;
        }
    }
    cout << "Invalid Route ID!" << endl;
    return false;
}

void Passenger::passengerMenu(vector<BusRoute>& routes) {
    while (true) {
        cout << "\n=== Passenger Menu ===" << endl;
        cout << "1. View Bus Routes" << endl;
        cout << "2. Book a Bus" << endl;
        cout << "3. Logout" << endl;
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;
        
        if (choice == 1) {
            viewBusRoutes(routes);
        }
        else if (choice == 2) {
            viewBusRoutes(routes);
            cout << "Do you want to book a bus? (Y/N): ";
            char bookChoice;
            cin >> bookChoice;
            
            if (toupper(bookChoice) == 'Y') {
                cout << "Enter Route ID to book: ";
                int routeId;
                cin >> routeId;
                
                if (bookBusRoute(routes, routeId)) {
                    cout << "Booking successful!" << endl;
                }
            }
        }
        else if (choice == 3) {
            cout << "Logging out..." << endl;
            break;
        }
    }
} 