//
// Created by shovon on 4/18/17.
//

#include <iostream>
#include <list>
using namespace std;


class SortedLinkedList {
public:
    void insert(int value);
    list<int>::iterator begin();
    list<int>::iterator end();
private:
    list<int> linkedList;
};

void SortedLinkedList::insert(int value) {

    if(linkedList.empty()) {
        linkedList.insert(linkedList.begin(), value);
        return;
    }


    list<int>::iterator i = linkedList.begin();

    while(i != linkedList.end() && *i <= value) {
        i++;
    }

//    cout << (i == linkedList.end()) << endl;

    linkedList.insert(i, value);
}


list<int>::iterator SortedLinkedList::begin() {
    return linkedList.begin();
}

list<int>::iterator SortedLinkedList::end() {
    return linkedList.end();
}



int main(void) {
    SortedLinkedList list;

    list.insert(54);
    list.insert(24);
    list.insert(60);
    list.insert(15);
    list.insert(90);
    list.insert(25);
    list.insert(58);



    for(int n : list) {
        cout << n << " ";
    }
    cout << endl;


    return EXIT_SUCCESS;
}