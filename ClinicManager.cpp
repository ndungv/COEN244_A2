
#include <iostream>

#include "ClinicManager.h"
#include "Doctor.h"
#include "Patient.h"
using namespace std;


// Constructor


ClinicManager::ClinicManager() {
    // Creates dynamic arrays for patients and doctors
    patients = new Patient*[max_patients];
    doctors = new Doctor*[max_doctors];
    patient_count = 0;
    doctor_count = 0;
    total_patients_week = 0;
}


// Destructor
ClinicManager::~ClinicManager() {
    for(int i = 0; i < patient_count; i++) {
        delete patients[i];
    }
    for(int i = 0; i < doctor_count; i++) {
        delete doctors[i];
    }
    delete[] patients;
    delete[] doctors;
}

 // Register new patient
void ClinicManager::insert_patient() {
    if (patient_count >= max_patients) {
        cout << "Maximum number of patients reached!" << endl;
        return;
    }

    string patient_name;
    int dob_date, dob_month, dob_year;
    string insurance;
    string doctor_name;
    string ap_date;
    int ap_hour, ap_minute;
    string temp;

    // Get patient information with proper validation
    cout << "\n=== Patient Registration Form ===" << endl;
    cout << "--------------------------------" << endl;

    cout << "Enter the patient's full name: ";
    getline(cin, patient_name);

    // Get and validate date of birth
    cout << "\n--- Date of Birth ---" << endl;
    cout << "Enter as: DD MM YYYY (Example: 7 3 2005): ";
    while (!(cin >> dob_date >> dob_month >> dob_year)) {
        cout << "Invalid input. Please enter numbers in format: DD MM YYYY" << endl;
        cin.clear();
        getline(cin, temp);
        cout << "Enter as: DD MM YYYY (Example: 7 3 2005): ";
    }
    getline(cin, temp);
    Date patient_birth(dob_date, dob_month, dob_year);

    // Check for duplicate
    for (int i = 0; i < patient_count; i++) {
        if (patients[i]->getPatientName() == patient_name &&
            patients[i]->get_patient_birth().getDay() == dob_date &&
            patients[i]->get_patient_birth().getMonth() == dob_month &&
            patients[i]->get_patient_birth().getYear() == dob_year) {
            cout << "\nPatient already exists!" << endl;
            return;
        }
    }

    // Get insurance information
    cout << "\n--- Insurance Information ---" << endl;
    cout << "Enter insurance number: ";
    getline(cin, insurance);

    // Get doctor assignment
    cout << "\n--- Doctor Assignment ---" << endl;
    cout << "Enter doctor's last name (without Dr. prefix): ";
    getline(cin, doctor_name);

    // Get appointment scheduling
    cout << "\n--- Appointment Scheduling ---" << endl;
    cout << "Enter as: Day Hour Minute" << endl;
    cout << "Example: Monday 14 30 (for Monday at 2:30 PM): ";
    cin >> ap_date >> ap_hour >> ap_minute;
    getline(cin, temp);
    AppointmentTime ap_patient(ap_date, ap_hour, ap_minute);

    // Create and store new patient
    patients[patient_count] = new Patient(patient_name, patient_birth, insurance, doctor_name, ap_patient);
    patient_count++;
    
    // Print info
    cout << "\n=== Registration Successful ===" << endl;
    cout << "--------------------------------" << endl;
    cout << "Name        : " << patient_name << endl;
    cout << "Date of Birth: " << dob_date << "/" << dob_month << "/" << dob_year << endl;
    cout << "Insurance   : " << insurance << endl;
    cout << "Doctor      : " << doctor_name << endl;
    cout << "Appointment : " << ap_date << " at " 
         << ap_hour << ":" << (ap_minute < 10 ? "0" : "") << ap_minute << endl;
    cout << "--------------------------------" << endl;
    cout << "Total patients in system: " << patient_count << endl;
    cout << "--------------------------------\n" << endl;
}


 //Displays information for all registered patients

void ClinicManager::print_all_patients() {
    if (patient_count == 0) {
        cout << "No patients registered." << endl;
        return;
    }

    for (int i = 0; i < patient_count; i++) {
        cout << "---------Patient " << i+1 << "----------" << endl;
        patients[i]->print_patient_info();
        cout << "-------------------------" << endl;
    }
}


 //Registers a new doctor in the system

void ClinicManager::insert_doctor() {
    if (doctor_count >= max_doctors) {
        cout << "Maximum number of doctors reached!" << endl;
        return;
    }

    string name;
    string temp;
    
    cout << "Enter doctor's last name (without Dr. prefix): ";
    getline(cin, name);

    // Check for duplicates
    for (int i = 0; i < doctor_count; i++) {
        if (doctors[i]->get_name() == name) {
            cout << "Doctor already exists!" << endl;
            return;
        }
    }

    doctors[doctor_count] = new Doctor(name);
    doctor_count++;
    cout << "Doctor " << name << " added successfully!" << endl;
    cout << "Current number of doctors: " << doctor_count << endl;
}


