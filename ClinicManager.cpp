#include <iostream>
#include "ClinicManager.h"
#include "Doctor.h"
#include "Patient.h"
using namespace std;

ClinicManager::ClinicManager(){
    patient = new Patient[num_patients];
    doctor = new Doctor[num_doctors];
  }
ClinicManager::~ClinicManager(){
  delete[] patient;
  delete[] doctor;
}

void ClinicManager::insert_patient(){
   string patient_name;
   string insurance;
   string doctor_name;

   cout << "Enter the name of the patient: ";
   cin >> patient_name;
   cout << "Enter the insurance of the patient: ";
   cin >> insurance;
   cout << "Enter the doctor name of the patient: ";
   cin >> doctor_name;

   patient[num_patients] = Patient(patient_name, insurance, doctor_name);
   num_patients++;
}


void ClinicManager::print_all_patients(){
  for (int i = 0; i < num_patients; i++){
  patient[i].print_patient_info();
  }
}
