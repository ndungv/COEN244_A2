#include <iostream>
#include "ClinicManager.h"
#include "Doctor.h"
#include "Patient.h"
using namespace std;

ClinicManager::ClinicManager(){
    patient = new Patient[1000];
    doctor = new Doctor[10];
  }

