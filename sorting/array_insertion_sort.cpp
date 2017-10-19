//
// Created by shovon on 4/18/17.
//

#include <iostream>
using namespace std;

#define LENGTH 100

class SortedArray {
public:
    SortedArray();
    void insert(int value);
    void print() const;
private:
    size_t n;
    int list[LENGTH];
};

SortedArray::SortedArray() {
    n = 0;
}


void SortedArray::insert(int value) {
    if(n == 0) {
        list[n] = value;
        n++;
        return;
    }

    int i = 0;
    while(list[i] < value && i < n) {
        i++;
    }

    for(int j = n; j > i; j--) {
        list[j] = list[j - 1];
    }

    list[i] = value;
    n++;
}


void SortedArray::print() const {
    for(int i = 0; i < n; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}


int main(void) {

//    SortedArray array;
//
//    array.insert(20);
//    array.insert(12);
//    array.insert(25);
//    array.insert(30);
//    array.insert(5);
//    array.insert(100);
//
//
//    array.print();









//    int numbers[] = {9, 5, 2, 8, 1, 3, 4, 7, 6, 10};
//
//    int tmp[10] = {0};
//    size_t tmp_length = 0;
//
//
//    // insertion sort with temporary array
//    for(int i = 0; i < 10; i++) {
//        int k = 0;
//        while(tmp[k] < numbers[i] && k < tmp_length) {
//            k++;
//        }
//
//        for(int j = tmp_length; j > k; j--) {
//            tmp[j] = tmp[j-1];
//        }
//
//        tmp[k] = numbers[i];
//        tmp_length++;
//    }
//
//
//
//
//    for(int i = 0; i < 10; i++) {
//        cout << numbers[i] << " ";
//    }
//    cout << endl;
//
//    for(int i = 0; i < 10; i++) {
//        cout << tmp[i] << " ";
//    }
//    cout << endl;
















//    int numbers[] = {9, 5, 2, 8, 1, 3, 4, 7, 6, 10};
    int numbers[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};



    for(int i = 0; i < 10; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;


    int n = 0; // to keep track of the sorted portion of the array


    // insertion sort with the same array
    for(int i = 0; i < 10; i++) {
        int k = 0;

        while(numbers[k] < numbers[i] && k < n) {
            k++;
        }

        int tmp = numbers[i]; // just after the last element of the sorted portion of the array

        for(int j = n; j > k; j--) {
            numbers[j] = numbers[j - 1];
        }

        numbers[k] = tmp;
        n++;
    }



    for(int i = 0; i < 10; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;





    return EXIT_SUCCESS;
}
