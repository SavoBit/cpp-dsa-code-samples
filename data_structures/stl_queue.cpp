#include <iostream>
#include <queue>

using namespace std;
//
// Created by shovon on 4/3/17.
//




int main(void) {
    queue<int> myQueue;

//    // check if the queue is empty
//    cout << myQueue.empty() << endl;
//


//    // add an element
//    myQueue.push(25);
//
//    cout << myQueue.empty() << endl;




    // adding to the back, and retrieving from the front
    myQueue.push(25);
    myQueue.push(35);
    myQueue.push(45);


    cout << myQueue.back() << endl;

    cout << "size: " << myQueue.size() << endl;


    cout << myQueue.front() << endl;
    myQueue.pop(); // removes the front
    cout << myQueue.front() << endl;
    myQueue.pop(); // removes the front
    cout << myQueue.front() << endl;





    return 0;
}

