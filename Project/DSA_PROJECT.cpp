#include <iostream>
using namespace std;
#include <bits/stdc++.h>

#define V 15

int *parent = new int[V];
string path[V];
string k[V];
int routeDistance;
string searchedSpots[] = {"NUST", "SADDAR", "FAIZABAD", "RAWAL CHOWK", "WESTRIDGE", "I8", "LOK VIRSA", "G-9", "FAST", "F-9", "26-number"};
string spots[11];
int visited[V];
int graph2[V][V] = {
        {0,  0,  0,  0, 0,  0,  0, 0, 0,  12, 8,  0, 0, 0, 0},
        {0,  0,  11, 0, 4,  0,  0, 0, 0,  0,  0,  0, 0, 0, 0},
        {0,  11, 0,  5, 0,  2,  0, 0, 0,  0,  0,  0, 0, 0, 0},
        {0,  0,  5,  0, 0,  0,  2, 0, 0,  0,  0,  0, 0, 0, 0},
        {0,  4,  0,  0, 0,  0,  0, 0, 7,  0,  11, 0, 0, 0, 0},
        {0,  0,  2,  0, 0,  0,  7, 6, 8,  0,  0,  0, 0, 0, 0},
        {0,  0,  0,  2, 0,  7,  0, 0, 0,  9,  0,  0, 0, 0, 0},
        {0 , 0,  0,  0, 0,  6,  0, 0, 9,  0,  0,  0, 0, 0, 0},
        {0,  0,  0,  0, 7,  8,  0, 9, 0,  10, 14, 0, 0, 0, 0},
        {12, 0,  0,  0, 0,  0,  9, 0, 10, 0,  17, 0, 0, 0, 0},
        {8,  0,  0,  0, 11, 0,  0, 0, 14, 17, 0,  0, 0, 0, 0},
        {0,  0,  0,  0, 0,  0,  0, 0, 0,  0,  0,  0, 0, 0, 0},
        {0,  0,  0,  0, 0,  0,  0, 0, 0,  0,  0,  0, 0, 0, 0},
        {0,  0,  0,  0, 0,  0,  0, 0, 0,  0,  0,  0, 0, 0, 0},
        {0,  0,  0,  0, 0,  0,  0, 0, 0,  0,  0,  0, 0, 0, 0}};

struct User
{
    string name, userName, password, contact;
    User *nextUser;
    User(string name, string userName, string password, string contact)
    {
        this->name = name;
        this->userName = userName;
        this->password = password;
        this->contact = contact;
        nextUser = NULL;
    }
    void displayUser()
    {
        cout << "\n\t\t\t\t\t\t\tName: " << name
             << "\n\t\t\t\t\t\t\tUsername: " << userName
             << "\n\t\t\t\t\t\t\tPassword: " << password
             << "\n\t\t\t\t\t\t\tContact: " << contact
             << "\n\n\t\t\t\t\t\t      *****\n";
    }
};

struct Ride
{
    int distance, fare;
    string riderName, route;
    bool status;
    Ride *nextRide;
    Ride(int distance, int fare, string riderName, string route)
    {
        this->distance = distance;
        this->fare = fare;
        this->riderName = riderName;
        this->route = route;
        this->status = true;
        nextRide = NULL;
    }
    void displayRide()
    {
        cout << "\n\t\t\t\t\t\t\tDistance: " << distance
             << "\n\t\t\t\t\t\t\tFare: " << fare
             << "\n\t\t\t\t\t\t\tRider Name: " << riderName
             << "\n\t\t\t\t\t\t\tRoute: " << route
             << "\n\t\t\t\t\t\t\tRide Status: " << status
             << "\n\n\t\t\t\t\t\t      *****\n";
    }
};

struct Captain
{
    string name, carName, regNo;
    int carType;
    bool status;
    Captain *nextCaptain;
    Ride *firstRide;
    Captain(string name, string carName, string regNo, int carType)
    {
        this->name = name;
        this->carName = carName;
        this->regNo = regNo;
        this->carType = carType;
        nextCaptain = NULL;
        firstRide = NULL;
    }
    void displayCaptain()

