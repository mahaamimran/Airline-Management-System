// Maham 22i-2733 SE-F
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
// prototypes
using namespace std;
class Airplane;
class City;
class Country;
class Booking;
class FlightSchedule;
class Login;
class AdminAccount;
class PassengerAccount;
class Passenger;
class PaymentDetails;
// Airplane class
class Airplane{
private:
    string airplaneID;
    int capacityEconomy;
    int capacityBusiness;
    int numofPassengers; //  total 60, 30 can sit (capacity/2)
public:
    // constructors
    Airplane();
    Airplane(string id,int capE,int capB,int num);
    Airplane(const Airplane &other);

    // getters and setters
    string getAirplaneID() const;
    void setAirplaneID(string id);
    int getCapacityEconomy() const;
    void setCapacityEconomy(int capE);
    int getCapacityBusiness() const;
    void setCapacityBusiness(int capB);
    int getNumofPassengers() const;
    void setNumofPassengers(int num);
};
// City class
class City{
private:
    string cityName;
    char NorthSouth; // 'N' or 'S'
    
public:
    // constructors
    City();
    City(string name,char NS);
    City(const City &other);

    // getters and setters
    string getCityName() const;
    void setCityName(string name);
    char getNorthSouth() const;
    void setNorthSouth(char NS);
   
};
// Country class
class Country{
    string name;
    int distance;
public:
    // constructors
    Country();
    Country(string name,int dist);
    Country(const Country &other);

    // getters and setters
    string getName() const;
    void setName(string name);
    int getDistance() const;
    void setDistance(int dist);
};
// Flight class
class Booking{
    Airplane *airplane; // 1
    Passenger *passenger; // 1 or more
    Country *country; // 1 to country
    City *city; // 1 from city
    City *cityTo;
    FlightSchedule *flightSchedule; // route details
    bool isLocal;
    // if flight is local only populate two city stuff idk omg
    // display cost by overloading << operator
public:
    // constructors
    Booking();
    Booking(Airplane* airplane, Passenger* passenger, Country* country, City* city, City *cityTo, FlightSchedule* flightSchedule, bool isLocal);

    // Getters
    Airplane* getAirplane() const;
    Passenger* getPassenger() const;
    Country* getCountry() const;
    City* getCity() const;
    City *getCityTo() const;
    FlightSchedule* getFlightSchedule() const;
    bool getIsLocal() const;

    // Setters
    void setAirplane(Airplane* airplane);
    void setPassenger(Passenger* passenger);
    void setCountry(Country* country);
    void setCity(City* city);
    void setCityTo(City *cityTo);
    void setFlightSchedule(FlightSchedule* flightSchedule);
    void setIsLocal(bool isLocal);
    // methods
        // search for seat on airplane
        // update flight schedule (25%)

    // overloading operator << to display everything
    friend ostream& operator<<(ostream& os, const Booking& booking);
};
// FlightSchedule class
class FlightSchedule{
    string departureTime;
    string arrivalTime;
    string departureDate;
    string arrivalDate;
    double ticketPrice; // calculated in a memeber function called calculateTicketPrice()
    // change/cancel 25% deduction
public:
    // constructors
    FlightSchedule();
    FlightSchedule(string depTime,string arrTime,string depDate,string arrDate,double price);
    FlightSchedule(const FlightSchedule &other);

    // getters + setters
    void setDepartureTime(string depTime);
    string getDepartureTime() const;
    void setArrivalTime(string arrTime);
    string getArrivalTime() const;
    void setDepartureDate(string depDate);
    string getDepartureDate() const;
    void setArrivalDate(string arrDate);
    string getArrivalDate() const;
    void setTicketPrice(double price);
    double getTicketPrice() const;

    // methods
    void calculateTicketPrice();
    void changeFlightSchedule();
    // change/cancel 25% deduction
};
// Login class
class Login{
    protected:
        string username;
        string password;

    public:
        // Constructors
        Login();
        Login(string un,string pw);
        Login(const Login &other);

        // Getters and setters
        string getUsername() const;
        void setUsername(string un);
        string getPassword() const;
        void setPassword(string pw);
};
class AdminAccount : public Login{
public:
   // Constructors
    AdminAccount();
    AdminAccount(string un,string pw);
    AdminAccount(const AdminAccount &other);

    // member functions
    void displayLoginDetails(); // '***' instead of pwd
    void changeFlightSchedule();
    void addNewRoute();
    void restrictNumberOfPassengers();
    // updates in these functions
};
class Passenger{
private:
    string name;
    string passportNumber;
    string cnic;
    bool visaStatus;
    PassengerAccount* login;
    PaymentDetails* paymentDetails;

public:
    // Constructors
    Passenger();
    Passenger(string nm,string pn,string cn,bool vs,PassengerAccount* lg,PaymentDetails* pd);
    Passenger(const Passenger &other);

    // getters + setters
    string getName() const;
    void setName(string nm);

    string getPassportNumber() const;
    void setPassportNumber(string pn);

    string getCnic() const;
    void setCnic(string cn);

    bool getVisaStatus() const;
    void setVisaStatus(bool vs);

    PassengerAccount* getLogin() const;
    void setLogin(PassengerAccount* lg);

    PaymentDetails* getPaymentDetails() const;
    void setPaymentDetails(PaymentDetails* pd);

    // Member Functions
    void viewMostVisitedCountry();
    void viewTravellingCost();

    // overloading<<operator
    friend ostream& operator<<(ostream& os,const Passenger& p);
};
// PassengerAccount class definition
class PassengerAccount : public Login{
public:
    // constructors
    PassengerAccount();
    PassengerAccount(string un,string pwd);
    PassengerAccount(const PassengerAccount &other);

    // member functions
    void displayAccountDetails(); // '***' instead of pwd
    void resetPassword(Passenger passenger,string name);
    void resetUsername(Passenger passenger, string name);
    // overloading operators
    bool operator==(const PassengerAccount &other);
    friend ostream& operator<<(ostream &out,const PassengerAccount &pa);
};
// PaymentDetails class definition
class PaymentDetails{
private:
    string cardNumber;
    string expiryDate;
    string cvv;
public:
    // constructors
    PaymentDetails();
    PaymentDetails(string cn,string ed,string cv);
    PaymentDetails(const PaymentDetails &other);
    // getters and setters
    string getCardNumber() const;
    void setCardNumber(string cn);
    string getExpiryDate() const;
    void setExpiryDate(string ed);
    string getCvv() const;
    void setCvv(string cv);
};
