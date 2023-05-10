// Maham 22i-2733 SE-F
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "header.h"
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
void displayLocalFlights();
void displayInternationalFlights();
void bookFlight(Passenger passenger);
void passengerLogin();
void adminLogin();
void guestLogin();
void mainMenu();

const int economySeats = 50;
const int businessSeats = 10;
int passengers=0;
Airplane::Airplane(){
    airplaneID = "";
    capacityEconomy = 0;
    capacityBusiness = 0;
    numofPassengers = 0;
}
Airplane::Airplane(string id,int capE,int capB,int num){
    airplaneID = id;
    capacityEconomy = capE;
    capacityBusiness = capB;
    numofPassengers = num;
}
Airplane::Airplane(const Airplane &other){
    airplaneID = other.airplaneID;
    capacityEconomy = other.capacityEconomy;
    capacityBusiness = other.capacityBusiness;
    numofPassengers = other.numofPassengers;
}
string Airplane::getAirplaneID() const{
    return airplaneID;
}
void Airplane::setAirplaneID(string id){
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
int Airplane::getNumofPassengers() const{
    return numofPassengers;
}
void Airplane::setNumofPassengers(int num){
    numofPassengers = num;
}
City::City(){
    cityName = "";
    NorthSouth = 'M'; // empty ahah
}
City::City(string name,char NS){
    cityName = name;
    NorthSouth = NS;
}
City::City(const City &other){
    cityName = other.cityName;
    NorthSouth = other.NorthSouth;
}
string City::getCityName() const{
    return cityName;
}
void City::setCityName(string name){
    cityName = name;
}
char City::getNorthSouth() const{
    return NorthSouth;
}
void City::setNorthSouth(char NS){
    NorthSouth = NS;
}


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

Booking::Booking():airplane(nullptr),passenger(nullptr),country(nullptr),city(nullptr),cityTo(nullptr),flightSchedule(nullptr),isLocal(false){}
Booking::Booking(Airplane* airplane, Passenger* passenger, Country* country, City* city, City *cityTo, FlightSchedule* flightSchedule, bool isLocal){
    this->airplane = airplane;
    this->passenger = passenger;
    this->country = country;
    this->city = city;
    this->cityTo = cityTo;
    this->flightSchedule = flightSchedule;
    this->isLocal = isLocal;
}
Airplane* Booking::getAirplane() const{
    return airplane;
}
Passenger* Booking::getPassenger() const{
    return passenger;
}
Country* Booking::getCountry() const{
    return country;
}
City* Booking::getCity() const{
    return city;
}
City *Booking::getCityTo() const{
    return cityTo;
}
FlightSchedule* Booking::getFlightSchedule() const{
    return flightSchedule;
}
bool Booking::getIsLocal() const{
    return isLocal;
}
void Booking::setAirplane(Airplane* airplane){
    this->airplane = airplane;
}
void Booking::setPassenger(Passenger* passenger){
    this->passenger = passenger;
}
void Booking::setCountry(Country* country){
    this->country = country;
}
void Booking::setCity(City* city){
    this->city = city;
}
void Booking::setCityTo(City *cityTo){
    this->cityTo = cityTo;
}
void Booking::setFlightSchedule(FlightSchedule* flightSchedule){
    this->flightSchedule = flightSchedule;
}
void Booking::setIsLocal(bool isLocal){
    this->isLocal = isLocal;
}


    // an array of passengers on an airplane
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
    ticketPrice =( stoi(arrivalTime.substr(0,1)) - stoi(departureTime.substr(0,1)) ) * 20000;
    cout<<"Total Price: "<<ticketPrice<<endl;
    int choice=0;
    do{
        cout<<"Was the flight International or Local?\n";
        cout<<"1. International\n";
        cout<<"2. Local\n";
        cin>>choice;
            if(choice==1){
                ticketPrice = 1.05*ticketPrice;
            }
            else if(choice==2){
                ticketPrice = 1.1*ticketPrice;
            }
            else{
                cout<<"Invalid choice\n";
            }
    }while(choice!=1 && choice!=2);
    cout<<"Price with Tax deduction: "<<ticketPrice<<endl;
    
}
void FlightSchedule::changeFlightSchedule(){
    ticketPrice = 0.75 * ticketPrice;
}

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
string Login::getPassword() const {
    return password;
}
void Login::setPassword(string pw){
    password = pw;
}