// Displays schedules for all registered doctors

void ClinicManager::print_all_doctors() {
    if (doctor_count == 0) {
        cout << "No doctors registered." << endl;
        return;
    }

    for (int i = 0; i < doctor_count; i++) {
        cout << "---------Doctor " << i+1 << "----------" << endl;
        doctors[i]->doctor_schedule();
        cout << "-------------------------" << endl;
    }
}

// bool ClinicManager::insert_doctor(Doctor* doctor) {
//     if (doctor_count >= max_doctors) return false;
//
//     for (int i = 0; i < doctor_count; i++) {
//         if (doctors[i]->get_name() == doctor->get_name()) {
//             return false;
//         }
//     }
//
//     doctors[doctor_count++] = doctor;
//     return true;
// }


//Appointment request

AppointmentTime ClinicManager::process_appointment(const AppointmentRequest& request) {
    string doctor_name = request.getDoctorName();
    Doctor* doctor = find_doctor(doctor_name);
    Patient* patient = find_patient(request.getPatientName());
    
    if (!doctor || !patient) {
        cout << "Doctor or patient not found!" << endl;
        cout << "Doctor name used for search: " << doctor_name << endl;
        cout << "Patient name used for search: " << request.getPatientName() << endl;
        return AppointmentTime(); 
    }

    // Convert appointment date string to day num
    string appointment_date = request.getAppointmentDate();
    int day_index = -1;

    if (appointment_date == "Monday") day_index = 0;
    else if (appointment_date == "Tuesday") day_index = 1;
    else if (appointment_date == "Wednesday") day_index = 2;
    else if (appointment_date == "Thursday") day_index = 3;
    else if (appointment_date == "Friday") day_index = 4;
    
    if (day_index == -1) {
        cout << "Invalid day! Please use Monday through Friday." << endl;
        return AppointmentTime();
    }
    
    // Calculate time slot
    int hour = 14;  // Default
    int minute = 30;
    
    int time_index;
    if (hour >= 9 && hour < 12) {
        time_index = (hour - 9) * 2;
    } else if (hour >= 14 && hour < 17) {
        time_index = ((hour - 14) + 3) * 2;
    } else {
        cout << "Invalid hour! Hours must be between 9-12 or 14-17." << endl;
        return AppointmentTime();
    }
    if (minute == 30) time_index++;
    
    // Attempt to book the appointment
    if (doctor->book_appointment(patient, day_index, time_index)) {
        cout << "Appointment booked successfully!" << endl;
        return AppointmentTime(appointment_date, hour, minute);
    } else {
        cout << "Time slot is not available." << endl;
        return AppointmentTime();
    }
}


// Cancels an existing appointment

bool ClinicManager::cancel_appointment(const string& doctor_name, const string& patient_name, const AppointmentTime& time) {
    Doctor* doctor = find_doctor(doctor_name);
    Patient* patient = find_patient(patient_name);
    
    if (!doctor || !patient) {
        cout << "Doctor or patient not found!" << endl;
        return false;
    }

    // Convert day name to index
    string day = time.getDay();
    int day_index = -1;
    if (day == "Monday") day_index = 0;
    else if (day == "Tuesday") day_index = 1;
    else if (day == "Wednesday") day_index = 2;
    else if (day == "Thursday") day_index = 3;
    else if (day == "Friday") day_index = 4;
    
    if (day_index == -1) {
        cout << "Invalid day! Please use Monday through Friday." << endl;
        return false;
    }

    // Calculate time slot index
    int hour = time.getHour();
    int minute = time.getMinute();
    int time_index = (hour - 9) * 2 + (minute == 30 ? 1 : 0);

    if (time_index < 0 || time_index >= 12) {
        cout << "Invalid time! Hours must be between 9 and 17." << endl;
        return false;
    }

    doctor->cancel_appointment(day_index, time_index);
    
    // Update patient's appointment info
    patient->setDoctorName("");
    patient->setAppointmentTime(AppointmentTime());
    
    cout << "Appointment cancelled successfully!" << endl;
    return true;
}


 // * Displays all patients assigned to a specific doctor

void ClinicManager::print_doctor_patients(const string& doctor_name) const {
    bool found = false;
    
    for (int i = 0; i < patient_count; i++) {
        if (patients[i]->getPatientDoctorName() == doctor_name) {
            cout << "Patient: " << patients[i]->getPatientName() 
                 << ", Insurance: " << patients[i]->getPatientInsurance() << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "No patients found for doctor " << doctor_name << endl;
    }
}


 // function to find a patient by name

Patient* ClinicManager::find_patient(const string& name) const {
    for (int i = 0; i < patient_count; i++) {
        if (patients[i]->getPatientName() == name) {
            return patients[i];
        }
    }
    return nullptr;
}


 //function to find a doctor by name

Doctor* ClinicManager::find_doctor(const string& name) const {
    for (int i = 0; i < doctor_count; i++) {
        if (doctors[i]->get_name() == name) {
            return doctors[i];
        }
    }
    return nullptr;
}



