#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// node for our linked list
struct node
{
    int data;                  // data value (could be a lot more values)

    node *next;               // we always need a "link" in a linked list
    node *previous;

    node(int x)
    {                        // constructor to make adding values easy
        data = x;
        next = NULL;
        previous = NULL;
    }
};

class MyVector           //creating the class named MyVector with public and private data members
{
private:
    node *head;
    node *tail;
    int size = 0;

public:
    MyVector()
    {
        head = tail = NULL;
    }

    MyVector(string FileName)
    {
        ifstream fin;       // stream reference
                            //
        fin.open(FileName); // open the file
                            //
        fin >> size;        // get first value which contains the file size
        int dat;

        while (!fin.eof())
        {
            fin >> dat;
            pushFront(dat); // add data into front of the list

            size++;        // increment in size
        }
    }

    MyVector(int A[], int size)
    {
        head = NULL;

        for (int i = 0; i < size; i++)
        {
            pushFront(A[i]);
        }
    }

    MyVector(const MyVector &V1)
    {
        head = tail = NULL;
        node *temp = V1.head;
        while (temp)
        {
            pushRear(temp->data);
            temp = temp->next;
        }
    }

    void pushFront(int x)
    {
        node *temp = new node(x); // create and add value

        if (!head)
        {

            head = tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }

    void pushFront(MyVector V2)
    {
        node *temp = V2.tail;

        while (temp)
        {
            pushRear(temp->data);
            temp = temp->previous;
        }
    }

    void pushRear(int x)
    {
        node *temp = new node(x); //creates new node and add value
        if (!head)
        {

            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void pushRear(MyVector V2)
    {
        node *temp = V2.head;

        while (temp)
        {
            pushRear(temp->data); // print data from node
            temp = temp->next;    // moving to next node
        }
    }

    

    int popRear()
    {
        int cmps = tail->data;
        node *temp = tail;
        tail = tail->previous;
        delete temp;
        return cmps;
    }
    
    int popFront()
    {
        int cmps = head->data;
        node *temp = head;
        head = head->next;
        delete temp;
        return cmps;
    }

    void PushAt(int loc, int val)
    {
        node *temp = head;
        node *newNode;
        newNode->data = val;

        int traVs = 0; // Traversing the linkedlist

        temp = head;
        if (head != NULL)
        {
            while (temp->next != NULL && traVs != loc)
            {
                temp->previous = temp;
                temp = temp->next;
                traVs++;
            }
            if (loc == 0)
            {
                pushFront(val);
            }
            else if (temp->next == NULL && loc == traVs + 1)
            {
                pushRear(val);
            }
            else if (loc > traVs + 1)
                cout << "not valid" << endl;
            else
            {
                temp->next = newNode;
                newNode->next = temp;
            }
        }
    }


    int popAt(int loc)                    // pops the  value
    {
        node *temp = head;
        int pop;

        int traVs = 0;
        if (head != NULL)
        {
            while (temp->next != NULL && traVs != loc)
            {
                temp->previous = temp;
                temp = temp->next;
                traVs++;
            }
            
            if (loc > traVs + 1)
                cout << "not valid" << endl;
            else
            {
                pop = temp->data;
                node *temp2 = temp;
                temp = temp->previous;
                delete temp;
                return pop;
            }
        }
    
};

    int find(int val)                    //finds the value at the list
    {
        node *temp = head;
        int i = 0;

        while (temp)
        {
            if (val == temp->data)
            {
                return i;
            }

            temp = temp->next;
            i++;
        }
        return -1;
    }

    void print()
    {
        node *temp = head;

   cout << "[";
        while (temp)
        {
            cout << temp->data; // print data from node
            
            if (temp->next)
            {
            
                cout << ", ";
            }
            temp = temp->next; // move to next node to print it out
        }
        cout << "]";
        cout << endl;          // end of the print list
    }
};