// AdminAccount class
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
    // change route of flight based on flightID?
    int choice;
    do{
    cout<<"Would you like to change an international flight or a local flight?"<<endl;
    cout<<"1. International"<<endl;
    cout<<"2. Local"<<endl;
    cin>>choice;
        switch(choice){
            case 1:{
                // change international flight
                cout<<"Enter the FlightID of the flight you would like to modify: ";
                // Ask the user for the flight details to be replaced
                string flightID;
                cin >> flightID;
                int planeChoice;
                string plane;
                string departureCity;
                char nsth='%';
                string arrivalCountry;
                do{
                    cout<<"What Airplane will be used for this flight?\n";
                    cout<<"1. PK101\n";
                    cout<<"2. PK102\n";
                    cout<<"3. PK103\n";
                    cout<<"4. PK104\n";
                    cout<<"5. PK105\n";
                    cout<<"6. PK106\n";
                    cout<<"7. PK107\n";
                    cout<<"8. PK108\n";
                    cout<<"9. PK109\n";
                    cout<<"10. PK110\n";
                    cin>>planeChoice;
                    switch(planeChoice){
                        case 1:
                            plane = "PK101";
                            break;
                        case 2:
                            plane = "PK102";
                            break;
                        case 3:
                            plane = "PK103";
                            break;
                        case 4:
                            plane = "PK104";
                            break;
                        case 5:
                            plane = "PK105";
                            break;
                        case 6:
                            plane = "PK106";
                            break;
                        case 7:
                            plane = "PK107";
                            break;
                        case 8:
                            plane = "PK108";
                            break;
                        case 9:
                            plane = "PK109";
                            break;
                        case 10:
                            plane = "PK110";
                            break;
                        default:
                            cout<<"Invalid choice. Please try again.\n";
                            break;
                    }

                }while(planeChoice<1 || planeChoice>10);

                
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
                // Open the input file and a temporary output file for writing
                string internationalFlightTxt = "/Users/mahamimran/Files/InternationalFlightSchedule.txt";
                ifstream fin(internationalFlightTxt);
                if (!fin) {
                    cout << "Error opening input file: " << internationalFlightTxt << endl;
                    return;
                }
                string tempFile = "/Users/mahamimran/InternationalFlightSchedule_temp.txt";
                ofstream fout(tempFile);
                if (!fout) {
                    cout << "Error opening temporary output file: " << tempFile << endl;
                    fin.close();
                    return;
                }

                // Read each line from the input file, check if it matches the user's flight details, and write the updated flight details to the temporary output file
                bool found = false;
                string line;
                while (getline(fin, line)) {
                    // check if the line matches the flight details
                    if (line.substr(0, flightID.length()) == flightID) {
                        found = true;
                        fout << flightID << "%" << plane << "%" << departureCity << "%" << nsth << "%" << arrivalCountry << "%" << departureDate << "%" << departureTime << "%" << arrivalDate << "%" << arrivalTime << "%" << endl;
                    } else {
                        fout << line << endl;
                    }
                }

                // If no matching line was found, print a message to the user
                if (!found) {
                    cout << "No matching flight with the given details was found." << endl;
                }

                // Close the input and output files
                fin.close();
                fout.close();

                // Delete the original input file and rename the temporary output file to the original filename
                remove(internationalFlightTxt.c_str());
                rename(tempFile.c_str(), internationalFlightTxt.c_str());

                break;
        }
        case 2:{
            // change local flight
            cout<<"Enter the FlightID of the flight you would like to modify: ";
            // Ask the user for the flight details to be replaced
            string flightID;
            cin >> flightID;
            int planeChoice;
            string plane;
            do{
                cout<<"What Airplane will be used for this flight?\n";
                cout<<"1. PK101\n";
                cout<<"2. PK102\n";
                cout<<"3. PK103\n";
                cout<<"4. PK104\n";
                cout<<"5. PK105\n";
                cout<<"6. PK106\n";
                cout<<"7. PK107\n";
                cout<<"8. PK108\n";
                cout<<"9. PK109\n";
                cout<<"10. PK110\n";
                cin>>planeChoice;
                switch(planeChoice){
                    case 1:
                        plane = "PK101";
                        break;
                    case 2:
                        plane = "PK102";
                        break;
                    case 3:
                        plane = "PK103";
                        break;
                    case 4:
                        plane = "PK104";
                        break;
                    case 5:
                        plane = "PK105";
                        break;
                    case 6:
                        plane = "PK106";
                        break;
                    case 7:
                        plane = "PK107";
                        break;
                    case 8:
                        plane = "PK108";
                        break;
                    case 9:
                        plane = "PK109";
                        break;
                    case 10:
                        plane = "PK110";
                        break;
                    default:
                        cout<<"Invalid choice. Please try again.\n";
                        break;
                }

            }while(planeChoice<1 || planeChoice>10);

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
            char nschar='%';
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
            char nsthto='%';
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
            string LocalFlightTxt = "/Users/mahamimran/Files/LocalFlightSchedule.txt";
            ifstream fin(LocalFlightTxt);
            if (!fin) {
                cout << "Error opening input file: " << LocalFlightTxt << endl;
                return;
            }
            string tempFile = "/Users/mahamimran/LocalFlightSchedule_temp.txt";
            ofstream fout(tempFile);
            if (!fout) {
                cout << "Error opening temporary output file: " << tempFile << endl;
                fin.close();
                return;
            }

            // Read each line from the input file, check if it matches the user's flight details, and write the updated flight details to the temporary output file
            bool found = false;
            string line;
            while (getline(fin, line)) {
                // check if the line matches the flight details
                if (line.substr(0, flightID.length()) == flightID) {
                    found = true;
                    fout<<flightID<<"%"<<plane<<"%"<<departureCity<<"%"<<nschar<<"%"<<arrivalCity<<"%"<<nsthto<<"%"<<departureDate<<"%"<<departureTime<<"%"<<arrivalDate<<"%"<<arrivalTime<<"%"<<endl;
                } else {
                    fout << line << endl;
                }
            }

            // If no matching line was found, print a message to the user
            if (!found) {
                cout << "No matching flight with the given details was found." << endl;
            }

            // Close the input and output files
            fin.close();
            fout.close();

            // Delete the original input file and rename the temporary output file to the original filename
            remove(LocalFlightTxt.c_str());
            rename(tempFile.c_str(), LocalFlightTxt.c_str());

                
            break;
            }
        default:
            cout<<"Invalid choice. Please try again."<<endl;
            break;
    }
    }while(choice!=1 && choice!=2);


    
}
void AdminAccount::addNewRoute(){
    // add new route
    // change flight schedule
    // booking object created, populated and stored in a file
    string departureCity;
    char nsth='%';
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
                cout<<"Enter the FlightID: ";
                string flightID;
                cin>>flightID;
                int planeChoice;
                string plane;
                do{
                    cout<<"What Airplane will be used for this flight?\n";
                    cout<<"1. PK101\n";
                    cout<<"2. PK102\n";
                    cout<<"3. PK103\n";
                    cout<<"4. PK104\n";
                    cout<<"5. PK105\n";
                    cout<<"6. PK106\n";
                    cout<<"7. PK107\n";
                    cout<<"8. PK108\n";
                    cout<<"9. PK109\n";
                    cout<<"10. PK110\n";
                    cin>>planeChoice;
                    switch(planeChoice){
                        case 1:
                            plane = "PK101";
                            break;
                        case 2:
                            plane = "PK102";
                            break;
                        case 3:
                            plane = "PK103";
                            break;
                        case 4:
                            plane = "PK104";
                            break;
                        case 5:
                            plane = "PK105";
                            break;
                        case 6:
                            plane = "PK106";
                            break;
                        case 7:
                            plane = "PK107";
                            break;
                        case 8:
                            plane = "PK108";
                            break;
                        case 9:
                            plane = "PK109";
                            break;
                        case 10:
                            plane = "PK110";
                            break;
                        default:
                            cout<<"Invalid choice. Please try again.\n";
                            break;
                    }

                }while(planeChoice<1 || planeChoice>10);

                
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
                    fout<<flightID<<"%"<<plane<<"%"<<departureCity<<"%"<<nsth<<"%"<<arrivalCountry<<"%"<<departureDate<<"%"<<departureTime<<"%"<<arrivalDate<<"%"<<arrivalTime<<"%"<<endl;
                }
                else cout<<"File not found.\n";
                fout.close();
                break;
            }
            case 2:{
                // add local flight
                cout<<"Enter the FlightID: ";
                string flightID;
                cin>>flightID;
                int planeChoice;
                string plane;
                do{
                    cout<<"What Airplane will be used for this flight?\n";
                    cout<<"1. PK101\n";
                    cout<<"2. PK102\n";
                    cout<<"3. PK103\n";
                    cout<<"4. PK104\n";
                    cout<<"5. PK105\n";
                    cout<<"6. PK106\n";
                    cout<<"7. PK107\n";
                    cout<<"8. PK108\n";
                    cout<<"9. PK109\n";
                    cout<<"10. PK110\n";
                    cin>>planeChoice;
                    switch(planeChoice){
                        case 1:
                            plane = "PK101";
                            break;
                        case 2:
                            plane = "PK102";
                            break;
                        case 3:
                            plane = "PK103";
                            break;
                        case 4:
                            plane = "PK104";
                            break;
                        case 5:
                            plane = "PK105";
                            break;
                        case 6:
                            plane = "PK106";
                            break;
                        case 7:
                            plane = "PK107";
                            break;
                        case 8:
                            plane = "PK108";
                            break;
                        case 9:
                            plane = "PK109";
                            break;
                        case 10:
                            plane = "PK110";
                            break;
                        default:
                            cout<<"Invalid choice. Please try again.\n";
                            break;
                    }

                }while(planeChoice<1 || planeChoice>10);

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
                char nschar='%';
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
                char nsthto='%';
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
                    fout<<flightID<<"%"<<plane<<"%"<<departureCity<<"%"<<nschar<<"%"<<arrivalCity<<"%"<<nsthto<<"%"<<departureDate<<"%"<<departureTime<<"%"<<arrivalDate<<"%"<<arrivalTime<<"%"<<endl;
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
void AdminAccount::restrictNumberOfPassengers(){
    // restrict number of passengers
    int planeChoice;
    string plane;
    do{
        cout<<"What Airplane will be used for this flight?\n";
        cout<<"1. PK101\n";
        cout<<"2. PK102\n";
        cout<<"3. PK103\n";
        cout<<"4. PK104\n";
        cout<<"5. PK105\n";
        cout<<"6. PK106\n";
        cout<<"7. PK107\n";
        cout<<"8. PK108\n";
        cout<<"9. PK109\n";
        cout<<"10. PK110\n";
        cin>>planeChoice;
        switch(planeChoice){
            case 1:
                plane = "PK101";
                break;
            case 2:
                plane = "PK102";
                break;
            case 3:
                plane = "PK103";
                break;
            case 4:
                plane = "PK104";
                break;
            case 5:
                plane = "PK105";
                break;
            case 6:
                plane = "PK106";
                break;
            case 7:
                plane = "PK107";
                break;
            case 8:
                plane = "PK108";
                break;
            case 9:
                plane = "PK109";
                break;
            case 10:
                plane = "PK110";
                break;
            default:
                cout<<"Invalid choice. Please try again.\n";
                break;
        }
    }while(planeChoice<1 || planeChoice>10);
    cout<<"Maximum amount of Economy seats: ";
    int eco;
    cin>>eco;
    cout<<"Maximum amount of Business seats: ";
    int bus;
    cin>>bus;
    Airplane airplane(plane,eco,bus,++passengers);
}


PassengerAccount::PassengerAccount():Login("",""){}
PassengerAccount::PassengerAccount(string un,string pwd):Login(un,pwd){}
PassengerAccount::PassengerAccount(const PassengerAccount &other):Login(other){}
void PassengerAccount::displayAccountDetails(){
    cout<<"username: "<<username<<endl;
    cout<<"password: "<<string(password.length(), '*')<<endl;
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
string PaymentDetails::getCvv() const {
    return string(cvv.length(), '*');
}
void PaymentDetails::setCvv(string cv){
    cvv = cv;
}

Passenger::Passenger(){
    name = "";
    passportNumber = "";
    cnic = "";
    visaStatus = false;
    login = nullptr;
    paymentDetails = nullptr;
}
Passenger::Passenger(string nm,string pn,string cn,bool vs,PassengerAccount* lg,PaymentDetails* pd){
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
string Passenger::getCnic() const{
    return cnic;
}
void Passenger::setCnic(string cn){
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
    fstream file;
    file.open("mostVisitedCountry.txt",ios::in);
    string line;
    while(getline(file,line)){
        cout<<line<<endl;
    }
    file.close();
    cout<<"You haven't visited enough countries yet.\n";
}
void Passenger::viewTravellingCost(){
    // display travelling cost
    fstream file;
    file.open("travellingCost.txt",ios::in);
    string line;
    while(getline(file,line)){
        cout<<line<<endl;
    }
    file.close();
    cout<<"How many hours do you plan to travel?\n";
    int hours;
    cin>>hours;
    hours = hours * 20000;
    cout<<"Your estimated travelling cost is: "<<hours<<endl;
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
    os << "Login Password: ";
    for (int i = 0; i < p.login->getPassword().length(); i++) {
        os << "*";
    }
    os << endl;

    return os;
}


// booking overloaded poperator
ostream& operator<<(ostream& os, const Booking& booking) {
    os << "Airplane ID: " << booking.airplane->getAirplaneID() << endl;
    os << "Economy Capacity: " << booking.airplane->getCapacityEconomy() << endl;
    os << "Business Class Capacity: " << booking.airplane->getCapacityBusiness() << endl;
    os << "Name: " << booking.getPassenger()->getName() << endl;
    os << "Passport Number: " << booking.getPassenger()->getPassportNumber() << endl;
    os << "CNIC: " << booking.getPassenger()->getCnic() << endl;
    os << "Visa Status: " << (booking.getPassenger()->getVisaStatus() ? "Valid" : "Invalid") << endl;
    os << "Username: "<<booking.getPassenger()->getLogin()->getUsername()<<endl;
    os << "Password: ";
    for (int i = 0; i < booking.getPassenger()->getLogin()->getPassword().length();i++) {
        os << "*";
    }
    os << endl;

    os << "Card Number: "<<booking.getPassenger()->getPaymentDetails()->getCardNumber()<<endl;
    os << "Expiry Date: " << booking.getPassenger()->getPaymentDetails()->getExpiryDate() << endl;
    os << "CVV: " << booking.getPassenger()->getPaymentDetails()->getCvv() << endl;
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
    string cnic;
    bool foundcnic = false;
    do{
        cout<<"Enter your CNIC (13 digits): ";
        cin>>cnic;
          // checks if cnic is already in file
        fstream fin;
        fin.open("/Users/mahamimran/Files/PassengerDetails.txt",ios::in);
        if(!fin){
            cout<<"Error opening file\n";
            return;
        }
        string line;
        while(getline(fin, line)){
            if(line.find(cnic) != string::npos){
                cout << "CNIC already in record. Please try again.\n";
                foundcnic = true;
                break;
            }
        }
        fin.close();
    }while(cnic.length()!=13 && foundcnic);
  
    
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
    // excpetion handling
    string password;
    bool isValidPassword = false;

    while (!isValidPassword) {
        try {
            cout << "Enter your password: ";
            cin >> password;

            cout << "Confirm your password: ";
            string confirmPassword;
            cin >> confirmPassword;

            if (password == confirmPassword
                && password.length() >= 8
                && password.length() <= 16
                && password.find_first_of("0123456789") != string::npos
                && password.find_first_of("!@#$%^&*()_+") != string::npos
                && password.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos
                && password.find_first_of("abcdefghijklmnopqrstuvwxyz") != string::npos) {
                isValidPassword = true;
            } else {
                throw runtime_error("Passwords do not match or do not meet the requirements.");
            }
        } catch (const exception& e) {
            cout << "Exception: " << e.what() << endl;
        }
    }

    cout << "Valid password entered!" << endl;
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
void displayLocalFlights(){
        cout<<"Local flights:\n";
            string flightID, plane, departureCity, arrivalCity, departureDate, departureTime, arrivalDate, arrivalTime;
            char nschar, nsthto;
            string nscharstring, nsthtostring;
            // display local flights
            fstream fin;
            fin.open("/Users/mahamimran/Files/LocalFlightSchedule.txt",ios::in);
            while(fin){
                if(fin.is_open()){
                    getline(fin, flightID, '%');
                    getline(fin, plane, '%');
                    getline(fin, departureCity, '%');
                    getline(fin, nscharstring, '%');
                    getline(fin, arrivalCity, '%'); 
                    getline(fin, nsthtostring, '%');
                    getline(fin, departureDate, '%');
                    getline(fin, departureTime, '%');
                    getline(fin, arrivalDate, '%');
                    getline(fin, arrivalTime, '%');
                    nsthto = nsthtostring[0];
                    nschar = nscharstring[0];
                    cout<<"Flight ID: "<<flightID<<endl;
                    cout<<"Plane: "<<plane<<endl;
                    cout<<"Departure City: "<<departureCity<<endl;
                    cout<<"North/South: "<<nschar<<endl;
                    cout<<"Arrival City: "<<arrivalCity<<endl;
                    cout<<"North/South: "<<nsthto<<endl;
                    cout<<"Departure Date: "<<departureDate<<endl;
                    cout<<"Departure Time: "<<departureTime<<endl;
                    cout<<"Arrival Date: "<<arrivalDate<<endl;
                    cout<<"Arrival Time: "<<arrivalTime<<endl;
                    cout<<endl;
                }
                else cout<<"file not open"<<endl;
            }
            fin.close();
    
            
}
void displayInternationalFlights(){
    // display international flights
            cout<<"International flights:\n";
            string flightID, plane, departureCity, arrivalCountry, departureDate, departureTime, arrivalDate, arrivalTime;
            char nsth;
            string nsthstring;
            // display local flights
            fstream fin;
            fin.open("/Users/mahamimran/Files/InternationalFlightSchedule.txt",ios::in);
            while(fin){
                if(fin.is_open()){
                    getline(fin, flightID, '%');
                    getline(fin, plane, '%');
                    getline(fin, departureCity, '%');
                    getline(fin, nsthstring, '%');
                    getline(fin, arrivalCountry, '%');
                    getline(fin, departureDate, '%');
                    getline(fin, departureTime, '%');
                    getline(fin, arrivalDate, '%');
                    getline(fin, arrivalTime, '%');
                    nsth = nsthstring[0];
                    cout<<"Flight ID: "<<flightID<<endl;
                    cout<<"Plane: "<<plane<<endl;
                    cout<<"Departure City: "<<departureCity<<endl;
                    cout<<"North/South: "<<nsth<<endl;
                    cout<<"Arrival Country: "<<arrivalCountry<<endl;
                    cout<<"Departure Date: "<<departureDate<<endl;
                    cout<<"Departure Time: "<<departureTime<<endl;
                    cout<<"Arrival Date: "<<arrivalDate<<endl;
                    cout<<"Arrival Time: "<<arrivalTime<<endl;
                    cout<<endl;
                }
                else cout<<"file not open"<<endl;
            }
            fin.close();
}
void bookFlight(Passenger passenger){
    int choice;
    do{
        cout<<"Would you like to book a local flight or an international flight?"<<endl;
        cout<<"1. Local flight"<<endl;
        cout<<"2. International flight"<<endl;
        cout<<"3. Exit\n";
        cin >> choice;
        switch(choice){
            case 1:{
                displayLocalFlights();
                cout<<"Enter the Flight ID you would like to book: ";
                string flightID;
                cin >> flightID;
                // check if flight exists
                bool found = false;
                fstream fin;
                fin.open("/Users/mahamimran/Files/LocalFlightSchedule.txt",ios::in);
                string line;
                while(!fin.eof()){
                    getline(fin,line);
                    if(line.find(flightID) != string::npos){
                        found = true;
                        cout<<"Flight found!"<<endl;
                        // book flight
                        break;
                    }
                }
                fin.close();
                string plane, departureCity, nsth, arrivalCity, nsthtostring, departureDate, departureTime, arrivalDate, arrivalTime;
                stringstream ss(line);

                getline(ss, flightID, '%');
                getline(ss, plane, '%');
                getline(ss, departureCity, '%');
                getline(ss, nsth, '%');
                getline(ss, arrivalCity, '%');
                getline(ss, nsthtostring, '%');
                getline(ss, departureDate, '%');
                getline(ss, departureTime, '%');
                getline(ss, arrivalDate, '%');
                getline(ss, arrivalTime, '%');
                cout << "Plane: " << plane << endl;
                cout << "Departure City: " << departureCity << endl;
                cout << "North/South: " << nsth << endl;
                cout << "Arrival City: " << arrivalCity << endl;
                cout << "North/South: " << nsthtostring << endl;
                cout << "Departure Date: " << departureDate << endl;
                cout << "Departure Time: " << departureTime << endl;
                cout << "Arrival Date: " << arrivalDate << endl;
                cout << "Arrival Time: " << arrivalTime << endl;
                
                Airplane airplane(plane,economySeats,businessSeats,++passengers);
                // passenger passed
                City city(departureCity,nsth[0]);
                City city2(arrivalCity,nsthtostring[0]);
                FlightSchedule flightSchedule(departureTime,arrivalTime,departureDate,arrivalDate,0);
                flightSchedule.calculateTicketPrice();
                Country c;
                Booking booking(&airplane,&passenger,&c,&city,&city2,&flightSchedule,1);
                // BOOKING OBJECT CREATED HERE
                break;
            }
            case 2:{
                displayInternationalFlights();
                cout<<"Enter the Flight ID you would like to book: ";
                string flightID;
                cin >> flightID;
                // check if flight exists
                bool found = false;
                fstream fin;
                fin.open("/Users/mahamimran/Files/InternationalFlightSchedule.txt",ios::in);
                string line;
                while(!fin.eof()){
                    getline(fin,line);
                    if(line.find(flightID) != string::npos){
                        found = true;
                        cout<<"Flight found!"<<endl;
                        // book flight
                        break;
                    }   
                }
                fin.close();
                string plane, departureCity, nsth, arrivalCountry, departureDate, departureTime, arrivalDate, arrivalTime;
                stringstream ss(line);
                getline(ss, flightID, '%');
                getline(ss, plane, '%');
                getline(ss, departureCity, '%');
                getline(ss, nsth, '%');
                getline(ss, arrivalCountry, '%');
                getline(ss, departureDate, '%');
                getline(ss, departureTime, '%');
                getline(ss, arrivalDate, '%');
                getline(ss, arrivalTime, '%');
                cout << "Flight ID: " << flightID << endl;
                cout << "Plane: " << plane << endl;
                cout << "Departure City: " << departureCity << endl;
                cout << "North/South: " << nsth << endl;
                cout << "Arrival Country: " << arrivalCountry << endl;
                cout << "Departure Date: " << departureDate << endl;
                cout << "Departure Time: " << departureTime << endl;
                cout << "Arrival Date: " << arrivalDate << endl;
                cout << "Arrival Time: " << arrivalTime << endl;
                
                Airplane airplane(plane,economySeats,businessSeats,++passengers);
                // passenger passed
                City city(departureCity,nsth[0]);
                City c;
                FlightSchedule flightSchedule(departureTime,arrivalTime,departureDate,arrivalDate,0);
                flightSchedule.calculateTicketPrice();
                // calculating distance
                // Convert departure time to minutes
                int departureHours = stoi(departureTime.substr(0, 2));
                int departureMinutes = stoi(departureTime.substr(3, 2));
                int departureTotalMinutes = departureHours * 60 + departureMinutes;
                
                // Convert arrival time to minutes
                int arrivalHours = stoi(arrivalTime.substr(0, 2));
                int arrivalMinutes = stoi(arrivalTime.substr(3, 2));
                int arrivalTotalMinutes = arrivalHours * 60 + arrivalMinutes;

                // Calculate duration in minutes
                double durationMinutes = arrivalTotalMinutes - departureTotalMinutes;
                double durationHours = durationMinutes / 60.0;
                
                
                Country country(arrivalCountry,800*durationHours);
                Booking booking(&airplane,&passenger,&country,&city,&c,&flightSchedule,0);
                // BOOKING OBJECT CREATED HERE
                cout<<"Booking successful!"<<endl;
                cout<<booking;
                break;
            }
            case 3:
                break;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
                break;
        }
        
    }while(choice!=3);
}
void passengerLogin(){
    bool found = false;
    string password;
    string username;
    string name = "";
    // login
    int ent = 0;
    ent++;
    Login *login;
    login = new Login[ent];

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
    login[ent-1].setUsername(username2);
    login[ent-1].setPassword(password2);

    bool visaStatus = (visaStatus2 == "1");
    PaymentDetails paymentDetails(cardNumber, expiryDate, cvv);
    PassengerAccount passengerAccount(username2, password2);
    Passenger passenger(name2, passportNumber, cnic, visaStatus, &passengerAccount, &paymentDetails);
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
                    bookFlight(passenger);
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
    delete [] login;
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
        cout<<"5. Exit\n";
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
                // exit
                cout<<"exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice entered. Please try again.\n";
        }
        }while(choice!=5);
    }
    else{
        adminLogin();
    }

}
void guestLogin(){
    cout<<"As a guest you can only view flight details\n";
    // open file and read all details
    int choice;
    do{
    cout<<"Which flights would you like to know the details of?\n";
    cout<<"1. Local\n";
    cout<<"2. International\n";
    cout<<"3. Exit\n";
    cin>>choice;
    switch(choice){
        case 1:{
            displayLocalFlights();
            break;
        }
        case 2:{
            displayInternationalFlights();
            break;
        }
        case 3:
            // exit
            cout<<"exiting..."<<endl;
            break;
        default:
            cout<<"Invalid choice entered. Please try again.\n";
    }
}while(choice!=3);
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
                    case 2:{
                        // register OR guest login
                        int choice;
                        do{
                            cout<<"Would you like to register or sign in as guest?\n";
                            cout<<"1. Register\n";
                            cout<<"2. Guest\n";
                            cout<<"3. Exit\n";
                            cin>>choice;
                            switch(choice){
                                case 1:
                                    // register
                                    passengerRegistration();
                                    break;
                                case 2:
                                    // guest
                                    guestLogin();
                                    break;
                                case 3:
                                    // exit
                                    cout<<"exiting...\n";
                                    break;
                                default:
                                    cout<<"Invalid choice\n";
                                    break;
                            }
                        }while(choice!=3);
                        break;
                    }
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
