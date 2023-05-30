/* Lexi Katramados                                                                                                    
   CPSC 1070: 005
   E2: Runtime Terror                                                                                               
   3/10/23 */

#ifndef DATE_H // used to prevent a header file from being inlcuded twice
#define DATE_H
#include <string>
using namespace std;

class Date {
public:
  // Default constructor to Jan 1st, 2000
  Date () {
    month = 1;
    day = 1;
    year = 2000;
  }

  // Overloaded constructor
  Date (int month, int day, int year) {
    setMonth(month);
    setDay(day);
    setYear(year);
  }

  // Accessors
  int getMonth();
  int getDay();
  int getYear();

  // Mutators
  void setMonth(int month);
  void setDay(int day);
  void setYear(int year);

  // Overloaded operators
  Date operator+(int days);
  Date operator-(int days);

  // Prefix and postfix
  Date operator++(void);
  Date operator++(int);
  Date operator--(void);
  Date operator--(int);

  // Implements the mystery machine
  string getDayOfWeek();

  // Declare variables
  int month;
  int day;
  int year;
};
#endif
