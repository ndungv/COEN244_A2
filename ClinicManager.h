#ifndef CLINICMANAGER_H
#define CLINICMANAGER_H
#include <string>
#include <array> 
#include "Patient.h"
#include "Doctor.h"
#include "AppointmentRequest.h"
#include "AppointmentTime.h"


using namespace std;

class Patient;
class Doctor;

class ClinicManager {
public:
    ClinicManager();

    ~ClinicManager();

    void insert_patient();
    // void insert_doctor();

    void print_all_patients();

    
//Doctor Insertion
    bool insertDoctor(Doctor* doctor);  
//Appointment Processing    
    AppointmentTime processAppointment(const AppointmentRequest& request); 
//Appointment Cancellation
    bool cancelAppointment(const string& doctorName, const string& patientName, const AppointmentTime& time); 
//Print Doctor Patients  
    void printDoctorPatients(const string& doctorName) const;
private:
    //An array of pointers to the Patient objects of size 1000.
    Patient* patient;
    int num_patients;
    const int max_patients = 1000;
    //An array of pointers to the Doctor objects of size 10.
    Doctor* doctor;
    int num_doctors;
    const int max_doctors = 10;

    int total_patients_week; 
    
    Patient* findPatient(const string& name) const;     
    Doctor* findDoctor(const std::string& name) const; 

};

#endif
