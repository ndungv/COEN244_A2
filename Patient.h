#ifndef PATIENT_H
#define PATIENT_H
#include "date.h"
#include "AppointmentTime.h"
#include <string>
using namespace std;

class Patient {
public:
    Patient();

    Patient(string p_name, string insurance, string d_name);

    void insert_patient(string patient_name, string insurance, string doctor_name);
    void print_patient_info() const;

private:
    string patient_name;
    Date patient_birth;
    string patient_insurance;
    string doctor_name;
    AppointmentTime doctor_appointment_time;
};

#endif