    {
        cout << "\n\t\t\t\t\t\t\tName: " << name
             << "\n\t\t\t\t\t\t\tCar Name: " << carName
             << "\n\t\t\t\t\t\t\tRegistration " << regNo
             << "\n\t\t\t\t\t\t\tCar Type: " << carType
             << "\n\n\t\t\t\t\t\t      **********************************\n";
    }
};

Captain *firstCaptain = NULL;
Captain *lastCaptain = NULL;

Ride *firstRide = NULL;
Ride *lastRide = NULL;

void enqueue(Ride *p)
{
    Ride *curr = p;
    if (!firstRide)
    {

        firstRide = lastRide = curr;
    }
    else
    {

        lastRide->nextRide = curr;
        lastRide = curr;
    }
}


void initVisited(){
	for(int i = 0;i<11;i++){
		visited[i] = -1;
	}
}
void dfs(int value){

	visited[value] = 1;
	spots[value] = searchedSpots[value];
	for(int j = 0; j<11;j++){
		if(graph2[value][j] != 0 && visited[j] == -1){
			dfs(j);
		}
	}	
}

int minDistance(int distance[], bool shortestPathTree[])
{
    int min = INT_MAX;
    int min_index;
    for (int i = 0; i < V; i++)
        if (shortestPathTree[i] == false && distance[i] <= min)
        {
            min = distance[i], min_index = i;
        }
    return min_index;
}
int c = 0;
void printPath(int *parent, int i, string path[])
{

    if (parent[i] == -1)
    {
        c++;
        return;
    }
    printPath(parent, parent[i], path);
    path[c - 1].append("->");
    path[c - 1].append(spots[i]);
}

int printSolution(int distance[], int *parent, string path[], int src)
{
    int source = src;

    for (int i = 0; i < V; i++)
    {
        if (distance[i] != INT_MAX)
        {
            path[i] = spots[source];
        }
        printPath(parent, i, path);
    }
    c = 0;
}

void dijkstrasAlgorithm(int graph[V][V], int source, int destination)
{
    int distance[V];
    bool shortestPathTree[V];

    for (int i = 0; i < V; i++)
    {
        distance[i] = INT_MAX;
        shortestPathTree[i] = false;
        parent[i] = -1;
        
    }

    distance[source] = 0;

    for (int count = 0; count < V - 1; count++)
    {

        int u = minDistance(distance, shortestPathTree);
        shortestPathTree[u] = true;

        for (int i = 0; i < V; i++)
        {

            if (shortestPathTree[i] == false && graph[u][i] && distance[u] != INT_MAX && distance[u] + graph[u][i] < distance[i])
            {
                distance[i] = distance[u] + graph[u][i];

                parent[i] = u;
            }
        }
    }
//    dfs(graph,0);
    routeDistance = distance[destination];
    printSolution(distance, parent, path, source);
}

int **graph(int source, int destination)
{
    
        

    dijkstrasAlgorithm(graph2, source, destination);
}

void addCaptain(string name, string carName, string regNo, int carType)
{
    Captain *curr = new Captain(name, carName, regNo, carType);
    if (!firstCaptain)
    {
        firstCaptain = lastCaptain = curr;
    }
    else
    {
        lastCaptain->nextCaptain = curr;
        lastCaptain = curr;
    }
}

void displayCaptains()
{
    if (!firstCaptain)
    {
        cout << "\n\t\t\t\t\t\t\t<<< No Captains to display >>>";
    }
    else
    {
    	
        Captain *p = firstCaptain;
        int count = 0;
        cout << "\n\t\t\t\t\t\t==============  Captian Details  ==============\n";
        while (p != NULL)
        {
            cout << "\n\t\t\t\t\t\t\tSerial: " << count + 1;
            count++;
            p->displayCaptain();

            p = p->nextCaptain;
        }
        cout << "\n\t\t\t\t\t\t================================================";
    }
}

