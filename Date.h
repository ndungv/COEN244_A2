#ifndef DATE_H
#define DATE_H
#include <string>
#include <array>
using namespace std;

class Date {
public:
    Date();

    Date(int day, int month, int year);

    //destruction
    ~Date();

    //Getter function
    //Getter function
    int getDay();

    int getMonth();

    int getYear();

    //Setter function
    void setDay(int day);

    void setMonth(int month);

    void setYear(int year);

private:
    int year;
    int month;
    int day;
};


#endif
