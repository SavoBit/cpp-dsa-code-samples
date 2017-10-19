//
// Created by shovon on 4/1/17.
//

#ifndef DSA_RUNTIMEEXCEPTION_H
#define DSA_RUNTIMEEXCEPTION_H

#include <iostream>
using namespace std;

class RuntimeException {
private:
    string errorMsg;
public:
    RuntimeException(const string &e);
    string getMessage() const;
};


#endif //DSA_RUNTIMEEXCEPTION_H
