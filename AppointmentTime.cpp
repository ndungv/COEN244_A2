/**
 * AppointmentTime.cpp
 * Implementation of the AppointmentTime class
 * Handles time-related functionality for appointments
 */

#include <iostream>
#include "AppointmentTime.h"
using namespace std;

//again, I don't think hour and minute should be negative, maybe I am wrong, idk
/*
AppointmentTime::AppointmentTime(){
    day = "";
  hour = -1;
  minute = -1;
}
*/

/**
 * Default constructor
 * Initializes an empty appointment time
 */
AppointmentTime::AppointmentTime() {
    day = "";
    hour = 0;
    minute = 0;
}

/**
 * Full constructor
 * @param d Day of the week (Monday-Friday)
 * @param h Hour in 24-hour format
 * @param m Minute (typically 0 or 30)
 */
AppointmentTime::AppointmentTime(string d, int h, int m) {
    day = d;
    hour = h;
    minute = m;
}

/**
 * Destructor
 * No dynamic memory to clean up
 */
AppointmentTime::~AppointmentTime() {
}

// Getter methods
string AppointmentTime::getDay() const {
    return day;
}

int AppointmentTime::getHour() const {
    return hour;
}

int AppointmentTime::getMinute() const {
    return minute;
}

// Setter methods
void AppointmentTime::setDay(string d) {
    day = d;
}

void AppointmentTime::setHour(int h) {
    hour = h;
}

void AppointmentTime::setMinute(int m) {
    minute = m;
}