void displayEveryDetail()
{
    if (!firstCaptain)
    {
        cout << "\n\t\t\t\t\t\t\t<<< No Captains to display >>>";
    }
    else
    {
    	
        Captain *p = firstCaptain;
        int count = 0;
        cout << "\n\t\t\t\t\t\t==============  Captian Details  ==============\n";
        while (p != NULL)
        {
            cout << "\n\t\t\t\t\t\t\tSerial: " << count + 1;
            count++;
            p->displayCaptain();
            Ride *q = p->firstRide;
            if(!q){
            	cout << "\n\t\t\t\t\t\t\t<<< No rides to display >>>";
			}
			else{
				while (q != NULL)
	            {
	
	                q->displayRide();
	                q = q->nextRide;
	            }
			}
            

            p = p->nextCaptain;
        }
        cout << "\n\t\t\t\t\t\t================================================";
    }
}

void removeCaptain()
{
    if (!firstCaptain)
    {
        cout << "\n\n\t\t\t\t\t\t\t <<< No captain found >>>";
    }
    else
    {
        displayCaptains();
        cout << "\n\n\t\t\t\t\t\t\tEnter serial: ";
        int serial;
        cin >> serial;
        Captain *p = firstCaptain;
        Captain *prev = NULL;
        for (int i = 0; i < serial - 1; i++)
        {
            prev = p;
            p = p->nextCaptain;
        }
        if (p == firstCaptain)
        {
            firstCaptain = firstCaptain->nextCaptain;
        }
        else
        {
            prev->nextCaptain = p->nextCaptain;
        }
        cout << "\n\n\t\t\t\t\t\t\t<<< Captain has been removed >>>";
    }
}

User *firstUser = NULL;
User *lastUser = NULL;

void addUser(string name, string userName, string password, string number)
{
    User *curr = new User(name, userName, password, number);
    if (!firstUser)
    {
        firstUser = lastUser = curr;
    }
    else
    {
        lastUser->nextUser = curr;
        lastUser = curr;
    }
    cout << "\n\n\t\t\t\t\t\t\t<<< User added successfully! >>>";
}

void displayUsers()
{
    cout << "\n\t\t\t\t\t\t==================== USERS =====================";
    if (!firstUser)
    {
        cout << "\n\n\t\t\t\t\t\t\t   <<< No Users to display >>>\n";
    }
    else
    {

        User *p = firstUser;
        int count = 0;
        while (p != NULL)
        {
            cout << "\n\t\t\t\t\t\t\tSerial: " << count + 1;
            count++;
            p->displayUser();
            p = p->nextUser;
        }
    }
    cout << "\n\t\t\t\t\t\t================================================";
}

void removeUser()
{
    if (!firstUser)
    {
        cout << "\n\n\t\t\t\t\t\t\t\t<<< No record found >>>";
    }
    else
    {
        displayUsers();
        cout << "\n\n\t\t\t\t\t\t\tEnter serial of the user you want to delete";
        int serial;
        cin >> serial;
        User *p = firstUser;
        User *prev = NULL;
        for (int i = 0; i < serial - 1; i++)
        {
            prev = p;
            p = p->nextUser;
        }
        if (p == firstUser)
        {
            firstUser = firstUser->nextUser;
        }
        else
        {
            prev->nextUser = p->nextUser;
        }
        cout << "\n\n\t\t\t\t\t\t\tUser has been removed";
    }
}

void addRide(Ride *ride)
{
    Ride *curr = ride;
    displayCaptains();
    cout << "\n\n\t\t\t\t\t\t\tEnter serial of the captain you want to add ride";
    int serial;
    cin >> serial;
    Captain *p = firstCaptain;
    for (int i = 0; i < serial - 1; i++)
    {
        p = p->nextCaptain;
    }
    curr->nextRide = p->firstRide;
    p->firstRide = curr;
    cout << "\n\n\t\t\t\t\t\t\tRide has been added";
}

