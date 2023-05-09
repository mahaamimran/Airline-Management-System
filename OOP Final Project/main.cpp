// Maham 22i-2733 SE-F
#include <iostream>
#include <fstream>
#include <string>
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

void storePassengerDetailsinFile(Passenger &passenger,string name);
bool verifyFinancialDetails(PaymentDetails* pd);
void passengerRegistration();
void passengerLogin();
void adminLogin();
void populateFlightSchedule();
void mainMenu();

// Airplane class
class Airplane{ 
private:
    int airplaneID;
    int capacityEconomy;
    int capacityBusiness;
    string status; // in air / landed
    int numofPassengers; //  total 60, 30 can sit (capacity/2)
public:
    // constructors
    Airplane();
    Airplane(int id,int capE,int capB,string stat,int num);
    Airplane(const Airplane &other);

    // getters and setters
    int getAirplaneID() const;
    void setAirplaneID(int id);
    int getCapacityEconomy() const;
    void setCapacityEconomy(int capE);
    int getCapacityBusiness() const;
    void setCapacityBusiness(int capB);
    string getStatus() const;
    void setStatus(string stat);
    int getNumofPassengers() const;
    void setNumofPassengers(int num);
};
Airplane::Airplane(){
    airplaneID = 0;
    capacityEconomy = 0;
    capacityBusiness = 0;
    status = "";
    numofPassengers = 0;
}
Airplane::Airplane(int id,int capE,int capB,string stat,int num){
    airplaneID = id;
    capacityEconomy = capE;
    capacityBusiness = capB;
    status = stat;
    numofPassengers = num;
}
Airplane::Airplane(const Airplane &other){
    airplaneID = other.airplaneID;
    capacityEconomy = other.capacityEconomy;
    capacityBusiness = other.capacityBusiness;
    status = other.status;
    numofPassengers = other.numofPassengers;
}
int Airplane::getAirplaneID() const{
    return airplaneID;
}
void Airplane::setAirplaneID(int id){
    airplaneID = id;
}
int Airplane::getCapacityEconomy() const{
    return capacityEconomy;
}
void Airplane::setCapacityEconomy(int capE){
    capacityEconomy = capE;
}
int Airplane::getCapacityBusiness() const{
    return capacityBusiness;
}
void Airplane::setCapacityBusiness(int capB){
    capacityBusiness = capB;
}
string Airplane::getStatus() const{
    return status;
}
void Airplane::setStatus(string stat){
    status = stat;
}
int Airplane::getNumofPassengers() const{
    return numofPassengers;
}
void Airplane::setNumofPassengers(int num){
    numofPassengers = num;
}
// City class
class City{
private:
    string cityName;
    char NorthSouth; // 'n' or 's'
    int distance; 
    Airplane *airplane; // 10 airplanes max
    int numberOfAirplanes;
public:
    // constructors
    City();
    City(string name,char NS,Airplane *a,int num);
    City(const City &other);

    // getters and setters
    string getCityName() const;
    void setCityName(string name);
    char getNorthSouth() const;
    void setNorthSouth(char NS);
    Airplane* getAirplane(int index) const;
    void setAirplane(Airplane *a,int index);
    int getNumberOfAirplanes() const;
    void setNumberOfAirplanes(int num);
    
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
Country::Country(){
    name = "";
    distance = 0;
}
Country::Country(string name,int dist){
    this->name = name;
    distance = dist;
}
Country::Country(const Country &other){
    name = other.name;
    distance = other.distance;
}
string Country::getName() const{
    return name;
}
void Country::setName(string name){
    this->name = name;
}
int Country::getDistance() const{
    return distance;
}
void Country::setDistance(int dist){
    distance = dist;
}

// Flight class 
class Booking{
    Airplane *airplane; // 1
    Passenger *passenger; // 1 or more 
    Country *country; // 1 to country
    City *city; // 1 from city
    FlightSchedule *flightSchedule; // route details
    bool isLocal;
    // if flight is local only populate two city stuff idk omg
    // display cost by overloading << operator
public:
    // constructors 
    // getters + setters
    // methods
        // search for seat on airplane
        // update flight schedule (25%)



