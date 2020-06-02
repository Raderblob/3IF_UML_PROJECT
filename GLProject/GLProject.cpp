// GLProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "AirQualityManager.h"
#include "Util.h"
#include "PrivateIndividual.h"
using namespace std;

void InterfaceLogin();
void InterfaceIdividual();
void InterfaceCompany();
void InterfaceGovernment();


AirQualityManager manager;
void test(){
    AirQualityManager aManager;
    aManager.loadEverything();
    aManager.print();
    cout << "Testing air quality in different zones" << endl;
    Util::startTimer();
    cout << "data::Coordinate(47, 1), 1" << endl;
    cout << aManager.getMeanAirQuality(data::Coordinate(47, 1), 1) << endl;
    cout << "data::Coordinate(47.6, 5.3), 1" << endl;
    cout << aManager.getMeanAirQuality(data::Coordinate(47.6, 5.3), 1) << endl;
    cout << "data::Coordinate(45.3333, 1.3333), 1" << endl;
    cout << aManager.getMeanAirQuality(data::Coordinate(45.3333, 1.3333), 1) << endl;
    cout << "data::Coordinate(45.333, 1.3333), 1,""2019 - 02 - 01 12:00 : 00"",""2019 - 03 - 01 00 : 00 : 00""" << endl;
    cout << aManager.getMeanAirQualityWithDate(data::Coordinate(45.333, 1.3333), 1,"2019-02-01 12:00:00","2019-03-01 00:00:00") << endl;
    cout << "data::Coordinate(46.666, 3.6666), 1" << endl;
    cout << aManager.getMeanAirQuality(data::Coordinate(46.666, 3.6666), 1) << endl;
    cout << "data::Coordinate(46.666, 3.6666), 1,""2019 - 02 - 01 12:00 : 00"",""2019 - 03 - 01 00 : 00 : 00""" << endl;
    cout << aManager.getMeanAirQualityWithDate(data::Coordinate(46.666, 3.6666), 1,"2019-02-01 12:00:00","2019-03-01 00:00:00") << endl;
    Util::stopTimer("getMeanAirQualityWithDate and getMeanAirQuality * 6");

    cout << "AirCleaner zone of effect" << endl;
    
    auto cleaners = aManager.getCleaners();
    for (auto cleaner : cleaners) {
        Util::startTimer();
        cout << cleaner.first << endl;
        cout << "ratio limit step = 0.01" << endl;
        cout << aManager.getAreaOfEffectOfCleaner(*cleaner.second,0.01,true,2) << endl;;
        Util::stopTimer("getAreaOfEffectOfCleaner");

        Util::startTimer();
        cout << cleaner.first << endl;
        cout << "max limit step = 0.01" << endl;
        cout << aManager.getAreaOfEffectOfCleaner(*cleaner.second,0.01, false, 1) << endl;
        Util::stopTimer("getAreaOfEffectOfCleaner");
    }
    
    cout << "tests finished" << endl;
}

int main()
{

    test();

    manager.loadEverything();

    InterfaceLogin();
}

void InterfaceLogin()
{
    int choice = 0;
    int finished = 0;
    int nb_choice = 3;

    while (!finished)
    {
        cout << "\n***Login as :*** " << endl;
        cout << "1 : individual " << endl;
        cout << "2 : staff in a company " << endl;
        cout << "3 : staff in a goverment" << endl;
        cout << "0 : exit" << endl;
        cout << "Choose a number please:";
        cin >> choice;

        for (int i = 0; i < nb_choice + 1; i++)
        {
            if (choice == i)
            {
                finished = 1;
                break;
            }
        }
        if (!finished)
        {
            cout << "\nplease enter a correct number " << endl;
        }
    }
    /*
   // UserManager* manager = new UserManager();
    string email;
    string password;
    cout << "Please input your email: ";
    cin >> email;
    cout << "\nPlease input your password: ";
    cin >> password;
    cout << endl;
   // const users::User* user = manager->tryLogin(email, password);
    */
    switch (choice)
    {
    case 1:
    {
        cout << "Login as an individual" << endl;
      //  if (user!=nullptr)
          InterfaceIdividual();
        break;
    }
    case 2:
    {
        cout << "Login as a staff in a company" << endl;
      //  if (user!=nullptr)
          InterfaceCompany();
        break;
    }

    case 3:
    {
        cout << "Login as a staff in a government" << endl;
       // if (user!=nullptr)
          InterfaceGovernment();
        break;
    }
    case 0:
    {
        cout << "See you next time!" << endl;
        break;
    }
    }
}


