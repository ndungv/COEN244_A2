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
// Copy construction_day and time
Doctor::Doctor(const Doctor &another_doctor){
  doctor_name = another_doctor.doctor_name
    for (int i = 0; i < 12; i++) {
      for (int j = 0; j < 5; j++) {
          patients_with_appointment[i][j] = another_doctor.patients_with_appointment[i][j];
      }
    }
} 
//book appointment 
bool Doctor::book_appointment(Patient* patient, int day_index, int time_index) {
//day should not be negative, business day: 5 days max. So do the time, max 12 hours
    if (day_index < 0 || day_index >= 5 || time_index < 0 || time_index >= 12) {
        cout << "Wrong time" << endl;
        return false;
    }
//check available or not
  if (patients_with_appointment[time_index][day_index] != nullptr) {
        cout << "No place available!" << endl;
        return false;
    } 
  patients_with_appointment[time_index][day_index] = patient;
  cout << "u now booked. " << endl;
    return true;
}
//cancel appointment
void Doctor::cancel_appointment(int day_index, int time_index) {
    if (day_index >= 0 && day_index < 5 && time_index >= 0 && time_index < 12) {
        if (patients_with_appointment[time_index][day_index] != nullptr) {
            patients_with_appointment[time_index][day_index] = nullptr;
            cout << "Now cancelled " << endl;
        } else {
            cout << "This time is still available " << endl;
        }
    } else {
        cout << "Wrong time-choosing " << endl;
    }
}
//doctor schedule for business day
void Doctor::doctor_schedule() const {
    const string days[5] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    
    cout << doctor_name << " 's Schedule: \n" << "Time" << endl;
    for (day : days) {
        cout << day;
    }	
    cout << endl;
    
for (int time = 0; time < 12; ++time) {
//if else case of hour and minute 9:00-12:00 (morning) and 14:00-17:00 (afternoon)
//morning or afternoon
        int hour = (time < 6) ? 9 + time/2 : 14 + (time-6)/2;
//30min check 
        int minute = (time % 2) ? 30 : 0;

        cout << hour << ":" <<minute << endl;
        
        for (int day = 0; day < 5; day++) {
          //if else case
            cout << (patients_with_appointment[time][day] ? patients_with_appointment[time][day]->get_name() : " Available ");
        }
        cout << endl;
    }
}
string Doctor::get_name() const {
    return doctor_name;
}



