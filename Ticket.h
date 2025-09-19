#ifndef TICKET_H
#define TICKET_H

class Ticket {
public:
    int ticketId;
    int vehicleId;
    int slotId;
    double amount;

    Ticket(int tId, int vId, int sId);
};

#endif // TICKET_H
