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

    // member functions
    bool isValidAccount();
};
 PassengerAccount::PassengerAccount() {
    cnic = "";
    passportNumber = "";
    passportType = "";
    visaStamp = false;
    accountDetails = "";
 }
PassengerAccount::PassengerAccount(string un, string pw, string cnic, string passportNumber, string passportType, bool visaStamp, string accountDetails) : Login(un, pw) {
    this->cnic = cnic;
    this->passportNumber = passportNumber;
    this->passportType = passportType;
    this->visaStamp = visaStamp;
    this->accountDetails = accountDetails;   
}
PassengerAccount::PassengerAccount(const PassengerAccount& other) : Login(other) {
    cnic = other.cnic;
    passportNumber = other.passportNumber;
    passportType = other.passportType;
    visaStamp = other.visaStamp;
    accountDetails = other.accountDetails;   
}
string PassengerAccount::getCNIC() {
    return cnic;
}
void PassengerAccount::setCNIC(string cnic) {
    this->cnic = cnic;
}
string PassengerAccount::getPassportNumber() {
    return passportNumber;
}
void PassengerAccount::setPassportNumber(string passportNumber) {
    this->passportNumber = passportNumber;
}
string PassengerAccount::getPassportType() {
    return passportType;
}
void PassengerAccount::setPassportType(string passportType) {
    this->passportType = passportType;
}
bool PassengerAccount::getVisaStamp() {
    return visaStamp;
}
void PassengerAccount::setVisaStamp(bool visaStamp) {
    this->visaStamp = visaStamp;
}
string PassengerAccount::getAccountDetails() {
    return accountDetails;
}
void PassengerAccount::setAccountDetails(string accountDetails) {
    this->accountDetails = accountDetails;
}
bool PassengerAccount::isValidAccount() {
    if (cnic == "" || passportNumber == "" || passportType == "" || accountDetails == "") {
        return false;
    }
    return true;
}




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
void passengerLogin(){
   // creates an object of passenger account and stores the details there
   PassengerAccount passengerAccount;
    string username, password, cnic, passportNumber, passportType, accountDetails;
    bool visaStamp;
    cout<<"Enter username: ";
    cin>>username;
    passengerAccount.setUsername(username);
    cout<<"Enter password: ";
    cin>>password;
    passengerAccount.setPassword(password);
    cout<<"Enter CNIC: ";
    cin>>cnic;
    passengerAccount.setCNIC(cnic);
    cout<<"Enter passport number: ";
    cin>>passportNumber;
    passengerAccount.setPassportNumber(passportNumber);
    cout<<"Enter passport type: ";
    cin>>passportType;
    passengerAccount.setPassportType(passportType);
    cout<<"Enter visa stamp: (1 for yes, 0 for no)";
    cin>>visaStamp;
    passengerAccount.setVisaStamp(visaStamp);
    cout<<"Enter account details: ";
    cin>>accountDetails;
    passengerAccount.setAccountDetails(accountDetails);
    cout<<"Account created successfully!\n";


   
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
    mainMenu();
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
