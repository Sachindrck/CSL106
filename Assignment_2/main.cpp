#include <iostream>
#include<chrono>
#include<thread>

using namespace std;
/*
 The user is asked to input the number of customers visiting the restaurant. The size of
 circular table is 5. The customers are seated or made to wait in the queue every 1 second.
 Customers then leave the table every X seconds where X is a random number. When a customer
 leaves the table he is replaced by the first customer in the queue.This goes on till the
 table is empty.
*/
class Node
{
public:
    string namedata;
    Node* next;
    bool type;
    Node(string x,bool typ)        //initializing the name and type(vip or not) of customer waiting in the queue
    {
        type=typ;
        namedata=x;
        next=NULL;
    }
};
class LinkedListQueue //linked list which represents a queue where customers wait if the table is full
{
public:
    Node* head;
    Node* tail;
    LinkedListQueue()
    {
        head=NULL;
        tail=NULL;
    }
    void addfront(string x,bool typ)    //if the customer is a vip add him at the front of the queue
    {
        Node* newnode=new Node(x,typ);
        if(head==NULL)
        {
            head=tail=newnode;
        }
        else if(head->type==false)      //if the first customer isn't a vip
        {
            newnode->next=head;
            head=newnode;
        }
        else                            //if the first customer/s is/are vip/s
        {
            Node* temp=head;
            while(temp->next!=NULL && temp->next->type==true)
            {
                temp=temp->next;
            }
            if(temp->next==NULL)
            {
                tail->next=newnode;
                tail=newnode;
            }
            else
            {
                newnode->next=temp->next;
                temp->next=newnode;
            }
        }

    }
    void addrear(string x,bool typ)     //if the customer is not a vip add him to the end of the queue
    {
        Node* newnode=new Node(x,typ);
        if(tail==NULL)
        {
            tail=head=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
    }
    void deletefront()          //delete the first customer in the queue as he is being moved to the table
    {
            Node* temp=head;
            head=head->next;
            delete temp;
    }
    void print()                // display who all are there in the queue
    {
        Node* temp=head;
        if(temp==NULL)
        {
            cout<<"Queue is empty."<<endl;
        }
        else
        {
            cout<<"People waiting in the queue are:"<<endl;
            while(temp!=NULL)
            {
                cout<<temp->namedata<<"-->";
                temp=temp->next;
            }
            cout<<endl;
        }
        cout<<endl;
    }
};
class CQueue: public LinkedListQueue
{
public:
    int fron;
    int rear;
    string* arr;                //array is used for a circular queue representing a circular table
    int length;
    CQueue(int maxsize)         //initializing table size and front and rear of the circular queue
    {
        fron=rear=-1;
        arr=new string[maxsize];
        length=maxsize;
    }
    void Enqueue(string name,bool type)
    {
        if(fron==-1)            //seating the first customer at the table
        {
            arr[++rear]=name;
            fron++;
        }
        else if(fron==(rear+1)%length)     //in case the table is full
        {
            cout<<"Table is full."<<endl;
            if(type==true)                 //if the next customer is a vip
            {
                addfront(name,type);
            }
            else                           //if the next customer is not a vip
            {
                addrear(name,type);
            }
        }
        else                       //seating the next customers when table is not full
         {
             rear=(rear+1)%length;
             arr[rear]=name;
         }
    }
    void Dequeue()              //customers leave the table
    {
        if(fron==-1)            //when the table is empty
        {
            cout<<"Noone is sitting at the table"<<endl;
        }
        else if(fron==rear)        //only one customer is at the table
        {
            cout<<arr[fron]<<" has left the table."<<endl;
            fron=-1;
            rear=-1;
        }
        else                    //customers are at the table
        {
            cout<<arr[fron]<<" has left the table."<<endl;
            fron=(fron+1)%length;
        }
        if(head!=NULL)          //if the queue is not empty then make the first customer in the queue to sit at the table
        {
            Enqueue(head->namedata,head->type);
            deletefront();
        }
    }
    void traverse()             //displaying which customers are seated at the table
    {
        if(fron==-1)
        {
            cout<<"Noone is sitting at the table."<<endl;
        }
        else
        {
            int temp=fron;
            cout<<"People seated at the table are:"<<endl;
            do
            {
                cout<<arr[temp]<<endl;
                temp=(temp+1)%length;
            }while(temp!=(rear+1)%length);
        }
    }
};


int main()
{
    cout<<"Restaurant is open!!"<<endl;
    int a;
    cout<<"Enter number of customers visiting the restaurant"<<endl;
    cin>>a;
    cout<<"Size of circular table is 5"<<endl;
    CQueue obj(5);

    srand(unsigned(time(0)));
    string name;
    bool vip;
    int random1;
    string customers[]={"Venkat","Sachin","Piyush","AK","Atharva","Jayesh","Aman","Ram","Navdeep","Sailesh"}; //list of customer names

    for(int i=0;i<a;i++)
    {
        random1=0+rand()%(10); //random value to decide which customer enters restaurant
        vip=(0+rand()%(2));     //random value to decide if customer is vip or not
        obj.Enqueue(customers[random1],vip);
        obj.traverse();
        obj.print();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));    //predefined code which uses libraries chrono and thread which pauses the program for 1 second
    }

    int random;
    while(obj.fron!=-1)  //to execute till the table is empty
    {
        random=1+rand()%(5);  //random vale to decide after how long a customer will leave the table
        std::this_thread::sleep_for(std::chrono::milliseconds(random*1000));
        obj.Dequeue();
        obj.traverse();
        obj.print();
    }
    cout<<"Restaurant is closed!!!"<<endl;
    return 0;
}

