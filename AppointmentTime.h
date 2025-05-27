

#ifndef APPOINTMENTTIME_H
#define APPOINTMENTTIME_H
#include <string>

using namespace std;

/**
 * AppointmentTime class
 * Handles the scheduling details of appointments
 * Stores day of week and time information
 */
class AppointmentTime {
public:
    // Constructors and Destructor
    AppointmentTime();                                     // Default constructor
    AppointmentTime(string day, int hour, int minute);    // Full constructor
    ~AppointmentTime();                                   // Destructor

    // Getter methods
    string getDay() const;    // Get day of the week
    int getHour() const;      // Get hour (24-hour format)
    int getMinute() const;    // Get minute

    // Setter methods
    void setDay(string d);    // Set day of the week
    void setHour(int h);      // Set hour
    void setMinute(int m);    // Set minute

private:
    string day;              // Day of the week (Monday-Friday)
    int hour;               // Hour in 24-hour format
    int minute;            // Minute (0 or 30 for half-hour slots)
};

#endif
