#ifndef PASSENGER_H
#define PASSENGER_H

#include "User.h"
#include "BusRoute.h"
#include <vector>

class Passenger : public User {
public:
    Passenger(const std::string& username, const std::string& password);
    void viewBusRoutes(const std::vector<BusRoute>& routes);
    bool bookBusRoute(std::vector<BusRoute>& routes, int routeId);
    void passengerMenu(std::vector<BusRoute>& routes);
};

#endif 