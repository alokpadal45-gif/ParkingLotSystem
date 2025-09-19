#include <iostream>
#include "ParkingLot.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    ParkingLot lot(5);
    int choice;

    while (true) {
        cout << "\n1. Park Vehicle\n2. Exit Vehicle\n3. Generate Report\n4. Exit\nChoose option: ";
        cin >> choice;
        if (choice == 1) {
            string num, type;
            cout << "Enter Vehicle Number: "; cin >> num;
            cout << "Enter Vehicle Type: "; cin >> type;
            lot.parkVehicle(num, type);
        } else if (choice == 2) {
            int ticketId;
            cout << "Enter Ticket ID: "; cin >> ticketId;
            lot.exitVehicle(ticketId);
        } else if (choice == 3) {
            lot.generateReport();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}

