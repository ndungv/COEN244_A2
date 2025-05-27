

#include <iostream>
#include "Date.h"
using namespace std;

/**
 * Default constructor
 */
Date::Date() {
    day = 1;
    month = 1;
    year = 2000;
}

/**
 * Full constructor with validation
 */
Date::Date(int d, int m, int y) {
    // Validate input
    if (y >= 1900 && m >= 1 && m <= 12 && d >= 1 && d <= 31) {
        day = d;
        month = m;
        year = y;
    } else {
        cout << "Invalid date. Setting to default (1/1/2000)" << endl;
        day = 1;
        month = 1;
        year = 2000;
    }
}

/**
 * Destructor
 */
Date::~Date() {
}

// Getter methods
int Date::getDay() {
    return day;
}

int Date::getMonth() {
    return month;
}

int Date::getYear() {
    return year;
}

// Setter methods with validation
void Date::setDay(int d) {
    if (d >= 1 && d <= 31) {
        day = d;
    } else {
        cout << "Invalid day value" << endl;
    }
}

void Date::setMonth(int m) {
    if (m >= 1 && m <= 12) {
        month = m;
    } else {
        cout << "Invalid month value" << endl;
    }
}

void Date::setYear(int y) {
    if (y >= 1900) {
        year = y;
    } else {
        cout << "Invalid year value" << endl;
    }
}






