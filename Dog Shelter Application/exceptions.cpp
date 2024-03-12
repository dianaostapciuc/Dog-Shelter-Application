//
// Created by Cristi on 5/8/2023.
//

#include "exceptions.h"
#include <utility>

exceptions::exceptions(string exception_message){
    this->message = move(exception_message);
}

const char *exceptions::what() const noexcept {
    return this->message.c_str();
}

exception_validator::exception_validator(string exception_message) : exceptions(move(exception_message)){

}

exception_repository::exception_repository(string exception_message) : exceptions(move(exception_message)){

}