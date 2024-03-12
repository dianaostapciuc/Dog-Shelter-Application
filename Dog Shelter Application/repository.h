#ifndef A45_XDIANAOST_REPOSITORY_H
#define A45_XDIANAOST_REPOSITORY_H

#endif //A45_XDIANAOST_REPOSITORY_H
#include "domain.h"
#include <vector>

#include "exceptions.h"

class repository
{
protected:
    vector<Dog> array_of_repo;
    vector<Dog> array_of_adopted_dogs;
    vector<Dog> sorted_array_of_dogs;
public:
    // constructor:
    repository(vector<Dog> array_of_repo1, vector<Dog> array_of_adopted_dogs1, vector<Dog> sorted_array_of_dogs1);

    repository();

    //virtual void generating_startup_entries();
    virtual bool check_if_element_exists(Dog dog) const;
    virtual vector<Dog>& get_repo();
    virtual vector<Dog>& get_sorted_repo();
    virtual int get_number_of_dogs();
    virtual int get_number_of_sorted_dogs();
    virtual int get_capacity_of_array();
    virtual bool adding_a_dog(Dog dog);
    virtual void adding_a_dog_to_adopted_list(Dog& dog);
    virtual void adding_a_dog_to_sorted_list(Dog& dog);
    virtual bool deleting_a_dog(int delete_index);
    virtual bool deleting_a_dog_from_sorted_array(int delete_index);
    virtual bool updating_a_dog(int update_index, Dog new_dog);
    virtual string displaying_each_dog(int index);
    virtual string displaying_adoption_list();
    ~repository();
};
void testing_repo();