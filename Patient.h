#ifndef PATIENT_H
#define PATIENT_H
#include "Date.h"
#include "AppointmentTime.h"
#include <string>
using namespace std;

class Patient {
public:
    Patient();

    Patient(string p_name,const Date& dob, string insurance, string d_name, const AppointmentTime& ap_patient);

    Date get_patient_birth() const;

    string getPatientName();
    string getPatientInsurance();
    string getPatientDoctorName();
    AppointmentTime getPatientAppointmentTime();

    void insert_patient(string patient_name, string insurance, string doctor_name);
    void print_patient_info(); //this function does not need const

private:
    string patient_name;
    Date patient_birth;
    string patient_insurance;
    string doctor_name;
    AppointmentTime patient_appointment_time;
};

#endif
