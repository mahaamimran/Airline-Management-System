// final project
// Maham 22i-2733
/*
- Aggregation:
    - `City` has an array of `Airplane` objects.
    - `Country` has an array of `Airplane` objects.
    - `Passenger` has a `PassengerAccount` object.
- Composition:
    - `Flight` is composed of an `Airplane` object and a `Booking` object.
- Inheritance:
    - `Admin` inherits from `Login`.
    - `PassengerAccount` inherits from `Login`.
*/

#include <iostream>
using namespace std;
// Airplane class
class Airplane {
    private:
        int airplaneID;
        int capacity;
        bool isInternational;
        string status; // in air / landed

    public:
        // Constructors
        Airplane();
        Airplane(int id, int cap, bool isInter, string stat);
        Airplane(const Airplane &other);

        // Getters and setters
        int getAirplaneID() const;
        void setAirplaneID(int id);
        int getCapacity() const;
        void setCapacity(int cap);
        bool getIsInternational() const;
        void setIsInternational(bool isInter);
        string getStatus() const;
        void setStatus(string stat);
};
Airplane::Airplane() {
    airplaneID = 0;
    capacity = 0;
    isInternational = false;
    status = "";
}
Airplane::Airplane(int id, int cap, bool isInter, string stat) {
    airplaneID = id;
    capacity = cap;
    isInternational = isInter;
    status = stat;
}
Airplane::Airplane(const Airplane &other) {
    airplaneID = other.airplaneID;
    capacity = other.capacity;
    isInternational = other.isInternational;
    status = other.status;
}
int Airplane::getAirplaneID() const {
    return airplaneID;
}
void Airplane::setAirplaneID(int id) {
    airplaneID = id;
}
int Airplane::getCapacity() const {
    return capacity;
}
void Airplane::setCapacity(int cap) {
    capacity = cap;
}
bool Airplane::getIsInternational() const {
    return isInternational;
}
void Airplane::setIsInternational(bool isInter) {
    isInternational = isInter;
}
string Airplane::getStatus() const {
    return status;
}
void Airplane::setStatus(string stat) {
    status = stat;
}
// City class
class City {
    private:
        string name;
        char direction; // north / south
        int numofAirplanes;
        Airplane* airplanes;

    public:
        // Constructors
        City();
        City(string nm, char dir, int num, Airplane* airps);
        City(const City &other);

        // Getters and setters
        string getName() const;
        void setName(string nm);
        char getDirection() const;
        void setDirection(char dir);
        int getNumofAirplanes() const;
        void setNumofAirplanes(int num);
        Airplane* getAirplanes(int i) const; // make i airplane thing
        void setAirplanes(int i, Airplane airps);
};
City::City() {
    name = "";
    direction = '\0';
    numofAirplanes = 0;
    airplanes = nullptr;
}
City::City(string nm, char dir, int num, Airplane* airps) {
    name = nm;
    direction = dir;
    numofAirplanes = num;
    airplanes = new Airplane[num]; // check if you can assign like this
}
City::City(const City &other) {
    name = other.name;
    direction = other.direction;
    numofAirplanes = other.numofAirplanes;
    airplanes = other.airplanes;
}
 // Getters and setters
string City::getName() const {
    return name;
}
void City::setName(string nm) {
    name = nm;
}
char City::getDirection() const {
    return direction;
}
void City::setDirection(char dir) {
    direction = dir;
}
int City::getNumofAirplanes() const {
    return numofAirplanes;
}
void City::setNumofAirplanes(int num) {
    numofAirplanes = num;
}
// set and get airplane

// Country class
class Country {
    private:
        string name;
        int numofAirplanes;
        Airplane* airplanes;

    public:
        // Constructors
        Country();
        Country(string nm, int num, Airplane* airps);
        Country(const Country &other);

        // Getters and setters
        string getName() const;
        void setName(string nm);
        int getNumofAirplanes() const;
        void setNumofAirplanes(int num);
        Airplane* getAirplanes() const;
        void setAirplanes(Airplane* airps);
};

// Login class
class Login {
    private:
        string username;
        string password;

