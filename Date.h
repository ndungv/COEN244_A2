/**
 * Date.h
 * Represents a calendar date
 * Handles date validation and storage
 */

#ifndef DATE_H
#define DATE_H
#include <string>
#include <array>
using namespace std;

/**
 * Date class
 * Manages date information with validation
 * Supports dates from 1900 onwards
 */
class Date {
public:
    // Constructors and Destructor
    Date();                          // Default constructor (sets to 1/1/1)
    Date(int day, int month, int year);  // Full constructor
    ~Date();                        // Destructor

    // Getter methods
    int getDay();                   // Get day of month (1-31)
    int getMonth();                 // Get month (1-12)
    int getYear();                  // Get year

    // Setter methods with validation
    void setDay(int day);           // Set day (validates 1-31)
    void setMonth(int month);       // Set month (validates 1-12)
    void setYear(int year);         // Set year (validates >= 1900)

private:
    int year;                       // Year (>= 1900)
    int month;                      // Month (1-12)
    int day;                        // Day (1-31)
};

#endif
