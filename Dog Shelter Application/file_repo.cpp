//
// Created by Cristi on 5/8/2023.
//
#define CAPACITY 20
#define breed_length 100
#define name_length 100
#define photo_length 300
#include "file_repo.h"
#include "exceptions.h"

file_repo::file_repo(string current_filename) {
    this->filename = current_filename;
    this->array_of_repo.reserve(CAPACITY);
    this->sorted_array_of_dogs.reserve(CAPACITY);
    this->array_of_adopted_dogs.reserve(CAPACITY);
    this->array_of_repo = read_from_file();
}

vector<Dog> file_repo::read_from_file() {
    ifstream input_file(this->filename);
    vector<Dog> dogs;
    string breed, name, photo;
    int age, nr_of_dogs;
    input_file>>nr_of_dogs;
    input_file.get();
    for(int i=0; i<nr_of_dogs; i++)
    {
        getline(input_file, breed);
        getline(input_file, name);
        input_file>>age;
        input_file.get();
        getline(input_file, photo);
        Dog new_dog(breed, name, age, photo);
        dogs.push_back(new_dog);
    }
    input_file.close();
    return dogs;
}

void file_repo::write_to_file() {
    ofstream output_file(this->filename);
    output_file<<this->array_of_repo.size()<<"\n";
    for(auto i:this->array_of_repo)
    {
        output_file<<i.get_breed()<<"\n";
        output_file<<i.get_name()<<"\n";
        output_file<<i.get_age()<<"\n";
        output_file<<i.get_photo()<<"\n";
    }
    output_file.close();
}
bool file_repo::adding_a_dog(Dog new_dog) {
    this->array_of_repo = read_from_file();
    if(check_if_element_exists(new_dog))
        throw exception_repository("The element to be added exists already.\n");
    this->array_of_repo.push_back(new_dog);
    this->write_to_file();
    return true;
}
bool file_repo::deleting_a_dog(int delete_index) {
    if(delete_index == -1)
        throw exception_repository("The element to be deleted doesn't exist!\n");
    this->array_of_repo.erase(this->array_of_repo.begin() + delete_index);
    this->write_to_file();
    return true;
}
bool file_repo::updating_a_dog(int update_index, Dog new_dog) {
    if(update_index == -1)
        throw exception_repository("The element to be updated doesn't exist!\n");
    this->array_of_repo.at(update_index) = new_dog;
    this->write_to_file();
    return true;
}