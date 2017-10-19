//
// Created by shovon on 4/20/17.
//

#include <iostream>
using namespace std;

int main(void) {
    int numbers[] = {1, 9, 9, 6, 7, 5, 7, 2, 1, 9, 4, 2, 3, 1};


    int max = numbers[0];

    for(int i = 1; i < 14; i++) {
        if(numbers[i] > max) {
            max = numbers[i];
        }
    }


    int sorted[max+1] = {0};


    for(int i = 0; i < 14; i++) {
        sorted[numbers[i]]++;
    }


    int k = 0;
    for(int i = 1; i < max+1; i++) {
        while(sorted[i] > 0) {
            numbers[k++] = i;
            sorted[i]--;
        }
    }


    for(int i = i; i < 14; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;




    return 0;
}