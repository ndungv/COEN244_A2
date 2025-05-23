#ifndef CLINICMANAGER_H
#define CLINICMANAGER_H
#include <string>
#include <array>

using namespace std;

class Patient;
class Doctor;

class ClinicManager {
public:
    ClinicManager();

    ~ClinicManager();

private:
    //An array of pointers to the Patient objects of size 1000.
    Patient *patient;
    //An array of pointers to the Doctor objects of size 10.
    Doctor *doctor;
    int total_patients_week;
};

#endif CLINICMANAGER_H
