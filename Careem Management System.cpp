#include <iostream>
using namespace std;
struct ride
{
	string RiderName;
	int charges;
	int kilometers;
	ride *next = NULL;
};
struct car
{
	string carName;
	int carId;
	string dirverName;
	car *next = NULL;
	car *prev = NULL;
	ride* rideFirst=NULL;
};
car *firstcar = NULL;


void RegisterCar(){
	car *p = new car;
	car *curr;
	curr=firstcar;
	cout << "Enter Car Name: ";
	cin >> p->carName;
	cout << "Enter Car ID: ";
	cin >> p->carId;
	cout << "Enter Driver Name: ";
	cin >> p->dirverName;
		   if (firstcar == NULL){
           p->prev=NULL;
		   firstcar = p;
          }
	else
	{	while (curr->next!=NULL)
	{
		curr=curr->next;
	}
		curr->next = p;
        p->prev=curr;
		p->next=NULL;
    }
}
void DisplayAllCars(){
	car *p;
	p=firstcar;
	if(firstcar!=NULL){
do
	{
	cout << "Car Name Is: "<<p->carName;
	cout << "\nCar ID Is: "<<p->carId;
	cout << "\nDriver Name Is: "<<p->dirverName<<endl;
	
		p=p->next;
	}	while(p!=NULL);
}

}
void DisplayType2(){
	car *p;
	p=firstcar;
	if(firstcar!=NULL){
do
	{
	cout << "Car Name Is: "<<p->carName;
	cout << "Car ID Is: "<<p->carId;
	cout << "Driver Name Is: "<<p->dirverName<<endl;	
		p=p->next;
	}	while(p!=firstcar);
}

}
void AddNewRide(){
	car* curr=firstcar;
	ride *p = new ride;
	int id;
	cout<<"Enter the Id of the Car: ";
	cin>>id;
while(curr->carId!=id && curr!=NULL){
	curr=curr->next;
}if(curr!=NULL){
	cout << "Enter Rider Name: ";
	cin >> p->RiderName;
	cout << "Enter Charges: ";
	cin >> p->charges;
	cout << "Enter  Kilometers Driven: ";
	cin >> p->kilometers;
	if(curr->rideFirst==NULL){
		curr->rideFirst=p;}
	else{
	p->next=curr->rideFirst;
	curr->rideFirst=p;}

}
	
}
void DisplayRidesDetails(){
	int id;
	cout<<"Enter Car Id for Ride Details:";
	cin>>id;
	car *curr=firstcar;
	while(curr->carId!=id && curr!=NULL){
		curr=curr->next;
	}
	ride* ridee=curr->rideFirst;
if (curr!=NULL)
	{
		while(ridee!=NULL){
	cout << "Rider Name Is: "<<ridee->RiderName;
	cout << "\nCharges Are: "<<ridee->charges;
	cout << "\nKilometers Are: "<<ridee->kilometers<<endl;
	ridee=ridee->next;}
	}


}
void DisplayParticularEarnings(){
	int id;
	int earnings=0;
	cout<<"Enter Car Id for its Earnings:";
	cin>>id;
	car *curr=firstcar;
	ride *p;
	while(curr->carId!=id && curr!=NULL){
		curr=curr->next;
	}
	ride* ridee=curr->rideFirst;
if (curr!=NULL)
	{
	while(ridee!=NULL){
	earnings+=ridee->charges;
	ridee=ridee->next;
	}
	cout<<"ToTal Earnings Are: "<<earnings;
	}
}
void DisplayTotalEarnings(){
	int id;
	car *curr=firstcar;
	ride *p;
	while(curr!=NULL){
	int earnings=0;
	ride* ridee=curr->rideFirst;
	while(ridee!=NULL){
	earnings+=ridee->charges;
	ridee=ridee->next;
	}
	cout<<"ToTal Earnings of Car with ID " <<curr->carId<<" Is: "<<earnings<<endl;
		curr=curr->next;
}
}

int main()
{
	int option;
	do
	{
		cout << "\nPress 1 Register New Car: ";
		cout << "\nPress 2 to Display All Registered Cars: ";
		cout << "\nPress 3 to Display Type-2 Cars: ";
        cout << "\nPress 4 to Add New Ride: ";
        cout << "\nPress 5 to Display Rides With Details: ";
		cout<<"\nPress 6 to Display Earnings of a Specific Car: ";
		cout<<"\nPress 7 to Display Total Earnings of All Cars: "<<endl;
		/*cout<<"\nPress 8 to Sort in Sorted Linked List: ";
		cout<<"\nPress 9 to Swap All Nodes: ";
		cout<<"\nPress 10 to Merge: ";
		cout << "\nPress 11 to Insert In List 2: ";
		cout << "\nPress 12 to display List 2:";
		cout << "\nPress 13 to Delete From List 2: "<<endl;*/
		cin >> option;
		switch (option)
		{
		case 1:
			RegisterCar();
			break;
		case 2:
			DisplayAllCars();
			break;
		case 3:
			DisplayType2();	 
			break;
        case 4:
			AddNewRide();	 
			break;
		case 5:
			DisplayRidesDetails();	 
			break;
		case 6:
			DisplayParticularEarnings();
			break;
		case 7:
			DisplayTotalEarnings();
			break;
		case 8:
			//InsertInSortLinkedList();
			break;
		case 9:
			//swapAllNodes();
			break;
		case 10:
			//Merge();
			break;
		case 11:
			//InsertAtEndList2();
			break;
		case 12:
			//displayList2();
			break;
		case 13:
			//DeleteAtEndList2();
			break;
		default:
			cout << "Please Enter Correct Choice";
			break;
		}

	} while (option != 0);
}



