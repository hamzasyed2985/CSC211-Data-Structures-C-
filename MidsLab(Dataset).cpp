#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string.h>

using namespace std;

struct Node
{
    string Make;
    string Model;
    int year;
    int horsepower;
    int Cylinders;
    Node *next=NULL;
    Node *prev=NULL;
 
};
struct Node *head = NULL;
struct Node *tail = NULL;

class LinkedStackk
{

public:
LinkedStackk()
{
head = NULL;
tail=NULL;
}
void push(int ch) {
    Node* p = new Node;
    p->horsepower = ch;
    p->next = head;
    p->prev = NULL;
    if (head != NULL) {
        head->prev = p;
    }
    head = p;
}

char pop(){
    char ch;
    Node *p=head;
  if(head==NULL){
    cout<<"Stackk is Empty";}
    else{
        ch=p->horsepower;
        head=head->next;
       if (head != NULL) {
            head->prev = NULL;
        }
    }return ch;
}
Node* top()
    {
        return head;
    }
bool isEmpty()
    {
        if(head==NULL)
        return true;
        else
            return false;
    }
}; 

class Que {
public:
    Que() {
        head = NULL;
        tail = NULL;
    }

    bool is_empty() {
        return (head == NULL);
    }

    void Enque(int x) {
        Node* p = new Node;
        p->Make = x;
        p->next = NULL;
        p->prev = tail;
        
        if (is_empty()) {
            head = p;
        } else {
            tail->next = p;
        }
        
        tail = p;
    }

    void Deque() {
        if (is_empty()) {
            cout << "Queue is already empty" << endl;
        } else {
            Node* temp = head;
            head = head->next;
            
            if (head != NULL) {
                head->prev = NULL;
            } else {
                tail = NULL;
            }
            
            delete temp;
        }
    }

	void display() {
    	Node* curr = head;
    		if (is_empty()) {
        	cout << "Queue is empty" << endl;
    		} 
			else 
			{
        	while (curr != NULL) {
            	cout << "Horsepower is: " << curr->horsepower << endl;
            	curr = curr->next;
        	}
    	}
	}

};

void addNode(string Make, string Model, int year, int horsepower, int cylinders) {
    
    Node* new_node = new Node;
    new_node->Make = Make;
    new_node->Model = Model;
    new_node->year = year;
    new_node->horsepower = horsepower;
    new_node->Cylinders = cylinders;
    new_node->next = NULL;
    new_node->prev = tail;


    if (head == NULL) {
        head = new_node;
        tail = new_node;
        return;
    }

    tail->next = new_node;
    tail = new_node;
}


