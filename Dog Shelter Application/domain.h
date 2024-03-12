#ifndef A45_XDIANAOST_DOMAIN_H
#define A45_XDIANAOST_DOMAIN_H

#endif //A45_XDIANAOST_DOMAIN_H
#include <string>
using namespace std;

class Dog
{
    private:
        string breed;
        string name;
        int age;
        string photo;

    public:
    // constructor:
    Dog(string breed = "-", string name = "-", int age = 0, string photo = "-");
    // rest of functions declared
    string get_breed();
    string get_name() const;
    string get_photo();
    int get_age();
    void * operator new(size_t size);
    void* operator new[](size_t size);
    bool operator==(const Dog& dog) const;
    string turn_into_string() const;
    // deconstructor:
    ~Dog();
};
void testing_domain();
