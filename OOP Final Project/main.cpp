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
    int numofPassengers; //  total 60, 30 can sit (capacity/2)
};
// City class
class City{
private:
    string cityName;
    char NorthSouth; // 'n' or 's'
    Airplane *airplane; // 10 airplanes max
    int numberOfAirplanes;

};
// Country class
class Country{
};
class Booking{
};

// Flight class definition
class Flight{
    FlightSchedule *flightSchedule;
    Airplane *airplane;
    Booking *booking;
};
// FlightSchedule class definition
class FlightSchedule{
};
// Booking class definition




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
    void displayAccountDetails(); // '***' instead of pwd
    void changeFlightSchedule();
    void addNewRoute();
    void restrictNumberofPassengers();
    void updateInquiryDetails();
};
AdminAccount::AdminAccount():Login("",""){}
AdminAccount::AdminAccount(string un,string pw):Login(un,pw){}
AdminAccount::AdminAccount(const AdminAccount &other):Login(other){}
void AdminAccount::displayAccountDetails(){
    cout<<"Username: "<<username<<endl;
    cout<<"Password: ";
    for (int i=0;i<password.length();i++){
        cout<<"*";
    }
    cout<<endl;
}
void AdminAccount::changeFlightSchedule(){
    // change flight schedule
}
void AdminAccount::addNewRoute(){
    // add new route
}
void AdminAccount::restrictNumberofPassengers(){
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
          || pwd.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos
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
    storePassengerDetailsinFile(passengerAccount,name);
    // menu should inlude booking flights etc
    // resetting password option should also be available
}
void passengerLogin(){
    cout<<"Enter your username: ";
    string username;
    cin >> username;
    cout<<"Enter your password: ";
    string password;
    cin >> password;
    // check if username and password match
    // read file
    fstream fin;
    fin.open("/Users/mahamimran/PassengerLogin.txt",ios::in);
    string line;
    bool found = false;
    string name = "";
    while(fin){
        getline(fin,line);
        if(line.find("%" + username + "%" + password) != string::npos){
            found = true;
            cout<<"login succesful"<<endl;
            size_t pos = line.find('%');
            name = line.substr(0, pos);
            cout<<"Welcome "<<name<<"!"<<endl;
            break;
        }
    }
    if(!found)cout<<"Invalid username or password. Please try again."<<endl;
    fin.close();
    // object for passenger created 
    PassengerAccount passengerAccount(username,password);
    if(found){
        // display menu
        // menu should inlude booking flights etc
        // resetting password option should also be available
        cout<<"What action would you like to perform?\n";
        cout<<"1. Book a flight\n";
        cout<<"2. Reset username\n";
        cout<<"3. Reset password\n";
        cout<<"4. Display account details\n";
        cout<<"5. Exit\n";
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                // book a flight
                break;
            case 2:
                // reset username
                passengerAccount.resetUsername(name);
                break;
            case 3:
                // reset password
                passengerAccount.resetPassword(name);
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
    fin.open("/Users/mahamimran/AdminLogin.txt",ios::in);
    string line;
    bool found = false;
    string name = "";
    while(fin){
        getline(fin,line);
        if(line.find("%" + username + "%" + password) != string::npos){
            found = true;
            cout<<"login succesful"<<endl;
            size_t pos = line.find('%');
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
        cout<<"What action would you like to perform?\n";
        cout<<"1. Display login details\n";
        cout<<"2. Change Flight Schedule\n";
        cout<<"3. Add new route\n";
        cout<<"4. Restrict number of passengers\n";
        cout<<"5. Update inquiry details\n";
        cout<<"6. Exit\n";
        int choice;
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
                    cout<<"Exiting...\n";
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
            cout<<"Exiting...\n";
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
