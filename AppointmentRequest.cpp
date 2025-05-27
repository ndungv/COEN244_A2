//created by Viet Dung Nguyen 40277173 and Yifan Ding 40129286

#include <iostream>
#include "AppointmentRequest.h"
using namespace std; 

AppointmentRequest::AppointmentRequest(){
    patient_name = "";
    doctor_name = "";
    appointment_date = "";
}

AppointmentRequest::AppointmentRequest(string p_name, string d_name, string ap_date){
    patient_name = p_name;
       doctor_name = d_name;
       appointment_date = ap_date;

}
//Getter and Setters 
string AppointmentRequest::getPatientName() const {
    return patient_name;
}
void AppointmentRequest::setPatientName(string p_name) {
    patient_name = p_name;
}

string AppointmentRequest::getDoctorName() const {
    return doctor_name;
}
void AppointmentRequest::setDoctorName(string d_name) {
    doctor_name = d_name;
}

string AppointmentRequest::getAppointmentDate() const {
    return appointment_date;
}
void AppointmentRequest::setAppointmentDate(string ap_date) {
    appointment_date = ap_date;
}
