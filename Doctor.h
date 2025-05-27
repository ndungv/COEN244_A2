
#ifndef DOCTOR_H
#define DOCTOR_H

#include "AppointmentRequest.h"
#include "AppointmentTime.h"
#include "Patient.h"
#include <string>
#include <array>

using namespace std;
class Patient;

/**
 * Doctor class
 */
class Doctor {
public:
    // Constructors and Destructor
    Doctor();                                // Default constructor
    Doctor(string d_name);                   // Constructor with name
    Doctor(const Doctor &another_doctor);    // Copy constructor
    ~Doctor();                               // Destructor

    // Appointment Management
    bool book_appointment(Patient* patient, int day_index, int time_index);  // Book a new appointment
    void cancel_appointment(int day_index, int time_index);                  // Cancel an appointment
    void doctor_schedule() const;                                            // Display doctor's schedule

    // Getters
    string get_name() const;                 // Get doctor's name

private:
    string doctor_name;                      // Doctor's name
    array<array<Patient *, 5>, 12> patients_with_appointment;  // 2D array for appointment schedule
                                            // First dimension: 12 time slots (9:00-12:00, 14:00-17:00)
                                            // Second dimension: 5 weekdays (Monday-Friday)
};

#endif
