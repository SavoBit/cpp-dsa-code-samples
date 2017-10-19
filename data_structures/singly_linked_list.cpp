#include <iostream>

using namespace std;


class IntegerNode {
private:
    int element;
    IntegerNode *next;

    friend class IntegerLinkedList;
};

class IntegerLinkedList {
public:
    IntegerLinkedList();
    ~IntegerLinkedList();
    const int &front() const;
    void addFront(const int &value);
    void removeFront();
    bool isEmpty();
    void move();
    bool isLast();
    void reset();
    const int &value() const;
    bool search(int element);
private:
    IntegerNode *head;
    IntegerNode *current;
};


bool IntegerLinkedList::search(int element) {
    IntegerNode *tmp = head;
    while(tmp != NULL) {
        if(tmp->element == element) {
            current = tmp;
            break;
        }
        tmp = tmp->next;
    }
}


void IntegerLinkedList::reset() {
    current = head;
}

bool IntegerLinkedList::isLast() {
    return (current == NULL);
}




IntegerLinkedList::IntegerLinkedList() : head(NULL), current(NULL) {}
IntegerLinkedList::~IntegerLinkedList() {
    while(!isEmpty()) {
        removeFront();
    }
    head = NULL;
    current = NULL;
}

bool IntegerLinkedList::isEmpty() {
    return (head == NULL);
}


void IntegerLinkedList::addFront(const int &value) {
    IntegerNode *node = new IntegerNode;
    node->element = value;
    node->next = head;
    head = node;
    current = head;
}

void IntegerLinkedList::removeFront() {
    IntegerNode *old = head;

    if(current == head) {
        current = old->next;
    }

    head = old->next;
    delete old;
}


const int &IntegerLinkedList::front() const {
    return head->element;
}

const int &IntegerLinkedList::value() const {
    return current->element;
}


void IntegerLinkedList::move() {
    current = current->next;
}

int main() {
    cout << "Implementations of Singly Linked List." << endl;

    IntegerLinkedList *list = new IntegerLinkedList;

    list->addFront(45);
    list->addFront(50);
    list->addFront(40);
    list->addFront(35);


//    for(int i = 0; i < 3; i++) {
//        cout << list->value() << " ";
//        list->move();
//    }
//    cout << endl;
//
//
//    cout << list->isEmpty() << endl;
//    cout << list->isLast() << endl;
//
//    list->reset();
//
//    cout << list->isLast() << endl;




//    while(!list->isLast()) {
//        cout << list->value() << " ";
//        list->move();
//    }
//    cout << endl;


    if(list->search(450)) {
        cout << "Element found: " << list->value() << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}