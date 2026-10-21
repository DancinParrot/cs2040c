
#pragma once
#ifndef SUPERLONGINT_H
#define SUPERLONGINT_H


#include <iostream>
#include "LinkedList.h"
// unsigned long long int max approximately 1.8 x 10^19
// max integer is 2,147,483,647 with 10 digits

class SuperLongInt {

protected:
    List _l;

public:
    SuperLongInt(unsigned long long int i);
    SuperLongInt(SuperLongInt a,SuperLongInt b); // create itself as a+b
    
    void showList() {std::cout << _l.to_string() << std::endl;};
    // Converts the container to std::string
    std::string to_string() const;
};

#endif
