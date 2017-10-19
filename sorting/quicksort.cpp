#include <iostream>
using namespace std;





void quickSort(int arr[], int left, int right) {

    int i = left, j = right;

    int tmp;

    int pivot = arr[(left + right) / 2];



    /* partition */

    while (i <= j) {

        while (arr[i] < pivot)

            i++;

        while (arr[j] > pivot)

            j--;

        if (i <= j) {

            tmp = arr[i];

            arr[i] = arr[j];

            arr[j] = tmp;

            i++;

            j--;

        }

    };


//  // DEBUG
//    for(int k = 0; k < 7; k++) {
//        cout << arr[k] << " ";
//    }
//    cout << endl;



    /* recursion */

    if (left < j)

        quickSort(arr, left, j);

    if (i < right)

        quickSort(arr, i, right);

}


int main(void) {
//    // 1ST PASS:
//    // USING DIFFERENT ARRAY
//    //-------------------------------------------------------------------------
//    int numbers[] = {4, 9, 3, 7, 8, 2, 1};
//
//
//    int base = numbers[0];
//
//    int halfSort[7];
//
//    int left, right;
//    left = 0; right = 6;
//
//    for(int i = 1; i < 7; i++) {
//        if(numbers[i] < base) {
//            halfSort[left++] = numbers[i];
//        }
//
//        if(numbers[i] > base) {
//            halfSort[right--] = numbers[i];
//        }
//    }
//
//    halfSort[left] = base;
//
//
//    for(int i = 0; i < 7; i++) {
//        cout << numbers[i] << " ";
//    }
//    cout << endl;
//
//    for(int i = 0; i < 7; i++) {
//        cout << halfSort[i] << " ";
//    }
//    cout << endl;
//
//
//
//
//    //-------------------------------------------------------------------------





//
//    // 1ST PASS
//    // USING THE SAME ARRAY
//    //-------------------------------------------------------------------------
//    int numbers[] = {4, 9, 3, 7, 8, 2, 1};
//
//
//    int base = numbers[0];
//    int left = 1, right = 6;
//    int removedIndex = 0;
//
//    while(left != right) {
//        if(removedIndex < left) {
//            if(numbers[right] < base) {
//                numbers[removedIndex] = numbers[right];
//                removedIndex = right;
//                right--;
//            } else {
//                right--;
//            }
//        }
//
//        if(removedIndex > right) {
//            if(numbers[left] > base) {
//                numbers[removedIndex] = numbers[left];
//                removedIndex = left;
//                left++;
//            } else {
//                left++;
//            }
//        }
//    }
//
//    numbers[removedIndex] = base;
//
//    for(int i = 0; i < 7; i++) {
//        cout << numbers[i] << " ";
//    }
//    cout << endl;
//
//    //-------------------------------------------------------------------------
















    // QUICKSORT RECURSIVE
    //-------------------------------------------------------------------------

    int numbers[] = {4, 9, 3, 7, 8, 2, 1};


    quickSort(numbers, 0, 6);

    for(int i = 0; i < 7; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;



    return EXIT_SUCCESS;
}