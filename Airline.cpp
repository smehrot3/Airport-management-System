
#include <iostream>			//Imports the packages used in this part of program
#include "Passenger.h"
#include "Flight.h"
#include <list>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>

using namespace std;

list<Passenger> passengers;	//List flights and passengers which act as memory
list<Flight> flights;
list<Passenger>::iterator i;//Iterators for the two lists.
list<Flight>::iterator j;


//Base Class
 class SetData{
protected:         //Private Members
    string password;
    string username;

public:          //Public members
 void setPass(string p){
        password = p;
}
 void setUserName( string s){
        username = s;
        }
};

//Derived Class
class GetData: public SetData{

public:
string getPass(){
return password;
}

string getUserName(){
return username;
}
};


bool flightExist(string flightNo)		//These method will be used to query our lists to see if a certain flight or passenger is contained in them.
{
	for(j = flights.begin();j != flights.end(); j++)
	{
		Flight tmp = *j;
		if(flightNo.compare(tmp.flightNo)==0)
			return true;
	}
	return false;
}
bool passengerExist(string passNo)
{
	for(i = passengers.begin();i != passengers.end(); i++)
	{
		Passenger tmp = *i;
		if(passNo.compare(tmp.passengerNo)==0)
			return true;
	}
	return false;
}


int main()		//main method
{
    system("color 2f");
    GetData g;
    beginning:

    string mainStuff;
    string password1;
    string password;
    string username;
    string oneortwo;
    string passLogin;
    string userName1;


    cout <<"         "<<"================================================="<< endl;
    cout <<"                "<< "Welcome to The Kenya Airways Login/Sign up Page." <<endl;
    cout <<"                "<< "                         " << endl;
    cout <<"                "<< "                         " << endl;
    cout <<"                "<< "Press 1 to Sign Up for a new account." << endl;
    cout <<"                "<< "Press 2 to Log In to an existing account." << endl;

    cout <<"         "<<"================================================="<< endl;
    cin >> oneortwo;

    if (oneortwo == "1") {


    cout <<"                "<< "Please Input your desired usermame "<< "*** atleast 6 characters long recomended***" << endl;
    cin >> userName1;
    g.setUserName(userName1);

    cout <<"                "<< "Please Input your desired Password "<< "*** atleast 8 characters long recomended***" << endl;
    cin >>  password1 ;
    g.setPass(password1);

    cout <<"                "<< "Thank you for signing up to the Kenya Airways System: " << g.getUserName() << endl;
    cout <<"                "<< "You'll now be redirected to the log in page" << endl;
    cout <<"                "<< "use the newly created user name and password to log in" << endl;
    system("pause");
    system("CLS");
    goto passLogin;

    }

    else if (oneortwo == "2"){
system("CLS");
goto passLogin;
    }

    else {
    cout << " please input a viable option" << endl;
    system("pause");
    system("CLS");
    goto beginning;
    }


passLogin:

    cout <<"         "<<"================================================="<< endl;
    cout <<"                "<< "Welcome to The Kenya Airways Login Page." <<endl;
    cout <<"                "<< "                         " << endl;
    cout <<"                "<< "                         " << endl;
    cout <<"                "<< "Please Enter your Username: " << endl;
    cin >> username;
    cout <<"                "<< "Please Enter your PassWord: " << endl;
    cin >> password;

    if (username == "AdminMash" && password == "Administrator1" )
{

        system("CLS");
        cout <<"                "<< "Thank you for logging in into the Kenya Airways Admin Panel: " << username << endl;
        cout <<"                "<< "You'll now be redirected to the Flight Management page" << endl;
        system("pause");
        system("CLS");
        goto mainStuff;
    }

else if (username == g.getUserName() && password == g.getPass())
{
        system("CLS");
        cout <<"                "<< "Thank you for logging in into the Kenya Airways Common User Panel: " << username << endl;
        cout <<"                "<< "You'll now be redirected to the Flight Management page" << endl;
        system("pause");
        system("CLS");
        goto SubStuff;
    }


    else {

        cout <<"                                                                " << endl;
        cout <<"                "<< " 404 ERROR!  " << endl;
        cout <<"                                                                " << endl;
        cout <<"                "<< " You Entered Invalid Logging Credentials;  " << endl;
        cout <<"                                                                " << endl;
        cout <<"                "<< "You'll be redirected Back to the Login in/sign up page" << endl;
        cout <<"                                                                " << endl;
        cout <<"                "<< "Try login in with a valid account or sign up if you don't have one" << endl;
        cout <<"                                                                " << endl;

        system("PAUSE");
        system("CLS");
        goto beginning;

    }

    exit:

    return 0;





mainStuff:
	int response;	//this will be used for making selections from menu
	while(response!=0)
	{
		string passNum;		//used for holding passenger and Flight numbers
		string flightNum;
        cout <<"         "<<"================================================="<< endl;
        cout <<"                "<< "Welcome to The Kenya Airways Admin Panel: AdminMash" <<endl;
        cout <<"                "<< "                         " << endl;
        cout <<"                "<< "                         " << endl;
		cout <<"                "<<"================================================="<<endl;
		cout <<"                "<< "Select your numbered choice from the Main Menu below:" << endl;
		cout <<"                "<< "1 to create a new Flight." << endl;						//very simple GUI
		cout <<"                "<< "2 to cancel an existing Flight." << endl;
		cout <<"                "<< "3 to see details of a Flight" << endl;
		cout <<"                "<< "4 to input information of a new Passenger." << endl;
		cout <<"                "<< "5 to book a Passenger onto a Flight." << endl;
		cout <<"                "<< "6 to show all Reservations for a passenger." << endl;
		cout <<"                "<< "7 to cancel a Passenger's Reservation." << endl;
		cout <<"                "<< "0 to exit." << endl;
		cout <<"                "<<"================================================="<< endl;

		cin >> response;
		switch(response)
		{
			case 1:{		//calls our create flight method from Flight class and stores the new flight in list
				Flight f;
				f.createFlight();
				flights.push_back(f);


				goto mainStuff;
				break;}

			case 2:{
				cout <<"                "<<"Enter Flight Number in the format (AB123) "<< "ie. three characters followed by three numbers: "<< endl;	//used to cancel a flight by removing it from our list.
				cin >> flightNum;
				if(flightExist(flightNum))
				{
					j = flights.erase(j);
					cout <<"                "<< "Flight " << flightNum <<" has been succesfully removed."<<endl;
				}
				else
					cout <<"     ERROR!           "<< "Flight " << flightNum <<" not found."<<endl;
				break;}

				caser:
			case 3:{
				cout <<"                "<<"Enter Flight Number in the format (AB123) "<< "ie. three characters followed by three numbers: "<< endl;		//Used for looking up flight details given a flight number.
				cin >> flightNum;
				if(flightExist(flightNum))
				{
					Flight tmp = *j;
					tmp.showFlight();
					goto mainStuff;
				}
				else {
					cout <<"     ERROR!           "<< "Flight " << flightNum <<" doesn't exist in our system."<<endl;
					cout <<"                      "<< "press the Enter key to go back and review the details" << endl;

					system("Pause");
					system("CLS");
					goto mainStuff;
				break;} }

			case 4:{
				Passenger p;	//takes information for a new passenger and saves it to list
				p.getInfo();
				passengers.push_back(p);
				break;}

				booker:
			case 5:{
				cout <<"                "<<"Enter Passenger Number in the format (A123) "<< "ie. three characters followed by three numbers: "<< endl;	//this is used to book a passenger onto a flight
				cin >> passNum;
				cout <<"                "<<"Enter Flight Number in the format (AB123) "<< "ie. three characters followed by three numbers: "<< endl;
				cin >> flightNum;
				if(passengerExist(passNum))	//check if passenger exits
				{
					if(flightExist(flightNum))		//check if flight exists
					{
						Passenger p = *i;
						Flight f = *j;
						if(f.longHaul&&f.seatsLeft>0)	//adds passenger to flight if requirments are met
						{
							p.makeReservation(flightNum,f.longHaul,f.basePrice);
							f.seatsLeft--;//adjust variables
							*i =p;	//updates lists
							*j=f;
						}
						else if(f.seatsLeft>0)	//used for shorthaul flights
						{
							p.makeReservation(flightNum,f.longHaul,f.basePrice);
							f.seatsLeft--;
							*i =p;
							*j=f;
						}
						else
							cout <<"     Sorry,       "<< "The Flight You Are Attempting to book is Full"<<endl;	//error messages
							cout <<"                      "<< "press the Enter key to Book a different plane" << endl;
					}
					else
						cout <<"      ERROR!          "<< "Flight " << flightNum <<" not found."<<endl;
						cout <<"                      "<< "press the Enter key to Book a different plane" << endl;

						system("pause");
						system("CLS");
						goto booker;
				}
				else
					cout<<"   Sorry,            "<<"Passenger not found"<<endl;
					cout <<"                      "<< "press the Enter key to Book the passenger afresh" << endl;

                        system("pause");
                        system("CLS");
						goto mainStuff;
				break;}

			case 6:{
				cout <<"                "<<"Enter Passenger Number in the format (A123) "<< "ie. three characters followed by three numbers: "<< endl;	//checks to see what flights a passenger is booked onto
				cin >> passNum;
				if(passengerExist(passNum))
				{
					Passenger p = *i;
					p.printInfo();
				}
				else

                    cout<<"   Sorry,            "<<"Passenger not found"<<endl;
					cout <<"                      "<< "press the Enter key to Book the passenger afresh" << endl;

                        system("pause");
                        system("CLS");
						goto mainStuff;
				break;}

			case 7:{
				cout <<"                "<<"Enter Passenger Number in the format (A123) "<< "ie. three characters followed by three numbers: "<< endl;		//used for removing a passenger from a flight
				cin >> passNum;
				cout <<"                "<<"Enter Flight Number in the format (AB123) "<< "ie. three characters followed by three numbers: "<< endl;
				cin >> flightNum;
				if(passengerExist(passNum))
				{
					if(flightExist(flightNum))
					{
						Passenger p = *i;
						Flight f = *j;
						p.cancelReservation(flightNum);
						f.seatsLeft++;		//increments seats available
					}
					else
						cout <<"                "<< "Flight " << flightNum <<" not found. Flight may have been cancelled!"<<endl;
				}
				else
                    cout<<"   Sorry,            "<<"Passenger not found"<<endl;
					cout <<"                      "<< "press the Enter key to Book the passenger afresh" << endl;

                        system("pause");
                        system("CLS");
						goto mainStuff;
				break;}

							case 0:{
							    system("CLS");
            cout <<"                "<< "***" << "Thank you for using our system: " << g.getUserName() << "***"<< endl;
            cout <<"                "<< "***" << "Have yourself a fabulous Day " << "***"<< endl;
            cout <<"                "<<"                                                                     "<< endl;
            cout <<"                "<<"                                                                     "<< endl;
            cout <<"                "<<"                                                                     "<< endl;
            cout <<"                "<<"                                                                     "<< endl;
            cout <<"                "<<"                                                                     "<< endl;
            cout <<"                "<<"                                                                     "<< endl;
            cout <<"                "<<"                                                                     "<< endl;
            cout <<"                "<<"                                                                     "<< endl;
            cout <<"                "<<" ALL RIGHTS RESERVED (c) Muguku inc. "<< endl;

				break;}
}
		}

SubStuff:

	int responsy;	//this will be used for making selections from menu
	while(responsy!=0)
	{
		string passNum;		//used for holding passenger and Flight numbers
		string flightNum;
        cout <<"         "<<"================================================="<< endl;
        cout <<"                "<< "The Kenya Airways Common User Panel: " << "***Current User: " << g.getUserName() << "***"<< endl;
        cout <<"                "<< "                         " << endl;
        cout <<"                "<< "                         " << endl;
		cout <<"                "<<"================================================="<<endl;
		cout <<"                "<< "Select your numbered choice from the Main Menu below:" << endl;
		cout <<"                "<< "1 to see details of a Flight" << endl;
		cout <<"                "<< "2 to Update your Passenger Information." << endl;
		cout <<"                "<< "3 to book a Flight." << endl;
		cout <<"                "<< "4 to show all your Reservations." << endl;
		cout <<"                "<< "5 to cancel Your Reservation(s)." << endl;
		cout <<"                "<< "0 to exit." << endl;
		cout <<"                "<<"================================================="<< endl;

		cin >> responsy;
		switch(responsy)
		{

			caser2:
			case 1:{
				cout <<"                "<<"Enter Flight Number in the format (AB123) "<< "ie. three characters followed by three numbers: "<< endl;		//Used for looking up flight details given a flight number.
				cin >> flightNum;
				if(flightExist(flightNum))
				{
					Flight tmp = *j;
					tmp.showFlight();


                    system("Pause");
					system("CLS");
					goto SubStuff;
				}
				else
					cout <<"     ERROR!           "<< "Flight " << flightNum <<" doesn't exist in our system."<<endl;
					cout <<"                      "<< "press the Enter key to go back and review the details" << endl;

					system("Pause");
					system("CLS");
					goto caser2;

				break;}
			case 2:{
				Passenger p;	//takes information for a new passenger and saves it to list
				p.getInfo();
				passengers.push_back(p);
				break;}

				booker2:
			case 3:{
				cout <<"                "<<"Enter Passenger Number in the format (A123) "<< "ie. three characters followed by three numbers: "<< endl;	//this is used to book a passenger onto a flight
				cin >> passNum;
				cout <<"                "<<"Enter Flight Number in the format (AB123) "<< "ie. three characters followed by three numbers: "<< endl;
				cin >> flightNum;
				if(passengerExist(passNum))	//check if passenger exits
				{
					if(flightExist(flightNum))		//check if flight exists
					{
						Passenger p = *i;
						Flight f = *j;
						if(f.longHaul&&f.seatsLeft>0)	//adds passenger to flight if requirments are met
						{
							p.makeReservation(flightNum,f.longHaul,f.basePrice);
							f.seatsLeft--;//adjust variables
							*i =p;	//updates lists
							*j=f;
						}
						else if(f.seatsLeft>0)	//used for shorthaul flights
						{
							p.makeReservation(flightNum,f.longHaul,f.basePrice);
							f.seatsLeft--;
							*i =p;
							*j=f;
						}
						else
							cout <<"     Sorry,       "<< "The Flight You Are Attempting to book is Full"<<endl;	//error messages
							cout <<"                      "<< "press the Enter key to Book a different plane" << endl;
					}
					else
						cout <<"      ERROR!          "<< "Flight " << flightNum <<" not found."<<endl;
						cout <<"                      "<< "press the Enter key to Book a different plane" << endl;

						system("pause");
						system("CLS");
						goto booker2;
				}
				else
					cout<<"   Sorry,            "<<"Passenger not found"<<endl;
					cout <<"                      "<< "press the Enter key to Book the passenger afresh" << endl;

                        system("pause");
                        system("CLS");
						goto mainStuff;
				break;}

			case 4:{
				cout <<"                "<<"Enter Passenger Number in the format (A123) "<< "ie. three characters followed by three numbers: "<< endl;	//checks to see what flights a passenger is booked onto
				cin >> passNum;
				if(passengerExist(passNum))
				{
					Passenger p = *i;
					p.printInfo();
				}
				else

                    cout<<"   Sorry,            "<<"Passenger not found"<<endl;
					cout <<"                      "<< "press the Enter key to Book the passenger afresh" << endl;

                        system("pause");
                        system("CLS");
						goto SubStuff;
				break;}

			case 5:{
				cout <<"                "<<"Enter Passenger Number in the format (A123) "<< "ie. three characters followed by three numbers: "<< endl;		//used for removing a passenger from a flight
				cin >> passNum;
				cout <<"                "<<"Enter Flight Number in the format (AB123) "<< "ie. three characters followed by three numbers: "<< endl;
				cin >> flightNum;
				if(passengerExist(passNum))
				{
					if(flightExist(flightNum))
					{
						Passenger p = *i;
						Flight f = *j;
						p.cancelReservation(flightNum);
						f.seatsLeft++;		//increments seats available
					}
					else
						cout <<"                "<< "Flight " << flightNum <<" not found. Flight may have been cancelled!"<<endl;
				}
				else
                    cout<<"   Sorry,            "<<"Passenger not found"<<endl;
					cout <<"                      "<< "press the Enter key to Book the passenger afresh" << endl;

                        system("pause");
                        system("CLS");
						goto SubStuff;
				break;}

							case 0:{

							    system("CLS");
            cout <<"                "<< "***" << "Thank you for using our system: " << g.getUserName() << "***"<< endl;
            cout <<"                "<< "***" << "Have yourself a fabulous Day " << "***"<< endl;
            cout <<"                "<<"                                                                     "<< endl;
            cout <<"                "<<"                                                                     "<< endl;
            cout <<"                "<<"                                                                     "<< endl;
            cout <<"                "<<"                                                                     "<< endl;
            cout <<"                "<<"                                                                     "<< endl;
            cout <<"                "<<"                                                                     "<< endl;
            cout <<"                "<<"                                                                     "<< endl;
            cout <<"                "<<"                                                                     "<< endl;
            cout <<"                "<<" ALL RIGHTS RESERVED (c) Muguku inc. "<< endl;

				break;}
}
		}

return 0;
	}


