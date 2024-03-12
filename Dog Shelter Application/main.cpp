#include <QApplication>
#include <QPushButton>
#include "gui.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    file_repo fr("startup_entries.txt");
    file_repo fr2("startup_entries.txt");
    string listing_mode = "html";
    services service(fr, &fr2, listing_mode);
    gui guis(service);
    guis.setStyleSheet("QMainWindow {background: 'green';}");
    guis.show();

    return QApplication::exec();
}
