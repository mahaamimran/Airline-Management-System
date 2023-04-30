// final project
#include <iostream>
using namespace std;
class Airplane {
public:
    Airplane(int capacity, bool isInternational);
    int getCapacity() const;
    bool isInternational() const;
private:
    int capacity_;
    bool isInternational_;
};
class City {
public:
    City(const string& name);
    void addAirplane(Airplane* airplane);
    void removeAirplane(Airplane* airplane);
    int getNumAirplanes() const;
    const string& getName() const;
private:
    string name_;
    Airplane* airplanes_[10];
    int numAirplanes_;
};


class Flight {
public:
    Flight(const string& source, const string& destination, int durationHours, Airplane* airplane);
    const string& getSource() const;
    const string& getDestination() const;
    int getDurationHours() const;
    Airplane* getAirplane() const;
    int getNumAvailableSeats() const;
    void reserveSeat();
    void cancelSeat();
private:
    string source_;
    string destination_;
    int durationHours_;
    Airplane* airplane_;
    int numAvailableSeats_;
};
class FlightSchedule {
public:
    FlightSchedule();
    void addFlight(Flight* flight);
    void removeFlight(Flight* flight);
    int getNumFlights() const;
private:
    Flight* flights_[15];
    int numFlights_;
};



class Passenger {
public:
    Passenger(const string& name, const string& passportNumber, bool isLocal);
    const string& getName() const;
    const string& getPassportNumber() const;
    bool isLocal() const;
    void addVisitedCountry(const string& country, int cost);
    const string& getMostVisitedCountry() const;
    int getEstimatedCostMostVisitedCountry() const;
private:
    string name_;
    string passportNumber_;
    bool isLocal_;
};

class Booking {
public:
    Booking(Flight* flight, Passenger* passenger);
    Flight* getFlight() const;
    Passenger* getPassenger() const;
    int getTicketPrice() const;
private:
    Flight* flight_;
    Passenger* passenger_;
    int ticketPrice_;
};
class Login {
  // properties
  string username;
  string password;

  // methods
  bool is_valid();
  // other methods related to managing login information
};

class Admin : public Login {
  // properties
  string name;
  vector<Country*> restricted_countries;

  // methods
  void change_flight_schedule(Flight* flight);
  void add_route(Country* country);
  void update_airline_inquiry_details();
  // other methods related to managing admin information and privileges
};

class PassengerAccount : public Login {
  // properties
  string name;
  string cnic;
  vector<Booking*> bookings;
  PaymentDetails* payment_details;

  // methods
  void register_account();
  void update_account();
  void reset_password();
  void verify_financial_details();
  // other methods related to managing passenger account information
};

class PaymentDetails {
  // properties
  string account_number;
  string routing_number;
  string card_number;
  string expiry_date;

  // methods
  bool is_valid();
  // other methods related to managing payment details
};
class Country {
  // properties
  string name;
  bool requires_visa;

  // methods
  // other methods related to managing country information
};
int main(){
 
    return 0;
}
