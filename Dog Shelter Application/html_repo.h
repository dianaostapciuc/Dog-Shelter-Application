//
// Created by Cristi on 5/9/2023.
//

#ifndef A7_XDIANAOST_1_HTML_REPO_H
#define A7_XDIANAOST_1_HTML_REPO_H
#pragma once
#include "file_repo.h"

class html_repo: public file_repo {
private:
    string html_filename;
public:
    void write_to_file() override;
    html_repo(string filename, string html_filename);

};


#endif //A7_XDIANAOST_1_HTML_REPO_H
