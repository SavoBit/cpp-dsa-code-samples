#include <iostream>
#include "RuntimeException.h"
using namespace std;
//
// Created by shovon on 4/1/17.
//

int main(void) {
    try {
        throw new RuntimeException("Hello World");
    } catch(const RuntimeException *e) {
        cout << e->getMessage() << endl;
    }

    try {
        throw RuntimeException("Hello World");
    } catch(const RuntimeException &e) {
        cout << e->getMessage() << endl;
    }



    try {
        throw string("Exception occured");
    } catch (const string &e) {
        cout << e << endl;
    }

    try {
        throw "Exception occured";
    } catch(const char *e) {
        cout << e << endl;
    }

    return EXIT_SUCCESS;
}


