#include <iostream>
using namespace std;

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


bool LinkedList::empty() const {
    return (head->next == tail);
}



int main(void) {
    LinkedList *list = new LinkedList;


    list->addFront("Shovon");
    list->addBack("Shaikat");
    list->addBack("Sayma");

    cout << list->front() << endl;
    cout << list->back() << endl;
    cout << "Length: " << list->length() << endl;

    list->removeBack();

    cout << list->front() << endl;
    cout << list->back() << endl;
    cout << "Length: " << list->length() << endl;

    return EXIT_SUCCESS;
}