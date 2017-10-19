#include <iostream>
#include <list>
using namespace std;

//
// Created by shovon on 4/1/17.
//


void Permute(int k, list<char> s, list<char> u) {

    for(int i = 0; i < k; i++) {
        s.push_front((char &&)u.front());
        u.pop_front();

        if(k == 1) {
            list<char> tmp(s);
            while(!tmp.empty()) {
                cout << tmp.front();
                tmp.pop_front();
            }
            cout << endl;
        } else {
            Permute(k - 1, s, u);
        }

        u.push_back((char &&)s.front());
        s.pop_front();
    }

}


int main(void) {
    list<char> s;
    s.push_front('A');
    s.push_front('B');
    s.push_front('C');


    list<char> u;


    Permute(3, u, s);

    return 0;
}


