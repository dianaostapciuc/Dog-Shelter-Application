//
// Created by Cristi on 5/9/2023.
//

#include "html_repo.h"
using namespace std;

html_repo::html_repo(string current_filename, string html_filename): file_repo(current_filename) {
    this->html_filename = html_filename;
}
void html_repo::write_to_file()
{
    ofstream output_file(this->html_filename);
    output_file << "<!DOCTYPE html>\n"
               "<html>\n"
               "\t<head>\n"
               "\t\t<title>Dogs</title>\n"
               "\t</head>\n"
               "\t<body>\n"
               "\t\t<table border=\"1\">\n"
               "\t\t\t<tr>\n"
               "\t\t\t\t<td>Breed</td>\n"
               "\t\t\t\t<td>Name</td>\n"
               "\t\t\t\t<td>Age</td>\n"
               "\t\t\t\t<td>Link</td>\n"
               "\t\t\t</tr>\n";
    for(auto i:this->array_of_repo)
    {
        output_file << "\t\t\t<tr>\n";
        output_file << "\t\t\t\t<td>" << i.get_breed()<< "</td>\n";
        output_file << "\t\t\t\t<td>" << i.get_name()<< "</td>\n";
        output_file << "\t\t\t\t<td>" << i.get_age()<< "</td>\n";
        output_file << "\t\t\t\t<td>" << i.get_photo() << "</td>\n";
        output_file << "\t\t\t</tr>\n";
    }
    output_file << "\t\t</table>\n"
                  "\t</body>\n"
                  "</html>";
    output_file.close();
}