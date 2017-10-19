#include <iostream>
#include <string>
using namespace std;
//
// Created by shovon on 4/3/17.
//


class Queue {
public:
    Queue(int cap = DEFAULT_CAPACITY);
    void push(const int &e);
    void pop();
    int front() const;
    bool empty() const;
    unsigned int size() const;
private:
    enum {DEFAULT_CAPACITY = 10};
    int *queue;
    unsigned int capacity;
    unsigned int frontIndex;
    unsigned int backIndex;
    unsigned int length;
};

Queue::Queue(int cap):capacity(cap), queue(new int[cap]),frontIndex(0), backIndex(0), length(0) {}

unsigned int Queue::size() const {
    return length;
}

bool Queue::empty() const {
    return (length == 0);
}

void Queue::push(const int &e) {
    if(size() == capacity) {
        throw string("Queue is full.");
    }

    queue[backIndex] = e;
    backIndex++;
    backIndex = (backIndex + 1) % capacity;

    length++;
}

void Queue::pop() {
    if(empty()) {
        throw string("Queue is empty");
    }

    frontIndex++;
    frontIndex = (frontIndex + 1) % capacity;

    length--;
}

int Queue::front() const {
    if(empty()) {
        throw string("Queue is empty");
    }

    return queue[frontIndex];
}


int main(void) {
    Queue myQueue(5);


    myQueue.push(5);
    myQueue.push(6);
    myQueue.push(7);

    myQueue.pop();
    myQueue.push(8);
    myQueue.push(9);
    myQueue.push(10);


    myQueue.pop();
    myQueue.push(11);

    myQueue.pop();
    myQueue.push(12);


    myQueue.pop();
    myQueue.push(13);

//    cout << myQueue.size() << endl;

    cout << myQueue.front() << endl;

    myQueue.pop();
    cout << myQueue.front() << endl;


    myQueue.pop();
    cout << myQueue.front() << endl;

    myQueue.pop();
    cout << myQueue.front() << endl;

    myQueue.pop();
    cout << myQueue.front() << endl;

    return EXIT_SUCCESS;
}
