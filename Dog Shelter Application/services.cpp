#include "services.h"
#include "assert.h"
#include "cstring"
using namespace std;

bool compare_strings(string string1, string string2)
{
    if(string1.length() != string2.length())
        return false;
    for(int i = 0; i< string1.length(); i++)
        if(string1[i] != string2[i])
            return false;
    return true;
}

services::services(file_repo repo1, file_repo* list_repo, string list): repo(repo1), listing(list_repo)
{
    this->create_list_in_html_or_csv(list);
}

void services::create_list_in_html_or_csv(string list) {
    if (list == "html")
    {
        this->listing = new html_repo("startup_entries.txt", "dogs.html");
    }
    else
    {
        this->listing = new csv_repo("startup_entries.txt", "dogs.csv");
    }
}
void services::load_listing() {
    this->listing->write_to_file();
}

vector<Dog>& services::get_services()
{
    return this->repo.get_repo();
}
vector<Dog>& services::get_sorted_services()
{
    return this->repo.get_sorted_repo();
}
bool services::add_service(string breed, string name, int age, string photo)
{
    Dog new_dog = Dog(breed, name, age, photo);
    return !this->repo.adding_a_dog(new_dog);
}
void services::adding_to_adoption_list(Dog dog)
{
    this->repo.adding_a_dog_to_adopted_list(dog);
}

string services::displaying_adoption_list()
{
    return this->repo.displaying_adoption_list();
}
bool services::delete_service(string name)
{
    int index_to_delete = -1, current_index = 0;
    for (auto & i : this->get_services()) {
        if (i.get_name() == name) {
            index_to_delete = current_index;
            break;
        }
        current_index++;
    }
    return this->repo.deleting_a_dog(index_to_delete);
}
bool services::delete_dog_from_sorted_list(string name)
{
    int index_to_delete = -1, current_index = 0;
    for (auto & i : this->get_services()) {
        if (i.get_name() == name) {
            index_to_delete = current_index;
            break;
        }
        current_index++;
    }

    return this->repo.deleting_a_dog_from_sorted_array(index_to_delete);
}

bool services::updating_service(string old_name, string new_name, string new_breed, int new_age, string new_photo)
{
    int update_index = -1, current_index = 0;
    for (auto &i : this->get_services()) {
        if (i.get_name() == old_name) {
            update_index = current_index;
            break;
        }
        current_index++;
    }
    return this->repo.updating_a_dog(update_index, Dog(new_breed, new_name, new_age, new_photo));
}
void services::sorting_the_array_of_dogs(string breed, int age)
{
    this->get_sorted_services().clear();
    for(auto i:this->get_services())
    {
        string new_breed;
        new_breed = i.get_breed();
        if ((breed == new_breed or breed == "") && i.get_age() < age)
            this->repo.adding_a_dog_to_sorted_list(i);
    }
}
string services::display_each_dog(int index)
{
    return this->repo.displaying_each_dog(index);
}
int services::get_number_of_dogs()
{
    return this->repo.get_number_of_dogs();
}

services::~services(){}

//void testing_services()
//{
//    Dog test_dog = Dog("Pit-bull", "Oli", 10, "photo-link");
//    vector<Dog> test_array;
//    vector<Dog> test_array_of_dogs;
//    vector<Dog> test_sorted_array;
//    repository test_repo = repository(test_array, test_array_of_dogs, test_sorted_array);
//    test_repo.generating_startup_entries();
//    services test_service = services(test_repo);
//    test_service.add_service("Bulldog", "Oli", 15, "photo-link");
//    assert(test_service.add_service("Bulldog", "Oli", 15, "photo-link") == true);
//    assert(test_service.delete_dog_from_sorted_list("Oh no!!") == false);
//    assert(test_service.delete_service("Oh no!!") == false);
//    assert(test_service.updating_service("oh no", "yeah", "o", 2, "o") == false);
//    test_service.adding_to_adoption_list(test_dog);
//    assert(test_service.get_services()[10].get_name() == "Oli");
//    test_service.sorting_the_array_of_dogs("Bulldog", 20);
//    assert(test_service.get_number_of_sorted_dogs() == 3);
//    assert(test_service.get_sorted_services()[2].get_name() == "Oli");
//   assert(test_service.get_number_of_dogs() == 11);
//    test_service.delete_dog_from_sorted_list("Oli");
//    assert(test_service.get_number_of_sorted_dogs() == 2);
//    test_service.delete_service("Oli");
//    assert(test_service.get_number_of_dogs() == 10);
//    test_service.updating_service("Fluff", "Rex", "Bichon", 4, "photo-link");
//   assert(test_service.delete_service("zzz") == false);
//    assert(test_service.delete_dog_from_sorted_list("zzz") == false);
//
//    vector<Dog> test_array2;
//    vector<Dog> test_array_of_dogs2;
//    vector<Dog> test_sorted_array2;
//
//    repository test_repo2 = repository(test_array, test_array_of_dogs, test_sorted_array);
//    test_repo.generating_startup_entries();
//    services test_service2 = services(test_repo2);
//    test_service2.adding_to_adoption_list(test_dog);
//    test_service2.add_service("Pit-bull", "Oli", 10, "photo-link");
//    string result;
//    result = test_service2.displaying_adoption_list();
//    assert(result == "The dog named Oli is of breed: Pit-bull, of age: 10 and its link is: \nphoto-link\n");
//    string result3;
//    result3 = test_service2.display_each_dog(0);
//    assert(result3 == "The dog named Oli is of breed: Pit-bull, of age: 10 and its link is: \nphoto-link\n");
//}
////Dog test_dog = Dog("Pit-bull", "Oli", 10, "photo-link");

