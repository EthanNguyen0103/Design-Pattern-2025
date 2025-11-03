#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Mock class for database library
class Database
{
public:
    void storeReservation(const string &reservation)
    {
        cout << "Database: Storing reservation: " << reservation << endl;
    }
};

// Mock class for payment gateway
class PaymentGateway
{
public:
    void processPayment(const string &paymentInfo)
    {
        cout << "Payment Gateway: Processing payment with info: " << paymentInfo << endl;
    }
};

// Mock class for messaging service
class MessagingService
{
public:
    void sendConfirmation(const string &message)
    {
        cout << "Messaging Service: Sending confirmation message: " << message << endl;
    }
};

class ReservationsystemFacede
{
    public:
        ReservationsystemFacede() : m_database(), m_paymentGateway(), m_messagingService() {};

        void reserveRoom(const string &reservation, const string &paymentInfo)
        {
            m_database.storeReservation(reservation);
            m_paymentGateway.processPayment(paymentInfo);
            m_messagingService.sendConfirmation("Reservation confirmed.");
        }
    private:
        Database m_database;
        PaymentGateway m_paymentGateway;
        MessagingService m_messagingService;
};

int main()
{
    // Database db;
    // PaymentGateway paymentGateway;
    // MessagingService messagingService;

    // const string reservation = "Room reservation info";
    // db.storeReservation(reservation);

    // const string paymentInfo = "Payment info";
    // paymentGateway.processPayment(paymentInfo);

    // messagingService.sendConfirmation("Reservation confirmed.");
    ReservationsystemFacede reservationSystem;

    const string reservation = "Room reservation info";
    const string paymentInfo = "Payment info";

    reservationSystem.reserveRoom(reservation, paymentInfo);

    return 0;
}
