//
// Created by Cristi on 5/22/2023.
//

#include "gui.h"
#include "qformlayout.h"
#include "qgridlayout.h"
#include "qlabel.h"
#include "iostream"
#include "QMessageBox"
#include <QCoreApplication>

using namespace std;
gui::gui(services service, QWidget *parent): service(service), QMainWindow(parent) {
    this->initialize_gui();
    this->connect_signals_and_slots();
}

void gui::initialize_gui() {
    QFont buttons_font("Consolas", 13, true);

    this->administrator_mode = new QPushButton{"administrator mode"};
    this->administrator_mode->setFont(buttons_font);

    this->user_mode = new QPushButton{"user mode"};
    this->user_mode->setFont(buttons_font);

    this->quit = new QPushButton{"quit!"};
    this->quit->setFont(buttons_font);

    this->listing_combo_box = new QComboBox{};
    this->listing_combo_box->setFont(buttons_font);
    this->listing_combo_box->addItem("HTML file");
    this->listing_combo_box->addItem("CSV file");

    QVBoxLayout* main_layout = new QVBoxLayout();

    QLabel *title = new QLabel();
    title->setText("ADOPT, DON'T SHOP! (:");
    title->setAlignment(Qt::AlignCenter);
    QFont title_font("Consolas", 20, true, true);
    title->setFont(title_font);

    QLabel *blank_text = new QLabel();
    blank_text->setText("");

    QLabel *listing_mode = new QLabel();
    listing_mode->setText("choose the listing mode!");
    QFont listing_mode_font("Consolas", 15, true);
    listing_mode->setFont(listing_mode_font);

    main_layout->addWidget(title);
    main_layout->addWidget(blank_text);
    main_layout->addWidget(blank_text);

    QFormLayout* listing_details = new QFormLayout();
    listing_details->addRow(listing_mode, this->listing_combo_box);

    main_layout->addLayout(listing_details);

    QGridLayout* button_layout = new QGridLayout();
    button_layout->addWidget(this->administrator_mode, 0, 0);
    button_layout->addWidget(this->user_mode, 1, 0);
    button_layout->addWidget(this->quit, 2, 0);

    main_layout->addLayout(button_layout);

    QWidget *main_window = new QWidget();
    main_window->setLayout(main_layout);
    setCentralWidget(main_window);
}

void gui::connect_signals_and_slots() {
    QObject::connect(this->administrator_mode, &QPushButton::clicked, this, &gui::start_administrator_mode);
    QObject::connect(this->user_mode, &QPushButton::clicked, this, &gui::start_user_mode);
    QObject::connect(this->quit, &QPushButton::clicked, this, &Quit);
}

void gui::start_administrator_mode() {
    this->setCursor(Qt::WaitCursor);
    administrator_gui* agui = new administrator_gui{service};
    this->setCursor(Qt::ArrowCursor);
}

void gui::start_user_mode() {
    this->setCursor(Qt::WaitCursor);
    user_gui* ugui = new user_gui{service};
    this->setCursor(Qt::ArrowCursor);
}

void gui::set_listing_mode() {
    this->listing_mode = this->listing_combo_box->currentText().toStdString();
    if(this->listing_mode == "CSV file")
        this->service.create_list_in_html_or_csv("csv");
    else this->service.create_list_in_html_or_csv("html");
}
// administrator gui:

administrator_gui::administrator_gui(services servi1, QWidget *parent): servi{servi1}, QDialog{parent} {
    this->initialise_admin_gui();
    this->generate_dogs();
    this->connect_signals_and_slots_in_admin();
}

void administrator_gui::initialise_admin_gui() {
    QFont button_font("Consolas", 13, true);

    this->dogs_list_widget = new QListWidget{};
    this->dogs_list_widget->setFont(button_font);

    this->old_name = new QLineEdit{};
    this->old_name->setFont(button_font);

    this->breed_line_edit = new QLineEdit{};
    this->breed_line_edit->setFont(button_font);

    this->name_line_edit = new QLineEdit{};
    this->name_line_edit->setFont(button_font);

    this->age_line_edit = new QLineEdit{};
    this->age_line_edit->setFont(button_font);

    this->photo_link_edit = new QLineEdit{};
    this->photo_link_edit->setFont(button_font);

    this->add = new QPushButton{"add!"};
    this->add->setFont(button_font);

    this->deleting = new QPushButton{"delete!"};
    this->deleting->setFont(button_font);

    this->update = new QPushButton{"update!"};
    this->update->setFont(button_font);

    this->quit = new QPushButton{"quit..."};
    this->quit->setFont(button_font);

    this->display_html_csv = new QPushButton{"display the dogs!"};
    this->display_html_csv->setFont(button_font);

    QLabel *blank = new QLabel();
    blank->setText("");

    QLabel *dogs = new QLabel();
    dogs->setText("DOGS");
    QFont dog_font("Consolas", 15, true);
    dogs->setFont(dog_font);

    QLabel *oldname = new QLabel();
    oldname->setText("old name:");
    oldname->setFont(dog_font);

    QLabel *breed = new QLabel();
    breed->setText("breed:");
    breed->setFont(dog_font);

    QLabel *name = new QLabel();
    name->setText("name:");
    name->setFont(dog_font);

    QLabel *age = new QLabel();
    age->setText("age:");
    age->setFont(dog_font);

    QLabel *photo = new QLabel();
    photo->setText("photo link:");
    photo->setFont(dog_font);

    QVBoxLayout* admin_layout = new QVBoxLayout();
    admin_layout->addWidget(dogs);
    admin_layout->addWidget(this->dogs_list_widget);

    QFormLayout* dog_details = new QFormLayout();
    dog_details->addRow(oldname, this->old_name);
    dog_details->addRow(breed, this->breed_line_edit);
    dog_details->addRow(name, this->name_line_edit);
    dog_details->addRow(age, this->age_line_edit);
    dog_details->addRow(photo, this->photo_link_edit);

    admin_layout->addLayout(dog_details);

    QGridLayout* button_layout = new QGridLayout();
    button_layout->addWidget(this->add, 0, 0);
    button_layout->addWidget(this->deleting, 0, 1);
    button_layout->addWidget(this->update, 0, 2);
    button_layout->addWidget(this->quit, 1, 1);

    admin_layout->addLayout(button_layout);

    QWidget* display_window = new QWidget();
    display_window->setLayout(admin_layout);
    display_window->show();

}

