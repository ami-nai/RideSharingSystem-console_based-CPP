#include "Header.h"
#include <bits/stdc++.h>
using namespace std;


Users::Users()
{
    //ctor
}

Users::~Users()
{
    //dtor
}

void Users::passengerSetter(){
    string lastName;
    fstream fout;
    fout.open("USER.txt", ios::app);
    //fout>>lastId;
    cout<<"Enter first name: ";
    cin>>passengerName;
    cout<<"Enter last name: ";
    cin>>lastName;
    passengerName += " " + lastName;
    cout<<"Enter username: ";
    cin>>passengerUsername;
    cout<<"Enter password: ";
    cin>>passengerPassword;
    cout<<"Enter mobile: ";
    cin>>passengerMobile;
    fout<<passengerName<<" "<<passengerUsername<<" "<<passengerPassword<<" "<<passengerMobile<<endl;
    fout.close();
}

void Users::passengerGetter(){
    string firstName, lastName, username, password, mobile;
    cout<<"Enter username & password: ";
    cin>>passengerUsername>>passengerPassword;
    fstream fin;
    fin.open("USER.txt", ios::in);
    bool flag = true;
    while(fin>>firstName>>lastName>>username>>password>>mobile){
        if(username == passengerUsername && password == passengerPassword){
            passengerName = firstName + " " + lastName;
            passengerMobile = mobile;
            cout<<"Log in successful."<<endl;
            flag = true;
            fin.close();
            userProfile();
            break;
        }
        else flag = false;

    }
    fin.close();

    if(flag == false){
        cout<<endl<<"Wrong username and  password"<<endl;
    }

}

void Users::userProfile(){

    while(true){
        int choice;
        cout << "User Portal:" << endl;
        cout << "Menu:" << endl;
        cout << "1. Book a ride          2. See map" << endl;
        cout << "3. Delete account       4. See Profile" << endl;
        cout << "5. Exit" << endl<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        int location, destination;
        switch (choice)
            {
            case 1:
                system("CLS");
                ctgMap();
                cout<<"1.Bakalia    2.Chawkbzr   3.Kotwali   4.Bdrhaat     5.New Mrkt   6.Muradpur    7.2No Gate   8.GEC\n";
                cout<<"9.Lalkhan    10.TigrPass  11.Dewanhat 12.Agrabad    13.Brk Build 14.Fzdarhat   15.City Gate 16.AK Khan\n";
                cout<<"17.Olongkar  18.Noyabzr   19.Boropol"<<endl<<endl;

                cout<<"Enter location and destination. Example: 4 16\n\n";
                cin>>location>>destination;
                cout<<endl<<endl;
                dijkstra(location, destination);
                requestARide();
                break;
            case 2:
                system("CLS");
                ctgMap();
                break;
            case 3:
                system("CLS");
                deleteUserAccount();
                return;
                break;
            case 4:
                system("CLS");
                seeUserProfile();
                break;
            case 5:
                cout << "tataa!!! Exiting the program." << endl;
                return;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
            }
    }
}

void Users::requestARide() {
    cout << "Do you want to request for a ride?";
    cout << "1. Yes    0. No" << endl;
    int choice;
    cin >> choice;

    if (choice == 1) {
        fstream fin;
        fin.open("RIDER.txt", ios::in);

        // Define a linked list node for riders
        struct RiderNode {
            string first, second, third, fourth, fifth, sixth, seventh;
            RiderNode* next;
        };

        // Initialize the linked list
        RiderNode* start = nullptr;
        RiderNode* ptr = nullptr;

        bool foundRider = false;

        string first, second, third, fourth, fifth, sixth, seventh;  // Move the declarations here

        while (fin >> first >> second >> third >> fourth >> fifth >> sixth >> seventh) {
            if (sixth == "ON" && seventh == "notRequested" && foundRider == false) {
                foundRider = true;
                cout << "Request sent to:" << endl;
                cout << "Name: " << first << " " << second << endl;
                cout << "Mobile: " << fifth << endl;

                // Update the rider's status in memory
                seventh = "Requested";
            }

            // Create a new node for each rider
            RiderNode* newNode = new RiderNode{first, second, third, fourth, fifth, sixth, seventh};
            newNode->next = nullptr;

            // Add the node to the linked list
            if (start == nullptr) {
                start = newNode;
                ptr = start;
            } else {
                ptr->next = newNode;
                ptr = newNode;
            }
        }
        fin.close();

        if (!foundRider) {
            cout << "There is no rider free." << endl << endl;

            // Free the allocated memory for the linked list
            RiderNode* current = start;
            while (current != nullptr) {
                RiderNode* nextNode = current->next;
                delete current;
                current = nextNode;
            }

            return;
        }

        // Write the updated rider information back to the file
        fstream fout;
        fout.open("RIDER.txt", ios::out);

        // Traverse the linked list and write to the file
        RiderNode* current = start;
        while (current != nullptr) {
            fout << current->first << " " << current->second << " " << current->third << " "
                 << current->fourth << " " << current->fifth << " " << current->sixth << " " << current->seventh << endl;

            current = current->next;
        }

        fout.close();

        // Free the allocated memory for the linked list
        current = start;
        while (current != nullptr) {
            RiderNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }

        cout << "Ride request successful." << endl;
    } else {
        cout << "Ride request canceled." << endl;
    }
}


void Users::deleteUserAccount() {
    string usernameToDelete;
    cout << "Enter your username: ";
    cin >> usernameToDelete;

    string passwordToDelete;
    cout << "Enter your password to confirm deletion: ";
    cin >> passwordToDelete;

    // Define a linked list node for users
    struct UserNode {
        string fname, lname, username, password, mobile;
        UserNode* next;
    };

    // Initialize the linked list
    UserNode* start = nullptr;
    UserNode* current = nullptr;
    UserNode* previous = nullptr;

    string fname, lname, username, password, mobile;
    fstream fin;
    fin.open("USER.txt", ios::in);

    // Read user information from the file and create nodes in the linked list
    while (fin >> fname >> lname >> username >> password >> mobile) {
        UserNode* newNode = new UserNode{fname, lname, username, password, mobile};
        newNode->next = nullptr;

        if (start == nullptr) {
            start = newNode;
            current = start;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }
    fin.close();

    // Traverse the linked list to find and delete the specified user
    current = start;
    while (current != nullptr) {
        if (current->username == usernameToDelete && current->password == passwordToDelete) {
            // Found the user to delete
            if (previous != nullptr) {
                // If not the first node, update the next pointer of the previous node
                previous->next = current->next;
            } else {
                // If the first node, update the start pointer
                start = current->next;
            }

            // Free the memory for the node
            delete current;

            cout << "User account deleted successfully." << endl;

            // Write the updated user information back to the file
            fstream fout;
            fout.open("USER.txt", ios::out);

            // Traverse the linked list and write to the file
            current = start;
            while (current != nullptr) {
                fout << current->fname << " " << current->lname << " " << current->username << " " << current->password << " " << current->mobile << endl;
                current = current->next;
            }

            fout.close();

            return;
        }

        // Move to the next node in the linked list
        previous = current;
        current = current->next;
    }

    // User not found or password incorrect
    cout << "Invalid username or password. User account not deleted." << endl;

    // Free the allocated memory for the linked list
    current = start;
    while (current != nullptr) {
        UserNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}


void Users::seeUserProfile(){

    cout<<"Name: "<< passengerName<<endl;
    cout<<"Username: "<< passengerUsername<<endl;
    cout<<"Mobile No: "<< passengerMobile<<endl;
    cout<<"Password: "<< "********"<<endl;
}
