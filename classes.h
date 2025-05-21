#ifndef CLASSES_H
#define CLASSES_H
#include <string>
#include <array>
using namespace std;

class Date{
private:
    int year;
    int month;
    int day;
};
class AppointmentTime{
private:
    string day;
    int hour;
    int minute;
};
class Patient{
private:
    string patient_name;
    Date patient_birth;
    string patient_insurance;
    string doctor_name;
    AppointmentTime doctor_appointment_time;

};

class Doctor{
  private:
    string doctor_name;
    array <array<Patient,5>,12> patients;
    };

class AppointmentRequest{
  private:
    string patient_name;
    string doctor_name;
    string appointment_date;
};

class ClinicManager{
  private:
    //An array of pointers to the Patient objects of size 1000.
    //An array of pointers to the Doctor objects of size 10.
    int total_patients_week;
};


#endif CLASSES_H