//
// Created by Cristi on 5/8/2023.
//

#ifndef A7_XDIANAOST_1_CSV_REPO_H
#define A7_XDIANAOST_1_CSV_REPO_H
#pragma once
#include "file_repo.h"

class csv_repo: public file_repo {
private:
    string csv_filename;
public:
    void write_to_file() override;
    csv_repo(string filename, string csv_filename);

};

#endif //A7_XDIANAOST_1_CSV_REPO_H
