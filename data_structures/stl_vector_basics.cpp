#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//
// Created by shovon on 4/2/17.
//


int vectorSum(const vector<int> &v) {
    int total = 0;

    for(int i = 0; i < v.size(); i++) {
        total += v[i];
    }

    return total;
}


int vectorSum2(const vector<int> &v) {
    int total = 0;

    for(vector<int>::const_iterator p = v.begin(); p != v.end(); ++p) {
        total += *p;
    }

    return total;
}


int vectorSum3(vector<int> v) {
    int total = 0;

    for(vector<int>::iterator p = v.begin(); p != v.end(); ++p) {
        total += *p;
    }

    return total;
}

int main(void) {
//    vector<int> v = {1, 2, 3};


//
//    // get the size
//    cout << "size: " << v.size() << endl;
//
//
//    // access specific element
//    cout << "element at index 2: " << v.at(2) << " " << v[2] << endl;
//
//
//    // inserting at specific location
//    auto v_it = v.begin();
//
//    v.insert(v_it + 1, 25);
//
//    v_it = v.end();
//    v.insert(v_it, 20);
//
//
//    // iterate through the vector
//    for(int n : v) {
//        cout << n << endl;
//    }


//
//    cout << "Total: " << vectorSum(v) << endl;
//    cout << "Total: " << vectorSum2(v) << endl;
//    cout << "Total: " << vectorSum3(v) << endl;








    int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

//    sort(a, a + 10);


    vector<int> v(a, a+10);


//    sort(v.begin(), v.end());

    random_shuffle(v.begin(), v.end());

//    v.push_back(11);
//    v.insert(v.begin(), 0);

//    cout << v.front() << endl;
//    cout << v.back() << endl;

    for(vector<int>::iterator p = v.begin(); p != v.end(); ++p) {
        cout << *p << " ";
    }
    cout << endl;

    return EXIT_SUCCESS;
}

