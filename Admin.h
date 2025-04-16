#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "BusRoute.h"
#include <vector>

class Admin : public User {
public:
    Admin(const std::string& username, const std::string& password);
    void viewBusRoutes(const std::vector<BusRoute>& routes);
    bool addBusRoute(std::vector<BusRoute>& routes);
    bool updateBusRoute(std::vector<BusRoute>& routes);
    bool removeBusRoute(std::vector<BusRoute>& routes);
    void adminMenu(std::vector<BusRoute>& routes);
};

#endif 