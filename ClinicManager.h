/**
 * ClinicManager.h
 * Main class for managing the clinic's operations
 * Handles patients, doctors, and appointments
 */

#ifndef CLINICMANAGER_H
#define CLINICMANAGER_H
#include <string>
#include <array> 
#include "Patient.h"
#include "Doctor.h"
#include "AppointmentRequest.h"
#include "AppointmentTime.h"

using namespace std;

class Patient;
class Doctor;

/**
 * ClinicManager class
 * Central management system for the clinic
 * Manages patient records, doctor schedules, and appointment bookings
 */
class ClinicManager {
public:
    // Constructors and Destructor
    ClinicManager();
    ~ClinicManager();

    // Patient Management
    void insert_patient();        // Register a new patient
    void print_all_patients();    // Display all registered patients
    
    // Doctor Management
    void insert_doctor();         // Register a new doctor
    void print_all_doctors();     // Display all registered doctors
    bool insert_doctor(Doctor* doctor);  // Insert a pre-created doctor object
    
    // Appointment Management
    AppointmentTime process_appointment(const AppointmentRequest& request);  // Process new appointment request
    bool cancel_appointment(const string& doctorName, const string& patientName, const AppointmentTime& time);  // Cancel existing appointment
    void print_doctor_patients(const string& doctorName) const;  // Show all patients for a specific doctor

private:
    // Patient storage
    Patient** patients;           // Dynamic array of patient pointers
    int patient_count;            // Current number of patients
    const int max_patients = 1000;  // Maximum allowed patients
    
    // Doctor storage
    Doctor** doctors;             // Dynamic array of doctor pointers
    int doctor_count;             // Current number of doctors
    const int max_doctors = 10;   // Maximum allowed doctors

    int total_patients_week;      // Track total patients per week
    
    // Helper functions
    Patient* find_patient(const string& name) const;     // Find patient by name
    Doctor* find_doctor(const string& name) const;       // Find doctor by name
};

#endif
