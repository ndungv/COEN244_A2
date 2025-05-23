#ifndef DOCTOR_H
#define DOCTOR_H


#include "date.h"
#include "Patient.h"

#include "AppointmentRequest.h"

#include "AppointmentTime.h"

#include <string>
#include <array>
using namespace std;

class Doctor{
private:

    string doctor_name;
    array <array<Patient,5>,12> patients;
};

#endif DOCTOR_H