void InterfaceIdividual()
{
    
    int choice = 0;
    int finished = 0;
    int nb_choice = 2;

    while (!finished)
    {
        cout << "\n***What do you want to do:*** " << endl;
        cout << "1 : send information " << endl;
        cout << "2 : show user current score " << endl;
        cout << "0 : Logout" << endl;
        cout << "Choose a number please:";
        cin >> choice;

        for (int i = 0; i < nb_choice + 1; i++)
        {
            if (choice == i)
            {
                finished = 1;
                break;
            }
        }

        if (finished == 0)
        {
            cout << "\nplease entre a correct number " << endl;
        }
    }
    
   // data::Coordinate* location = new data::Coordinate (12345, 54321);
   // data::Sensor* mySensor = new data::Sensor(123, 0, true, location, "My phone sensor");
    //users::PrivateIndividual individual = new users::PrivateIndividual(*mySensor, user.fName,user.lName, user.mail, user.passw, user.pNumber);

    switch (choice)
    {
    case 1:
    {
      //data::Reading* reading = new data::Reading("N02", 12);
     // data::AirQualityData* data = new data::AirQualityData(1327, &mySensor, &reading);
     // individual.sensor.addData(&data);
      break;
    }
    case 2:
    {
        //showScore();
        break;
    }
    case 0:
    {
        cout << "See you next time!" << endl;
       // int exit = manager.tryLogout(user);
        break;
    }
    }
    
}

