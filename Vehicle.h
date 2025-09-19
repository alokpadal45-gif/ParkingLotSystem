#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <ctime>
using std::string;

class Vehicle {
public:
    int id;
    string number;
    string type;
    time_t entryTime;
    time_t exitTime;
    bool isInside;

    Vehicle(int _id, const string &_number, const string &_type);
};

#endif // VEHICLE_H

