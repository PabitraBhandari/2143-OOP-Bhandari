
/*****************************************************************************
*                    
*  Author:           Pabitra Bhandari
*  Email:            pabitrabhandari19@gmail.com
*  Label:            A04
*  Title:            Commenting Code
*  Course:           CMPS 2143
*  Semester:         FALL 2021
* 
*  Description:
*        commenting this short code. 
* 
*  Usage:
*        none
* 
*  Files:
*        main.cpp
*****************************************************************************/


/************************************/
* CircularArrayQue
*
* Description:
*    This program is using class to run an array based circular queue by removing front items using pop method and adding items
*    by using push method at the rear point of the queue.
*
* Private Methods:
*      void           init(int size = 0)
*      bool           Full()
*
* Public Methods:
*      constructors   CircularArrayQue(),  CircularArrayQue(int size)
*      void          Push(int item)
*      int           Pop()
* Usage:
*
*     CircularArrayQue()            // creates the queue of size ()
*     CircularArrayQue(int size)    // creates the given queue of size ()
*     Push(int item)                // push in int items in the queue
*     Pop()                         // pop out items in the queue
/*************************************************/

#include <iostream>

using namespace std;


class CircularArrayQue {                    // Create class named CircularArrayQue for the queue.
private:                                    // Declaring the class type and data members.
    int *Container;                         // pointer Container to store the data of the queue.
    int Front;                              // Declaring the data type of the front data of the queue.
    int Rear;                               // Declaring the data type of the rear data of the queue.
    int QueSize;                            // items in the queue.
    int CurrentSize;                        // current size of the queue.
    
    void init(int size = 0) {               // void function
        Front = Rear = CurrentSize = 0;     // Inilitializing the value of the front,rear,and current size of the queue to 0
        QueSize = size;
    }

    bool Full() {                           // Checking if the queue is full or not.
        return CurrentSize == QueSize;
    }

public:
    CircularArrayQue() {                    // constructor
        Container = new int[10];            // creating the size '10'
        init(10);                           // initial value of queue is set to 10.
    }
    CircularArrayQue(int size) {            // constructor
        Container = new int[size];          // initilizing the dynamic data type and the size.
        init(size);                         // initial value of queue is set to the size of the queue.
    }

    void Push(int item) {                   // pushing the items into the queue
        if (!Full()) {
            Container[Rear] = item;         // If the queue is not full add the items in the rear points of the queue.
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;                  // increasing the current size of the queue.
        } else {
            cout << "FULL!!!!" << endl;     // If the queue is full then print FULL!!!!
        }
    }

    int Pop() {                             // Removes the items from the front of the queue
        int temp = Container[Front];        // Decalring temp with int data type and initilizing it with front point of the queue.
        Front = (Front + 1) % QueSize;
        CurrentSize--;                      // decreasing the current size of the queue.
        return temp;
    }
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};
ostream &operator<<(ostream &os, const CircularArrayQue &other)
                                           // a friend function operator overload to access the private data member of the class.
{

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize)
                                          // reading through individual item of the queue from the front.
                                        
    {
        os << other.Container[i] << " ";  // output for the other size of the container
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */

int main() {
    CircularArrayQue C1(5); // queue having size of 5

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);            // inserting the items in the queue
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;    // Print items on C1

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;    // Print items on C1
}

