#include <iostream>
#include <fstream>
#include <string>
#define INF 10000000000  //infinity

using namespace std;

template <class M>
class MyVector {
  
  private:

                          // Node for the linked list
    struct node {
      M dat;             // data value

      node* next;       // pointer to point the next node
      node* previous;   // pointer to point the previous node

     
      node(M x, node* n = nullptr, node* p = nullptr) {  // constructor
          dat = x;
          next = n;
          previous = p;
      }
    };

    node* head;       // the head of  list
    node* tail;       // the tail of list

    int CurrentsiZe; // data type of the current size of the vector


  public:

    MyVector() {
      head = nullptr;    // the head of list is assigned as null.
      tail = nullptr;    // the tail of is assigned as null.

      CurrentsiZe = 0; //the current size of the vector is assigned as 0.
    }

    MyVector(M *C, int size) {
      head = nullptr;
      tail = nullptr;

      CurrentsiZe = 0;

      for(int i = 0; i < size; i++) {
        pushRear(C[i]);             //adding the array of i at the rear of the list.
      }
    }

    MyVector(string filename) {    //my vector creating a file.
      head = nullptr;
      tail = nullptr;

      CurrentsiZe = 0;

      ifstream fin;
      fin.open(filename);           //opening the file

      int TemPs;
      while(!fin.eof()) {
        fin >> TemPs;
        pushRear(TemPs);           // adding the value at the rear of the data in the file
      }

    }

    MyVector(const MyVector &V1) {   //initiliazing a MyVector including data of another MyVector into it. (copy cinstructor &V1).
      head = nullptr;
      tail = nullptr;

      CurrentsiZe = 0;

      node* TemPs = V1.head;

      while(TemPs != nullptr) {
        pushRear(TemPs->dat);
        TemPs = TemPs->next;
      }
    }

    ~MyVector() {              //Destructor to delete to get free space.
      node* TemPs = head;
      node* useless;

      while(TemPs != nullptr) {
        useless = TemPs;
        TemPs = TemPs->next;
        delete useless;

      }
    }

    void printSize() {
      cout << CurrentsiZe << endl;   // printing Currentsize
    }


    void pushRear(M numBer) {        //adding number at the end of the list
      
      
      if(head == nullptr) {
        head = new node(numBer);
        tail = head;
                              
        CurrentsiZe++;               //increasing the current size
      }
      else{
        tail->next = new node(numBer, nullptr, tail);// adding a number to the end and moving to the next.
         
        tail = tail->next;            // go to the next at the tail
        CurrentsiZe++;
      }
    }
    void inOrderPush(M numBer) {      //to arrange the list in order by adding the numbers

      int cmp = 0;

      if(head->dat < tail->dat) {       // if the list is in increasing order
        node* TemPs = head;
        while(TemPs->dat < numBer) {
          cmp++;                       // increase the size
          if(cmp == CurrentsiZe) {
            break;
          }
          TemPs = TemPs->next;
        }
        pushAt(cmp, numBer);            // adding the value at the function
      }
      else if(head > tail) {           // if the list is in decreasing order
        node* TemPs = head;
        while(TemPs->dat > numBer) {
          cmp++;                      // decrease the size
          if(cmp == CurrentsiZe) {
            break;
          }
          TemPs = TemPs->next;
        }
        pushAt(cmp, numBer);
      }
    }
    
    void push_rear(M array, int index) {  // M data with the int index of that array
      for(int i = 0; i < index; i++) {
        pushBack(array[i]);              //adding data i from an array on the end of the list.
      }
    }

    void pushRear(MyVector &vector) {  //adding vector to the end of the vector list

      node* TemPs = vector.head;

      
      while(TemPs) {
        pushRear(TemPs->dat);       //adding the data to the end of the list using push method

        TemPs = TemPs->next;        //go to next one

      }
      
    }
    void pushFront(M numBer) {       //adding numbers to the front
      
      
      if(head == nullptr) {
        head = new node(numBer);
        tail = head;
                              
        CurrentsiZe++;                //increasing the current size of the vector
      }
      else {
        head->previous = new node(numBer, head);
        head = head->previous;
                                              
        CurrentsiZe++;
      }
    }
    
    void pushFront(MyVector &vector) {     //adding vector to the front of the vector list
      node* TemPs = vector.tail;

      
      while(TemPs) {
        pushFront(TemPs->dat);             //adding the data to the front of the list

        TemPs = TemPs->previous;           //go to previous item

      }
    }

