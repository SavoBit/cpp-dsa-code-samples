#include <iostream>
using namespace std;

//
// Created by shovon on 4/3/17.
//


class CircleList;

class Node {
private:
    string element;
    Node *next;

    friend class CircleList;
};


class CircleList {
public:
    CircleList();
    ~CircleList();
    CircleList *add(const string &element);
    CircleList *remove();
    const string &front() const;
    const string &back() const;
    bool empty() const;
    CircleList *advance();
private:
    Node *cursor;
};



CircleList *CircleList::remove() {
    Node *tmp = cursor->next;

    if(tmp == cursor) {
        cursor = NULL;
    } else {
        cursor->next = tmp->next;
    }

    delete tmp;
}


CircleList *CircleList::advance() {
    cursor = cursor->next;
}

bool CircleList::empty() const {
    return (cursor == NULL);
}


const string &CircleList::front() const {
    return cursor->next->element;
}

const string &CircleList::back() const {
    return cursor->element;
}


CircleList::CircleList(): cursor(NULL) { }


CircleList::~CircleList() {
    while(!empty()) {
        remove();
    }

    delete cursor;
}

CircleList *CircleList::add(const string &element) {
    Node *n = new Node;
    n->element = element;

    if(cursor == NULL) {
        n->next = n;
        cursor = n;
    } else {
        n->next = cursor->next;
        cursor->next = n;
    }

    return this;
}



class StackEmptyException {
public:
    StackEmptyException(string msg) {
        this->msg = msg;
    }

    string getMessage() const {
        return this->msg;
    }

private:
    string msg;
};



class LinkedQueue {
public:
    LinkedQueue();
    unsigned int size() const;
    bool empty() const;
    const string &front() const throw(StackEmptyException);
    void enqueue(const string &element);
    void dequeue() throw(StackEmptyException);
private:
    CircleList queue;
    unsigned int n;
};




LinkedQueue::LinkedQueue():queue(), n(0) {}


unsigned int LinkedQueue::size() const {
    return n;
}


bool LinkedQueue::empty() const {
    return (n == 0);
}

void LinkedQueue::enqueue(const string &element) {
    queue.add(element);
    queue.advance();
    n++;
}

void LinkedQueue::dequeue() throw(StackEmptyException) {
    if(empty()) {
        throw StackEmptyException("Stack is empty.");
    }

    queue.remove();
    n--;
}

const string& LinkedQueue::front() const throw(StackEmptyException){
    if(empty()) {
        throw StackEmptyException("Stack is empty.");
    }

    return queue.front();
}


int main(void) {

    LinkedQueue queue;


    queue.enqueue("Hello");
    queue.enqueue("World");
    queue.enqueue("Hey");

    queue.dequeue();

    cout << queue.front() << endl;

    return 0;
}