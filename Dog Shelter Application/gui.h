//
// Created by Cristi on 5/22/2023.
//

#ifndef A_89_GUI_H
#define A_89_GUI_H
#include "services.h"
#include "validators.h"
#include "exceptions.h"
#include <QVBoxLayout>
#include "qwidget.h"
#include "qlistwidget.h"
#include "qlineedit.h"
#include "qpushbutton.h"
#include <QComboBox>
#include <QMainWindow>
#include <QDialog>

class gui: public QMainWindow {
        Q_OBJECT
private:
    string listing_mode;
    services service;
    void initialize_gui();
    QComboBox *listing_combo_box;
    QPushButton* administrator_mode, *user_mode, *quit, *listing;
public:
    gui(services service, QWidget *parent = 0);
    void set_listing_mode();
    void connect_signals_and_slots();
    void start_user_mode();
    void start_administrator_mode();

};

class administrator_gui: public QDialog{
private:
    services servi;
    QListWidget* dogs_list_widget;
    QLineEdit* old_name, *new_name, *name_line_edit, *breed_line_edit, *age_line_edit, *photo_link_edit;
    QPushButton *quit, *add, *deleting, *update, *display_html_csv;
public:
    administrator_gui(services servi, QWidget* parent = NULL);
    ~administrator_gui(){};
    void connect_signals_and_slots_in_admin();
    void get_old_name() const;
    void initialise_admin_gui();
    void generate_dogs();

    void add_dog();
    void delete_dog();
    void update_dog();
};

class user_gui: public QDialog{
private:
    int position;
    string breed;
    services servi;
    QListWidget* dogs_list_widget;
    QListWidget adopted_dogs_list_widget;
    QWidget* window_widget;
    QPushButton *view_all_dogs, *adopt_dog;
    QPushButton *done, *next, *adopting;
    QLineEdit *breed_to_sort, *age_to_sort;
public:
    user_gui(services servi1, QWidget* parent = NULL);
    ~user_gui(){};
    void connect_signals_and_slots_to_user();
    void connect_signals_and_slots_to_user_see_dogs();
    void initialise_usermode_gui();
    void show_dogs_interface();
    void initialise_display_dogs();
    void display_adopted_dogs();
    void display_sorted_adopted_dogs();
    void show_user_dogs();
    void next_dog();
    void stop_iterating_dogs();
    void mark_as_adopted();
    void adopting_dogs();

};

static void Quit();

#endif //A_89_GUI_H
