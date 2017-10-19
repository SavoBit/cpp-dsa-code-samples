#include <iostream>
using namespace std;


int linearSum(int A[], int n) {
    if(n == 1) {
        return A[0];
    } else {
        return A[n - 1] + linearSum(A, n - 1);
    }
}


void recursiveReverseArray(int A[], int i, int j) {
    if(j > i) {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;

        recursiveReverseArray(A, i+1, j-1);
    }
}


void iterativeReverseArray(int A[], int i, int j) {
    while(i < j) {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
        i++;
        j--;
    }
}


int binarySum(int A[], int i, int n) {
    if(n == 1) {
        return A[i];
    }

    return binarySum(A, i, n/2) + binarySum(A, i + (n/2), n - (n/2));
}




unsigned long long BinFib(int k) {
    if(k <= 1) {
        return k;
    }

    return BinFib(k - 1) + BinFib(k - 2);
}




unsigned long long LinearFibonacci(unsigned int k, unsigned long long nm1 = 1, unsigned long long nm2 = 0) {
    if(k == 0) {
        return nm2;
    }

    if(k == 1) {
        return nm1;
    }

    return LinearFibonacci(k - 1, nm1+nm2, nm1);
}














int main(void) {





//    unsigned long long start;
//    unsigned long long end;
//
//
////    start = time(NULL);
////    for(int i = 0; i <= 40; i++) {
////        cout << BinFib(i) << " ";
////    }
////    cout << endl;
////
////    end = time(NULL);
////    cout << end - start << endl;
//
//
//
//    start = time(NULL);
//
//    for(int i = 0; i <= 1000; i++) {
//        cout << LinearFibonacci(i) << " ";
//    }
//    cout << endl;
//
//    end = time(NULL);
//    cout << end - start << endl;
















//    int numbers[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
//    cout << linearSum(numbers, 20) << endl;



//    int numbers[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
//
//
//    for(int i = 0; i < 20; i++) {
//        cout << numbers[i] << " ";
//    }
//    cout << endl;
//
//    iterativeReverseArray(numbers, 0, 19);
//
//    for(int i = 0; i < 20; i++) {
//        cout << numbers[i] << " ";
//    }
//    cout << endl;




//
//    int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//
//
//
//    cout << "Total: " << binarySum(numbers, 0, 10) << endl;


    return EXIT_SUCCESS;
}