void print() {
    Node* ptr = head;
    if (ptr == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    cout << "Make , Model , Year , Horsepower , Cylinders" << endl;
    while (ptr != NULL) {
        cout << ptr->Make << " , " << ptr->Model << " , " << ptr->year << " , "<< ptr->horsepower << " , " << ptr->Cylinders << endl;
        ptr = ptr->next;
    }
}


void printbycylinders(int cylinders) {
    Node* ptr = head;
    
    bool cylindersfound = false;

    if (head != NULL) {
        while (ptr) {
            if (ptr->Cylinders == cylinders) {
            	cout << "Make , Model , Year , Horsepower , Cylinders" << endl;
                cout << ptr->Make << " , " << ptr->Model << " , " << ptr->year << " , " << ptr->horsepower << " , " << ptr->Cylinders << endl;
                cylindersfound = true;
            }
            ptr = ptr->next;
        }
    }

    if (!cylindersfound) {
        cout << "Cylinder number not found" << endl;
    }
}


void printbyyear(int y) {
    Node* ptr = head;

    bool yearfound = false;

    if (head != NULL) {
        while (ptr) {
            if (ptr->year == y) {
            	cout << "Make , Model , Year , Horsepower , Cylinders" << endl;
                cout << ptr->Make << " , " << ptr->Model << " , " << ptr->year << " , " << ptr->horsepower << " , " << ptr->Cylinders << endl;
                yearfound = true;
            }
            ptr = ptr->next;
        }
    }

    if (!yearfound) {
        cout << "Year not found" << endl;
    }
}


void printyearGreater(int d) {
    Node* ptr = head;
    bool yearfound = false;

    if (head != NULL) {
        

        while (ptr) {
            if (ptr->year > d) 
			{
            	cout << "Make , Model , Year , Horsepower , Cylinders" << endl;
                cout << ptr->Make << " , " << ptr->Model << " , " << ptr->year << " , " << ptr->horsepower << " , " << ptr->Cylinders << endl;
                yearfound = true;
            }
            ptr = ptr->next;
        }
    }

    if (!yearfound) {
        cout << "No matching years found" << endl;
    }
}



void deleteHorsePowerLess(int d)
{
    Node *ptr = head;
    while (ptr)
    {
        if(ptr->horsepower<d)
        {
        
            if((ptr==head||ptr==tail) && head==tail)
            {
                head=NULL;
                tail=NULL;
            }
      
            else if(ptr==head)
            {
                head=head->next;
                head->prev=NULL;
            }
   
            else if(ptr==tail)
            {
                tail=tail->prev;
                tail->next=NULL;
            }
         
            else
            {
                ptr->prev->next=ptr->next;
                ptr->next->prev=ptr->prev;
            }
        }
        ptr=ptr->next;
    }
}

void SortByName() {

    if (head == nullptr || head->next == nullptr)
        return;

    int count = 0;
    Node* p = head;
    while (p != nullptr) {
        count++;
        p = p->next;
    }

    for (int i = 0; i < count - 1; i++) {
        Node* current = head;
        Node* nextNode = current->next;
        bool swapped = false;

        for (int j = 0; j < count - i - 1; j++) {
            if (current->Make >= nextNode->Make) {
              
                string tempMake = current->Make;
                current->Make = nextNode->Make;
                nextNode->Make = tempMake;

            
                string tempModel = current->Model;
                current->Model = nextNode->Model;
                nextNode->Model = tempModel;

             
                int tempYear = current->year;
                current->year = nextNode->year;
                nextNode->year = tempYear;

        
                int tempHorsepower = current->horsepower;
                current->horsepower = nextNode->horsepower;
                nextNode->horsepower = tempHorsepower;

            
                int tempCylinders = current->Cylinders;
                current->Cylinders = nextNode->Cylinders;
                nextNode->Cylinders = tempCylinders;

                swapped = true;
            }

            current = nextNode;
            nextNode = nextNode->next;
        }

        if (swapped==false)
            break;
    }
}

void SwapNodes(Node* node1, Node* node2) {
    if (node1 == nullptr || node2 == nullptr || node1 == node2)
        return;

  
    if (node1->next == node2) {
        node1->next = node2->next;
        if (node2->next != nullptr)
            node2->next->prev = node1;
        node2->next = node1;
        node1->prev = node2;
    } else if (node2->next == node1) {
        node2->next = node1->next;
        if (node1->next != nullptr)
            node1->next->prev = node2;
        node1->next = node2;
        node2->prev = node1;
    } else {
        Node* temp = node1->next;
        node1->next = node2->next;
        node2->next = temp;

        if (node1->next != nullptr)
            node1->next->prev = node1;
        if (node2->next != nullptr)
            node2->next->prev = node2;

        temp = node1->prev;
        node1->prev = node2->prev;
        node2->prev = temp;

        if (node1->prev != nullptr)
            node1->prev->next = node1;
        if (node2->prev != nullptr)
            node2->prev->next = node2;
    }


    if (head == node1)
        head = node2;
    else if (head == node2)
        head = node1;

    if (tail == node1)
        tail = node2;
    else if (tail == node2)
        tail = node1;
}

void ReverseDisplay(Node* ptr){
    if(ptr==NULL){
        return;
    }
    ReverseDisplay(ptr->next);
    cout<<ptr->Make<<" , "<<ptr->Model<<" , "<<ptr->year<<" , "<<ptr->horsepower<<" , "<<ptr->Cylinders<< endl;
}

void Reverse(){
	Node* curr;
	
	Node *temp;
	curr=head;
    
	while(curr!=NULL){
		temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
	}
    tail=head;
	head=temp->prev;
}






int main()
{
	int years;

    ifstream fin;
    fin.open("cars1.csv");
    string line, word;
    vector<string> lineData;
    int lines = 0;
    while(!fin.eof()){
       
        getline(fin,line);
        stringstream s(line);
        while(getline(s,word,',')){
            lineData.push_back(word);
        }
    
        stringstream s1(lineData[2]);
        int year;
        s1>>year;
        stringstream s2(lineData[3]);
        int horsepower;
        s2>>horsepower;
        stringstream s3(lineData[4]);
        int cylinders;
        s3>>cylinders;
    
        if(lines!=0)
        {
            addNode(lineData[0],lineData[1],year,horsepower,cylinders);
        }
        
        lineData.clear();
        lines++;
    }
    
    int choice = 0;
    do
    {
        cout<<"\n 1.Print information about all Cars"<<endl;
        cout<<"2.Print information about Cars With Specific Cylinders"<<endl;
        cout<<"3.Print information about Cars having Year more than specific Year"<<endl;
        cout<<"4.Delete Cars having Horsepower less than a specific Horsepower"<<endl;
        cout<<"5.Sort Using Name"<<endl;
        cout<<"6.Swap Any Two Nodes"<<endl;
        cout<<"7.Reverse Display"<<endl;
        cout<<"8.Reverse "<<endl;
        cout<<"9.find by specific year "<<endl;
        cout<< "Select an option and 0 to exit:";
        cin>>choice;
        switch(choice)
        {
            case 1 :
            {
                print();
                break;
            }
            case 2 :
            {
                int cylinders;
                cout<<"Enter Numbers of Cylinders :";
                cin>>cylinders;
                printbycylinders(cylinders);
                break;
            }
            case 3 :
            {
                int year;
                cout<<"Enter Year ):";
                cin>>year;
                printyearGreater(year);
                break;
            }
            case 4 :
            {
                int horsepower;
                cout<<"Enter horsepower :";
                cin>>horsepower;
                deleteHorsePowerLess(horsepower);
                break;
            }
            case 5:
            {
                SortByName();
            break;
            }
            case 6:
            {
                Node* curr1=head;
                Node* curr2=head;
                string nam1;
                string nam2;
            cout<<"Enter Model";
            cin>>nam1;
            cout<<"Enter Second Model";
            cin>>nam2;
            while(curr1->Model!=nam1){
			curr1=curr1->next;
		}
	    while(curr2->Model!=nam2){
			curr2=curr2->next;
		}
               SwapNodes(curr1,curr2);
            break;
            }
        case 7:
            {
                cout << "Make , Model , Year , Horsepower , Cylinders" << endl;
                    ReverseDisplay(head);
            break;
            }
        
        	
        case 8:
            {
                    Reverse();
            break;
            }
        case 9:
        	{
        		cout<<"enter the year"<<endl;
        		cin>>years;
        		printbyyear(years);
        		break;
			}
        default:
            {
                cout<<"Invalid choice!"<<endl;
            }
        }
    }
    while(choice!=0);
    return 0;
}