void displayRides()
{
    Captain *p = firstCaptain;
    if (!p)
    {
        cout << "\n\n\t\t\t\t\t\t\tNo records to display";
    }
    else
    {
        while (p != NULL)
        {
            Ride *q = p->firstRide;
            if (!q)
            {
                cout << endl;
                cout << p->name << "\n\t\t\t\t\t\t\tDoesnot have any ride yet";
            }
            else
            {
                cout << endl
                     << "\t\t\t\t\t\t\t" << p->name << "'s Rides: ";
                while (q != NULL)
                {
                    q->displayRide();
                    q = q->nextRide;
                }
            }
            p = p->nextCaptain;
        }
    }
}

bool searchUser(string username, string password)
{
    User *p = firstUser;
    if (!p)
    {
        return false;
    }
    else
    {
        while (p != NULL)
        {
            if (p->userName == username)
            {
                if (p->password == password)
                {
                    return true;
                }
                cout << "\n\n\t\t\t\t\t\t\tWrong Password";
                return false;
            }
            p = p->nextUser;
        }
        return false;
    }
}

void displaySpots()
{
	initVisited();
	dfs(0);
    int arrSize = sizeof(spots) / sizeof(spots[0]);
    for (int i = 0; i < arrSize; i++)
    {
        cout << "\n\t\t\t\t\t\t\t" << i + 1 << ". " << spots[i];
    }
}

void startRide(string username)
{
    int pickUp, destination, type, fare;
    cout << "\n\n\t\t\t\t\t\t================= PICKUP POINTS ================\n";
    displaySpots();
    cout << "\n\t\t\t\t\t\t\tEnter Pickup Point: ";
    cin >> pickUp;
    cout << "\n\n\t\t\t\t\t\t================ DROPOFF POINTS ================\n";
    displaySpots();
    cout << "\n\t\t\t\t\t\t\tEnter Destination: ";
    cin >> destination;
    cout << "\n\t\t\t\t\t\t\tSelect Car Type ";
    cout << "\n\t\t\t\t\t\t\t1. Mini ";
    cout << "\n\t\t\t\t\t\t\t2. Go ";
    cin >> type;
    graph(pickUp - 1, destination - 1);
    string dest = path[destination - 1];

    User *p = firstUser;
    while (p->userName != username)
    {
        p = p->nextUser;
    }
    string name = p->name;
    if(type==1){
    	fare = routeDistance * 20;
	}
    else{
		fare = routeDistance * 30;
	}
    Ride *curr = new Ride(routeDistance, fare, name, dest);
    curr->displayRide();
    enqueue(curr);
}
void history(string username)
{
    Captain *p = firstCaptain;
    if (!p)
    {
        cout << endl
             << "\n\t\t\t\t\t\t\t<<< No history to display >>>";
    }
    else
    {
        int c = 0;
        while (p != NULL)
        {
            Ride *q = p->firstRide;
            if(q)
            {
                User *k = firstUser;

                while (k->userName != username)
                {
                    k = k->nextUser;
                }
                string name = k->name;
                while (q != NULL)
                {
                    if (q->riderName == name)
                    {
                        q->displayRide();
                        c++;
                    }
                    q = q->nextRide;
                }
            }
            p = p->nextCaptain;
        }
        if(c==0){
            cout << endl
             << "\n\t\t\t\t\t\t\t<<< No history to display >>>";
        }
    }
}
void deleteMyProfile(string username)
{
    if (!firstUser)
    {
        cout << "\n\n\t\t\t\t\t\t\t\t<<< No record found >>>";
    }
    else
    {
        User *p = firstUser;
        User *prev = NULL;
        int choice;
        while (p->userName != username)
        {
            prev = p;
            p = p->nextUser;
        }
        cout << "\n\n\t\t\t\t\t\t\tAre you sure you want to remove your account?"
             << "\n\t\t\t\t\t\t\t1.Yes"
             << "\n\t\t\t\t\t\t\t2.No"
             << "\n\t\t\t\t\t\t\tSelect Option: ";
        cin >> choice;
        if (choice == 1)
        {
            if (p == firstUser)
            {
                firstUser = firstUser->nextUser;
            }
            else
            {
                prev->nextUser = p->nextUser;
            }
            cout << "\n\n\t\t\t\t\t\t  <<< User's account has been removed >>>\n";
        }
    }
}
void rideStatus(string username)
{
    if (!firstRide)
    {
        cout << "\n\n\t\t\t\t\t\t\t<<< No rides in queue >>>\n";
    }
    else
    {
        User *userPointer = firstUser;
        Ride *k = firstRide;
        string name;
        int s1 = 1, s2 = 1;
        int flag = true;
        while (userPointer != NULL)
        {
            if (userPointer->userName == username)
            {
                name = userPointer->name;
                flag = false;
                break;
            }
            userPointer = userPointer->nextUser;
        }
        if (flag)
        {
            cout << "\n\n\t\t\t\t\t\t\t<<< User not found! >>>\n";
        }
        else
        {
            while (k != NULL)
            {

                if (k->riderName == name && k->status != false)
                {
                    cout << "\n\n\t\t\t\t\t\t\tSerial: " << s1;
                    k->displayRide();
                    s1++;
                }
                k = k->nextRide;
            }
        }
    }
}
void changeStatus(string username)
{
    if (!firstRide)
    {
        cout << "\n\n\t\t\t\t\t\t\t<<< No rides in queue >>>";
    }
    else
    {
        User *userPointer = firstUser;
        Ride *k = firstRide;
        string name;
        int s1 = 1, s2 = 1;
        int flag = true;
        while (userPointer != NULL)
        {
            if (userPointer->userName == username)
            {
                name = userPointer->name;
                flag = false;
                break;
            }
            userPointer = userPointer->nextUser;
        }
        if (flag)
        {
            cout << "\n\n\t\t\t\t\t\t\t<<< User not found! >>>";
        }
        else
        {
            while (k != NULL)
            {

                if (k->riderName == name && k->status != false)
                {
                    cout << "\n\n\t\t\t\t\t\t\tSerial: " << s1;
                    k->displayRide();
                    s1++;
                }
                k = k->nextRide;
            }
            k = firstRide;
            if (s1 == 1)
            {
                cout << "\n\n\t\t\t\t\t\t\t\t<<< No ride found! >>>";
            }

            else if (s1 == 2)
            {
                while (k != NULL)
                {

                    if (k->riderName == name && k->status != false)
                    {
                        k->status = false;
                        cout << "\n\n\t\t\t\t\t\t\t<<< Your ride has been cancelled! >>>";
                    }
                    k = k->nextRide;
                }
            }
            else
            {
                cout << "\n\n\t\t\t\t\t\t\tEnter Serial: ";
                cin >> s2;
                while (k != NULL)
                {

                    if (k->riderName == name && s1 == s2 && k->status != false)
                    {
                        k->status = false;
                        cout << "\n\n\t\t\t\t\t\t\t<<< Your ride has been cancelled! >>>";
                    }
                    s2++;
                    k = k->nextRide;
                }
            }
        }
    }
}