    bool pushAt(int cmp, M numBer) {        // adding a number at certain place at the list
      
      if(cmp > CurrentsiZe || cmp < 0) {     // bool condition
        return false;
      }
      else {
        if(cmp == 0) {
          pushFront(numBer);
        }
        else if (cmp == CurrentsiZe) {
          pushRear(numBer);
        }

        else {
          
          node* TemPs = head;
          for(int i = 0; i < cmp; i++) {       //list transversing to add value
            TemPs = TemPs->next;
          }

          node* OtherTemPs = TemPs->previous;
          TemPs->previous = new node(numBer, TemPs, OtherTemPs);
          OtherTemPs->next = TemPs->previous; //connecting previous and new node
          CurrentsiZe++;
        }
        return true;
      }
      
    }
    
    
    M popFront() {                             //to remove a number from the front of the list using pop method.
      int numBer = head->dat;

      node* TemPs = head;
      head = head->next;
      head->previous = nullptr;
      delete TemPs;

      CurrentsiZe--;                         //decreasing the current size of the list

      return numBer;
    }
    M popRear() {                            //to remove number from the end/tail of the list
      int numBer = tail->dat;    

      node* TemPs = tail;
      tail = tail->previous;
      tail->next = nullptr;
      delete TemPs;

      CurrentsiZe--;

      return numBer;
    }

    M popAt(int cmp) {                          //to remove a number of a certain location in the list
      M numBer;

     
      if(cmp >= CurrentsiZe || cmp < 0) {       //bool condition to retrun true/false
        return false;
      }
      else {
        if(cmp == 0) {
          numBer = popFront();
        }
        else if (cmp == CurrentsiZe-1) {
          numBer = popRear();
        }

        else {
          
          node* TemPs = head;
         
          for(int i = 0; i < cmp; i++) {
            TemPs = TemPs->next;
          }
          numBer = TemPs->dat;
            
          node* useless = TemPs;                              //deleting the useless data
          node* OtherTemPs = TemPs->previous;
          TemPs = useless->next;
          OtherTemPs->next = TemPs;
          TemPs->previous = OtherTemPs;
          delete useless;
          
        }
        CurrentsiZe--;
        return numBer;
      }

    }

    
    int find(M val) {                                 //finding a value for user return
      int cmp = 0;

      node* TemPs = head;
      while(TemPs != nullptr && TemPs->dat != val) {  //searching for the value
        TemPs = TemPs->next;
        cmp++;

      }
      if(cmp == CurrentsiZe) {
        cmp = -1;
      }
      
      return cmp;
    }

    void print(ofstream &outfile) {  //printing the data in the file
      node* TemPs = head;

     
      cout << "[";
      while(TemPs->next != nullptr) {
        cout << TemPs->dat << ", ";
        TemPs = TemPs->next;
      }
      cout << TemPs->dat << "]" <<endl;

      
      TemPs = head;
      outfile << "[";
      while(TemPs->next != nullptr) {
        outfile << TemPs->dat << ", ";
        TemPs = TemPs->next;
      }
      outfile << TemPs->dat << "]" <<endl;  //  Printing the data of the outfile
      
    }

    void printBack(ofstream &outfile) { //printing the data from the back of the list
      node* TemPs = tail;

      cout << "[";
      while(TemPs->previous != nullptr) {
        cout << TemPs->dat << ", ";
        TemPs = TemPs->previous;
      }
      cout << TemPs->dat << "]" <<endl;

      TemPs = tail;
      outfile << "[";
      while(TemPs->previous != nullptr) {
        outfile << TemPs->dat << ", ";
        TemPs = TemPs->previous;
      }
      outfile << TemPs->dat << "]" <<endl;
    }

    M &operator[](int cmp) {         //using overloaded array operator
      node* TemPs = this->head;
      
     
      if(cmp >=this->CurrentsiZe || cmp < 0) {
        cout << "cmps is on"<<endl;
        exit(0);
      }
      else {
        for(int i = 0; i < cmp; i++) {
          TemPs = TemPs->next;
        }
      }
      return TemPs->dat;      //returning the data
      
    }

    friend ostream &operator<<(ostream& out, const MyVector& vector) {
//using friend function to access the private data member.Also, overloading operator

      node* TemPs = vector.head;

      out << "[";
      while(TemPs->next != nullptr) {
        out << TemPs->dat << ", ";
        TemPs = TemPs->next;
      }
      out << TemPs->dat << "]";

      return out;
    }
    friend ofstream &operator<<(ofstream& out, const MyVector& vector) {

      node* TemPs = vector.head;

      out << "[";
      while(TemPs->next != nullptr) {
        out << TemPs->dat << ", ";
        TemPs = TemPs->next;
      }
      out << TemPs->dat << "]";

      return out;
    }
    
    MyVector operator-(MyVector& other) {   //subtract one vector from other using - operator
      MyVector AssiGned;
      node* TemPs = this->head;
      node* OtherTemPs = other.head;

      int MiniMum;

      bool MaxiMum = false;

      if(this->CurrentsiZe >= other.CurrentsiZe) {
        MiniMum = other.CurrentsiZe;
      }
      else {
        MiniMum = this->CurrentsiZe;
        MaxiMum = true;
      }

      for(int i = 0; i < MiniMum; i++) {   //for loop

        AssiGned.pushRear(TemPs->dat - OtherTemPs->dat);
        TemPs = TemPs->next;
        OtherTemPs = OtherTemPs->next;
      }

      if(MaxiMum) {
        for(int i = MiniMum; i < other.CurrentsiZe; i++) {
          AssiGned.pushRear(other[i]);
        }
      }
      else {
        for(int i = MiniMum; i < this->CurrentsiZe; i++) {
          
          AssiGned.pushRear(TemPs->dat);
          if(TemPs->next != nullptr)
            TemPs = TemPs->next;
        }
      }

      return AssiGned;
    }
    
