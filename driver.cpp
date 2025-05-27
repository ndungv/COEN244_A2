/**
 * Main driver file for the Clinic Management System
 */

#include <iostream>
#include <limits>
#include "ClinicManager.h"
#include "AppointmentRequest.h"

using namespace std;

// Function declarations
void test_clinic_functionality();  // Test function for system functionality
void patient_menu();              // Handle patient-related operations
void doctor_menu();               // Handle doctor-related operations
void appointment_menu();          // Handle appointment-related operations
void main_menu();                 // Main menu of the system

// Global clinic manager instance
ClinicManager clinic_manager;

int main() {
    cout << "Welcome to the Clinic Management System!" << endl;
    main_menu();
    return 0;
}



/**
 * Main menu
 */
void main_menu() {
    int option;
    string temp;
    while (true) {
        cout <<"-----------ClinicManager-----------"<<endl;
        cout <<"______________________________"<<endl;
        cout <<"Welcome to ClinicManager"<<endl;
        cout <<"Please choose a function: "<<endl;

        cout <<"1. Patient Menu"<<endl;
        cout <<"2. Doctor Menu"<<endl;
        cout <<"3. Appointment Menu"<<endl;
        cout <<"0. Exit"<<endl;
        
        if (!(cin >> option)) {
            cin.clear();
            getline(cin, temp);
            continue;
        }
        getline(cin, temp); // Clear the buffer after reading the number

        switch (option) {
            case 1:
                patient_menu();
                break;
            case 2:
                doctor_menu();
                break;
            case 3:
                appointment_menu();
                break;
            case 0:
                exit(0);
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
}

/**
 * Patient menu
 */
void patient_menu() {
    int option;
    string temp;
    while (true) {
        cout <<"-----------Patient Menu-----------"<<endl;
        cout << "Please choose a function: "<<endl;
        cout <<"1. Add a Patient "<<endl;
        cout <<"2. Show patients list"<<endl;
        cout <<"0. Main menu"<<endl;

        if (!(cin >> option)) {
            cin.clear();
            getline(cin, temp);
            continue;
        }
        getline(cin, temp); // Clear the buffer after reading the number

        switch (option) {
            case 1:
                clinic_manager.insert_patient();
                break;
            case 2:
                clinic_manager.print_all_patients();
                break;
            case 0:
                return;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
        cout <<"______________________________"<<endl;
    }
}

/**
 * Doctor menu
 */
void doctor_menu() {
    int option;
    string temp;
    while (true) {
        cout <<"-----------Doctor Menu-----------"<<endl;
        cout << "Please choose a function: "<<endl;
        cout <<"1. Add a Doctor "<<endl;
        cout <<"2. Show Doctors list"<<endl;
        cout <<"3. Show Doctor's Patients"<<endl;
        cout <<"0. Main menu"<<endl;

        if (!(cin >> option)) {
            cin.clear();
            getline(cin, temp);
            continue;
        }
        getline(cin, temp); // Clear the buffer after reading the number

        switch (option) {
            case 1:
                clinic_manager.insert_doctor();
                break;
            case 2:
                clinic_manager.print_all_doctors();
                break;
            case 3: {
                string doctor_name;
                cout << "Enter doctor's name: ";
                getline(cin, doctor_name);
                clinic_manager.print_doctor_patients(doctor_name);
                break;
            }
            case 0:
                return;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
        cout <<"______________________________"<<endl;
    }
}

/**
 * Appointment menu
 */
void appointment_menu() {
    int option;
    string temp;
    while (true) {
        cout <<"-----------Appointment Menu-----------"<<endl;
        cout << "Please choose a function: "<<endl;
        cout <<"1. Request Appointment"<<endl;
        cout <<"2. Cancel Appointment"<<endl;
        cout <<"0. Main menu"<<endl;

        if (!(cin >> option)) {
            cin.clear();
            getline(cin, temp);
            continue;
        }
        getline(cin, temp); // Clear the buffer after reading the number

        switch (option) {
            case 1: {
                string patient_name, doctor_name, appointment_date;
                cout << "Enter patient name: ";
                getline(cin, patient_name);
                
                cout << "Enter doctor's last name (without Dr. prefix): ";
                getline(cin, doctor_name);
                
                cout << "Enter preferred day (Monday-Friday): ";
                getline(cin, appointment_date);
                
                AppointmentRequest req(patient_name, doctor_name, appointment_date);
                AppointmentTime apt = clinic_manager.process_appointment(req);
                
                if(apt.getHour() != 0) {
                    cout << "Appointment scheduled for " << apt.getDay() 
                         << " at " << apt.getHour() << ":" 
                         << (apt.getMinute() < 10 ? "0" : "") << apt.getMinute() << endl;
                }
                break;
            }
            case 2: {
                string patient_name, doctor_name, day;
                int hour, minute;
                cout << "Enter patient name: ";
                getline(cin, patient_name);
                
                cout << "Enter doctor's last name (without Dr. prefix): ";
                getline(cin, doctor_name);
                
                cout << "Enter appointment day (Monday-Friday): ";
                getline(cin, day);
                
                cout << "Enter appointment hour (24-hour format): ";
                cin >> hour;
                getline(cin, temp); // Clear the buffer
                
                cout << "Enter appointment minute: ";
                cin >> minute;
                getline(cin, temp); // Clear the buffer
                
                // Add Dr. prefix if not present
                if (doctor_name.substr(0, 3) != "Dr.") {
                    doctor_name = "Dr. " + doctor_name;
                }
                
                AppointmentTime apt(day, hour, minute);
                if(clinic_manager.cancel_appointment(doctor_name, patient_name, apt)) {
                    cout << "Appointment cancelled successfully" << endl;
                } else {
                    cout << "Could not cancel appointment" << endl;
                }
                break;
            }
            case 0:
                return;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
        cout <<"______________________________"<<endl;
    }
}