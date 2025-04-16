#ifndef BUSROUTE_H
#define BUSROUTE_H

#include <string>

class BusRoute {
private:
    int routeId;
    std::string from;
    std::string to;
    double price;
    std::string time;
    int availableSeats;

public:
    BusRoute(int id, const std::string& from, const std::string& to, 
             double price, const std::string& time, int seats);
    
    int getRouteId() const;
    std::string getFrom() const;
    std::string getTo() const;
    double getPrice() const;
    std::string getTime() const;
    int getAvailableSeats() const;
    void setAvailableSeats(int seats);
    void displayRoute() const;
};

#endif 