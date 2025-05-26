#include <iostream>
#include "Patient.h"
using namespace std;


Patient::Patient() {
    patient_name = "";
    patient_insurance = "";
    doctor_name = "";
}

Patient::Patient(string p_name,const Date& dob, string insurance, string d_name, const AppointmentTime& ap_patient) :
    patient_name(p_name),
    patient_birth(dob),
    patient_insurance(insurance),
    doctor_name (d_name),
    patient_appointment_time (ap_patient)
{}

//Getter function

string Patient::getPatientName() {
    return patient_name;
}
string Patient::getPatientInsurance() {
    return patient_insurance;
}
string Patient::getPatientDoctorName() {
    return doctor_name;
}
AppointmentTime Patient::getPatientAppointmentTime() {
    return patient_appointment_time;
}

Date Patient::get_patient_birth() const {
    return patient_birth;
}

void Patient::print_patient_info() {
    cout<<"Patient Name: "<<patient_name<<endl;
    cout <<"Patient date of birth: "<<patient_birth.getDay()<<patient_birth.getMonth()<<patient_birth.getYear()<<endl;
    cout << "Patient insurance: "<<patient_insurance<<endl;
    cout << "Doctor Name: "<<doctor_name<<endl;
    cout <<"Patient appointment time: "<<patient_appointment_time.getDay()<<patient_appointment_time.getHour()<<patient_appointment_time.getMinute()<<endl;
}

