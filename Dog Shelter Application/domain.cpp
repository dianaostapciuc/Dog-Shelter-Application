#include "domain.h"
#include "assert.h"
using namespace std;

Dog::Dog(string breed, string name, int age, string photo)
{
    this->breed = breed;
    this->name = name;
    this->age = age;
    this->photo = photo;
}

string Dog::get_breed()
{
    return this->breed;
}

string Dog::get_name() const {
    return this->name;
}

int Dog::get_age()
{
    return this->age;
}

string Dog::get_photo()
{
    return this->photo;
}

void * Dog::operator new(size_t size) {
    void * pointer = ::operator new(size);
    return pointer;
}

void* Dog::operator new[](size_t size) {
    void* pointer = ::operator new[](size);
    return pointer;
}
bool Dog::operator==(const Dog &dog) const {
    if (this->name.compare(dog.name) == 0)
        if(this->breed.compare(dog.breed) == 0)
            if(this->age == dog.age)
                if(this->photo.compare(dog.photo) == 0)
                    return true;
    return false;
}

Dog::~Dog(){} // resets the values to the initial ones;

string Dog::turn_into_string() const
{
    int age;
    age = this->age;
    string age_string;
    age_string = to_string(age);
    string result;
    result = result + "The dog named " + this->name + " is of breed: " + this->breed + ", of age: " + age_string + " and its link is: " + "\n" + this->photo;
    return result;
}

//void testing_domain()
//{
//    Dog test_dog = Dog("Pit-bull", "Oli", 10, "photo-link");
//    assert(test_dog.get_name() == "Oli");
//    assert(test_dog.get_age() == 10);
//    assert(test_dog.get_photo() == "photo-link");
//    assert(test_dog.get_breed() == "Pit-bull");
//    assert(test_dog.turn_into_string() == "The dog named Oli is of breed: Pit-bull, of age: 10 and its link is: \nphoto-link");
//    auto array = new Dog[2];
//    auto array_2 = new Dog;
//}
