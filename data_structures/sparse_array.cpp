//
// Created by shovon on 4/14/17.
//


#include <iostream>
#include <iomanip>
using namespace std;


class SparseArray {
public:
    SparseArray() {
        defaultValue = 0;
        array = NULL;
        n = 0;
    }
    void set(int row, int col, int value);
    int get(int row, int col) const;
    unsigned long long length() const;
private:
    struct ColCell {
        unsigned long long colNumber;
        ColCell *nextCell;
        int value;
    };


    struct RowCell {
        unsigned long long rowNumber;
        RowCell *nextRow;
        ColCell *data;
    };


    unsigned long long n;
    int defaultValue;
    RowCell *array;
};



unsigned long long SparseArray::length() const {
    return n;
}



int SparseArray::get(int row, int col) const {
    RowCell *tmpRowCell = array;

    while(tmpRowCell != NULL) {
        if(tmpRowCell->rowNumber == row) {
            break;
        }

        tmpRowCell = tmpRowCell->nextRow;
    }

    if(tmpRowCell == NULL) {
        return defaultValue;
    }


    ColCell *tmpColCell = tmpRowCell->data;

    while(tmpColCell != NULL) {
        if(tmpColCell->colNumber == col) {
            break;
        }

        tmpColCell = tmpColCell->nextCell;
    }

    if(tmpColCell == NULL) {
        return defaultValue;
    }

    return tmpColCell->value;;
}


void SparseArray::set(int row, int col, int value) {
    n++;


    // if the sparse array is empty
    if(array == NULL) {
        RowCell *nRowCell = new RowCell;
        nRowCell->nextRow = NULL;
        nRowCell->rowNumber = row;

        ColCell *nColCell = new ColCell;
        nColCell->nextCell = NULL;
        nColCell->value = value;
        nColCell->colNumber = col;

        nRowCell->data = nColCell;

        array = nRowCell;


        return; // no more action required
    }





    // if the sparse array is not empty
    RowCell *tmpRowCell = array;

    while(tmpRowCell != NULL) {
        if(tmpRowCell->rowNumber == row) {
            break;
        }

        tmpRowCell = tmpRowCell->nextRow;
    }

    // row not found, add it to the beginning of the array
    if(tmpRowCell == NULL) {
        RowCell *nRowCell = new RowCell;
        nRowCell->nextRow = array;
        nRowCell->rowNumber = row;


        ColCell *nColCell = new ColCell;
        nColCell->colNumber = col;
        nColCell->value = value;
        nColCell->nextCell = NULL;

        nRowCell->data = nColCell;

        array = nRowCell;

        return;
    }




    // row found, check the columns
    if(tmpRowCell != NULL) {
        ColCell *tmpColCell = tmpRowCell->data;

        while(tmpColCell != NULL) {
            if(tmpColCell->colNumber == col) {
                // column found, change the value
                tmpColCell->value = value;

                break;
            }

            tmpColCell = tmpColCell->nextCell;
        }


        // column not found, add a new column to the front
        if(tmpColCell == NULL) {
            ColCell *nColCell = new ColCell;
            nColCell->value = value;
            nColCell->colNumber = col;
            nColCell->nextCell = tmpRowCell->data;

            tmpRowCell->data = nColCell;
        }

    }
}

int main(void) {

    SparseArray numbers;
    numbers.set(0, 5, 25);
    numbers.set(5, 2, 30);
    numbers.set(5, 6, 36);


    cout << numbers.get(0, 5) << endl;
    cout << numbers.get(5, 2) << endl;
    cout << numbers.get(5, 6) << endl;
    cout << "Length: " << numbers.length() << endl;

    return EXIT_SUCCESS;
}