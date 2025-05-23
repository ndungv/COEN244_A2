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
