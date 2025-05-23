#ifndef CLINICMANAGER_H
#define CLINICMANAGER_H


#include "Patient.h"
#include "Doctor.h"

#include <string>
#include <array>


using namespace std;


class ClinicManager{
private:

    //An array of pointers to the Patient objects of size 1000.
    Patient *patient;
    //An array of pointers to the Doctor objects of size 10.
    Doctor *doctor;
    int total_patients_week;
};

#endif CLINICMANAGER_H