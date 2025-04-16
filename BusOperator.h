#ifndef BUSOPERATOR_H
#define BUSOPERATOR_H

#include "User.h"
#include "BusRoute.h"
#include <vector>

class BusOperator : public User {
public:
    BusOperator(const std::string& username, const std::string& password);
    void viewBusRoutes(const std::vector<BusRoute>& routes);
    bool updateSeats(std::vector<BusRoute>& routes, int routeId, int newSeats);
    void operatorMenu(std::vector<BusRoute>& routes);
};

#endif 