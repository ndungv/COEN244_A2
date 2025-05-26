#ifndef DATE_H
#define DATE_H
#include <string>
#include <array>
using namespace std;

class Date {
public:
    Date();
    Date(int day, month, year);

//destruction
    ~Date();

//Getter and setter 
    int getDay() const;
    void setDay(int day);
    int getMonth() const;
    void setMonth(int month);
    int getYear() const;
    void setYear(int year);

private:
    int year;
    int month;
    int day;
};


#endif
