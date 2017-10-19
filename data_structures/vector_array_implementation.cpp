#include <iostream>
#include "../exceptions/RuntimeException.h"
using namespace std;
//
// Created by shovon on 4/4/17.
//


// Status: FAILED

class IndexOutOfBoundsException : public RuntimeException {
public:
    IndexOutOfBoundsException(string msg) : RuntimeException(msg) {}
};

class NoSuchElementException : public RuntimeException {
public:
    NoSuchElementException(string msg) : RuntimeException(msg) {}
};


class FixedArrayVector {
public:
    FixedArrayVector(int cap = 10);
    int at(int index) const throw(NoSuchElementException);
    void set(int index, int element) throw(NoSuchElementException);
    void insert(int index, int element) throw(IndexOutOfBoundsException);
    void erase(int index) throw(NoSuchElementException);
    int size() const;
    bool empty() const;

private:
    int capacity;
    int n;
    int *vector;
};




FixedArrayVector::FixedArrayVector(int cap):capacity(cap), n(0), vector(new int[cap]) {}


int FixedArrayVector::size() const {
    return n;
}

bool FixedArrayVector::empty() const {
    return (n == 0);
}

int FixedArrayVector::at(int index) const throw(NoSuchElementException) {
    if(index >= size()) {
        throw NoSuchElementException("No element at position " + index);
    }

    return vector[index];
}


void FixedArrayVector::set(int index, int element) throw(NoSuchElementException) {
    if(index >= size()) {
        throw NoSuchElementException("No element at position " + index);
    }

    vector[index] = element;
}


void FixedArrayVector::erase(int index) throw(NoSuchElementException) {
    if(index >= size()) {
        throw NoSuchElementException("No element at position " + index);
    }

    for(int i = index; i < size(); i++) {
        vector[i] = vector[i+1];
    }

    n--;
}


void FixedArrayVector::insert(int index, int element) throw(IndexOutOfBoundsException) {

    if(size() == capacity) {
        throw IndexOutOfBoundsException("Vector is full.");
    }


//    int i = n;
//    while(i >= index) {
//        vector[i + 1] = vector[i];
//        i--;
//    }

    for(int i = n; i >= index; i--) {
        vector[i + 1] = vector[i];
    }

    vector[index] = element;

    n++;

}











//
//class ArrayVector {
//public:
//    ArrayVector();
////    int size() const;
////    bool empty() const;
////    int &operator[](int i);
////    int &at(int i) throw(IndexOutOfBoundsException);
////    void erase(int i);
//    void insert(int i, const int &element);
//    void reserve(int N);
//private:
//    int capacity;
//    int n;
//    int *A;
//};
//
//
//ArrayVector::ArrayVector():capacity(0), n(0), A(NULL) {}
//
//void ArrayVector::reserve(int N) {
//    if(capacity >= N) {
//        return;
//    }
//
//    int *B = new int[N];
//
//    for(int j = 0; j < n; j++) {
//        B[j] = A[j];
//    }
//
//    if(A != NULL) {
//        delete [] A;
//    }
//
//    A = B;
//
//    capacity = N;
//}
//
//
//
//void ArrayVector::insert(int i, const int &element) {
//    if(n >= capacity) {
//        reserve(2 * capacity);
//    }
//
//
//    for(int j = n; j >= i; j-- ) {
//        A[j + 1] = A[j];
//    }
//
//    A[i] = element;
//
//    n++;
//}


class SimpleVector {
public:
    SimpleVector() {
        capacity = 10;
        V = new int[capacity];
        n = 0;
    }

    void insert(int index, const int &element) {
        int i = n;
        while(i >= index) {
            V[i + 1] = V[i];
            i--;
        }

        V[index] = element;

        n++;
    }


    const int &at(int index) {
        return V[index];
    }
private:
    int n;
    int *V;
    int capacity;
};


int main(void) {

    FixedArrayVector vector;

    vector.insert(0, 5); // [5]
    vector.insert(0, 6); // [6 5]
    vector.insert(1, 8); // [6 8 5]

    vector.erase(0);  // [ 8 5 ]
    vector.set(0, 11); // [11 5 ]

    cout << vector.at(0) << endl;
    cout << vector.at(1) << endl;







    return EXIT_SUCCESS;
}