void user();

void displayRidesQueue()
{
    if (!firstRide)
    {
        cout << "\n\n\t\t\t\t\t\t\t\t<<< No Ride Yet >>>\n";
    }
    else
    {
        Ride *p = firstRide;
        while (p != NULL)
        {
            p->displayRide();
            p = p->nextRide;
        }
    }
}

void dequeue()
{
    if (firstRide == NULL)
    {
        cout << "\n\n\t\t\t\t\t\t\t\t<<< No Ride Yet >>>\n";
    }
    else
    {
        Ride *temp = firstRide;
        if (firstRide->nextRide == NULL)
        {
            firstRide = NULL; // Queue
        }
        else
        {
            firstRide = firstRide->nextRide;
        }
        temp->nextRide = NULL;
        if (temp->status != false)
        {
            addRide(temp);
        }
        else
        {
            cout << "\n\n\t\t\t\t\t\t\t<<< Ride was cancelled by the user "
                 << temp->riderName
                 << " >>>\n";
        }
    }
}
void newUser()
{
    string name, username, password, contact;
    cout << "\n\n\t\t\t\t\t\t\tEnter name: ";
    cin >> name;
    cout << "\n\t\t\t\t\t\t\tEnter username: ";
    cin >> username;
    cout << "\n\t\t\t\t\t\t\tEnter password: ";
    cin >> password;
    cout << "\n\t\t\t\t\t\t\tEnter contact: ";
    cin >> contact;
    addUser(name, username, password, contact);
    user();
}
void userPanel()
{
    int sel;
    cout << "\n\t\t\t\t\t\t================== USER CONSOLE ================"
         << "\n\n\t\t\t\t\t\t\t1. Sign in"
         << "\n\t\t\t\t\t\t\t2. Sign up"
         << "\n\t\t\t\t\t\t\tSelect Option: ";
    cin >> sel;
    if (sel == 1)
    {
        user();
    }
    else if (sel == 2)
    {
        newUser();
    }
    else
    {
        cout << "\n\t\t\t\t\t\t\t<<< Option invalid >>>\n";
    }
}
void admin();