    public:
        // Constructors
        Login();
        Login(string un, string pw);
        Login(const Login &other);

        // Getters and setters
        string getUsername() const;
        void setUsername(string un);
        string getPassword() const;
        void setPassword(string pw);
};

// Admin class
class Admin : public Login {
    private:
        bool isAdmin;

    public:
        // Constructors
        Admin();
        Admin(bool isa);
        Admin(const Admin &other);

        // Getters and setters
        bool getIsAdmin() const;
        void setIsAdmin(bool isa);
};
// PassengerAccount class definition
class PassengerAccount : public Login {
private:
    string cnic;
    string passportNumber;
    string passportType;
    bool visaStamp;
    string accountDetails;
public:
    // constructors
    PassengerAccount();
    PassengerAccount(string un, string pw, string cnic, string passportNumber, string passportType, bool visaStamp, string accountDetails);
    PassengerAccount(const PassengerAccount& other);

    // getters and setters
    string getCNIC();
    void setCNIC(string cnic);

    string getPassportNumber();
    void setPassportNumber(string passportNumber);

    string getPassportType();
    void setPassportType(string passportType);

    bool getVisaStamp();
    void setVisaStamp(bool visaStamp);

    string getAccountDetails();
    void setAccountDetails(string accountDetails);
};
class Passenger {
private:
    int name;
    string passportNumber;
    bool isLocal;
    bool visaStatus;
    PassengerAccount* login;

public:
    // Constructors
    Passenger();
    Passenger(int name, string passportNumber, bool isLocal, bool visaStatus, PassengerAccount* login);
    Passenger(const Passenger& other);

    // Getters and Setters
    int getName();
    void setName(int name);
    string getPassportNumber();
    void setPassportNumber(string passportNumber);
    bool getIsLocal();
    void setIsLocal(bool isLocal);
    bool getVisaStatus();
    void setVisaStatus(bool visaStatus);
    PassengerAccount* getLogin();
    void setLogin(PassengerAccount* login);

    // Member Functions
    void viewMostVisitedCountry();
    void viewTravellingCost();
    void updateDetails();
};

// Flight class definition
class Flight {
private:
    string departureLocation;
    string destination;
    int durationHours;
    double distanceCovered;
    bool isInternational;
public:
    // constructors
    Flight();
    Flight(string departureLocation, string destination, int durationHours, double distanceCovered, bool isInternational);
    Flight(const Flight& other);

    // getters and setters
    string getDepartureLocation();
    void setDepartureLocation(string departureLocation);

    string getDestination();
    void setDestination(string destination);

    int getDurationHours();
    void setDurationHours(int durationHours);

    double getDistanceCovered();
    void setDistanceCovered(double distanceCovered);

    bool getIsInternational();
    void setIsInternational(bool isInternational);
};

// FlightSchedule class definition
class FlightSchedule {
private:
    Flight *flights;
public:
    // constructors
    FlightSchedule();
    FlightSchedule(Flight flights);
    FlightSchedule(const FlightSchedule& other);

    // getters and setters
    Flight getFlights();
    void setFlights(Flight &flights);
};

// Booking class definition
class Booking {
private:
  
public:
    // constructors
    Booking();
   
    Booking(const Booking& other);

};

// PaymentDetails class definition
class PaymentDetails {
private:
    string accountNumber;
    string routingNumber;
    string cardNumber;
    string expiryDate;
public:
    // constructors
    PaymentDetails();
    PaymentDetails(string accountNumber, string routingNumber, string cardNumber, string expiryDate);
    PaymentDetails(const PaymentDetails& other);

    // getters and setters
    string getAccountNumber();
    void setAccountNumber(string accountNumber);

    string getRoutingNumber();
    void setRoutingNumber(string routingNumber);

    string getCardNumber();
    void setCardNumber(string cardNumber);

    string getExpiryDate();
    void setExpiryDate(string expiryDate);
};
void mainMenu(){
    cout<<"1. Admin Login"<<endl;
    cout<<"2. Passenger Login"<<endl;
    cout<<"3. Exit"<<endl;

}
int main(){
 
    return 0;
}
