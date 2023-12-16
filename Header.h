#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <bits/stdc++.h>
#define mapsize 13
#define V 19
using namespace std;

class Users
{
public:
    string passengerName;
    string passengerUsername;
    string passengerPassword;
    string passengerMobile;
    Users();
    virtual ~Users();

    void passengerSetter();
    void passengerGetter();
    void userProfile();
    void requestARide();
    void deleteUserAccount();
    void seeUserProfile();

protected:
private:
};

class Riders{
public:
    string riderName;
    string riderUsername;
    string riderPassword;
    string riderMobile;
    Riders();
    virtual ~Riders();

    void riderSetter();
    void riderGetter();
    void riderProfile();
    void seeRequest();
    void deleteRiderAccount();
    void seeRiderProfile();

protected:
private:
};



void ctgMap();
void dijkstra(int location, int destination);


#endif // HEADER_H_INCLUDED
