#ifndef APPOINTMENTTIME_H
#define APPOINTMENTTIME_H

#include "date.h"
#include "Patient.h"
#include "Doctor.h"
#include "AppointmentRequest.h"
#include "ClinicManager.h"

#include <string>
#include <array>
using namespace std;

class AppointmentTime{
private:
    string day;
    int hour;
    int minute;
};

#endif APPOINTMENTTIME_H