void rawData()
{
    addCaptain("Shakeel", "Alto", "ABC 123", 1);
    addCaptain("Akram", "WagonR", "LEX 231", 2);
    addUser("Haris", "harisxayyaz", "123", "123456");
    addUser("Zaman", "Zaman", "123", "123456");
}
void about()
{

    cout << "\n\n\t\t\t\t\t\t=================== ABOUT INFO =================="
         << "\n\n\t\t\t\t\t\t   Project for Data Structures and Algorithms "
         << "\n\n\t\t\t\t\t\t   Members: "
         << "\n\t\t\t\t\t\t\tSyed Hamza\tSP22-BCS-099"
         << "\n\t\t\t\t\t\t\tUsman Akram\tSP21-BCS-103"
         << "\n\n\t\t\t\t\t\t   Instructor:"
         << "\n\t\t\t\t\t\t\tDr. Inayat ur Rehman"
         << "\n\n\t\t\t\t\t\t   Structure Division:"
         << "\n\n\t\t\t\t\t\t\tHamza-099"
         << "\n\t\t\t\t\t\t\t   ->Multiple Linked List"
         << "\n\t\t\t\t\t\t\t   ->Queue"
         << "\n\n\t\t\t\t\t\t\tUsman Akram-103"
         << "\n\t\t\t\t\t\t\t   ->Graph"
         << "\n\t\t\t\t\t\t\t   ->Stack"
         << "\n\n\t\t\t\t\t\t=================================================";
}

string adminPassword = "admin";

bool adminLogin(string password)
{
    if (password == adminPassword)
    {
        return true;
    }
    return false;
}

void setAdminPass(string newPass)
{
    adminPassword = newPass;
    cout << "\n\n\t\t\t\t\t\t  <<< Password has been changed successfully! >>>";
}

void mainMenu()
{
    int choice;
    while (true)
    {
        cout << "\n\n\t\t\t\t\t\t\t\t<<< MAIN MENU >>>"
             << "\n\n\t\t\t\t\t\t\t\t1. Admin"
             << "\n\t\t\t\t\t\t\t\t2. User"
             << "\n\t\t\t\t\t\t\t\t3. About Project"
             << "\n\n\t\t\t\t\t\t\t\tSelect Option: ";
        cin >> choice;
        if (choice == 1)
        {
            string adminPass;
            cout<<"\n\t\t\t\t\t      --------------- ADMIN CREDENTIALS ----------------";
            cout << "\n\n\t\t\t\t\t\t   Enter admin password: ";
            cin >> adminPass;
            
            if (adminLogin(adminPass))
            {
                admin();
            }
            else
            {
                cout << "\n\n\t\t\t\t\t\t\t     <<< Wrong Password >>>";
            }
        }
        else if (choice == 2)
        {
            userPanel();
        }
        else if (choice == 3)
        {
            about();
        }
    }
}
int main()
{
    cout << "\n\t\t\t\t\t\t==============================================\n";
    cout << "\n\t\t\t\t\t\t\t    <<< CAB MANAGEMENT >>>"
         << "\n\n\t\t\t\t\t\t    Project by\n\n\t\t\t\t\t\t    Syed Hamza\tSP22-BCS-099\n\t\t\t\t\t\t    Usman Akram\tSP22-BCS-103\n"
         << "\n\t\t\t\t\t\t==============================================\n";
    mainMenu();

    return 0;
}