    MyVector operator+(MyVector& other) {  //adding two vectors using + operator
      MyVector AssiGned;                   // new type of vector
      node* TemPs = this->head;
      node* OtherTemPs = other.head;

      int MiniMum;                        // Munimum vector

      bool MaxiMum = false;               // bool for maximum vector

      if(this->CurrentsiZe >= other.CurrentsiZe) {
        MiniMum = other.CurrentsiZe;
      }
      else {
        MiniMum = this->CurrentsiZe;
        MaxiMum = true;
      }

      for(int i = 0; i < MiniMum; i++) {
        AssiGned.pushRear(TemPs->dat + OtherTemPs->dat);  // adding the two vectors data
        TemPs = TemPs->next;
        OtherTemPs = OtherTemPs->next;
      }
      if(MaxiMum) {
        for(int i = MiniMum; i < other.CurrentsiZe; i++) {
          AssiGned.pushRear(other[i]);
          
        }
      }
      else {
        for(int i = MiniMum; i < this->CurrentsiZe; i++) {
          AssiGned.pushRear(TemPs->dat);
          if(TemPs->next != nullptr)
            TemPs = TemPs->next;
        }
      }

      return AssiGned;
    }

    MyVector operator*(MyVector& other) {    //multiplying two vectros using * operator
      MyVector AssiGned;
      node* TemPs = this->head;
      node* OtherTemPs = other.head;

      int MiniMum;

      bool MaxiMum = false;

      if(this->CurrentsiZe >= other.CurrentsiZe) {
        MiniMum = other.CurrentsiZe;
      }
      else {
        MiniMum = this->CurrentsiZe;
        MaxiMum = true;
      }
      for(int i = 0; i < MiniMum; i++) {
        AssiGned.pushRear(TemPs->dat * OtherTemPs->dat);
        TemPs = TemPs->next;
        OtherTemPs = OtherTemPs->next;
      }
      if(MaxiMum) {
        for(int i = MiniMum; i < other.CurrentsiZe; i++) {
          AssiGned.pushRear(other[i]);
        }
      }
      else {
        for(int i = MiniMum; i < this->CurrentsiZe; i++) {
          
          AssiGned.pushRear(TemPs->dat);
          if(TemPs->next != nullptr)
            TemPs = TemPs->next;
        }
      }

      return AssiGned;
    }
    MyVector operator/(MyVector& other) {    //dividing one vector by other using / operator
      MyVector AssiGned;
      node* TemPs = this->head;
      node* OtherTemPs = other.head;

      int MiniMum;

      bool MaxiMum = false;
      if(this->CurrentsiZe >= other.CurrentsiZe) {
        MiniMum = other.CurrentsiZe;
      }
      else {
        MiniMum = this->CurrentsiZe;
        MaxiMum = true;
      }
      for(int i = 0; i < MiniMum; i++) {

        if(OtherTemPs->dat == 0){          //checking for undefined ;if dividing by 0.
          cout<<"undefined!"<<endl;
          exit(0);
        }
        AssiGned.pushRear(TemPs->dat / OtherTemPs->dat);
        TemPs = TemPs->next;
        OtherTemPs = OtherTemPs->next;
      }

      if(MaxiMum) {
        for(int i = MiniMum; i < other.CurrentsiZe; i++) {
          AssiGned.pushRear(other[i]);
        }
      }
      else {
        for(int i = MiniMum; i < this->CurrentsiZe; i++) {
          
          AssiGned.pushRear(TemPs->dat);
          if(TemPs->next != nullptr)
            TemPs = TemPs->next;
        }
      }

      return AssiGned;
    }
    bool operator==(MyVector& other) {    //bool chcek for assignment operator; if two vector are equal or not
 
      node* TemPs = this->head;
      node* OtherTemPs = other.head;

      if(this->CurrentsiZe != other.CurrentsiZe) {
        return false;
      }
      else {
        while(TemPs) {                         //while loop
          if(TemPs->dat != OtherTemPs->dat) {
            return false;
          }
          TemPs = TemPs->next;
          OtherTemPs = OtherTemPs->next;
        }
      }
      return true;                           // if they are equal return true.
    }

    MyVector &operator=(const MyVector& vects) {  // implementation of copy constructor

      node* TemPs = head;
      node* useless;
      while(TemPs != nullptr) {
        useless = TemPs;
        TemPs = TemPs->next;
        delete useless;
      }
      head = tail = nullptr;

      node* currentTemPs = vects.head;
    
for (int i = 0; i < vects.CurrentsiZe; i++) {   // the for loop for the vects and the value
        pushRear(currentTemPs->dat);
        currentTemPs = currentTemPs->next;
      }

      this->CurrentsiZe = vects.CurrentsiZe;

      return *this;
    }

};

