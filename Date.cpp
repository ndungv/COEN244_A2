#include <iostream>
#include "Date.h" //I saw you changed this to date.h, it should be Date.h. Rename your file
#include "Patient.h"
#include "Doctor.h"
#include "AppointmentRequest.h"
#include "ClinicManager.h"
#include "AppointmentTime.h"
using namespace std;

//❗I don't think day, month, and year should be negative, instead it should start from 1 ???
// => Yea it just a null data placeholder like " " of string
/*
Date::Date(){
day = -1;
month = -1;
year = -1;
}
*/

//Initialization
//Day, month, and year should not be negative
Date::Date() : day(1), month(1), year(1) {
  
}

//Parameterized constructor
Date::Date(int d, int m, int y) {
day = d;
month = m;
year = y;
}

//Destruction
Date::~Date(){
  cout << "Date: destroyed" << endl;  
}
//Getter and Setter's return
int Date::getDay() {
  return day; 
}
void Date::setDay(int day) { 
  this->day = day;
}
int Date::getMonth() {
  return month; 
}
void Date::setMonth(int month) {       
  this->month = month;
}
int Date::getYear() {
  return year; 
}
void Date::setYear(int year) {
  this->year = year; 
}





