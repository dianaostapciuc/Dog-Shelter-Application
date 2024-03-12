//
// Created by Cristi on 5/8/2023.
//

#ifndef A7_XDIANAOST_1_EXCEPTIONS_H
#define A7_XDIANAOST_1_EXCEPTIONS_H

#pragma once
#include <string>
#include <exception>
#include <utility>

using namespace std;

class exceptions: public exception {
protected:
    string message;
public:
    explicit exceptions(string exception_message);
    const char* what() const noexcept override;

};

class exception_validator: public exceptions{
public:
    explicit exception_validator(string exception_message);
};

class exception_repository: public  exceptions{
public:
    explicit exception_repository(string exception_message);
};

#endif //A7_XDIANAOST_1_EXCEPTIONS_H
