#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    stack<string> words;

    cout << "Empty: " << words.empty() << endl;
    cout << "Size: " << words.size() << endl << endl;




    // adding to stack
    words.push("Hello");
    words.push("Blue");

    cout << "Empty: " << words.empty() << endl;
    cout << "Size: " << words.size() << endl << endl;



    // top element
    cout << words.top() << endl << endl;

    // remove the top element
    words.pop();


    // print the next top element
    cout << words.top() << endl << endl;



    cout << "Empty: " << words.empty() << endl;
    cout << "Size: " << words.size() << endl << endl;


    return EXIT_SUCCESS;
}