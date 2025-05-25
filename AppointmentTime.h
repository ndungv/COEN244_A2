#ifndef APPOINTMENTTIME_H
#define APPOINTMENTTIME_H
#include <string>

using namespace std;

class AppointmentTime{
    public:
    AppointmentTime();
    AppointmentTime(string d, int h, int m);
private:
    string day;
    int hour;
    int minute;
};

#endif