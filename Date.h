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
//Getter and setter 



private:
    int year;
    int month;
    int day;
};


#endif
