#include <iostream>
#include "../exceptions/RuntimeException.h"
using namespace std;

//
// Created by shovon on 4/1/17.
//





class StackEmptyException : public RuntimeException {
public:
    StackEmptyException(const string &e) : RuntimeException(e) {}
};

class StackFullException: public RuntimeException {
public:
    StackFullException(const string &e) : RuntimeException(e) {}
};

template <typename T>
class ArrayStack {
public:
    ArrayStack(int cap = DEF_CAPACITY);
    int size() const;
    bool empty() const;
    const T &top() const throw(StackEmptyException);
    void push(const T & e) throw(StackFullException);
    void pop() throw(StackEmptyException);
private:
    enum { DEF_CAPACITY = 100};
    T *stack;
    int capacity;
    int t;
};


template <typename T>
ArrayStack<T>::ArrayStack(int cap):stack(new T[cap]), capacity(cap), t(-1) {}


template <typename T>
int ArrayStack<T>::size() const {
    return t+1;
}

template <typename T>
bool ArrayStack<T>::empty() const {
    return (t == -1);
}



template <typename T>
void ArrayStack<T>::push(const T &e) throw(StackFullException) {
//    cout << "size: " << size() << ", capacity: " << capacity << endl;
    if(size() == capacity) {
        throw StackFullException("StackFullException: Stack is full");
    }

    stack[++t] = e;
}


template <typename T>
const T &ArrayStack<T>::top() const throw(StackEmptyException) {
    if(empty()) {
        throw StackEmptyException("StackEmptyException: Stack is empty");
    }

    return stack[t];
}


template <typename T>
void ArrayStack<T>::pop() throw(StackEmptyException) {
    if(empty()) {
        throw StackEmptyException("StackEmptyException: Stack is empty");
    }

    t--;
}





int main(void) {
//    ArrayStack<int> stack(5);
//
//    cout << stack.empty() << endl;
//
//    stack.push(54);
//    cout << stack.empty() << endl;
//
//    cout << stack.top() << endl;
//
//
//    stack.push(12);
//    stack.push(50);
//    stack.push(112);
//
//    cout << stack.top() << endl;
//
//    stack.pop();
//
//    cout << stack.top() << endl;
//
//
//    stack.push(120);
//
//    stack.push(74);
//    cout << stack.size() << endl;
//








    ArrayStack<string> words(3);

    try {
        words.push("Baby");
        words.push("Tree");
        words.push("Good");
        words.push("Error");
    } catch (StackFullException &e) {
        cout << e.getMessage() << endl;
    } catch (StackEmptyException &e) {
        cout << e.getMessage() << endl;
    }


    return EXIT_SUCCESS;
}