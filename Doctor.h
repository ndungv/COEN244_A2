#ifndef DOCTOR_H
#define DOCTOR_H

#include "date.h"
#include "AppointmentRequest.h"

#include "AppointmentTime.h"
#include "Patient.h"

#include <string>
#include <array>
using namespace std;
class Patient;
class Doctor {
public:
    Doctor();

    Doctor(string d_name);

    Doctor(const Doctor &another_doctor);

    ~Doctor();

private:
    string doctor_name;
    array<array<Patient *, 5>, 12> patients_with_appointment;
};

#endif DOCTOR_H
