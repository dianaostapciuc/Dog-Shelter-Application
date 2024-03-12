#ifndef A45_XDIANAOST_SERVICES_H
#define A45_XDIANAOST_SERVICES_H

#endif //A45_XDIANAOST_SERVICES_H
#include "file_repo.h"
#include "html_repo.h"
#include "csv_repo.h"

class services
{
private:
    file_repo repo;
protected:
    file_repo* listing;
public:
    // constructor:
    services(file_repo repo, file_repo* list_repo, string list);
    // others:
    vector<Dog>& get_services();
    vector<Dog>& get_sorted_services();
    void load_listing();
    void create_list_in_html_or_csv(string listing);
    bool add_service(string breed, string name, int age, string photo);
    void adding_to_adoption_list(Dog dog);
    void sorting_the_array_of_dogs(string breed, int age);
    bool delete_service(string name);
    bool delete_dog_from_sorted_list(string name);
    bool updating_service(string old_name, string new_name, string new_breed, int new_age, string new_photo);
    string display_each_dog(int index);
    int get_number_of_dogs();
    string displaying_adoption_list();
    // destructor:
    ~services();

};
void testing_services();