

#include <iostream>
#include "Patient.h"
using namespace std;

/**
 * Default constructor

 */
Patient::Patient() {
    patient_name = "";
    patient_insurance = "";
    doctor_name = "";
}

/**
 * Full constructor
 */
Patient::Patient(string p_name, const Date& dob, string insurance, string d_name, const AppointmentTime& ap_patient) :
    patient_name(p_name),
    patient_birth(dob),
    patient_insurance(insurance),
    doctor_name(d_name),
    patient_appointment_time(ap_patient)
{}

// Getter methods
string Patient::getPatientName() const {
    return patient_name;
}

string Patient::getPatientInsurance() const {
    return patient_insurance;
}

string Patient::getPatientDoctorName() const {
    return doctor_name;
}

AppointmentTime Patient::getPatientAppointmentTime() const {
    return patient_appointment_time;
}

Date Patient::get_patient_birth() const {
    return patient_birth;
}

// Setter methods
void Patient::setPatientName(const string& name) {
    patient_name = name;
}

void Patient::setPatientInsurance(const string& insurance) {
    patient_insurance = insurance;
}

void Patient::setDoctorName(const string& name) {
    doctor_name = name;
}

void Patient::setAppointmentTime(const AppointmentTime& time) {
    patient_appointment_time = time;
}

/**
 * Displays all patient info
 */
void Patient::print_patient_info() {
    cout << "Patient Name: " << patient_name << endl;
    cout << "Patient date of birth: " << patient_birth.getDay() << "/" 
         << patient_birth.getMonth() << "/" << patient_birth.getYear() << endl;
    cout << "Patient insurance: " << patient_insurance << endl;
    cout << "Doctor Name: " << doctor_name << endl;
    cout << "Patient appointment time: " << patient_appointment_time.getDay() << " " 
         << patient_appointment_time.getHour() << ":" 
         << (patient_appointment_time.getMinute() < 10 ? "0" : "") 
         << patient_appointment_time.getMinute() << endl;
}

