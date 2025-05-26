#include <iostream>
#include "ClinicManager.h"
#include "Doctor.h"
#include "Patient.h"
using namespace std;

ClinicManager::ClinicManager() {
    patient = new Patient[num_patients];
    doctor = new Doctor[num_doctors];
}

ClinicManager::~ClinicManager() {
    delete[] patient;
    delete[] doctor;
}

void ClinicManager::insert_patient() {
    string patient_name;
    int dob_date;
    int dob_month;
    int dob_year;
    string insurance;
    string doctor_name;
    string ap_date;
    int ap_hour;
    int ap_minute;


    cout << "Enter the name of the patient: ";
    cin >> patient_name;
    cout <<"Enter Patient date of birth (date month year - separated by space) "<<endl;
    cin >> dob_date>>dob_month>>dob_year;
    Date patient_birth(dob_date,dob_month,dob_year);
    cout << "Enter the insurance of the patient: ";
    cin >> insurance;
    cout << "Enter the doctor name of the patient: ";
    cin >> doctor_name;
    cout << "Enter the patient appointment time: "<<endl;
    cin >> ap_date>>ap_hour>>ap_minute;
    AppointmentTime ap_patient(ap_date, ap_hour, ap_minute);

    if (num_patients >= 1) {
        bool duplicate = false;
        for (int i = 0; i < num_patients; i++) {
            bool name_match = (patient_name == patient[i].getPatientName());
            bool dob_match = (dob_date == patient[i].get_patient_birth().getDay() &&
                              dob_month == patient[i].get_patient_birth().getMonth() &&
                              dob_year == patient[i].get_patient_birth().getYear());
            bool insurance_match = (insurance == patient[i].getPatientInsurance());
            bool doctor_match = (doctor_name == patient[i].getPatientDoctorName());
            bool appointment_match = (ap_date == patient[i].getPatientAppointmentTime().getDay() &&
                                      ap_hour == patient[i].getPatientAppointmentTime().getHour() &&
                                      ap_minute == patient[i].getPatientAppointmentTime().getMinute());

            if (name_match && dob_match && insurance_match && doctor_match && appointment_match) {
                cout <<"Patient exists! Please re-enter patient info"<<endl;
                ClinicManager::insert_patient();
                duplicate = true;
                break;
            }
        }
        if (!duplicate) {
            cout <<"Patient added!"<<endl;
            patient[num_patients] = Patient(patient_name, patient_birth, insurance, doctor_name,ap_patient);
            num_patients++;
            cout <<"Current number of patients: "<<num_patients<<endl;
        }
    }

    else {
        cout <<"Patient added!"<<endl;
        patient[num_patients] = Patient(patient_name, patient_birth, insurance, doctor_name,ap_patient);
        num_patients++;
        cout <<"Current number of patients: "<<num_patients<<endl;
    }
}



void ClinicManager::print_all_patients() {
    for (int i = 0; i < num_patients; i++) {
        cout<< "---------Patient "<<i+1<<"----------"<<endl;
        patient[i].print_patient_info();
        cout <<"-------------------------"<<endl;
    }
}