    // an array of passengers on an airplane
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
FlightSchedule::FlightSchedule(){
    departureTime = "";
    arrivalTime = "";
    departureDate = "";
    arrivalDate = "";
    ticketPrice = 0;
}
FlightSchedule::FlightSchedule(string depTime,string arrTime,string depDate,string arrDate,double price){
    departureTime = depTime;
    arrivalTime = arrTime;
    departureDate = depDate;
    arrivalDate = arrDate;
    ticketPrice = price;
}
FlightSchedule::FlightSchedule(const FlightSchedule &other){
    departureTime = other.departureTime;
    arrivalTime = other.arrivalTime;
    departureDate = other.departureDate;
    arrivalDate = other.arrivalDate;
    ticketPrice = other.ticketPrice;
}
void FlightSchedule::setDepartureTime(string depTime){
    departureTime = depTime;
}
string FlightSchedule::getDepartureTime() const{
    return departureTime;
}
void FlightSchedule::setArrivalTime(string arrTime){
    arrivalTime = arrTime;
}
string FlightSchedule::getArrivalTime() const{
    return arrivalTime;
}
void FlightSchedule::setDepartureDate(string depDate){
    departureDate = depDate;
}
string FlightSchedule::getDepartureDate() const{
    return departureDate;
}
void FlightSchedule::setArrivalDate(string arrDate){
    arrivalDate = arrDate;
}
string FlightSchedule::getArrivalDate() const{
    return arrivalDate;
}
void FlightSchedule::setTicketPrice(double price){
    ticketPrice = price;
}
double FlightSchedule::getTicketPrice() const{
    return ticketPrice;
}
void FlightSchedule::calculateTicketPrice(){
    // calculate ticket price
}
void FlightSchedule::changeFlightSchedule(){
    // change flight schedule
    // change/cancel 25% deduction
}

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
Login::Login(){
    username = "";
    password = "";
}
Login::Login(string un,string pw){
    username = un;
    password = pw;
}
Login::Login(const Login &other){
    username = other.username;
    password = other.password;
}
string Login::getUsername() const{
    return username;
}
void Login::setUsername(string un){
    username = un;
}
string Login::getPassword() const{
    return password;
}
void Login::setPassword(string pw){
    password = pw;
}

// AdminAccount class
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
    void updateInquiryDetails();
};
AdminAccount::AdminAccount():Login("",""){}
AdminAccount::AdminAccount(string un,string pw):Login(un,pw){}
AdminAccount::AdminAccount(const AdminAccount &other):Login(other){}
void AdminAccount::displayLoginDetails(){
    cout<<"Username: "<<username<<endl;
    cout<<"Password: ";
    for (int i=0;i<password.length();i++){
        cout<<"*";
    }
    cout<<endl;
}
void AdminAccount::changeFlightSchedule(){
    // change flight schedule
    // booking object created, populated and stored in a file
    string departureCity;
    char nsth;
    string arrivalCountry;
    
    int choice;
    do{
        cout<<"Would you like to add an international flight or a local flight?\n";
        cout<<"1. International\n";
        cout<<"2. Local\n";
        cout<<"3. Exit\n";
        cin>>choice;
        switch(choice){
            case 1:{
                // add international flight
                // asking admin to enter flight details
                int depCity;
                do{
                    cout<<"Which city is the flight departing from?\n";
                    cout<<"1. Islamabad\n";
                    cout<<"2. Lahore\n";
                    cout<<"3. Quetta\n";
                    cout<<"4. Peshawar\n";
                    cout<<"5. Karachi\n";
                    cin>>depCity;
                    switch(depCity){
                        case 1:
                            departureCity = "Islamabad";
                            break;
                        case 2:
                            departureCity = "Lahore";
                            break;
                        case 3:
                            departureCity = "Quetta";
                            break;
                        case 4:
                            departureCity = "Peshawar";
                            break;
                        case 5:
                            departureCity = "Karachi";
                            break;
                        default:
                            cout<<"Invalid choice. Please try again.\n";
                            break;
                    }
                }while(depCity<1 || depCity>5);

                int ns=0;
                do{
                    cout<<"Which Airport are you travelling from? (North/South)\n";
                    cout<<"1. North\n";
                    cout<<"2. South\n";
                    cin>>ns;
                    
                    switch(ns){
                        case 1:
                            nsth = 'N';
                            break;
                        case 2:
                            nsth = 'S';
                            break;
                        default:
                            cout<<"Invalid choice. Please try again.\n";
                            break;
                    }
                }while(ns<1 || ns >2);

                cout<<"Which Country is the flight arriving at?\n";
                // 25 countries
                int arrCountry;
                do{
                    cout<<"1. United States\n";
                    cout<<"2. Australia\n";
                    cout<<"3. Bangladesh\n";
                    cout<<"4. Canada\n";
                    cout<<"5. China\n";
                    cout<<"6. Egypt\n";
                    cout<<"7. France\n";
                    cout<<"8. Germany\n";
                    cout<<"9. India\n";
                    cout<<"10. Iran\n";
                    cout<<"11. Iraq\n";
                    cout<<"12. Italy\n";
                    cout<<"13. Japan\n";
                    cout<<"14. Malaysia\n";
                    cout<<"15. Nepal\n";
                    cout<<"16. New Zealand\n";
                    cout<<"17. Oman\n";
                    cout<<"18. Qatar\n";
                    cout<<"19. Russia\n";
                    cout<<"20. Saudi Arabia\n";
                    cout<<"21. South Africa\n";
                    cout<<"22. Spain\n";
                    cout<<"23. Sri Lanka\n";
                    cout<<"24. Turkey\n";
                    cout<<"25. United Kingdom\n";
                    cin>>arrCountry;
                    
                    switch(arrCountry){
                        case 1:
                            arrivalCountry = "United States";
                            break;
                        case 2:
                            arrivalCountry = "Australia";
                            break;
                        case 3:
                            arrivalCountry = "Bangladesh";
                            break;
                        case 4:
                            arrivalCountry = "Canada";
                            break;
                        case 5:
                            arrivalCountry = "China";
                            break;
                        case 6:
                            arrivalCountry = "Egypt";
                            break;
                        case 7:
                            arrivalCountry = "France";
                            break;
                        case 8:
                            arrivalCountry = "Germany";
                            break;
                        case 9:
                            arrivalCountry = "India";
                            break;
                        case 10:
                            arrivalCountry = "Iran";
                            break;
                        case 11:
                            arrivalCountry = "Iraq";
                            break;
                        case 12:
                            arrivalCountry = "Italy";
                            break;
                        case 13:
                            arrivalCountry = "Japan";
                            break;
                        case 14:
                            arrivalCountry = "Malaysia";
                            break;
                        case 15:
                            arrivalCountry = "Nepal";
                            break;
                        case 16:
                            arrivalCountry = "New Zealand";
                            break;
                        case 17:
                            arrivalCountry = "Oman";
                            break;
                        case 18:
                            arrivalCountry = "Qatar";
                            break;
                        case 19:
                            arrivalCountry = "Russia";
                            break;
                        case 20:
                            arrivalCountry = "Saudi Arabia";
                            break;
                        case 21:
                            arrivalCountry = "South Africa";
                            break;
                        case 22:
                            arrivalCountry = "Spain";
                            break;
                        case 23:
                            arrivalCountry = "Sri Lanka";
                            break;
                        case 24:
                            arrivalCountry = "Turkey";
                            break;
                        case 25:
                            arrivalCountry = "United Kingdom";
                            break;
                        default:
                            cout<<"Invalid choice. Please try again.\n";
                            break;
                    }
                }while(arrCountry<1||arrCountry>25);

                cout<<"Enter the departure date in the following format: dd/mm/yyyy\n";
                string departureDate;
                cin>>departureDate;
                cout<<"Enter the departure time in the following format: hh:mm\n";
                string departureTime;
                cin>>departureTime;
                cout<<"Enter the arrival date in the following format: dd/mm/yyyy\n";
                string arrivalDate;
                cin>>arrivalDate;
                cout<<"Enter the arrival time in the following format: hh:mm\n";
                string arrivalTime;
                cin>>arrivalTime;

                // storing flight object in a file
                fstream fout;
                fout.open("/Users/mahamimran/Files/InternationalFlightSchedule.txt",ios::out|ios::app);
                if(fout.is_open()){
                    fout<<departureCity<<"%"<<nsth<<"%"<<arrivalCountry<<"%"<<departureDate<<"%"<<departureTime<<"%"<<arrivalDate<<"%"<<arrivalTime<<"%"<<endl;
                }
                else cout<<"File not found.\n";
                fout.close();
                break;
            }
            case 2:{
                // add local flight
                int depCity;
                string departureCity;
                do{
                    cout<<"Which city is the flight departing from?\n";
                    cout<<"1. Islamabad\n";
                    cout<<"2. Lahore\n";
                    cout<<"3. Quetta\n";
                    cout<<"4. Peshawar\n";
                    cout<<"5. Karachi\n";
                    cin>>depCity;
                    switch(depCity){
                        case 1:
                            departureCity = "Islamabad";
                            break;
                        case 2:
                            departureCity = "Lahore";
                            break;
                        case 3:
                            departureCity = "Quetta";
                            break;
                        case 4:
                            departureCity = "Peshawar";
                            break;
                        case 5:
                            departureCity = "Karachi";
                            break;
                        default:
                            cout<<"Invalid choice. Please try again.\n";
                            break;
                    }
                }while(depCity<1 || depCity>5);

                int ns=0;
                char nschar;
                do{
                    cout<<"Which Airport are you travelling from? (North/South)\n";
                    cout<<"1. North\n";
                    cout<<"2. South\n";
                    cin>>ns;
                    switch(ns){
                        case 1:
                            nschar = 'N';
                            break;
                        case 2:
                            nschar = 'S';
                            break;
                        default:
                            cout<<"Invalid choice. Please try again.\n";
                            break;
                    }
                }while(ns<1 || ns >2);

                int arrCity;
                string arrivalCity;
                do{
                    cout<<"Which city is the flight arriving to\n";
                    cout<<"1. Islamabad\n";
                    cout<<"2. Lahore\n";
                    cout<<"3. Quetta\n";
                    cout<<"4. Peshawar\n";
                    cout<<"5. Karachi\n";
                    cin>>arrCity;
                    switch(arrCity){
                        case 1:
                            arrivalCity = "Islamabad";
                            break;
                        case 2:
                            arrivalCity = "Lahore";
                            break;
                        case 3:
                            arrivalCity = "Quetta";
                            break;
                        case 4:
                            arrivalCity = "Peshawar";
                            break;
                        case 5:
                            arrivalCity = "Karachi";
                            break;
                        default:
                            cout<<"Invalid choice. Please try again.\n";
                            break;
                    }
                }while(arrCity<1 || arrCity>5);

                int nsto=0;
                char nsthto;
                do{
                    cout<<"Which Airport are you travelling to? (North/South)\n";
                    cout<<"1. North\n";
                    cout<<"2. South\n";
                    cin>>nsto;
                    switch(nsto){
                        case 1:
                            nsthto = 'N';
                            break;
                        case 2:
                            nsthto = 'S';
                            break;
                        default:
                            cout<<"Invalid choice. Please try again.\n";
                            break;
                    }
                }while(nsto<1 || nsto >2);


                cout<<"Enter the departure date in the following format: dd/mm/yyyy\n";
                string departureDate;
                cin>>departureDate;
                cout<<"Enter the departure time in the following format: hh:mm\n";
                string departureTime;
                cin>>departureTime;
                cout<<"Enter the arrival date in the following format: dd/mm/yyyy\n";
                string arrivalDate;
                cin>>arrivalDate;
                cout<<"Enter the arrival time in the following format: hh:mm\n";
                string arrivalTime;
                cin>>arrivalTime;
                
                fstream fout;
                fout.open("/Users/mahamimran/Files/LocalFlightSchedule.txt",ios::out|ios::app);
                if(fout.is_open()){
                 fout<<departureCity<<"%"<<nschar<<"%"<<arrivalCity<<"%"<<nsthto<<"%"<<departureDate<<"%"<<departureTime<<"%"<<arrivalDate<<"%"<<arrivalTime<<"%"<<endl;
                }
                else cout<<"File not found.\n";
                fout.close();
                break;
            }
            case 3:
                cout<<"exiting...\n";
                break;
            default:
                cout<<"Invalid choice. Please try again.\n";
                break;
        }
        
    }while(choice!=3);
    
}
void AdminAccount::addNewRoute(){
    // add new route
}
void AdminAccount::restrictNumberOfPassengers(){
    // restrict number of passengers
}
void AdminAccount::updateInquiryDetails(){
    // update inquiry details
}

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
PassengerAccount::PassengerAccount():Login("",""){}
PassengerAccount::PassengerAccount(string un,string pwd):Login(un,pwd){}
PassengerAccount::PassengerAccount(const PassengerAccount &other):Login(other){}
void PassengerAccount::displayAccountDetails(){
    string pwd="";
    for(int i=0;i<password.length();i++) pwd+="*";
    cout<<"username: "<<username<<endl;
    cout<<"password: "<<pwd<<endl;
    // display username and password
}


bool PassengerAccount::operator==(const PassengerAccount &other){
    if(username==other.username && password==other.password) return true;
    return false;
}
ostream& operator<<(ostream &out,const PassengerAccount &pa){
    string pwd="";
    for(int i=0;i<pa.password.length();i++) pwd+="*";
    out<<"username: "<<pa.username<<endl;
    out<<"password: "<<pwd<<endl;
    return out;
}

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
PaymentDetails::PaymentDetails(){
    cardNumber = "";
    expiryDate = "";
    cvv = "";
}
PaymentDetails::PaymentDetails(string cn,string ed,string cv){
    cardNumber = cn;
    expiryDate = ed;
    cvv = cv;
}
PaymentDetails::PaymentDetails(const PaymentDetails &other){
    cardNumber = other.cardNumber;
    expiryDate = other.expiryDate;
    cvv = other.cvv;
}
string PaymentDetails::getCardNumber() const{
    return cardNumber;
}
void PaymentDetails::setCardNumber(string cn){
    cardNumber = cn;
}
string PaymentDetails::getExpiryDate() const{
    return expiryDate;
}
void PaymentDetails::setExpiryDate(string ed){
    expiryDate = ed;
}
string PaymentDetails::getCvv() const{
    return cvv;
}
void PaymentDetails::setCvv(string cv){
    cvv = cv;
}

class Passenger{
private:
    string name;
    string passportNumber;
    int cnic;
    bool visaStatus;
    PassengerAccount* login;
    PaymentDetails* paymentDetails;

public:
    // Constructors
    Passenger();
    Passenger(string nm,string pn,int cn,bool vs,PassengerAccount* lg,PaymentDetails* pd);
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

