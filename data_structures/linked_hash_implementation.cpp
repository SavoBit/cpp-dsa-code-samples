//
// Created by shovon on 4/15/17.
//

#include <iostream>
using namespace std;




class Person {
public:
    Person(string name, int studentID, string college) {
        this->name = name;
        this->studentID = studentID;
        this->college = college;
    }

    void print() {
        cout << name << endl;
        cout << studentID << endl;
        cout << college << endl << endl;
    }

    Person() {}

    string name;
    int studentID;
    string college;
};


class LinkedHashEntry {
public:
    LinkedHashEntry(Person *p) {
        this->p = p;
        this->next = NULL;
    }

    Person *get() const {
        return p;
    }

    void set(Person *p) {
        this->p = p;
    }

    LinkedHashEntry *getNext() {
        return next;
    }

    void setNext(LinkedHashEntry *next) {
        this->next = next;
    }
private:
    Person *p;
    LinkedHashEntry *next;
};



const int TABLE_SIZE = 10;

class HashMap {
public:
    HashMap() {
        table = new LinkedHashEntry*[TABLE_SIZE];

        for(int i = 0; i < TABLE_SIZE; i++) {
            table[i] = NULL;
        }
    }


    Person *get(int key) {
        int hash = key % TABLE_SIZE;

        if(table[hash] == NULL) {
            return NULL;
        } else {
            LinkedHashEntry *entry = table[hash];

            while(entry != NULL && entry->get()->studentID != key) {
                entry = entry->getNext();
            }

            if(entry == NULL) {
                return NULL;
            } else {
                return entry->get();
            }
        }
    }


    void set(Person *p) {
        int hash = p->studentID % TABLE_SIZE;


        if(table[hash] == NULL) {
            table[hash] = new LinkedHashEntry(p);
        } else {
            LinkedHashEntry *entry = table[hash];

            while(entry->getNext() != NULL) {
                entry = entry->getNext();
            }

            if(entry->get()->studentID == p->studentID) {
                entry->set(p);
            } else {
                entry->setNext(new LinkedHashEntry(p));
            }
        }
    }
private:
    LinkedHashEntry **table;
};



int main(void) {
    HashMap map;

    map.set(new Person("Shovon", 151, "KUET"));
    map.set(new Person("Shaikat", 152, "KST"));
    map.set(new Person("Alex", 112, "SUST"));

    map.get(151)->print();
    map.get(152)->print();
    map.get(112)->print();

    return EXIT_SUCCESS;
}