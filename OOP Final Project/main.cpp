// final project
// Maham 22i-2733 SE-F

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// Airplane class
class Airplane{
    private:
        int airplaneID;
        int capacity;
        bool isInternational;
        string status; // in air / landed

    public:
        // Constructors
        Airplane();
        Airplane(int id,int cap,bool isInter,string stat);
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
Airplane::Airplane(){
    airplaneID = 0;
    capacity = 0;
    isInternational = false;
    status = "";
}
Airplane::Airplane(int id,int cap,bool isInter,string stat){
    airplaneID = id;
    capacity = cap;
    isInternational = isInter;
    status = stat;
}
Airplane::Airplane(const Airplane &other){
    airplaneID = other.airplaneID;
    capacity = other.capacity;
    isInternational = other.isInternational;
    status = other.status;
}
int Airplane::getAirplaneID() const{
    return airplaneID;
}
void Airplane::setAirplaneID(int id){
    airplaneID = id;
}
int Airplane::getCapacity() const{
    return capacity;
}
void Airplane::setCapacity(int cap){
    capacity = cap;
}
bool Airplane::getIsInternational() const{
    return isInternational;
}
void Airplane::setIsInternational(bool isInter){
    isInternational = isInter;
}
string Airplane::getStatus() const{
    return status;
}
void Airplane::setStatus(string stat){
    status = stat;
}
// City class
class City{
    private:
        string name;
        char direction; // north / south
        int numofAirplanes;
        Airplane* airplanes;

    public:
        // Constructors
        City();
        City(string nm,char dir,int num,Airplane* airps);
        City(const City &other);

        // Getters and setters
        string getName() const;
        void setName(string nm);
        char getDirection() const;
        void setDirection(char dir);
        int getNumofAirplanes() const;
        void setNumofAirplanes(int num);
        Airplane* getAirplanes(int i) const; // make i airplane thing
        void setAirplanes(int i,Airplane airps);
};
City::City(){
    name = "";
    direction = '\0';
    numofAirplanes = 0;
    airplanes = nullptr;
}
City::City(string nm,char dir,int num,Airplane* airps){
    name = nm;
    direction = dir;
    numofAirplanes = num;
    airplanes = new Airplane[num]; // check if you can assign like this
}
City::City(const City &other){
    name = other.name;
    direction = other.direction;
    numofAirplanes = other.numofAirplanes;
    airplanes = other.airplanes;
}
 // Getters and setters
string City::getName() const{
    return name;
}
void City::setName(string nm){
    name = nm;
}
char City::getDirection() const{
    return direction;
}
void City::setDirection(char dir){
    direction = dir;
}
int City::getNumofAirplanes() const{
    return numofAirplanes;
}
void City::setNumofAirplanes(int num){
    numofAirplanes = num;
}
// set and get airplane

// Country class
class Country{
    private:
        string name;
        int numofAirplanes;
        Airplane* airplanes;

    public:
        // Constructors
        Country();
        Country(string nm,int num,Airplane* airps);
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


// Admin class
class Admin : public Login{
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
Admin::Admin(){
    isAdmin = false;
}
Admin::Admin(bool isa){
    isAdmin = isa;
}
Admin::Admin(const Admin &other){
    isAdmin = other.isAdmin;
}
bool Admin::getIsAdmin() const{
    return isAdmin;
}
void Admin::setIsAdmin(bool isa){
    isAdmin = isa;
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
    void resetPassword(string name);
    void resetUsername(string name);
    // overloading operators
    bool operator==(const PassengerAccount &other);
    friend ostream& operator<<(ostream &out,const PassengerAccount &pa);
};
void storePassengerDetailsinFile(PassengerAccount passengerAccount,string name){
    // WOHHOOO IT WORKED
    // open the input file for reading
    string logintxt = "/Users/mahamimran/PassengerLogin.txt";
    ifstream fin(logintxt);
    if (!fin){
        cout<<"Error opening input file: "<<logintxt<<endl;
        return;
    }
    // open a temporary output file for writing
    string tempFile = "/Users/mahamimran/PassengerLogin_temp.txt";
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
            fout<<name<<"%"<<passengerAccount.getUsername()<<"%"<<passengerAccount.getPassword()<<endl;
            found = true;
        }
        else fout<<line<<endl;
        
    }
    // if no matching line was found,add a new line for the passenger at the end of the file
    if (!found){
        fout<<name<<"%"<<passengerAccount.getUsername()<<"%"<<passengerAccount.getPassword()<<endl;
    }
    // close the input and output files
    fin.close();
    fout.close();

