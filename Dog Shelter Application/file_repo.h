//
// Created by Cristi on 5/8/2023.
//

#ifndef A7_XDIANAOST_1_FILE_REPO_H
#define A7_XDIANAOST_1_FILE_REPO_H
#include "repository.h"
#include "iostream"
#include "fstream"
using namespace std;


class file_repo: public repository {
protected:
    string filename;
private:
    vector<Dog> read_from_file();
public:
    virtual void write_to_file();
    file_repo(string filename);

    bool adding_a_dog(Dog new_dog) override;
    bool deleting_a_dog(int delete_index) override;
    bool updating_a_dog(int update_index, Dog new_dog) override;

};


#endif //A7_XDIANAOST_1_FILE_REPO_H
