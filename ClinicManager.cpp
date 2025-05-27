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
//Patient Insertion
bool ClinicManager::insertPatient(Patient* patient) {
    if (patientCount >= 1000) {
        return false;
    }
    for (int i = 0; i < patientCount; i++) {
        if (patients[i]->getName() == patient->getName() && patients[i]->getDateOfBirth() == patient->getDateOfBirth()) {
            return false;
        }
    }
    
    patients[patientCount++] = patient;
    return true;
}

//Doctor Insertion
bool ClinicManager::insertDoctor(Doctor* doctor) {
    if (doctorCount >= 10) return false;
        for (int i = 0; i < doctorCount; i++) {
        if (doctors[i]->getName() == doctor->getName()) {
            return false;
        }
    }
    doctors[doctorCount++] = doctor;
    return true;
}
//Process appointment 
AppointmentTime ClinicManager::processAppointment(const AppointmentRequest& request) {
    Doctor* doctor = findDoctor(request.getDoctorName());
    Patient* patient = findPatient(request.getPatientName());
    
    if (!doctor || !patient) {
        return AppointmentTime(); 
    }
    // Find available time
    for (int hour = 9; hour <= 17; hour++) {
        if (hour == 12 || hour == 13) {
            continue; 
        }
        for (int minute = 0; minute < 60; minute += 30) {
            if (doctor->isTimeSlotAvailable(request.getDay(), hour, minute)) {
                AppointmentTime apt(request.getDay(), hour, minute);          
//refresh patient                
                patient->setDoctorName(doctor->getName());
                patient->setAppointmentTime(apt);
                
//refresh doctor                
                doctor->bookAppointment(patient, request.getDay(), hour, minute);              
                return apt;
            }
        }
    }
//Full    
    return AppointmentTime(); 
}
//Appointment cancellation
bool ClinicManager::cancelAppointment(const string& doctorName, const string& patientName, const AppointmentTime& time) {
    Doctor* doctor = findDoctor(doctorName);
    Patient* patient = findPatient(patientName);
    
    if (!doctor || !patient) {
        return false;
    }
    // Remove the reservation from doctor 
    if (!doctor->cancelAppointment(time.getDay(), time.getHour(), time.getMinute())) {
        return false;
    }

    
    patient->setDoctorName("");
    patient->setAppointmentTime(AppointmentTime());
    return true;
}
//Print doctor patient
void ClinicManager::printDoctorPatients(const string& doctorName) const {
    bool found = false;
    
    for (int i = 0; i < patientCount; i++) {
        if (patients[i]->getPatientDoctorName() == doctorName) {
            cout << "Patient: " << patients[i]->getPatientName() << ", Insurance: " << patients[i]->getPatientInsurance() << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Dr. " << doctorName << " not found "endl;
    }
}

Patient* ClinicManager::findPatient(const string& name) const {
    for (int i = 0; i < patientCount; i++) {
        if (patients[i]->getPatientName() == name) {
            return patients[i];
        }
    }
    return nullptr;
}

Doctor* ClinicManager::findDoctor(const string& name) const {
    for (int i = 0; i < doctorCount; i++) {
        if (doctors[i]->get_name() == name) {
            return doctors[i];
        }
    }
    return nullptr;
}




