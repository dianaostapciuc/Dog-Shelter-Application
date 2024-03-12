//
// Created by Cristi on 5/9/2023.
//

#ifndef A7_XDIANAOST_1_VALIDATORS_H
#define A7_XDIANAOST_1_VALIDATORS_H
#include "string"
#include "exceptions.h"
using namespace std;
class validators {
public:
    static bool validate_breed(string breed);
    static bool validate_name(string name);
    static bool validate_age(int age);
    static bool validate_link(string link);
    static bool validate_listing(string list);
};


#endif //A7_XDIANAOST_1_VALIDATORS_H