    PaymentDetails* getPaymentDetails() const;
    void setPaymentDetails(PaymentDetails* pd);

    // Member Functions
    void viewMostVisitedCountry();
    void viewTravellingCost();
    void updateDetails();

    // overloading<<operator
    friend ostream& operator<<(ostream& os,const Passenger& p);
};
Passenger::Passenger(){
    name = "";
    passportNumber = "";
    cnic = 0;
    visaStatus = false;
    login = nullptr;
    paymentDetails = nullptr;
}
Passenger::Passenger(string nm,string pn,int cn,bool vs,PassengerAccount* lg,PaymentDetails* pd){
    name = nm;
    passportNumber = pn;
    cnic = cn;
    visaStatus = vs;
    login = lg;
    paymentDetails = pd;
}
Passenger::Passenger(const Passenger &other){
    name = other.name;
    passportNumber = other.passportNumber;
    cnic = other.cnic;
    visaStatus = other.visaStatus;
    login = other.login;
    paymentDetails = other.paymentDetails;
}
string Passenger::getName() const{
    return name;
}
void Passenger::setName(string nm){
    name = nm;
}
string Passenger::getPassportNumber() const{
    return passportNumber;
}
void Passenger::setPassportNumber(string pn){
    passportNumber = pn;
}
int Passenger::getCnic() const{
    return cnic;
}
void Passenger::setCnic(int cn){
    cnic = cn;
}
bool Passenger::getVisaStatus() const{
    return visaStatus;
}
void Passenger::setVisaStatus(bool vs){
    visaStatus = vs;
}
PassengerAccount* Passenger::getLogin() const{
    return login;
}
void Passenger::setLogin(PassengerAccount* lg){
    login = lg;
}
PaymentDetails* Passenger::getPaymentDetails() const{
    return paymentDetails;
}
void Passenger::setPaymentDetails(PaymentDetails* pd){
    paymentDetails = pd;
}


void Passenger::viewMostVisitedCountry(){
    // display most visited country
}
void Passenger::viewTravellingCost(){
    // display travelling cost
}
void Passenger::updateDetails(){
    // update details
}


// werid placement ik
void PassengerAccount::resetPassword(Passenger passenger,string name){
    cout<<"Enter new password: ";
    string pwd;
    cin >> pwd;
    cout<<"Confirm your password: ";
    string confirmPassword;
    cin >> confirmPassword;
    while(pwd != confirmPassword
          || pwd.length() < 8
          || pwd.length() > 16
          || pwd.find_first_of("0123456789") == string::npos
          || pwd.find_first_of("!@#$%^&*()_+") == string::npos
          || pwd.find_first_of("A ") == string::npos
          || pwd.find_first_of("abcdefghijklmnopqrstuvwxyz") == string::npos){
        cout<<"Passwords do not match or do not meet the requirements. Please try again."<<endl;
        cout<<"Password must be 8-16 characters long and include at least one uppercase letter,one lowercase letter,one digit,and one special character."<<endl;
        cout<<"Enter your password: ";
        cin >> pwd;
        cout<<"Confirm your password: ";
        cin >> confirmPassword;
    }
    password = pwd;
     // update username in file
    storePassengerDetailsinFile(passenger, name);
}
void PassengerAccount::resetUsername(Passenger passenger,string name){
    string un;
    cout<<"Enter new username: ";
    cin>>un;
    username = un;
    // update username in file
    storePassengerDetailsinFile(passenger, name);
}
ostream& operator<<(ostream& os,const Passenger& p){
    os<<"Name: "<<p.name<<endl;
    os<<"Passport Number: "<<p.passportNumber<<endl;
    os<<"CNIC: "<<p.cnic<<endl;
    os<<"Visa Status: "<<p.visaStatus<<endl;
    os<<"Login Username: "<<p.login->getUsername()<<endl;
    // displaying *** instead of password
    string pwd="";
    for(int i=0;i<p.login->getPassword().length();i++) pwd+="*";
    os<<"Login Password: "<<pwd<<endl;
    return os;
}

// END OF CLASS DEFINITIONS
void storePassengerDetailsinFile(Passenger &passenger,string name){
    // WOHHOOO IT WORKED
    // open the input file for reading
    string logintxt = "/Users/mahamimran/Files/PassengerDetails.txt";
    ifstream fin(logintxt);
    if (!fin){
        cout<<"Error opening input file: "<<logintxt<<endl;
        return;
    }
    // open a temporary output file for writing
    string tempFile = "/Users/mahamimran/PassengerDetails_temp.txt";
    ofstream fout(tempFile);
    if (!fout){
        cout<<"Error opening temporary output file: "<<tempFile<<endl;
        fin.close();
        return;
    }
    // loop through each line in the input file
    bool found = false;
    string line;
    while (getline(fin,line)){
        // check if the line matches the passenger's name
        if (line.substr(0,name.length()) == name){
            fout << passenger.getName() << "%" << passenger.getPassportNumber() << "%" << passenger.getCnic() << "%" << passenger.getVisaStatus() << "%" << passenger.getLogin()->getUsername() << "%" << passenger.getLogin()->getPassword() << "%" << passenger.getPaymentDetails()->getCardNumber() << "%" << passenger.getPaymentDetails()->getExpiryDate() << "%" << passenger.getPaymentDetails()->getCvv() << endl;
            found = true;
        }
        else fout<<line<<endl;
        
    }
    // if no matching line was found,add a new line for the passenger at the end of the file
    if (!found){
        fout << passenger.getName() << "%" << passenger.getPassportNumber() << "%" << passenger.getCnic() << "%" << passenger.getVisaStatus() << "%" << passenger.getLogin()->getUsername() << "%" << passenger.getLogin()->getPassword() << "%" << passenger.getPaymentDetails()->getCardNumber() << "%" << passenger.getPaymentDetails()->getExpiryDate() << "%" << passenger.getPaymentDetails()->getCvv() << endl;
    }
    // close the input and output files
    fin.close();
    fout.close();

    // delete the original input file and rename the temporary output file to the original filename
    remove(logintxt.c_str());
    rename(tempFile.c_str(),logintxt.c_str());
}

bool verifyFinancialDetails(PaymentDetails* pd){
// verify financial details
    if(pd->getCardNumber().length()!=16 || pd->getCvv().length()!=3 || pd->getExpiryDate().length()!=5){
        cout<<"Invalid details entered. Please try again."<<endl;
        return false;
    }
    else{
        cout<<"Valid Payment details!"<<endl;
        return true;
    }
}

void passengerRegistration(){
   // creates an object of passenger and stores the details there
    cout<<"Are you registering for yourself or an under 18 dependant?\n";
    cout<<"1. Myself\n";
    cout<<"2. Dependant\n";
    int choice;
    cin>>choice;
    cout<<"Enter your name: ";
    string name;
    cin >> name;
    cout<<"Enter your passport number: ";
    string passportNumber;
    cin >> passportNumber;
    int cnic;
    cout<<"Enter your CNIC (13 digits): ";
    cin>>cnic;
    // ADD VALIDATION
    // 13 digits, not previously in record :/
    cout<<"Do you have a visa? (1 for yes,0 for no): ";
    bool visaStatus;
    cin >> visaStatus;
  
    bool isValid = false;
    PaymentDetails paymentDetails;
    while(!isValid){
        // Get card number
        string cn;
        cout << "Enter card number (16 digits): ";
        cin >> cn;
        paymentDetails.setCardNumber(cn);

        // Get expiry date
        string ed;
        cout << "Enter expiry date (MM/YY): ";
        cin >> ed;
        paymentDetails.setExpiryDate(ed);

        // Get CVV
        string cvv;
        cout << "Enter CVV (3 digits): ";
        cin >> cvv;
        paymentDetails.setCvv(cvv);
        
        // Verify details
        isValid = verifyFinancialDetails(&paymentDetails);
    }
    // create passenger account
    cout<<"creating account...\n";
    cout<<"Your username is: "<<name<<"_"<<endl;
    cout<<"Enter your password: ";
    string password;
    cin >> password;
    cout<<"Confirm your password: ";
    string confirmPassword;
    cin >> confirmPassword;
    while(password != confirmPassword
          || password.length() < 8
          || password.length() > 16
          || password.find_first_of("0123456789") == string::npos
          || password.find_first_of("!@#$%^&*()_+") == string::npos
          || password.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos
          || password.find_first_of("abcdefghijklmnopqrstuvwxyz") == string::npos){
        cout<<"Passwords do not match or do not meet the requirements. Please try again."<<endl;
        cout<<"Password must be 8-16 characters long and include at least one uppercase letter,one lowercase letter,one digit,and one special character."<<endl;
        cout<<"Enter your password: ";
        cin >> password;
        cout<<"Confirm your password: ";
        cin >> confirmPassword;
    }
    PassengerAccount passengerAccount(name+"_",password);
    Passenger passenger(name,passportNumber,cnic,visaStatus,&passengerAccount,&paymentDetails);
    cout<<"Your account has been created successfully!\n";
    cout<<"Your details are as follows:\n";
    // operator overloading used
    cout<<passenger;

    // storing in a file
    storePassengerDetailsinFile(passenger,name);
    // menu should inlude booking flights etc
    // resetting password option should also be available
}
void passengerLogin(){
    bool found = false;
    string password;
    string username;
    string name = "";
    do{
        cout<<"Enter your username: ";
      
        cin >> username;
        cout<<"Enter your password: ";
       
        cin >> password;
        // check if username and password match
        // read file
        fstream fin;
        fin.open("/Users/mahamimran/Files/PassengerDetails.txt",ios::in);
        string line;
       
        while(!fin.eof()){
            getline(fin,line);
            if(line.find("%" + username + "%" + password + "%") != string::npos){
                found = true;
                cout<<"login succesful"<<endl;
                int pos = int(line.find('%'));
                name = line.substr(0, pos);
                cout<<"Welcome "<<name<<"!"<<endl;
                break;
            }
        }
        if(!found)cout<<"Invalid username or password. Please try again."<<endl;
        fin.close();
    }while(!found);
    
    fstream fin;
    // opens file to read passenger details
    fin.open("/Users/mahamimran/Files/PassengerDetails.txt",ios::in);
    
       string name2, passportNumber, cnic, visaStatus2, username2, password2, cardNumber, expiryDate, cvv;
 while (fin) {
     // populating passenger
    getline(fin, name2, '%');
    getline(fin, passportNumber, '%');
    getline(fin, cnic, '%');
    getline(fin, visaStatus2, '%');
    getline(fin, username2, '%');
    getline(fin, password2, '%');
    getline(fin, cardNumber, '%');
    getline(fin, expiryDate, '%');
    getline(fin, cvv);
     // converting to bool
   
     // just checkinh awein
    if(name == name2){
        break;
    }
}
    bool visaStatus = (visaStatus2 == "1");
    PaymentDetails paymentDetails(cardNumber, expiryDate, cvv);
    PassengerAccount passengerAccount(username2, password2);
    Passenger passenger(name2, passportNumber, stoi(cnic), visaStatus, &passengerAccount, &paymentDetails);
    cout << "Your details are as follows:\n";
    cout << passenger;

    if(found){
        int choice;
        do{
            // display menu
            // menu should inlude booking flights etc
            // resetting password option should also be available
            cout<<"What action would you like to perform?\n";
            cout<<"1. Book a flight\n";
            cout<<"2. Reset username\n";
            cout<<"3. Reset password\n";
            cout<<"4. Display account details\n";
            cout<<"5. Exit\n";
            
            cin>>choice;
            switch(choice){
                case 1:
                   // book a flight
                    break;
                case 2:
                    // reset username
                    passengerAccount.resetUsername(passenger,name);
                    break;
                case 3:
                    // reset password
                    passengerAccount.resetPassword(passenger,name);
                    break;
                case 4:
                    // display account details
                    passengerAccount.displayAccountDetails();
                    break;
                case 5:
                    // exit
                    cout<<"exiting..."<<endl;
                    break;
                default:
                    cout<<"Invalid choice entered. Please try again.\n";
                    break;
            }
        }while(choice!=5);
    }
    else{
        passengerLogin();
    }
    // if yes, then display menu
    // if no, then display error message
    // menu should inlude booking flights etc
    // resetting password option should also be available
}
void adminLogin(){
    // creates an object of admin and stores the details there
     cout<<"Enter your username: ";
    string username;
    cin >> username;
    cout<<"Enter your password: ";
    string password;
    cin >> password;
    // check if username and password match
    // read file
    fstream fin;
    fin.open("/Users/mahamimran/Files/AdminLogin.txt",ios::in);
    string line;
    bool found = false;
    string name = "";
    while(fin){
        getline(fin,line);
        if(line.find("%" + username + "%" + password) != string::npos){
            found = true;
            cout<<"login succesful"<<endl;
            int pos = int(line.find('%'));
            name = line.substr(0, pos);
            cout<<"Welcome "<<name<<"!"<<endl;
            break;
        }
    }
    if(!found)cout<<"Invalid username or password. Please try again."<<endl;
    fin.close();
    // object for admin created 
    AdminAccount adminAccount(username,password);
    if(found){
        int choice;
        do{
        cout<<"What action would you like to perform?\n";
        cout<<"1. Display login details\n";
        cout<<"2. Change Flight Schedule\n";
        cout<<"3. Add new route\n";
        cout<<"4. Restrict number of passengers\n";
        cout<<"5. Update inquiry details\n";
        cout<<"6. Exit\n";
        cin>>choice;
        switch(choice){
            case 1:
                // display login details
                adminAccount.displayLoginDetails();
                break;
            case 2:
                // change flight schedule
                adminAccount.changeFlightSchedule();
                break;
            case 3:
                // add new route
                adminAccount.addNewRoute();
                break;
            case 4:
                // restrict number of passengers
                adminAccount.restrictNumberOfPassengers();
                break;
            case 5:
                // update inquiry details
                adminAccount.updateInquiryDetails();
                break;
            case 6:
                // exit
                cout<<"exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice entered. Please try again.\n";
        }
        }while(choice!=6);
    }
    else{
        adminLogin();
    }

}
void mainMenu(){
    int choice=0;
    while(choice!=3){
        cout<<"Are you a passenger or an admin?\n";
        cout<<"1. Passenger\n";
        cout<<"2. Admin\n";
        cout<<"3. Exit\n";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Do you have an existing account?\n";
                cout<<"1. Yes\n";
                cout<<"2. No\n";
                cout<<"3. Exit\n";
                int choice2;
                cin>>choice2;
                switch(choice2){
                    case 1:
                        // login
                        passengerLogin();
                        break;
                    case 2:
                        // register
                        passengerRegistration();
                        break;
                    case 3:
                        // exit
                        cout<<"exiting...\n";
                        break;
                    default:
                        cout<<"Invalid choice\n";
                        break;
                }
                break;
            case 2:
                // admin
                adminLogin();
                break;
            case 3:
                // exit
                cout<<"exiting...\n";
                break;
            default:
                cout<<"Invalid choice\n";
                break;
        }
    }
}
int main(){
    mainMenu();
    return 0;
}
