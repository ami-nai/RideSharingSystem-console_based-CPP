#include "Header.h"
#include <bits/stdc++.h>
using namespace std;



                //        0  1  2  3  4  5  6  7  8  9 10 11 12 13  14 15 16 17 18
int graph[V][V] =     { { 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     //0
                        { 0, 0, 2, 0, 0, 4, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     //1
                        { 0, 2, 0, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     //2
                        { 3, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     //3
                        { 0, 0, 2, 0, 0, 0, 0, 0, 0, 3, 0, 0, 9, 0, 0, 0, 0, 0, 0},     //4
                        { 0, 4, 0, 4, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     //5
                        { 0, 5, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},     //6
                        { 0, 5, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0},     //7
                        { 0, 5, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},     //8
                        { 0, 0, 0, 0, 3, 0, 0, 0, 1, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0},     //9
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 2, 0, 0, 0, 0, 3, 4, 0},     //10
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 4},     //11
                        { 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},     //12
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0},     //13
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 2, 0, 0, 0},     //14
                        { 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},     //15
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 1, 0, 3, 0},     //16
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 3, 0, 2},     //17
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 2, 0}, };  //18



string mappinng[mapsize][mapsize+2];

void ctgMap(){

    for(int i=0; i<mapsize; i++){
        for(int j=0; j<mapsize+2; j++){
            mappinng[i][j] = ".......";
        }
    }
    mappinng[0][2] = "Bakalia";
    mappinng[1][5] = "Chawkbzr";
    mappinng[1][7] = "Kotwali";
    mappinng[2][1] = "Bdrhaat";
    mappinng[3][7] = "New Mrkt";
    mappinng[4][3] = "Muradpur";
    mappinng[6][4] = "2No Gate";
    mappinng[6][5] = "GEC";
    mappinng[6][6] = "Lalkhan";
    mappinng[6][7] = "TigrPass";
    mappinng[7][9] = "Dewanhat";
    mappinng[7][11] = "Agrabad";
    mappinng[7][12] = "Brk Build";
    mappinng[9][0] = "Fzdarhat";
    mappinng[10][3] = "City Gate";
    mappinng[10][5] = "AK Khan";
    mappinng[10][6] = "Olongkar";
    mappinng[11][10] = "Noyabzr";
    mappinng[11][12] = "Boropol";

    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    for(int i=0; i<mapsize; i++){
        cout<<"    ";
        for(int j=0; j<mapsize+2; j++){
            cout<<mappinng[i][j]<<"   ";
        }
        cout<<endl;
        cout<<endl;
        cout<<endl;
    }
}

int minDistance(int dist[], bool sptSet[])
{

    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[], int destination)
{
    cout << "Distance from the location to the destination" << endl;
    for (int i = 0; i < V; i++)
        if(i == destination){
            cout << i << " \t\t\t\t" << dist[i] << "Km" << endl;
            cout<<"Total fare: "<<dist[i]*5<<" TK"<<endl;
            cout<<"Total time: "<<dist[i]*2<<" minutes"<<endl;
        }
}

void dijkstra(int src, int destination)
{
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)

            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, destination);
}


int main()
{
    Users user;
    Riders rider;
    cout << "Welcome to TripleS, a convenient ride sharing program" << endl;


    while(true)
    {
        int choice;
        cout << "Home Page:" << endl;
        cout << "Menu:" << endl;
        cout << "1. Login as user        2. Register as user" << endl;
        cout << "3. Login as rider       4. Register as rider" << endl;
        cout << "5. See map              6. Exit" << endl<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("CLS");
            user.passengerGetter();
            break;
        case 2:
            system("CLS");
            user.passengerSetter();
            //user.totalUser = user.passengerId;
            break;
        case 3:
            system("CLS");
            rider.riderGetter();
            // Code
            break;
        case 4:
            system("CLS");
            rider.riderSetter();
            //rider.totalRider = rider.riderId;
            break;
        case 5:
            system("CLS");
            ctgMap();
            break;
        case 6:
            cout << "tataa!!! Exiting the program." << endl;
            //cout<<user.totalUser<<" "<<rider.totalRider<<endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }



    return 0;
}
