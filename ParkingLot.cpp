#include "ParkingLot.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::max;

ParkingLot::ParkingLot(int totalSlots) : nextVehicleId(1), nextTicketId(1) {
    for (int i = 1; i <= totalSlots; i++)
        slots.push_back(Slot(i));
}

int ParkingLot::parkVehicle(const string &number, const string &type) {
    for (auto &slot : slots) {
        if (!slot.isOccupied) {
            slot.isOccupied = true;
            Vehicle v(nextVehicleId, number, type);
            vehicles.push_back(v);
            Ticket t(nextTicketId, v.id, slot.slotId);
            tickets.push_back(t);
            cout << "Vehicle parked. Ticket ID: " << nextTicketId
                 << ", Slot ID: " << slot.slotId << endl;
            nextVehicleId++;
            return nextTicketId++;
        }
    }
    cout << "Parking full! Cannot park vehicle." << endl;
    return -1;
}

double ParkingLot::exitVehicle(int ticketId) {
    auto tit = std::find_if(tickets.begin(), tickets.end(),
                            [ticketId](Ticket &t){ return t.ticketId == ticketId; });
    if (tit == tickets.end()) {
        cout << "Invalid Ticket ID!" << endl;
        return 0;
    }

    auto vit = std::find_if(vehicles.begin(), vehicles.end(),
                            [tit](Vehicle &v){ return v.id == tit->vehicleId; });
    if (vit == vehicles.end()) {
        cout << "Vehicle not found!" << endl;
        return 0;
    }

    if (!vit->isInside) {
        cout << "Vehicle has already exited!" << endl;
        return tit->amount;
    }

    vit->exitTime = time(nullptr);
    vit->isInside = false;
    double hours = difftime(vit->exitTime, vit->entryTime) / 3600.0;
    double bill = max(1.0, hours) * 10;
    tit->amount = bill;

    auto sit = std::find_if(slots.begin(), slots.end(),
                            [tit](Slot &s){ return s.slotId == tit->slotId; });
    if (sit != slots.end()) sit->isOccupied = false;

    cout << fixed << setprecision(2);
    cout << "Vehicle exited. Ticket ID: " << tit->ticketId
         << ", Bill: $" << bill << endl;
    cout.unsetf(std::ios::fixed);
    return bill;
}

void ParkingLot::generateReport() {
    cout << "\n--- Parking Lot Report ---\n";
    cout << "Total Slots: " << slots.size() << "\n";
    int occupied = std::count_if(slots.begin(), slots.end(),
                                 [](Slot &s){ return s.isOccupied; });
    cout << "Occupied Slots: " << occupied << "\n";
    cout << "Available Slots: " << slots.size() - occupied << "\n";

    double totalEarnings = 0;
    for (auto &t : tickets) totalEarnings += t.amount;
    cout << fixed << setprecision(2);
    cout << "Total Earnings: $" << totalEarnings << "\n";

    cout << "\nCurrent Parked Vehicles:\n";
    for (auto &v : vehicles) {
        if (v.isInside) {
            auto tit = std::find_if(tickets.begin(), tickets.end(),
                                    [&v](Ticket &t){ return t.vehicleId == v.id; });
            if (tit != tickets.end())
                cout << "Vehicle ID: " << v.id
                     << " | Number: " << v.number
                     << " | Slot: " << tit->slotId
                     << " | Type: " << v.type << endl;
        }
    }
    cout << "--------------------------\n";
    cout.unsetf(std::ios::fixed);
}

