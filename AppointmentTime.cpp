#include <iostream>
#include "AppointmentTime.h"
using namespace std;
AppointmentTime::AppointmentTime(){
    day = "";
  hour = -1;
  minute = -1;
}
AppointmentTime::AppointmentTime(string d, int h, int m){
  day = d;
  hour = h;
  minute = m;
}