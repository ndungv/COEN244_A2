

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

 */
AppointmentTime::AppointmentTime() {
    day = "";
    hour = 0;
    minute = 0;
}

/**
 * Full constructor
 */
AppointmentTime::AppointmentTime(string d, int h, int m) {
    day = d;
    hour = h;
    minute = m;
}

/**
 * Destructor
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
