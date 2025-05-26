#ifndef APPOINTMENTTIME_H
#define APPOINTMENTTIME_H
#include <string>

using namespace std;

class AppointmentTime{
public:
    AppointmentTime();
    AppointmentTime(string d, int h, int m);
//Destruction
    ~AppointmentTime();

//Getter and setter
    string getDay() const;
    void setDay(string d);
    int getHour() const;
    void setHour(int h);
    int getMinute() const;
    void setMinute(int m);

private:
    string day;
    int hour;
    int minute;
};

#endif