void administrator_gui::generate_dogs() {
    this->dogs_list_widget->clear();
    vector<Dog> all_dogs = this->servi.get_services();
    for(auto i = all_dogs.begin(); i!= all_dogs.end(); i++)
        this->dogs_list_widget->addItem(QString::fromStdString(i->turn_into_string()));
}

void administrator_gui::connect_signals_and_slots_in_admin() {
    QObject::connect(this->add, &QPushButton::clicked, this, &administrator_gui::add_dog);
    QObject::connect(this->deleting, &QPushButton::clicked, this, &administrator_gui::delete_dog);
    QObject::connect(this->update, &QPushButton::clicked, this, &administrator_gui::update_dog);
    QObject::connect(this->quit, &QPushButton::clicked, this, &Quit);
}
void administrator_gui::add_dog() {
    string name = this->name_line_edit->text().toStdString();
    string breed = this->breed_line_edit->text().toStdString();
    int age = this->age_line_edit->text().toInt();
    string photo_link = this->photo_link_edit->text().toStdString();
    if(!validators::validate_name(name) || !validators::validate_age(age) || !validators::validate_breed(breed) || !validators::validate_link(photo_link))
    {
        QMessageBox::critical(this, "error!", "invalid input...");
        return;
    }
    else
    {
        try {
            this->servi.add_service(breed, name, age, photo_link);
        }
        catch (exception_repository)
        {
            QMessageBox::critical(this, "error!", "couldn't be added...");
        }
    }
    this->generate_dogs();

}
void administrator_gui::delete_dog() {
    string oldName = this->name_line_edit->text().toStdString();
    if(!validators::validate_name(oldName))
    {
        QMessageBox::critical(this, "error!", "bad input...");
        return;
    }
    else
    {
        try
        {
            this->servi.delete_service(oldName);
        }
        catch(exception_repository)
        {
            QMessageBox::critical(this, "error!", "can't be deleted...");
        }
        this->generate_dogs();
    }


}
void administrator_gui::update_dog() {
    string oldName = this->old_name->text().toStdString();
    string name = this->name_line_edit->text().toStdString();
    string breed = this->breed_line_edit->text().toStdString();
    int age = this->age_line_edit->text().toInt();
    string photo_link = this->photo_link_edit->text().toStdString();
    if(!validators::validate_name(name) || !validators::validate_age(age) || !validators::validate_breed(breed) || !validators::validate_link(photo_link) || !validators::validate_name(oldName))
    {
        QMessageBox::critical(this, "error!", "invalid input...");
        return;
    }
    else
    {
        try {
            this->servi.updating_service(oldName, name, breed, age, photo_link);
        }
        catch(exception_repository)
        {
            QMessageBox::critical(this, "error!", "nothing to update...");
        }
    }
    this->generate_dogs();
}

// user gui:

user_gui::user_gui(services servi1, QWidget *parent): servi(servi1)  {
    this->initialise_usermode_gui();
    this->connect_signals_and_slots_to_user();
    this->display_adopted_dogs();
}

