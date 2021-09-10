## 05-P01
## MyVector Program

### Pabitra Bhandari

## Project Description:
The program of MyVector Class is a basic container type of integers that can grow or shrink easily without the need to copy values over to newly allocated memory when resizing.

Initializing the class instance:

From an array
V1 = new MyVector(int *A, int size) : adds each item from an array type

From a file
V1 = new MyVector(string FileName) : read until eof loading each value into list

From another instance of same type (this is known as a Copy Constructor)

V2 = new MyVector(MyVector V1) : traverse other.list adding each value to this.list

Adding items to the class instance:


To the front

V.pushFront(int val) : adds single value to front of this.list

V.pushFront(MyVector V2): adds entire other.list to front of this.list


To the rear

V.pushRear(int val) : adds single value to rear of this.list

V.pushRear(MyVector V2) : adds entire other.list to rear of this.list

At a specified location (if it exists)

V.pushAt(int loc,int val)


Removing items from a class instance:

From the front

val = V.popFront() : removes single value from front of list

From the rear

val = V.popRear() : removes single value from rear of list

A specified location

val = V.popAt(int loc) : removes single value from an indexed location if index between 0 and size of list -1

By a search than removal (if it exists)

loc = V.find(int val) : find location of item (index) if it exists

val = V.popAt(int loc)) : then use index to remove item


### Printing:

Output is similar to: [v1, v2, v3, ... , vn]


### Files:

|   #   | File     | Description                      |
| :---: | -------- | -------------------------------- |
|   1   |[main.cpp](https://github.com/PabitraBhandari/2143-OOP-Bhandari/blob/main/Assigments/05-P01/main.cpp) | Main driver of my list program . |
|   2   | [myvector.hpp](https://github.com/PabitraBhandari/2143-OOP-Bhandari/blob/main/Assigments/05-P01/myvector.hpp)  | Vector Functionalities of my list program.|
| 3     | [banner.txt](https://github.com/PabitraBhandari/2143-OOP-Bhandari/blob/main/Assigments/05-P01/banner.txt) | Banner of the assignment.|
| 4     | [input.dat](https://github.com/PabitraBhandari/2143-OOP-Bhandari/blob/main/Assigments/05-P01/input.dat) |  Inuput Data for the program.|
 | 5 |    [test.out](https://github.com/PabitraBhandari/2143-OOP-Bhandari/blob/main/Assigments/05-P01/test.out) | Output for the user infromation.|

### Instructions:
The code is executable.This program does not require any non standard libraries.

### Common Errors:
There is no actual error. The code is running with warning. 


