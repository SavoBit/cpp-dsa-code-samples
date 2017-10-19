//
// Created by shovon on 4/19/17.
//

#include <iostream>
using namespace std;


int main(void) {
    int numbers[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};



    for(int i = 0; i < 10; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;


//    int exec = 0; // for counting the number of inner loop n(n-1)/2, n = 10

    int min;
    for(int i = 0; i < 10; i++) {
        min = i;
        for(int j = i+1; j < 10; j++) {
            if(numbers[j] < numbers[min]) {
                min = j;
            }
//            exec++;
        }

        // swap
        int tmp = numbers[min];
        numbers[min] = numbers[i];
        numbers[i] = tmp;
    }


    for(int i = 0; i < 10; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;


//    cout << "Exec: " << exec << endl;


    return 0;
}