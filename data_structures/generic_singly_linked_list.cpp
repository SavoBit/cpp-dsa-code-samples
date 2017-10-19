#include <iostream>

using namespace std;

// forward declaration
// must be included
template <typename E>
class LinkedList;


template <typename E>
class Node {
private:
    E element;
    Node<E> *next;
    friend class LinkedList<E>;
};


template <typename E>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    bool empty() const;
    void addFront(const E &element);
    const E &removeFront();
    unsigned long long getLength() const;
    const E &front() const;
private:
    Node<E> *head;
    unsigned long long size;
};


template <typename E>
const E &LinkedList<E>::removeFront() {
    Node<E> *tmp = head;
    head = tmp->next;
    delete tmp;

    size--;
}



template <typename E>
const E &LinkedList<E>::front() const {
    return head->element;
}



template <typename E>
unsigned long long LinkedList<E>::getLength() const {
    return size;
}



template <typename E>
void LinkedList<E>::addFront(const E &element) {
    Node<E> *v = new Node<E>;
    v->element = element;
    v->next = head;

    head = v;
    size++;
}



template <typename E>
bool LinkedList<E>::empty() const {
    return (head == NULL);
}


template <typename E>
LinkedList<E>::LinkedList() : head(NULL), size(0) {
    cout << "Initializing Singly Linked List..." << endl;
}

template <typename E>
LinkedList<E>::~LinkedList() {
    cout << "Cleaning up Singly Linked List..." << endl;
    while(!empty()) {
        removeFront();
        size--;
    }
    cout << "Cleaned up." << endl;
}



int main(void) {
//    LinkedList<int> list;
//    list.addFront(5);
//    cout << list.empty() << " " << list.getLength() << endl;






//    LinkedList<int> *list = new LinkedList<int>;
//    cout << list->empty() << endl;
//    cout << list->getLength() << endl;
//    delete list;





//
//    LinkedList<int> *list = new LinkedList<int>;
//
//    cout << "empty: " << list->empty() << endl;
//    cout << "length: " << list->getLength() << endl;
//
//
//
//    for(int i = 1; i <= 25; i+= 2) {
//        list->addFront(i);
//    }
//
//
//    list->removeFront();
//    list->removeFront();
//    cout << list->front() << endl;
//
//    cout << "empty: " << list->empty() << endl;
//    cout << "length: " << list->getLength() << endl;
//
//    delete list;




    LinkedList<int> *list = new LinkedList<int>;
    for(int i = 1; i <= 250; i += 2) {
        list->addFront(i);
    }


    while(!list->empty()) {
        cout << list->front() << " ";
        list->removeFront();
    }

    cout << endl;

    delete list;


    return 0;
}