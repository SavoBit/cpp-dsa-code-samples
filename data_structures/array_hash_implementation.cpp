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

    Person() {}

    string name;
    int studentID;
    string college;
};


class Hash {
public:
    Person get(int id) const {
        return persons[id%10];
    }

    void set(Person p) {
        persons[p.studentID%10] = p;
    }

    void print(int id) const {
        Person p = persons[id%10];
        cout << p.name << endl;
        cout << p.studentID << endl;
        cout << p.college << endl;
    }
private:
    Person persons[10];
};












int main(void) {
    Person p1;
    p1.name = "Shahriar Shovon";
    p1.studentID = 10025;
    p1.college = "KUET";

    Person p2("Shaikat", 10024, "KJST");
    Person p3("Alex", 10024, "SUST");


    Hash personHash;

    personHash.set(p1);
    personHash.set(p2);
    personHash.set(p3); // problem: replaces item

    personHash.print(p1.studentID);

    cout << endl;

    personHash.print(p2.studentID);







    return EXIT_SUCCESS;
}