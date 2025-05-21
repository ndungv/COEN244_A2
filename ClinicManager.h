#ifndef CLINICMANAGER_H
#define CLINICMANAGER_H

#include "date.h"
#include "Patient.h"
#include "Doctor.h"
#include "AppointmentRequest.h"
#include "AppointmentTime.h"
#include "Patient.h"

#include <string>
#include <array>


using namespace std;

class Patient;

class ClinicManager{
private:

    //An array of pointers to the Patient objects of size 1000.
    Patient *patient;
    //An array of pointers to the Doctor objects of size 10.
    Doctor *doctor;
    int total_patients_week;
};

#endif CLINICMANAGER_H