#include <iostream>
#include "date.h"
#include "Patient.h"
#include "Doctor.h"
#include "AppointmentRequest.h"
#include "ClinicManager.h"
#include "AppointmentTime.h"
using namespace std;

//❗I don't think day, month, and year should be negative, instead it should start from 1 ???
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
Date::Date(int day, int month, int year) {
day = day; 
month = month;
year = year;
}

//Destruction
Date::~Date(){
  cout << "Date: destroyed" << endl;  
}
//Getter and Setter's return
int Date::getDay() const { 
  return day; 
}
void Date::setDay(int day) { 
  this->day = day;
}
int Date::getMonth() const {
  return month; 
}
void Date::setMonth(int month) {       
  this->month = month;
}
int Date::getYear() const {
  return year; 
}
void Date::setYear(int year) {
  this->year = year; 
}