    // delete the original input file and rename the temporary output file to the original filename
    remove(logintxt.c_str());
    rename(tempFile.c_str(),logintxt.c_str());
}

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
void PassengerAccount::resetPassword(string name){
    string pwd;
    cout<<"Enter new Password: ";
    cin>>pwd;
    password = pwd;
    // update username in file
    PassengerAccount pa(username,password);
    storePassengerDetailsinFile(pa,name);
}
void PassengerAccount::resetUsername(string name){
    string un;
    cout<<"Enter new username: ";
    cin>>un;
    username = un;
    // update username in file
    PassengerAccount pa(username,password);
    storePassengerDetailsinFile(pa,name);

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
    int cvv;
public:
    // constructors
    PaymentDetails();
    PaymentDetails(string cn,string ed,int cv);
    PaymentDetails(const PaymentDetails &other);
    // getters and setters
    string getCardNumber() const;
    void setCardNumber(string cn);
    string getExpiryDate() const;
    void setExpiryDate(string ed);
    int getCvv() const;
    void setCvv(int cv);
};
PaymentDetails::PaymentDetails(){
    cardNumber = "";
    expiryDate = "";
    cvv = 0;
}
PaymentDetails::PaymentDetails(string cn,string ed,int cv){
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
int PaymentDetails::getCvv() const{
    return cvv;
}
void PaymentDetails::setCvv(int cv){
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
// Flight class definition
class Flight{
private:
    string departureLocation;
    string destination;
    int durationHours;
    double distanceCovered;
    bool isInternational;
public:
    // constructors
    Flight();
    Flight(string departureLocation,string destination,int durationHours,double distanceCovered,bool isInternational);
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
class FlightSchedule{
private:
    Flight *flights;
public:
   
};

// Booking class definition
class Booking{
private:
  
public:
    // constructors
    Booking();
    Booking(const Booking& other);

};



void passengerLogin(){
   // creates an object of passenger and stores the details there
    cout<<"Enter your name: ";
    string name;
    cin >> name;
    cout<<"Enter your passport number: ";
    string passportNumber;
    cin >> passportNumber;
    int cnic;
    cout<<"Enter your CNIC: ";
    cin>>cnic;
    // ADD VALIDATION
    cout<<"Do you have a visa? (1 for yes,0 for no): ";
    bool visaStatus;
    cin >> visaStatus;
    cout<<"Enter your card number: ";
    string cardNumber;
    cin >> cardNumber;
    cout<<"Enter your card expiry date: ";
    string expiryDate;
    cin >> expiryDate;
    cout<<"Enter your card CVV: ";
    int cvv;
    cin >> cvv;
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

    PaymentDetails paymentDetails(cardNumber,expiryDate,cvv);
    PassengerAccount passengerAccount(name+"_",password);
    Passenger passenger(name,passportNumber,cnic,visaStatus,&passengerAccount,&paymentDetails);
    cout<<"Your account has been created successfully!\n";
    cout<<"Your details are as follows:\n";
    // operator overloading used
    cout<<passenger;
    // storing in a file
    storePassengerDetailsinFile(passengerAccount,name);
    passengerAccount.resetUsername(name);
    passengerAccount.resetPassword(name);
    
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
            // add a thing for registering for dependants
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