void InterfaceCompany()
{
    
    int choice = 0;
    int finished = 0;
    int nb_choice = 3;
    
   // AirQualityManager* myManager = new AirQualityManager();
   // Coordiante location = new Coordinate(12345, 12345);
   // CompanyEmployee companyEmp = new CompanyEmployee(1234,"CompanyA", myManager.getMeanAirQuality(location), &myManager, user.fName,user.lName, user.mail, user.passw, user.pNumber);

    while (!finished)
    {
        cout << "\n***What do you want to do:*** " << endl;
        cout << "1 : Request data about local area" << endl;
        cout << "2 : Analyse the impact of air cleaners on a precise area before and after a date" << endl;
        cout << "3 : Choose the air cleaner you want to see the impact of" << endl;
        cout << "0 : Logout" << endl;
        cout << "Choose a number please:";
        cin >> choice;

        for (int i = 0; i < nb_choice + 1; i++)
        {
            if (choice == i)
            {
                finished = 1;
                break;
            }
        }

        if (finished == 0)
        {
            cout << "\nplease entre a correct number" << endl;
        }
    }

    switch (choice)
    {
      case 1:
      {
        double latitude;
        double longitude;
        int radius;
        cout << "Latitude: ";
        cin >> latitude;
        cout << "\nLongitude: ";
        cin >> longitude;
        cout << "\n Radius: ";
        cin >> radius;
        data::Coordinate area =  data::Coordinate(latitude, longitude);
        cout << "\n Last month's air quality for the area centered in: "<< endl;
        cout << " The latitude: " << latitude << endl ;
        cout << " The longitude: " << longitude << endl ;
        double quality = manager.getMeanAirQuality(area, radius);
        cout << " is: " << quality   << endl ;
        break;
      }
      case 2:
      {
        double latitude;
        double longitude;
        int radius;
        string date;
        string date2;

        cout << "Latitude: ";
        cin >> latitude;
        cout << "\nLongitude: ";
        cin >> longitude;
        cout << "\n Radius: ";
        cin >> radius;
        cout << " Input the date following the format : 2019-01-01 " <<endl;
        cin >> date;
        date+=" 12:00:00";

        data::Coordinate area =  data::Coordinate(latitude, longitude);
        cout << "\n Two month ago, the air quality for the area centered in: "<< endl;
        cout << " The latitude: " << latitude << endl ;
        cout << " The longitude: " << longitude << endl ;
        cout << "was: "<< endl;
        double quality1 = manager.getMeanAirQualityWithDate(area, radius,"2019-01-01 12:00:00",date);
        cout << quality1 << endl;
        double quality2 =manager.getMeanAirQualityWithDate(area, radius,date,"2019-12-31 12:00:00");
        cout << "\nAfter using our cleaners, the air quality is now: "<< quality2 << endl;

        break;
      }
      case 3:
      {
        Util::startTimer();
        auto cleaners = manager.getCleaners();
        cout << "List of air cleaners : " << endl;
        for (auto cleaner : cleaners) {
            
            cout << cleaner.first << endl;
        }
        Util::stopTimer("TimeToReturnTheListOfCleaners");
        cout << "Which one do you want to witness the impact ? "<< endl;
        int nbC;
        cin >>nbC;
        Util::startTimer();
        AirCleaner* cleanerChosen = cleaners.find(nbC)->second;
        string date;
        cout << " Input the date following the format : 2019-01-01 " <<endl;
        cin >> date;
        date+=" 12:00:00";
        cout << "\n The air quality in the area of this cleaner has gone from : "<< endl;
        double quality1 = manager.getMeanAirQualityWithDate(cleanerChosen->getPosition(), manager.getAreaOfEffectOfCleaner(*cleanerChosen->second,0.01,true,2),"2019-01-01 12:00:00",date);
        cout << quality1 << endl;
        double quality2 =manager.getMeanAirQualityWithDate(cleanerChosen->getPosition(), manager.getAreaOfEffectOfCleaner(*cleanerChosen->second,0.01,true,2),date,"2019-12-31 12:00:00");
        cout << "\nAfter using our cleaners, the air quality "<< quality2 << endl;
        cout << " is: " << quality2   << endl ;
        Util::stopTimer("TimeToShowTheDifferenceInAirQuality");
        break;
      }
      case 0:
      {
          cout << "See you next time!" << endl;
        //  int exit = manager.tryLogout(user);
          break;
      }
    }
    
}

void InterfaceGovernment()
{
    
    int choice = 0;
    int finished = 0;
    int nb_choice = 4;
    
    //AirQualityManager* myManager = new AirQualityManager();
    //GovEmployee govEmp = new GovEmployee(1234567, &myManager, user.fName, user.lName, user.mail, user.passw, user.pNumber);

    while (!finished)
    {
        cout << "\n***What you want to do:*** " << endl;
        cout << "1 : View stored information " << endl;
        cout << "2 : Parse database with certain parameters " << endl;
        cout << "3 : Manage individual points " << endl;
        cout << "4 : Reply to company " << endl;
        cout << "0 : Logout" << endl;
        cout << "Choose a number please:";
        cin >> choice;

        for (int i = 0; i < nb_choice + 1; i++)
        {
            if (choice == i)
            {
                finished = 1;
                break;
            }
        }

        if (finished == 0)
        {
            cout << "\nplease entre a number correct" << endl;
        }
    }

    switch (choice)
    {
    case 1:
    {
        manager.print();
        break;
    }
    case 2:
    {
       // manager.saveEverything();
        break;
    }
    case 3:
    {
        //
        break;
    }
    case 4:
    {
        //
        break;
    }
    case 0:
    {
        cout << "See you next time!" << endl;
       // int exit = manager.tryLogout(user);
        break;
    }
  }
  

}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
