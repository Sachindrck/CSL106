#include <iostream>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;
class Node   // Class Node for declaring pointers
{
public:

    int Phoneno;
    int enrolno;
    string name;
    int n;
    double cgpa;
    vector <string> arr; //arr.push_back("hello")
    Node* next;
    Node* prev;

    Node()
    {

        next = NULL;  //Pointer
        prev = NULL;  //Pointer
    }
};
class Doubly  // Class Doubly for declaring pointers Head and Tail.
{
public:
    Node* head; // Pointer to Head Node
    Node* tail;  // Pointer to Tail Node

    Doubly()
    {
        head = NULL;
        tail = NULL;
    }

    //Function to Insert at Front.
    void Insertatfront(int Phoneno, string name, int enrolno, double cgpa, vector <string> arr,int n)
    {
        Node* temp = new Node();  // New Node formed

        temp -> Phoneno = Phoneno;
        temp -> name = name;
        temp -> enrolno = enrolno;
        temp -> cgpa = cgpa;
        temp -> arr = arr;
        temp->n = n;

        if (head == NULL && tail == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp -> next = head;
            head -> prev = temp;
            head = temp;
        }
    }

    //Function to Insert at Back.
    void Insertatback(int Phoneno, string name, int enrolno, double cgpa, vector <string> arr,int n)
    {
        Node* temp = new Node();  // New Node formed
        temp -> name = name;
        temp -> enrolno = enrolno;
        temp -> Phoneno = Phoneno;
        temp -> cgpa = cgpa;
        temp -> arr = arr;
        temp->n =n;
        temp -> prev = tail;
        tail -> next = temp;
        tail = temp;

    }
    // Sorting on the basis of Enrollment Number.
    void Insertinbetween(int Phoneno, string name, int enrolno, double cgpa, vector <string> arr,int n)
    {
        Node* temp = new Node();  // New Node formed
        temp -> name = name;
        temp -> enrolno = enrolno;
        temp -> Phoneno = Phoneno;
        temp -> cgpa = cgpa;
        temp -> arr = arr;
        temp ->n =n;
        if (head == NULL && tail == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        else if(tail -> enrolno < temp -> enrolno)
        {
            Insertatback(Phoneno, name, enrolno, cgpa, arr,n);
            return;
        }
        else if (head -> enrolno > temp -> enrolno)
        {
            Insertatfront(Phoneno,  name,  enrolno, cgpa, arr,n);
            return;
        }
        else
        {
            Node* temp1 = head;
            while (temp1 -> enrolno <= temp -> enrolno)
            {
                temp1 = temp1 -> next;
            }

            temp -> prev = temp1 -> prev;
            temp -> next = temp1;
            temp1 -> prev -> next = temp;
            temp1 -> prev = temp;
        }

    }
    // Delete Node from Front.
    void Deletefromfront()
    {
        Node* temp = head;
        head = head -> next;
        head -> prev = NULL;
        delete temp;
    }
    // Delete Node from Back.
    void Deletefromback()
    {
        Node* temp = tail;
        tail = tail -> prev;
        tail -> next = NULL;
        delete temp;
    }
    // Delete nth Node whose Enrollment No. is given.
    void Deletenthnode(int n)
    {
        if (tail -> enrolno == n)
        {
            Deletefromback();
        }
        else if (head -> enrolno == n)
        {
            Deletefromfront();
        }
        else
        {
            Node* temp = head;
            while (temp -> enrolno != n)
            {
                temp = temp -> next;
            }
            temp -> next -> prev = temp -> prev;
            temp -> prev -> next = temp -> next;
            delete temp;
        }
    }

    //To print the list from front.
    void PrintListf()
    {
        Node* temp = head;
        cout << "Student database : Accessed from Front"<< endl;
        while (temp != NULL)
        {
            cout << "------------------------------------------------------------------------------------"<<endl;
            cout << "Name : " << temp -> name << endl;
            cout << "Enrollment No. : " << temp -> enrolno << endl;
            cout << "CGPA : " << temp -> cgpa << endl;
            cout << "Phone No. : " << temp -> Phoneno << endl;



            for (int e = 0; e < temp -> n; e++) //To Print Subjects.
            {
                cout << "Subjects Registered :" << temp -> arr[e] << endl;
            }
            temp = temp -> next;
            cout << "------------------------------------------------------------------------------------"<<endl;
        }
       cout << "------------------------------------------------------------------------------------"<<endl;

    }

    //To print the list from back.
    void PrintListb()
    {
        Node* temp = tail;
        cout << "Student database : Accessed from Back" << endl ;
        while (temp != NULL)
        {
            cout << "------------------------------------------------------------------------------------"<<endl;
            cout << "Name : " << temp -> name << endl;
            cout << "Enrollment No. : " << temp -> enrolno << endl;
            cout << "CGPA : " << temp -> cgpa << endl;
            cout << "Phone No. : " << temp -> Phoneno << endl;
            for (int e = 0; e < temp -> n; e++)  //To Print Subjects.
            {
                cout << "Subjects Registered :" << temp -> arr[e] << endl;
            }
            temp = temp -> prev;
            cout << "------------------------------------------------------------------------------------"<<endl;
        }
        cout << "------------------------------------------------------------------------------------"<<endl;
    }

};

//Driver Code.
int main()
{
    cout << "Hello, Welcome to the Record list of students of CSL106!" << endl;
    Doubly DL; //Object

    vector <string> arr; // Array to store Subjects.
    int n;
    cout << "What you want to do :" << endl;
    cout << "1. Insert a Entry. -- press 1 " << endl;
    cout << "2. Delete an Entry. -- press 2 " << endl;
    cout << "3. View the Database -- press 3 " << endl;

    int cc;
    cin >> cc;

    if (cc == 1)
    {
        int i;
        cout << "How many Students entry you want to make: " ;
        cin >> i;
        for (int j =0; j< i; j++)
        {
            string name; //name Variable.
            cout << "Enter first_Name of the Student: " ;
            cin >> name;
            int Enrolno;
            cout << "Enter Enrollment No. of the Student(Last 3-digit.): ";
            cin >> Enrolno;
            double cgpa;
            cout << "Enter CGPA of the Student: ";
            cin >> cgpa;
            long int phoneno;
            cout << "Enter Phone No(Landline). of the Student: ";  // It should be of 6 digits, I am considering only Landline Numbers.
            cin >> phoneno;

            cout << "How many Subjects are registered by the Student: ";
            cin >> n;
            cout << "Enter the Subjects registered by the Student: ";
            for (int i = 0; i < n; i++)
            {
                string ent;
                cin >> ent;
                arr.push_back(ent);

            }

            DL.Insertinbetween(phoneno, name, Enrolno, cgpa, arr,n);  // Inserting into LinkedList.

            arr.clear();


            }

        }
    else if (cc == 2)
    {

        cout << "Which entry you want to delete : Enter it's Enrollment No." << endl;
        int roll;
        cin >> roll;
        DL.Deletenthnode(roll);
        DL.PrintListf();

    }
    else if (cc == 3)
    {
        cout << "Welcome to the Student Database :" << endl ;
        cout <<  "For Forward view press 1" << endl;
        cout <<  "For Reverse view press 2" << endl;
        int ac;
        cin >> ac;
        if (ac == 1)
        {
            DL.PrintListf();
        }
        else
        {
            DL.PrintListb();
        }
    }

    cout << "What you want to do :" << endl;
    cout << "1. Insert a Entry. -- press 1 " << endl;
    cout << "2. Delete an Entry. -- press 2 " << endl;
    cout << "3. View the Database -- press 3 " << endl;

    cin >> cc;

    if (cc == 1)
    {
        int i;
        cout << "How many Students entry you want to make: " ;
        cin >> i;
        for (int j =0; j< i; j++)
        {
            string name;
            cout << "Enter first_Name of the Student: " ;
            cin >> name;
            int Enrolno;
            cout << "Enter Enrollment No. of the Student(Last 3-digit.): ";
            cin >> Enrolno;
            double cgpa;
            cout << "Enter CGPA of the Student: ";
            cin >> cgpa;
            long int phoneno;
            cout << "Enter Phone No(Landline). of the Student: ";  // It should be of 6 digits, I am considering only Landline Numbers.
            cin >> phoneno;

            cout << "How many Subjects are registered by the Student: ";
            cin >> n;
            cout << "Enter the Subjects registered by the Student: ";
            for (int i = 0; i < n; i++)
            {
                string ent;
                cin >> ent;
                arr.push_back(ent);

            }

            DL.Insertinbetween(phoneno, name, Enrolno, cgpa, arr, n); // Inserting into LinkedList.
            arr.clear();
            }


        }
    else if (cc == 2)
    {
        cout << "Which entry you want to delete : Enter it's Enrollment No." << endl;
        int roll;
        cin >> roll;
        DL.Deletenthnode(roll);
        DL.PrintListf();

    }
    else if (cc == 3)
    {

        cout << "Welcome to the Student Database :" << endl ;
        cout <<  "For Forward view press 1" << endl;
        cout <<  "For Reverse view press 2" << endl;
        int ac;
        cin >> ac;
        if (ac == 1)
        {
            DL.PrintListf();
        }
        else
        {
            DL.PrintListb();
        }
    }

    cout << "What you want to do :" << endl;
    cout << "1. Insert a Entry. -- press 1 " << endl;
    cout << "2. Delete an Entry. -- press 2 " << endl;
    cout << "3. View the Database -- press 3 " << endl;

    cin >> cc;

    if (cc == 1)
    {
        int i;
        cout << "How many Students entry you want to make: " ;
        cin >> i;
        for (int j =0; j < i; j++)
        {
            string name;
            cout << "Enter first_Name of the Student: " ;
            cin >> name;
            int Enrolno;
            cout << "Enter Enrollment No. of the Student(Last 3-digit.): "; //Last 3 - digits only.
            cin >> Enrolno;
            double cgpa;
            cout << "Enter CGPA of the Student: ";
            cin >> cgpa;
            int long phoneno;
            cout << "Enter Phone No(Landline). of the Student: "; // It should be of 6 digits, I am considering only Landline Numbers.
            cin >> phoneno;

            int n;
            cout << "How many Subjects are registered by the Student: ";
            cin >> n;
            cout << "Enter the Subjects registered by the Student: ";

            for (int i = 0; i < n; i++)
            {
                string ent;
                cin >> ent;
                arr.push_back(ent);

            }


            DL.Insertinbetween(phoneno, name, Enrolno, cgpa, arr, n);  // Inserting into LinkedList.
            arr.clear();

            }

        }
    else if (cc == 2)
    {
        cout << "Which entry you want to delete : Enter it's Enrollment No." << endl;
        int roll;
        cin >> roll;
        DL.Deletenthnode(roll);
        DL.PrintListf();

    }
    else if (cc == 3)
    {
        cout << "Welcome to the Student Database :" << endl ;
        cout <<  "For Forward view press 1" << endl;
        cout <<  "For Reverse view press 2" << endl;
        int ac;
        cin >> ac;
        if (ac == 1)
        {
            DL.PrintListf();
        }
        else
        {
            DL.PrintListb();
        }
    }




    /*vector <string> arr;
    arr.push_back("sub1");
    arr.push_back("sub2");
    DL.Insertinbetween(224353, "Sachin", 145, 7.8, arr);

    int len = arr.size();
    DL.PrintListf(len);*/
    return 0;

}



