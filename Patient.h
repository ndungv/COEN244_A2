/**
 * Patient.h
 * Represents a patient in the clinic system
 * Manages patient information and appointments
 */

#ifndef PATIENT_H
#define PATIENT_H
#include "Date.h"
#include "AppointmentTime.h"
#include <string>
using namespace std;

/**
 * Patient class
 * Stores and manages individual patient information
 * Includes personal details, insurance, and appointment data
 */
class Patient {
public:
    // Constructors
    Patient();  // Default constructor
    Patient(string p_name, const Date& dob, string insurance, string d_name, const AppointmentTime& ap_patient);  // Full constructor

    // Getter methods
    Date get_patient_birth() const;                    // Get patient's birth date
    string getPatientName() const;                     // Get patient's name
    string getPatientInsurance() const;                // Get insurance information
    string getPatientDoctorName() const;               // Get assigned doctor's name
    AppointmentTime getPatientAppointmentTime() const; // Get appointment time

    // Setter methods
    void setPatientName(const string& name);           // Set patient's name
    void setPatientInsurance(const string& insurance); // Set insurance information
    void setDoctorName(const string& name);           // Set doctor's name
    void setAppointmentTime(const AppointmentTime& time); // Set appointment time

    // Utility methods
    void print_patient_info();  // Display patient information

    void insert_patient(string patient_name, string insurance, string doctor_name);

private:
    string patient_name;              // Patient's full name
    Date patient_birth;              // Patient's date of birth
    string patient_insurance;        // Insurance information
    string doctor_name;              // Assigned doctor's name
    AppointmentTime patient_appointment_time;  // Scheduled appointment time
};

#endif
