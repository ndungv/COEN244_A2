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

    void insert_patient();
    // void insert_doctor();

    void print_all_patients();

private:
    //An array of pointers to the Patient objects of size 1000.
    Patient *patient;
    int num_patients;
    const int max_patients = 1000;
    //An array of pointers to the Doctor objects of size 10.
    Doctor *doctor;
    int num_doctors;
    const int max_doctors = 10;

    int total_patients_week; // total patients per week
};

#endif
