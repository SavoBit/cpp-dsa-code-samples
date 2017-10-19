//
// Created by shovon on 4/1/17.
//

#include "RuntimeException.h"
RuntimeException::RuntimeException(const string &e) {
    errorMsg = e;
}


string RuntimeException::getMessage() const {
    return errorMsg;
}