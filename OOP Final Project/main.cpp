// final project
// Maham 22i-2733 SE-F


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
Login::Login() {
    username = "";
    password = "";
}
Login::Login(string un, string pw) {
    username = un;
    password = pw;
}
Login::Login(const Login &other) {
    username = other.username;
    password = other.password;
}
string Login::getUsername() const {
    return username;
}
void Login::setUsername(string un) {
    username = un;
}
string Login::getPassword() const {
    return password;
}
void Login::setPassword(string pw) {
    password = pw;
}


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
Admin::Admin() {
    isAdmin = false;
}
Admin::Admin(bool isa) {
    isAdmin = isa;
}
Admin::Admin(const Admin &other) {
    isAdmin = other.isAdmin;
}
bool Admin::getIsAdmin() const {
    return isAdmin;
}
void Admin::setIsAdmin(bool isa) {
    isAdmin = isa;
}


// PassengerAccount class definition
class PassengerAccount : public Login {
private:
public:
    // constructors
    PassengerAccount();
    PassengerAccount(string un, string pwd);

    // member functions
    bool isValidAccount();
    void updateAccount();
    void displayAccountDetails(); // '***' instead of pwd
};
PassengerAccount::PassengerAccount():Login("","") {
}
PassengerAccount::PassengerAccount(string un, string pwd):Login(un,pwd) {
}

bool PassengerAccount::isValidAccount() {
    // check if username and password are valid
    return true;
}
void PassengerAccount::updateAccount() {
    // update username and password
}
void PassengerAccount::displayAccountDetails() {
    // display username and password
}

class Passenger {
private:
    string name;
    string passportNumber;
    int cnic;
    bool visaStatus;
    PassengerAccount* login;

public:
    // Constructors
    Passenger();
    Passenger(int nm, string pn, int cn, bool vs, PassengerAccount* lg);
    Passenger(const Passenger &other);

    // getters + setters
    string getName() const;
    void setName(string nm);
    string getPassportNumber() const;
    void setPassportNumber(string pn);
    int getCnic() const;
    void setCnic(int cn);
    bool getVisaStatus() const;
    void setVisaStatus(bool vs);
    PassengerAccount* getLogin() const;
    void setLogin(PassengerAccount* lg);

    // Member Functions
    void viewMostVisitedCountry();
    void viewTravellingCost();
    void updateDetails();

    // overloading << operator
    friend ostream& operator<<(ostream& os, const Passenger& p);
};
Passenger::Passenger() {
    name = "";
    passportNumber = "";
    cnic = 0;
    visaStatus = false;
    login = nullptr;
}
Passenger::Passenger(int nm, string pn, int cn, bool vs, PassengerAccount* lg) {
    name = nm;
    passportNumber = pn;
    cnic = cn;
    visaStatus = vs;
    login = lg;
}
Passenger::Passenger(const Passenger &other) {
    name = other.name;
    passportNumber = other.passportNumber;
    cnic = other.cnic;
    visaStatus = other.visaStatus;
    login = other.login;
}
string Passenger::getName() const {
    return name;
}
void Passenger::setName(string nm) {
    name = nm;
}
string Passenger::getPassportNumber() const {
    return passportNumber;
}
void Passenger::setPassportNumber(string pn) {
    passportNumber = pn;
}
int Passenger::getCnic() const {
    return cnic;
}
void Passenger::setCnic(int cn) {
    cnic = cn;
}
bool Passenger::getVisaStatus() const {
    return visaStatus;
}
void Passenger::setVisaStatus(bool vs) {
    visaStatus = vs;
}
PassengerAccount* Passenger::getLogin() const {
    return login;
}
void Passenger::setLogin(PassengerAccount* lg) {
    login = lg;
}

void Passenger::viewMostVisitedCountry() {
    // display most visited country
}
void Passenger::viewTravellingCost() {
    // display travelling cost
}
void Passenger::updateDetails() {
    // update details
}
ostream& operator<<(ostream& os, const Passenger& p){
    os << "Name: " << p.name << endl;
    os << "Passport Number: " << p.passportNumber << endl;
    os << "CNIC: " << p.cnic << endl;
    os << "Visa Status: " << p.visaStatus << endl;
    os << "Login: " << p.login << endl;
    return os;
}
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
void passengerLogin(){
   // creates an object of passenger and stores the details there
   PassengerAccount passengerAccount("username", "password");
   Passenger passenger;
   cout << "Enter your name: ";
   string name;
    cin >> name;
    passenger.setName(name);
    cout << "Enter your passport number: ";
    string passportNumber;
    cin >> passportNumber;
    passenger.setPassportNumber(passportNumber);
    cout << "Enter your CNIC: ";
    int cnic;
    cin >> cnic;
    passenger.setCnic(cnic);
    cout << "Do you have a visa? (1 for yes, 0 for no): ";
    bool visaStatus;
    cin >> visaStatus;
    passenger.setVisaStatus(visaStatus);
    passenger.setLogin(&passengerAccount);
    cout << "Your account has been created successfully!\n";
    cout << "Your account details are as follows:\n";
    cout << passenger;
    





   
}
void adminLogin(){
    // creates an object of admin and stores the details there

}
void loginMenu(){
    cout<<"Are you a passenger or an admin?\n";
    cout<<"1. Passenger\n";
    cout<<"2. Admin\n";
    cout<<"3. Exit\n";
    int choice;
    cin>>choice;
    switch(choice){
        case 1:
            // passenger
            passengerLogin();
            break;
        case 2:
            // admin
            adminLogin();
            break;
        case 3:
            // exit
            cout<<"Exiting...\n";
            break;
        default:
            cout<<"Invalid choice\n";
            break;
    }
}
void mainMenu(){
    cout<<"Are you a registered user?\n";
    cout<<"1. Yes\n";
    cout<<"2. No\n";
    cout<<"3. Exit\n";
    int choice;
    cin>>choice;
    switch(choice){
        case 1:
            // login
            loginMenu();
            break;
        case 2:
            // register
            // this person can only look up flight schedules
            break;
        case 3:
            // exit
            cout<<"Exiting...\n";
            break;
        default:
            cout<<"Invalid choice\n";
            break;
    }

}
int main(){
    passengerLogin();
    return 0;
}
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
