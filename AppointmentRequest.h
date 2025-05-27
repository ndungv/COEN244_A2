//created by Viet Dung Nguyen 40277173 and Yifan Ding 40129286
#ifndef APPOINTMENTREQUEST_H
#define APPOINTMENTREQUEST_H


#include <string>
#include <array>
using namespace std;

class AppointmentRequest {
public:
    AppointmentRequest(); 
    AppointmentRequest(string p_name, string d_name, string ap_date);

// Getter and setters
  string getPatientName() const;
  void setPatientName(string p_name);
  string getDoctorName() const;
  void setDoctorName(string d_name);
  string getAppointmentDate() const;
  void setAppointmentDate(string ap_date);

private:
    string patient_name;
    string doctor_name;
    string appointment_date;
};

#endif
