#include <iostream>
#include "Patient.h"
using namespace std;


Patient::Patient() {
    patient_name = "";
    patient_insurance = "";
    doctor_name = "";
}

Patient::Patient(string p_name, string insurance, string d_name) {
    patient_name = p_name;;
    patient_insurance = insurance;
    doctor_name = d_name;
} 

void Patient::print_patient_info() {
    cout<<"Patient Name: "<<patient_name<<endl;
    cout << "Patient insurance: "<<patient_insurance<<endl;
    cout << "Doctor Name: "<<doctor_name<<endl;
}

