#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <vector>
#include <string>
#include "Vehicle.h"
#include "Slot.h"
#include "Ticket.h"
using std::vector;
using std::string;

class ParkingLot {
private:
    vector<Slot> slots;
    vector<Vehicle> vehicles;
    vector<Ticket> tickets;
    int nextVehicleId;
    int nextTicketId;

public:
    ParkingLot(int totalSlots);

    int parkVehicle(const string &number, const string &type);
    double exitVehicle(int ticketId);
    void generateReport();
};

#endif // PARKINGLOT_H

