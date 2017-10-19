#include <iostream>
using namespace std;

class CircleList;

class Node {
private:
    string element;
    Node *next;

    friend class CircleList;
};


class CircleList {
public:
    CircleList();
    ~CircleList();
    CircleList *add(const string &element);
    CircleList *remove();
    const string &front() const;
    const string &back() const;
    bool empty() const;
    CircleList *advance();
private:
    Node *cursor;
};



CircleList *CircleList::remove() {
    Node *tmp = cursor->next;

    if(tmp == cursor) {
        cursor = NULL;
    } else {
        cursor->next = tmp->next;
    }

    delete tmp;
}


CircleList *CircleList::advance() {
    cursor = cursor->next;
}

bool CircleList::empty() const {
    return (cursor == NULL);
}


const string &CircleList::front() const {
    return cursor->next->element;
}

const string &CircleList::back() const {
    return cursor->element;
}


CircleList::CircleList(): cursor(NULL) { }


CircleList::~CircleList() {
    while(!empty()) {
        remove();
    }

    delete cursor;
}

CircleList *CircleList::add(const string &element) {
    Node *n = new Node;
    n->element = element;

    if(cursor == NULL) {
        n->next = n;
        cursor = n;
    } else {
        n->next = cursor->next;
        cursor->next = n;
    }

    return this;
}





int main(void) {
    CircleList *list = new CircleList;
    list->add("Fox")->add("Hen")->add("Dog")->add("Cat");

//    cout << list->front() << endl;

//    list->advance()->advance()->advance()->advance()->advance();



//    list->advance()->advance()->advance();
//    cout << list->front() << endl;
//    cout << list->back() << endl;
//

//    for(int i = 0; i < 10; i++) {
//        cout << list->front() << " " << list->back() << endl;
//        list->advance();
//    }




    while(!list->empty()) {
        cout << list->front() << endl;
        list->remove();
    }



    return EXIT_SUCCESS;
}