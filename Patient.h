#ifndef PATIENT_H
#define PATIENT_H
#include "date.h"

#include "AppointmentRequest.h"

#include "AppointmentTime.h"

#include <string>
#include <array>
using namespace std;

class Patient{
    public:
        Patient();
    private:
        string patient_name;
        Date patient_birth;
        string patient_insurance;
        string doctor_name;
        AppointmentTime doctor_appointment_time;

};

#endif PATIENT_H