#include "Vehicle.h"

Vehicle::Vehicle(int _id, const string &_number, const string &_type)
    : id(_id), number(_number), type(_type), isInside(true)
{
    entryTime = time(nullptr);
    exitTime = 0;
}