void user_gui::initialise_usermode_gui() {
    QFont button_font("Consolas", 13, true);

    this->dogs_list_widget = new QListWidget{};
    this->dogs_list_widget->setFont(button_font);

    this->view_all_dogs = new QPushButton{"viewing all dogs!"};
    this->view_all_dogs->setFont(button_font);

    this->adopt_dog = new QPushButton{"sorting the dogs..."};
    this->adopt_dog->setFont(button_font);

    QLabel *blank = new QLabel();
    blank->setText("");

    this->breed_to_sort = new QLineEdit{};
    this->breed_to_sort->setFont(button_font);

    this->age_to_sort = new QLineEdit{};
    this->age_to_sort->setFont(button_font);

    QLabel *age = new QLabel();
    age->setText("age:");
    age->setFont(button_font);

    QLabel *breed = new QLabel();
    breed->setText("breed:");
    breed->setFont(button_font);

    QFormLayout* dog_details = new QFormLayout();
    dog_details->addRow(breed, this->breed_to_sort);
    dog_details->addRow(age, this->age_to_sort);

    QLabel *dogs = new QLabel();
    dogs->setText("dogs possible for adoption:");
    QFont dogs_font("Consolas", 15, true);
    dogs->setFont(dogs_font);

    QVBoxLayout* user_layout = new QVBoxLayout(this);
    user_layout->addWidget(dogs);
    user_layout->addWidget(this->dogs_list_widget);

    QGridLayout* buttons_layout = new QGridLayout();
    buttons_layout->addWidget(this->view_all_dogs, 0, 0);
    buttons_layout->addWidget(this->adopt_dog, 1, 0);

    user_layout->addLayout(dog_details);
    user_layout->addLayout(buttons_layout);

    QWidget *user_display_window = new QWidget();
    user_display_window->setLayout(user_layout);
    user_display_window->show();

}
void user_gui::connect_signals_and_slots_to_user() {
    QObject::connect(this->view_all_dogs, &QPushButton::clicked, this, &user_gui::show_dogs_interface);
    QObject::connect(this->adopt_dog, &QPushButton::clicked, this, &user_gui::adopting_dogs);
}

void user_gui::connect_signals_and_slots_to_user_see_dogs() {
    QObject::connect(this->next, &QPushButton::clicked, this, &user_gui::next_dog);
    QObject::connect(this->adopting, &QPushButton::clicked, this, &user_gui::mark_as_adopted);
    QObject::connect(this->done, &QPushButton::clicked, this, &user_gui::stop_iterating_dogs);
}

void user_gui::display_adopted_dogs() {
    this->dogs_list_widget->clear();
    vector<Dog> all_dogs = this->servi.get_services();
    for (auto i = all_dogs.begin(); i!=all_dogs.end(); i++)
    {
        this->dogs_list_widget->addItem(QString::fromStdString(i->turn_into_string()));
    }
}

void user_gui::display_sorted_adopted_dogs() {
    this->dogs_list_widget->clear();
    vector<Dog> all_dogs = this->servi.get_sorted_services();
    for (auto i = all_dogs.begin(); i!=all_dogs.end(); i++)
    {
        this->dogs_list_widget->addItem(QString::fromStdString(i->turn_into_string()));
    }
}

void user_gui::show_dogs_interface() {
    this->initialise_display_dogs();
    this->connect_signals_and_slots_to_user_see_dogs();
    this->position = -1;
    this->next_dog();
}

void user_gui::next_dog() {
    if(this->position + 1 == this->servi.get_sorted_services().size())
        this->position = -1;
    this->dogs_list_widget->clear();
    this->position++;
    this->dogs_list_widget->addItem(QString::fromStdString(this->servi.get_services().at(this->position).turn_into_string()));
    string link = this->servi.get_services().at(this->position).get_name();
    //ShellExecuteA(NULL, "open", "chrome.exe", link, NULL, SW_SHOW);

}

void user_gui::mark_as_adopted() {
    this->servi.adding_to_adoption_list(this->servi.get_services().at(this->position));
    this->servi.delete_service(this->servi.get_services().at(this->position).get_name());
    this->stop_iterating_dogs();
}

void user_gui::stop_iterating_dogs() {
    this->display_adopted_dogs();
    this->window_widget->close();
}

void user_gui::adopting_dogs() {
    string breed = this->breed_to_sort->text().toStdString();
    int age = this->age_to_sort->text().toInt();
    this->servi.sorting_the_array_of_dogs(breed, age);
    this->display_sorted_adopted_dogs();
}

void user_gui::initialise_display_dogs() {
    QFont buttons_font("Consolas", 13, true);

    this->dogs_list_widget = new QListWidget{};
    this->dogs_list_widget->setFont(buttons_font);

    this->next = new QPushButton{"next"};
    this->next->setFont(buttons_font);

    this->adopting = new QPushButton{"want to adopt!"};
    this->adopting->setFont(buttons_font);

    this->done = new QPushButton{"done"};
    this->done->setFont(buttons_font);

    QLabel *dogs_text = new QLabel();
    dogs_text->setText("dogs");
    QFont dogs_font("Consolas", 15, true);
    dogs_text->setFont(dogs_font);

    QVBoxLayout* display_layout = new QVBoxLayout();
    display_layout->addWidget(dogs_text);
    display_layout->addWidget(this->dogs_list_widget);

    QGridLayout* buttons_layout = new QGridLayout();
    buttons_layout->addWidget(this->next, 0, 0);
    buttons_layout->addWidget(this->adopting, 0, 1);
    buttons_layout->addWidget(this->done, 0, 2);

    display_layout->addLayout(buttons_layout);
    QWidget *main_display_window = new QWidget();
    main_display_window->setLayout(display_layout);
    this->window_widget = main_display_window;
    main_display_window->show();
}

void user_gui::show_user_dogs() {
    this->display_adopted_dogs();
}

void Quit()
{
    QCoreApplication::quit();
}
