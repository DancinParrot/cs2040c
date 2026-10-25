// Assignment 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BST.h"
#include <string>





#include <iostream>


int main() {

    SparseArray arr;
    
    arr.store(5, 123);
    arr.store(7, 999);
    std::cout << "Storing 123 into index 5 and 999 into index 7:" << endl;
    std::cout << arr.listString(0,10) << std::endl;

    std::cout << "Replaceing entry with index 7 by 777:" << endl;
    arr.store(7, 777);
    std::cout << arr.listString(0, 10) << std::endl;


    arr.store(9223372036854775798,123456);
    arr.store(9223372036854775806,9999);
    
    std::cout << "Second Example:" << std::endl;
    std::cout << arr.listString(9223372036854775785, 9223372036854775810) << std::endl;
    std::cout << "Replace one value to 654" << std::endl;
    arr.store(9223372036854775806,654);
    std::cout << arr.listString(9223372036854775785, 9223372036854775810) << std::endl;
   
    return 0;
}

int main2()
{
    

    
/*
    Tree<int> tree;
    tree.insert(2);
    tree.insert(4);
    tree.insert(1);
    tree.insert(0);
    tree.insert(3);
    std::cout << tree.to_string() << std::endl;*/
    return 0;
};
