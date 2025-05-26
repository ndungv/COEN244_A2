#include <iostream>
#include "Doctor.h"

using namespace std;

Doctor::Doctor(){
doctor_name = "";
  }
Doctor::~Doctor() {
cout << "Doctor: " << doctor_name << "destroyed. " << endl; 
}
Doctor::Doctor(string d_name){
    doctor_name = d_name;
  }
