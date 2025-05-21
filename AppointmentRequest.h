#ifndef APPOINTMENTREQUEST_H
#define APPOINTMENTREQUEST_H

#include "date.h"
#include "Patient.h"
#include "Doctor.h"

#include "ClinicManager.h"
#include "AppointmentTime.h"

#include <string>
#include <array>
using namespace std;

class AppointmentRequest{
private:
    string patient_name;
    string doctor_name;
    string appointment_date;
};

#endif APPOINTMENTREQUEST_H