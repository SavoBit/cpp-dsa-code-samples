#include <iostream>
#include <vector>
using namespace std;

//
// Created by shovon on 4/2/17.
//

bool matchParen(string code) {
    vector<char> s;

    for(auto c : code) {
        if(c == '(') {
            s.push_back(c);
        } else if(c == ')') {
            if(s.empty()) {
                return false;
            }
            s.pop_back();
        }
    }


    if(s.empty()) {
        return true;
    }

    return false;
}





bool matchMultiParen(string code) {
    vector<char> s;

    for(auto c : code) {
        if(c == '(' || c == '{' || c == '[') {
            s.push_back(c);
        } else if(c == ')' || c == '}' || c == ']') {
            if(s.empty()) {
                return false;
            } else if((s.back() == '(' && c == ')') || (s.back() == '{' && c == '}') || (s.back() == '[' && c == ']')) {
                s.pop_back();
            } else {
                return false;
            }
        }
    }


    if(s.empty()) {
        return true;
    }

    return false;
}


int main(void) {

    cout << matchParen("(Hello (World)))") << endl;
    cout << matchMultiParen("(Hello {Wor[ld]})") << endl;

    return 0;
}

