// GLProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include "AirQualityManager.h"
//#include "Util.h"
/*
void test(){
    AirQualityManager airManager;
   // airManager.userManager.addUser(new users::User("bob","Stand","splat@free","13","123"));
    airManager.userManager.showContents();
    airManager.userManager.saveUsers();
}
*/
using namespace std;

void InterfaceLogin();
void InterfaceIdividual();
void InterfaceCompany();
void InterfaceGovernment();

void test(){
    AirQualityManager aManager;
    aManager.loadEverything();
    aManager.print();//only prints half
}

int main()
{
    test();
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
            cout << "\nplease entre a number correct" << endl;
        }
    }

    switch (choice)
    {
    case 1:
    {
        cout << "Login as an individual" << endl;
        InterfaceIdividual();
        break;
    }
    case 2:
    {
        cout << "Login as a staff in a company" << endl;
        InterfaceCompany();
        break;
    }

    case 3:
    {
        cout << "Login as a staff in a government" << endl;
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
        cout << "\n***What you want to do:*** " << endl;
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
            cout << "\nplease entre a number correct" << endl;
        }
    }

    switch (choice)
    {
    case 1:
    {
        //showScore();
        break;
    }
    case 2:
    {
        //sendInfo();
        break;
    }
    case 0:
    {
        cout << "See you next time!" << endl;
        break;
    }
    }
}

void InterfaceCompany()
{
    int choice = 0;
    int finished = 0;
    int nb_choice = 2;

    while (!finished)
    {
        cout << "\n***What you want to do:*** " << endl;
        cout << "1 : Request data about local area " << endl;
        cout << "2 : Access and parse the data " << endl;
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
        //requestdata();
        break;
    }
    case 2:
    {
        //accessData();
        break;
    }
    case 0:
    {
        cout << "See you next time!" << endl;
        break;
    }
    }
}

void InterfaceGovernment()
{
    int choice = 0;
    int finished = 0;
    int nb_choice = 4;

    while (!finished)
    {
        cout << "\n***What you want to do:*** " << endl;
        cout << "1 : Receive the information collected " << endl;
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
        //
        break;
    }
    case 2:
    {
        //
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
