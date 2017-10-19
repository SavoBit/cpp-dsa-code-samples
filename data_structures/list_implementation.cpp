#include <iostream>
using namespace std;
//
// Created by shovon on 4/4/17.
//



class NodeList {
private:
    class Node {
    private:
        int element;
        Node *next;
        Node *prev;

        friend class Iterator;
        friend class NodeList;
    };


public:
    class Iterator {
    public:
        int &operator*();

        bool operator==(const Iterator &p) const;
        bool operator!=(const Iterator &p) const;

        Iterator &operator++();
        Iterator &operator--();

        friend class NodeList;
    private:
        Node *v;
        Iterator(Node *u);
    };


public:
    NodeList();

    int size() const;
    bool empty() const;

    Iterator begin() const;
    Iterator end() const;

    void insertFront(const int &element);
    void insertBack(const int &element);

    void eraseFront();
    void eraseBack();

    void insert(const Iterator &p, const int &element);
    void erase(const Iterator &p);


private:
    int n;
    Node *head;
    Node *tail;
};




NodeList::Iterator::Iterator(Node *u) {
    v = u;
}

int &NodeList::Iterator::operator*() {
    return v->element;
}

bool NodeList::Iterator::operator==(const Iterator &p) const {
    return (v == p.v);
}

bool NodeList::Iterator::operator!=(const Iterator &p) const {
    return (v != p.v);
}


NodeList::Iterator &NodeList::Iterator::operator++() {
    v = v->next;
    return *this;
}

NodeList::Iterator& NodeList::Iterator::operator--() {
    v = v->prev;

    return *this;
}





NodeList::NodeList() {
    n = 0;
    head = new Node;
    tail = new Node;

    head->next = tail;
    tail->prev = head;
}


int NodeList::size() const {
    return n;
}

bool NodeList::empty() const {
    return (n == 0);
}



NodeList::Iterator NodeList::begin() const {
    return Iterator(head->next);
}

NodeList::Iterator NodeList::end() const {
    return Iterator(tail);
}


void NodeList::insert(const Iterator &p, const int &element) {
    Node *w = p.v;
    Node *u = w->prev;

    Node *v = new Node;
    v->element = element;

    v->next = w;
    w->prev = v;

    v->prev = u;
    u->next = v;

    n++;
}

void NodeList::erase(const Iterator &p) {
    Node *w = p.v;
    Node *u = w->prev;
    Node *v = w->next;

    u->next = v;
    v->prev = u;

    delete w;
    n--;
}


void NodeList::insertFront(const int &element) {
    insert(begin(), element);
}

void NodeList::insertBack(const int &element) {
    insert(end(), element);
}

void NodeList::eraseFront() {
    erase(begin());
}

void NodeList::eraseBack() {
    erase(--end());
}



int main(void) {
    NodeList list;

    list.insertFront(54);
    list.insertFront(58);
    list.insertBack(20);

    list.eraseBack();
    list.eraseFront();

    cout << *(list.begin()) << endl;


    return EXIT_SUCCESS;
}

