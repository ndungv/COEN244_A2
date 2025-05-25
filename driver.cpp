#include <iostream>
#include "ClinicManager.h"


using namespace std;

int option;

void patient_menu();
void doctor_menu();

ClinicManager clinic_manager;   //ClinicManager object


int main() {


    cout <<"Welcome to ClinicManager"<<endl;
    cout <<"Please choose a function: "<<endl;

    cout <<"1. Patient Menu"<<endl;
    cout <<"2. Doctor Menu"<<endl;
    cout <<"0. Exit"<<endl;
    cin >> option;

    switch (option) {
        case 1:
            patient_menu();
            break;
        case 2:
            // clinic_manager.insert_doctor();
            break;
        case 0:
            exit(0);
    }
}

void patient_menu() {
    int option;
    cout << "Please choose a function: "<<endl;
    cout <<"1. Add a Patient "<<endl;
    cout <<"2. Show patients list"<<endl;
    cin >> option;
    switch (option) {
        case 1:
            clinic_manager.insert_patient();
            patient_menu();
        break;
        case 2:
            clinic_manager.print_all_patients();
            patient_menu();
        break;
        case 0:
            exit(0);
    }

}