//created by Viet Dung Nguyen 40277173 and Yifan Ding 40129286
#ifndef APPOINTMENTTIME_H
#define APPOINTMENTTIME_H
#include <string>

using namespace std;

class AppointmentTime{
public:
    AppointmentTime();
    AppointmentTime(string day, int hour, int minute);
//Destruction
    ~AppointmentTime();

    //Getter
    string getDay();
    int getHour();
    int getMinute();
    //Setter
    void setDay(string d);
    void setHour(int h);
    void setMinute(int m);

private:
    string day;
    int hour;
    int minute;
};

#endif