void admin()
{
    int choice;
    while (true)
    {
        //        cout << "\n\n\t\t\t\t\t\t\t <<< ADMIN CONSOLE >>>"
        cout << "\n\t\t\t\t\t\t================= ADMIN CONSOLE ================"
             << "\n\n\t\t\t\t\t\t\t    1. Add Captain"
             << "\n\t\t\t\t\t\t\t    2. Remove Captain"
             << "\n\t\t\t\t\t\t\t    3. Display Captains"
             << "\n\t\t\t\t\t\t\t    4. Display Rides"
             << "\n\t\t\t\t\t\t\t    5. Approve Ride"
             << "\n\t\t\t\t\t\t\t    6. View Pending Rides"
             << "\n\t\t\t\t\t\t\t    7. Remove user"
             << "\n\t\t\t\t\t\t\t    8. Display Users"
             << "\n\t\t\t\t\t\t\t    9. Raw Data"
             << "\n\t\t\t\t\t\t\t    10. Change Password"
             << "\n\t\t\t\t\t\t\t    11. Back"
             << "\n\n\t\t\t\t\t\t\t    Select Option: ";
        cin >> choice;
        string name, carName, regNo;
        int carType;
        string newPassword;
        switch (choice)
        {
        case 1:
            cout << "\n\n\t\t\t\t\t\t\tEnter Name: ";
            cin >> name;
            cout << "\n\t\t\t\t\t\t\tEnter Car Name: ";
            cin >> carName;
            cout << "\n\t\t\t\t\t\t\tEnter Registration No: ";
            cin >> regNo;
            cout << "\n\t\t\t\t\t\t\tEnter Car Type: ";
            cin >> carType;
            addCaptain(name, carName, regNo, carType);
            break;
        case 2:
            removeCaptain();
            break;
        case 3:
            displayEveryDetail();
            break;
        case 4:
            displayRides();
            break;
        case 5:
            dequeue();
            break;
        case 6:
            displayRidesQueue();
            break;
        case 7:
            removeUser();
            break;
        case 8:
            displayUsers();
            break;
        case 9:
            rawData();
            break;
        case 10:
        	cout<<"\n\t\t\t\t\t      ------------- CHANGE ADMIN CREDENTIALS --------------";
            cout << "\n\t\t\t\t\t\t    Enter new password: ";
            cin >> newPassword;
            setAdminPass(newPassword);
            break;
        case 11:
            mainMenu();
            break;
        default:
            break;
        }
    }
}
void user()
{

    string username, password;
    cout << "\n\t\t\t\t\t\t\tUsername: ";
    cin >> username;
    cout << "\n\t\t\t\t\t\t\tPassword: ";
    cin >> password;
    int choice;
    if (searchUser(username, password))
    {

        cout << "\n\t\t\t\t\t\t\t<<< Login successful! >>>";
        do
        {

            cout << "\n\n\t\t\t\t\t\t\t    1. Start Ride"
                 << "\n\t\t\t\t\t\t\t    2. View History"
                 << "\n\t\t\t\t\t\t\t    3. Cancel Request"
                 << "\n\t\t\t\t\t\t\t    4. View Ride Status"
                 << "\n\t\t\t\t\t\t\t    5. Delete my Profile"
                 << "\n\t\t\t\t\t\t\t    0. To exit"
                 << "\n\n\t\t\t\t\t\t\t    Select Option: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                startRide(username);
                break;
            case 2:
                history(username);
                break;
            case 3:
                changeStatus(username);
                break;
            case 4:
                rideStatus(username);
                break;
            case 5:
                deleteMyProfile(username);
                mainMenu();
            default:
                break;
            }
        } while (choice != 0);
    }
    else
    {
        cout << "\n\t\t\t\t\t\t\t<<< Invalid username/password! >>>";
    }
}
