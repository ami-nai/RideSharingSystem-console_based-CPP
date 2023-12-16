//#include "Riders.h"
#include "Header.h"
#include <bits/stdc++.h>
using namespace std;

Riders::Riders()
{
    //ctor
}

Riders::~Riders()
{
    //dtor
}

void Riders::riderSetter(){
    string lastName;
    fstream fout;
    fout.open("RIDER.txt", ios::app);
    //fout>>lastId;
    cout<<"Enter first name: ";
    cin>>riderName;
    cout<<"Enter last name: ";
    cin>>lastName;
    riderName += " " + lastName;
    cout<<"Enter username: ";
    cin>>riderUsername;
    cout<<"Enter password: ";
    cin>>riderPassword;
    cout<<"Enter mobile: ";
    cin>>riderMobile;
    fout<<riderName<<" "<<riderUsername<<" "<<riderPassword<<" "<<riderMobile<<" "<<"ON"<<" "<<"notRequested"<<endl;
    fout.close();
}

void Riders::riderGetter(){
    string firstName, lastName, username, password, status, req;
    cout<<"username & password: ";
    cin>>username>>password;
    fstream fin;
    fin.open("RIDER.txt", ios::in);
    bool flag = true;
    while(fin>>firstName>>lastName>>riderUsername>>riderPassword>>riderMobile>>status>>req){
        if(username == riderUsername && password == riderPassword){
            riderName = firstName + " " + lastName;
            cout<<"Log in successful"<<endl;
            flag = true;
            fin.close();
            riderProfile();
            break;
        }
        else flag = false;
    }
    fin.close();
    if(flag == false){
        cout<<endl<<"Wrong username and password"<<endl;
    }
}
void Riders::riderProfile(){

    while(true)
    {
        int choice;
        cout << "Rider Portal:" << endl;
        cout << "Menu:" << endl;
        cout << "1. See request          2. Delete account" << endl;
        cout << "3. See Rider Profile    4. See map" << endl;
        cout << "5. Return to main menu" << endl<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("CLS");
            seeRequest();
            system("CLS");
            break;
        case 2:
            system("CLS");
            deleteRiderAccount();
            return;
            //user.totalUser = user.passengerId;
            break;
        case 3:
            system("CLS");
            seeRiderProfile();
            // Code
            break;
        case 4:
            system("CLS");
            ctgMap();
            //rider.totalRider = rider.riderId;
            break;
        case 5:
            system("CLS");
            return;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
}

void Riders::seeRequest() {
    string first, second, third, fourth, fifth, sixth, seventh;

    // Define a struct for the linked list node
    struct linked_list {
        string a, b, c, d, e, f, g;
        struct linked_list* next;
    };

    // Define a type for the linked list node
    typedef struct linked_list node;

    // Initialize pointers for the linked list
    node* start = nullptr;
    node* ptr = nullptr;
    node* current = nullptr;

    // Open the file for reading
    fstream fin;
    fin.open("RIDER.txt", ios::in);

    bool flag = false;
    // Read data from the file
    while (fin >> first >> second >> third >> fourth >> fifth >> sixth >> seventh) {
        // Create a new node and initialize its values
        node* newNode = new node{first, second, third, fourth, fifth, sixth, seventh};
        newNode->next = nullptr;

        // Initialize the linked list if it's empty
        if (start == nullptr) {
            start = newNode;
            current = start;
        } else {
            current->next = newNode;
            current = newNode;
        }

        // Check if the data matches the current rider's username and password
        if (third == riderUsername && fourth == riderPassword) {
            if (seventh == "Requested") {
                flag = true;
                cout << "You have a request. Do you want to accept?" << endl;
                cout << "1. Yes   2. No" << endl;
                int choice;
                cin >> choice;
                if (choice == 1) {
                    current->g = "notRequested";
                    cout<<"Ride acceptation completed. Hurry to the location."<<endl;
                    this_thread::sleep_for(std::chrono::seconds(3));
                }
            }
        }
    }
    if(!flag){
        cout<<"You have no ride request"<<endl;
        this_thread::sleep_for(std::chrono::seconds(3));
    }
    fin.close();

    // Open the file for writing
    fstream fout;
    fout.open("RIDER.txt", ios::out);

    // Traverse the linked list and write to the file
    current = start;
    while (current != nullptr) {
        fout << current->a << " " << current->b << " " << current->c << " "
             << current->d << " " << current->e << " " << current->f << " " << current->g << endl;

        // Move to the next node
        node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    fout.close();
}




void Riders::deleteRiderAccount() {
    string usernameToDelete = riderUsername;  // Assuming riderUsername is the currently logged-in user
    string passwordToDelete;

    // Prompt the user to enter their password to confirm deletion
    cout << "Enter your password to confirm deletion: ";
    cin >> passwordToDelete;

    // Define a linked list node for users
    struct riderNode {
        string fname, lname, username, password, mobile, status, req;
        riderNode* next;
    };

    // Initialize the linked list
    string fname, lname, username, password, mobile, status, req;
    riderNode* start = nullptr;
    riderNode* current = nullptr;
    riderNode* previous = nullptr;

    fstream fin;
    fin.open("RIDER.txt", ios::in);

    // Read user information from the file and create nodes in the linked list
    while (fin >> fname >> lname >> username >> password >> mobile >> status >> req) {
        riderNode* newNode = new riderNode{fname, lname, username, password, mobile, status, req};
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

            cout << "Rider account deleted successfully." << endl;

            // Write the updated user information back to the file
            fstream fout;
            fout.open("RIDER.txt", ios::out);

            // Traverse the linked list and write to the file
            current = start;
            while (current != nullptr) {
                fout << current->fname << " " << current->lname << " " << current->username << " " << current->password << " " << current->mobile << " " << current->status << " " << current->req << endl;
                current = current->next;
            }

            fout.close();

            return;
        }

        // Move to the next node in the linked list
        previous = current;
        current = current->next;
    }

    // Rider not found or password incorrect
    cout << "Invalid username or password. Rider account not deleted." << endl;

    // Free the allocated memory for the linked list
    current = start;
    while (current != nullptr) {
        riderNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void Riders::seeRiderProfile(){
    cout<<"Name: "<< riderName<<endl;
    cout<<"Username: "<< riderUsername<<endl;
    cout<<"Mobile No: "<< riderMobile<<endl;
    cout<<"Password: "<< "********"<<endl;
}
