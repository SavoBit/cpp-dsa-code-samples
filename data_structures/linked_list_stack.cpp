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
//    cout << "Initializing Singly Linked List..." << endl;
}

template <typename E>
LinkedList<E>::~LinkedList() {
//    cout << "Cleaning up Singly Linked List..." << endl;
    while(!empty()) {
        removeFront();
        size--;
    }
//    cout << "Cleaned up." << endl;
}




class StackEmptyException {
public:
    StackEmptyException(string s) {
        msg = s;
    }

    string getMessage() const {
        return msg;
    }

private:
    string msg;
};

template <typename T>
class LinkedStack {
public:
    LinkedStack();
    unsigned int size() const;
    bool empty() const;
    const T &top() const throw(StackEmptyException);
    void push(const T &element);
    void pop() throw(StackEmptyException);
private:
    LinkedList<T> stack;
    unsigned int n;
};




template <typename T>
LinkedStack<T>::LinkedStack():stack(), n(0) {}

template <typename T>
unsigned int LinkedStack<T>::size() const {
    return n;
}

template <typename T>
bool LinkedStack<T>::empty() const {
    return (n == 0);
}

template <typename T>
void LinkedStack<T>::push(const T &element) {
    stack.addFront(element);
    n++;
}


template <typename T>
void LinkedStack<T>::pop() throw(StackEmptyException) {
    if(stack.empty()) {
        throw StackEmptyException("Stack is empty.");
    }

    stack.removeFront();
    n--;
}

template <typename T>
const T &LinkedStack<T>::top() const throw(StackEmptyException) {
    if(stack.empty()) {
        throw StackEmptyException("Stack is empty.");
    }

    return stack.front();
}

int main(void) {

//    LinkedStack<string> words;
//
//    try {
////        words.top();
//        words.push("Programming");
//        words.push("Java");
//
//        words.pop();
//        words.pop();
//
//        cout << words.top() << endl;
//    } catch(const StackEmptyException &e) {
//        cout << e.getMessage() << endl;
//    }








    // reversing array with stack
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


    // before reverse operation
    for(int i = 0; i < 10; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    LinkedStack<int> intStack;

    for(int i =  0; i < 10; i++) {
        intStack.push(numbers[i]);
    }


    for(int i = 0; i < 10; i++) {
        numbers[i] = intStack.top(); // get the top element
        intStack.pop(); // remove the top element
    }


    // after reverse operation
    for(int i = 0; i < 10; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}