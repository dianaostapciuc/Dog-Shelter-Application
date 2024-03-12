//
// Created by Cristi on 5/9/2023.
//

#include "validators.h"

bool validators::validate_age(int age) {
    if (age<=0 or age >20)
        throw exception_validator("Age invalid.\n");
    return true;
}
bool validators::validate_breed(string breed) {
    for (int i = 0; i <breed.length(); i++)
        if (isdigit(breed[i]) == true)
            throw exception_validator("Breed invalid.\n");
    return true;
}
bool validators::validate_name(string name) {
    for (int i = 0; i <name.length(); i++)
        if (isdigit(name[i]) == true)
            throw exception_validator("Name invalid.\n");
    return true;
}
bool validators::validate_link(string link) {
    if(link.length() < 13)
        throw exception_validator("Invalid link length.\n");
    if(link[0] != 'h' || link[1] != 't' || link[2] != 't' || link[3] != 'p' ||
       link[4] != 's' || link[5] != ':' || link[6] != '/' || link[7] != '/')
        throw exception_validator("Invalid link!\n");
    return true;
}
bool validators::validate_listing(string list) {
    if (list.compare("html") == 0 or list.compare("csv") == 0)
        return true;
    else throw exception_validator("Invalid listing.\n");
}