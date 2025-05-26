#ifndef DOCTOR_H
#define DOCTOR_H

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

//check if book/cancel successfully or not
    bool book_appointment(Patient* patient, int day_index, int time_index);
    void cancel_appointment(int day_index, int time_index);
//doctor schedule
    void doctor_schedule() const;
//getter
    string get_name() const;


private:
    string doctor_name;
    array<array<Patient *, 5>, 12> patients_with_appointment;
};

#endif
