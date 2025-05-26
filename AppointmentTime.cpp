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

//Default
AppointmentTime::AppointmentTime(){
    day = "";
    hour = 0;
    minute = 0;
}

AppointmentTime::AppointmentTime(string d, int h, int m){
  day = d;
  hour = h;
  minute = m;
}
//Destruction 
AppointmentTime::~AppointmentTime() {
    cout << "AppointmentTime: destroyed" << endl;
}
//Getter and Setters 
string AppointmentTime::getDay() {
 return day; 
}
void AppointmentTime::setDay(string d) {
 day = d; 
}
int AppointmentTime::getHour() {
 return hour; 
}
void AppointmentTime::setHour(int h) {
 hour = h; 
}
int AppointmentTime::getMinute() {
 return minute; 
}
void AppointmentTime::setMinute(int m) {
 minute = m; 
}
