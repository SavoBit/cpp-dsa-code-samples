#include <iostream>
using namespace std;

//
// Created by shovon on 4/3/17.
//



class LinkedList;


class Node {
private:
    string element;
    Node *next;
    Node *prev;
    friend class LinkedList;
};



class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    bool empty() const;
    void addFront(const string &element);
    void addBack(const string &element);
    void removeFront();
    void removeBack();
    const string &front() const;
    const string &back() const;
    const unsigned long long length() const;
private:
    Node *head;
    Node *tail;
    unsigned long long size;

protected:
    void add(Node *v, const string &element);
    void remove(Node *v);
};



bool LinkedList::empty() const {
    return (length() == 0);
}


const unsigned long long LinkedList::length() const {
    return size;
}


void LinkedList::addBack(const string &element) {
    add(tail->prev, element);
}


const string &LinkedList::back() const {
    return tail->prev->element;
}

const string &LinkedList::front() const {
    return head->next->element;
}


void LinkedList::addFront(const string &element) {
    add(head, element);
}

void LinkedList::removeFront() {
    remove(head->next);
}

void LinkedList::removeBack() {
    remove(tail->prev);
}

void LinkedList::remove(Node *v) {
    Node *a = v->prev;
    Node *b = v->next;

    a->next = b;
    b->prev = a;

    delete v;

    size--;
}


void LinkedList::add(Node *v, const string &element) {
    Node *a = v->next;

    Node *n = new Node;
    n->element = element;
    n->prev = v;
    n->next = a;

    a->prev = n;
    v->next = n;

    size++;
}



LinkedList::LinkedList():size(0) {
    head = new Node;
    tail = new Node;

    head->next = tail;
    tail->prev = head;
}



LinkedList::~LinkedList() {
    while(!empty()) {
        removeFront();
    }

    delete head;
    delete tail;
}



class DequeEmptyException {
public:
    DequeEmptyException(string msg) {
        this->msg = msg;
    }

    string getMessage() const {
        return this->msg;
    }

private:
    string msg;
};



class LinkedDeque {
public:
    LinkedDeque();
    unsigned int size() const;
    bool empty() const;

    const string &front() const throw(DequeEmptyException);
    const string &back() const throw(DequeEmptyException);

    void insertFront(const string &element);
    void insertBack(const string &element);

    void removeFront() throw(DequeEmptyException);
    void removeBack() throw(DequeEmptyException);

private:
    LinkedList queue;
};



LinkedDeque::LinkedDeque():queue() {}

bool LinkedDeque::empty() const {
    return queue.empty();
}

unsigned int LinkedDeque::size() const {
    return queue.length();
}


const string& LinkedDeque::front() const throw(DequeEmptyException) {
    if(empty()) {
        throw DequeEmptyException("Deque is empty.");
    }

    return queue.front();
}

const string& LinkedDeque::back() const throw(DequeEmptyException){
    if(empty()) {
        throw DequeEmptyException("Deque is empty.");
    }

    return queue.back();
}



void LinkedDeque::insertFront(const string &element) {
    queue.addFront(element);
}

void LinkedDeque::insertBack(const string &element) {
    queue.addBack(element);
}


void LinkedDeque::removeFront() throw(DequeEmptyException) {
    if(empty()) {
        throw DequeEmptyException("Deque is empty.");
    }

    queue.removeFront();
}


void LinkedDeque::removeBack() throw(DequeEmptyException) {
    if(empty()) {
        throw DequeEmptyException("Deque is empty.");
    }

    queue.removeBack();
}







class DequeStackEmptyException : public DequeEmptyException {
public:
    DequeStackEmptyException(string msg) : DequeEmptyException(msg) {}
};


class DequeStack {
public:
    DequeStack();
    void pop() throw(DequeStackEmptyException);
    const string &top() const throw(DequeStackEmptyException);
    void push(const string &element);
    bool empty() const;
    unsigned int size() const;
private:
    LinkedDeque queue;
};


DequeStack::DequeStack():queue() {}

bool DequeStack::empty() const {
    return queue.empty();
}

unsigned int DequeStack::size() const {
    return queue.size();
}

void DequeStack::push(const string &element) {
    queue.insertFront(element);
}

void DequeStack::pop() throw(DequeStackEmptyException) {
    if(queue.empty()) {
        throw DequeEmptyException("Stack is empty.");
    }

    queue.removeFront();
}

const string &DequeStack::top() const throw(DequeStackEmptyException) {
    if(queue.empty()) {
        throw DequeEmptyException("Stack is empty.");
    }

    queue.front();
}





int main(void) {
    LinkedDeque deque;

    deque.insertFront("Hello");
    deque.insertBack("World");


    cout << deque.front() << endl;



    return EXIT_SUCCESS;
}