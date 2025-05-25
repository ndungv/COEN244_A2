#ifndef APPOINTMENTREQUEST_H
#define APPOINTMENTREQUEST_H


#include <string>
#include <array>
using namespace std;

class AppointmentRequest {
public:
    AppointmentRequest();

    AppointmentRequest(string p_name, string d_name, string ap_date);

private:
    string patient_name;
    string doctor_name;
    string appointment_date;
};

#endif
