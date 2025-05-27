

#include <iostream>
#include "Doctor.h"
#include <iomanip>

using namespace std;

/**
 * Default constructor
 */
Doctor::Doctor() {
    doctor_name = "";
    // Initialize all appointment slots to nullptr
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 5; j++) {
            patients_with_appointment[i][j] = nullptr;
        }
    }
}

/**
 * Destructor
 */
Doctor::~Doctor() {
    // Delete all dynamically allocated Patient objects
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 5; j++) {
            if (patients_with_appointment[i][j] != nullptr) {
                delete patients_with_appointment[i][j];
                patients_with_appointment[i][j] = nullptr;
            }
        }
    }
    cout << "Doctor: " << doctor_name << " destroyed." << endl; 
}

/**
 * Constructor with name parameter
 */
Doctor::Doctor(string d_name) {
    doctor_name = d_name;
    // Initialize all appointment slots to nullptr
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 5; j++) {
            patients_with_appointment[i][j] = nullptr;
        }
    }
}

/**
 * Copy constructor
 */
Doctor::Doctor(const Doctor &another_doctor) {
    doctor_name = another_doctor.doctor_name;
    // Initialize all slots to nullptr first
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 5; j++) {
            patients_with_appointment[i][j] = nullptr;
        }
    }
    // Now copy only the non-null pointers
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 5; j++) {
            if (another_doctor.patients_with_appointment[i][j] != nullptr) {
                // Create a new Patient object with the same data
                Patient* original = another_doctor.patients_with_appointment[i][j];
                patients_with_appointment[i][j] = new Patient(
                    original->getPatientName(),
                    original->get_patient_birth(),
                    original->getPatientInsurance(),
                    original->getPatientDoctorName(),
                    original->getPatientAppointmentTime()
                );
            }
        }
    }
} 

/**
 * Books an appointment for a patient
 */
bool Doctor::book_appointment(Patient* patient, int day_index, int time_index) {
    // Validate indices
    if (day_index < 0 || day_index >= 5 || time_index < 0 || time_index >= 12) {
        cout << "Invalid appointment time slot." << endl;
        return false;
    }
    // Check if slot is available
    if (patients_with_appointment[time_index][day_index] != nullptr) {
        cout << "The selected time slot is not available." << endl;
        return false;
    } 
    patients_with_appointment[time_index][day_index] = patient;
    cout << "Appointment successfully booked." << endl;
    return true;
}

/**
 * Cancels an appointment
 */
void Doctor::cancel_appointment(int day_index, int time_index) {
    if (day_index >= 0 && day_index < 5 && time_index >= 0 && time_index < 12) {
        if (patients_with_appointment[time_index][day_index] != nullptr) {
            patients_with_appointment[time_index][day_index] = nullptr;
            cout << "Now cancelled " << endl;
        } else {
            cout << "This time slot is already available." << endl;
        }
    } else {
        cout << "Invalid time slot selected." << endl;
    }
}

/**
 * Displays the doctor's weekly schedule
 */
void Doctor::doctor_schedule() const {
    const string days[5] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    
    cout << doctor_name << "'s Schedule:" << endl;
    
    // Print header with fixed width columns
    cout << "\nTime     ";  // 8 spaces for time
    for (const string& day : days) {
        cout << left << setw(12) << day;  // 12 spaces for each day
    }
    cout << endl;
    cout << string(68, '-') << endl;  // 68 = 8 + (12 * 5)
    
    for (int time = 0; time < 12; ++time) {
        // Calculate hour and minute
        int base_hour = (time < 6) ? 9 : 14;
        int hour = base_hour + (time % 6) / 2;
        int minute = (time % 2) * 30;

        // Print time with proper formatting
        printf("%02d:%02d   ", hour, minute);  // 8 spaces total
        
        // Print appointments/availability for each day
        for (int day = 0; day < 5; day++) {
            if (patients_with_appointment[time][day] != nullptr) {
                cout << left << setw(12) << patients_with_appointment[time][day]->getPatientName();
            } else {
                cout << left << setw(12) << "Available";
            }
        }
        cout << endl;
    }
    cout << string(68, '-') << endl;
}

/**
 * Gets the doctor's name
 */
string Doctor::get_name() const {
    return doctor_name;
}



