#include <iostream>
#include <vector>
#include <string>
#include "User.h"
#include "Passenger.h"
#include "BusOperator.h"
#include "Admin.h"
#include "BusRoute.h"

using namespace std;

void initializeBusRoutes(vector<BusRoute>& routes) {
    routes.push_back(BusRoute(1, "Klang", "Kuala Lumpur", 15.00, "08:00", 40));
    routes.push_back(BusRoute(2, "Kuala Lumpur", "Shah Alam", 12.00, "09:00", 40));
    routes.push_back(BusRoute(3, "Shah Alam", "Klang", 10.00, "10:00", 40));
}

void displayMainMenu() {
    cout << "\n=== Bus Booking System ===" << endl;
    cout << "1. Passenger" << endl;
    cout << "2. Bus Operator" << endl;
    cout << "3. Admin" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    vector<BusRoute> busRoutes;
    initializeBusRoutes(busRoutes);
    
    while (true) {
        displayMainMenu();
        int choice;
        cin >> choice;
        
        if (choice == 4) {
            cout << "Thank you for using the Bus Booking System!" << endl;
            break;
        }
        
        cout << "\n1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "Enter your choice: ";
        int authChoice;
        cin >> authChoice;
        
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        
        if (authChoice == 1) {
            // Login logic
            switch (choice) {
                case 1: {
                    Passenger passenger(username, password);
                    if (passenger.login(username, password)) {
                        passenger.passengerMenu(busRoutes);
                    } else {
                        cout << "Login failed!" << endl;
                    }
                    break;
                }
                case 2: {
                    BusOperator operator_(username, password);
                    if (operator_.login(username, password)) {
                        operator_.operatorMenu(busRoutes);
                    } else {
                        cout << "Login failed!" << endl;
                    }
                    break;
                }
                case 3: {
                    Admin admin(username, password);
                    if (admin.login(username, password)) {
                        admin.adminMenu(busRoutes);
                    } else {
                        cout << "Login failed!" << endl;
                    }
                    break;
                }
            }
        } else if (authChoice == 2) {
            // Register logic
            switch (choice) {
                case 1: {
                    Passenger passenger(username, password);
                    if (passenger.registerUser(username, password)) {
                        cout << "Registration successful!" << endl;
                    } else {
                        cout << "Registration failed!" << endl;
                    }
                    break;
                }
                case 2: {
                    BusOperator operator_(username, password);
                    if (operator_.registerUser(username, password)) {
                        cout << "Registration successful!" << endl;
                    } else {
                        cout << "Registration failed!" << endl;
                    }
                    break;
                }
                case 3: {
                    Admin admin(username, password);
                    if (admin.registerUser(username, password)) {
                        cout << "Registration successful!" << endl;
                    } else {
                        cout << "Registration failed!" << endl;
                    }
                    break;
                }
            }
        }
    }
    
    return 0;
} 