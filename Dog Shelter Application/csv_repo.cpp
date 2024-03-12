//
// Created by Cristi on 5/8/2023.
//

#include "csv_repo.h"
using namespace std;
csv_repo::csv_repo(string filename1, string csv_filename1):file_repo(filename1) {
    this->csv_filename = csv_filename1;
}
void csv_repo::write_to_file() {
    ofstream output_file(this->csv_filename);
    for(auto i:this->array_of_repo)
    {
        output_file<<i.get_breed()<<", ";
        output_file<<i.get_name()<<", ";
        output_file<<i.get_age()<<", ";
        output_file<<i.get_photo()<<"\n";
    }
    output_file.close();
}