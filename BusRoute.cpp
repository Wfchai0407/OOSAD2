#include "BusRoute.h"
#include <iostream>
#include <iomanip>

using namespace std;

BusRoute::BusRoute(int id, const string& from, const string& to, 
                   double price, const string& time, int seats)
    : routeId(id), from(from), to(to), price(price), time(time), availableSeats(seats) {}

int BusRoute::getRouteId() const {
    return routeId;
}

string BusRoute::getFrom() const {
    return from;
}

string BusRoute::getTo() const {
    return to;
}

double BusRoute::getPrice() const {
    return price;
}

string BusRoute::getTime() const {
    return time;
}

int BusRoute::getAvailableSeats() const {
    return availableSeats;
}

void BusRoute::setAvailableSeats(int seats) {
    availableSeats = seats;
}

void BusRoute::displayRoute() const {
    cout << "Route ID: " << routeId << endl;
    cout << "From: " << from << " To: " << to << endl;
    cout << "Price: RM" << fixed << setprecision(2) << price << endl;
    cout << "Time: " << time << endl;
    cout << "Available Seats: " << availableSeats << endl;
    cout << "------------------------" << endl;
} 