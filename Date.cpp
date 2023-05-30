/* Lexi Katramados                                                                                                 
   CPSC 1070: 005                                                                                                     
   E2: Runtime Terror                                                                                                
   3/10/23 */

// File headers
#include <iostream> // allows us to do input and output (cin and cout)
#include <string> // allows us to do mathematical functionsuse strings
#include "Date.h" // allows us to implement Date class
#include "ParkingWars.h" // allows us to implement ParkingWars class
#include "MysteryMachine.h" // allows us to implement MysteryMachine class

using namespace std;

// Method to return month from user
int Date :: getMonth() {
  return month;
}

// Method to return day from user
int Date :: getDay() {
  return day;
}

// Method to return year from user
int Date :: getYear() { 
  return year;
}

// Method to set user input for month into private variable
void Date :: setMonth (int userMonth) {
  month = userMonth;
}

// Method to set user input for day into private variable
void Date :: setDay (int userDay) {
  day = userDay;
}

// Method to set user input for year into private variable
void Date :: setYear (int userYear) {
  year = userYear;
}

// Method to get day of the week depending on date
string Date :: getDayOfWeek() {
  // Make object of MysteryMachine type, call method, and return
  MysteryMachine mystMach;
  return mystMach.getDayOfWeek(*this);
}

// Method to increase days by a certain number of days
Date Date :: operator+(int days) {

  // Make a variable to hold day of week and object
  Date newDate;
  string weekday = getDayOfWeek();

  // Make a for loop to iterate through the number of days inputed as a parameter
  for (int i = 0; i < days; ++i) {
  // See what day of the week user picked, and increment accordingly
  if (weekday == "Friday") {
    ++day;
    ++day;
    ++day;
  }
  else if (weekday == "Saturday") {
    ++day;
    ++day;
  }
  else {
    ++day;
  }

  // Check if it's on the last day of a month
  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
    if (day > 31) {
      ++month;
      day = day - 31;
    }
  }
  else if (month == 2) {
    if (day > 28) {
      ++month;
      day = day - 28;
    }
  }
  else if (month == 4 || month == 6 || month == 9 || month == 11) {
    if (day > 30) {
      ++month;
      day = day - 30;
    }
  }
  
  // If it's the last day of December, increment year and reset year
  if (month == 13) {
    month = 1;
    ++year;
  }

  // Use object to change and return new date
  newDate.setDay(day);
  newDate.setMonth(month);
  newDate.setYear(year);
  weekday = getDayOfWeek();
  } // end of for loop

  // Gets final info outside loop and returns
  newDate.setDay(day);
  newDate.setMonth(month);
  newDate.setYear(year);
  return newDate;
}

// Method to decrease days by a certain number of days
Date Date :: operator-(int days) {

  // Make a variable to hold day of week, object, and other necessary variables
  Date newDate;
  string weekday = getDayOfWeek();
  int tempVar = day;
  int num;

  // Make a for loop to iterate through the number of days inputed as a parameter
  for (int i = days; i > 0; --i) {

  // See what day of the week user picked, and increment accordingly
  if (weekday == "Monday") {
      --day;
      --day;
      --day;
      num = tempVar - 3;
      tempVar = day;
    }
  else if (weekday == "Sunday") {
      --day;
      --day;
      num = tempVar - 2;
      tempVar = day;
  }
  else {
    --day;
    num = tempVar - 1;
    tempVar = day;
  }

  // Check if it's on the last day of a month
  if ((month == 5 || month == 7 || month == 10 || month == 12) && (day <= 0)) {
    tempVar = num;
    if (num <= 0) {
      num = num + 30;
      tempVar = num;
    }
    --month;
  }
  else if (month == 3 && day <= 0) {
    tempVar = num;
    if (num <= 0) {
      num = num + 28;
      tempVar = num;
    }
    --month;
  }
  else if ((month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11) && (day <= 0)) {
    tempVar = num;
    if (num <= 0) {
      num = num + 31;
      tempVar = num;
    }
    month = 12;
    --year;
  }
  else if (month == 1 && day <=0) {
    tempVar = num;
    if (num <= 0) {
      num = num + 31;
      tempVar = num;
    }
    month = 12;
    --year;
  }
    
  // Use object to change and return new date
  day = tempVar;
  newDate.setDay(day);
  newDate.setMonth(month);
  newDate.setYear(year);
  weekday = getDayOfWeek();
  } // end of for loop

  // Gets final info outside loop and returns
  newDate.setDay(day);
  newDate.setMonth(month);
  newDate.setYear(year);
  return newDate;
}

// Method to increment days, months, and years prefix
Date Date :: operator++(void) {

  // Make a variable to hold day of week
  string weekday = getDayOfWeek();

  // See what day of the week user picked, and increment accordingly
  if (weekday == "Friday") {
      ++day;
      ++day;
      ++day;
    }
  else if (weekday == "Saturday") {
      ++day;
      ++day;
  }
  else {
    ++day;
  }
  
  // Check if it's on the last day of a month
  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
    if (day > 31) {
      ++month;
      day = day - 31;
    }
  }
  else if (month == 2) {
    if (day > 28) {
      ++month;
      day = day - 28;
    }
  }
  else if (month == 4 || month == 6 || month == 9 || month == 11) {
    if (day > 30) {
      ++month;
      day = day - 30;
    }
  }

  // If it's the last day of December, increment year and reset year
  if (month == 13) {
    month = 1;
    ++year;
  }

  // Make object to change and return new date
  Date newDate;
  newDate.setDay(day);
  newDate.setMonth(month);
  newDate.setYear(year);
  return newDate;
}

// Method to increment days, months, years postfix
Date Date :: operator++(int) {

 // Make object to change                                                                        
  Date newDate;
  newDate.setDay(day);
  newDate.setMonth(month);
  newDate.setYear(year);

  // Make variable to hold day of the week
  string weekday = getDayOfWeek();

  // See what day of the week user picked, and increment accordingly
  if (weekday == "Friday") {
      day++;
      day++;
      day++;
    }
  else if (weekday == "Saturday") {
      day++;
      day++;
  }
  else {
    day++;
  }
  
  // Check if it's on the last day of a month
  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
    if (day > 31) {
      month++;
      day = day - 31;
    }
  }
  else if (month == 2) {
    if (day > 28) {
      month++;
      day = day - 28;
    }
  }
  else if (month == 4 || month == 6 || month == 9 || month == 11) {
    if (day > 30) {
      month++;
      day = day - 30;
    }
  }

  // If it's the last day of December, increment year and reset year
  if (month == 13) {
    month = 1;
    year++;
  }

  // Return date
  return newDate;
}

// Method to decrement days, months, years prefix
Date Date :: operator--(void) {

  // Make a variable to hold day of week
  string weekday = getDayOfWeek();
  int tempVar = day;
  int num;

  // See what day of the week user picked, and increment accordingly
  if (weekday == "Monday") {
      --day;
      --day;
      --day;
      num = tempVar - 3;
      tempVar = day;

      if (month == 1 && day == -1) {
	month = 12;
	day = 31;
	--year;
      }
    }
  else if (weekday == "Sunday") {
      --day;
      --day;
      num = tempVar - 2;
      tempVar = day;
  }
  else if (month == 2 && day == 1) {
      month = 1;
      day = 31;
  }
  else {
      --day;
      num = tempVar - 1;
      tempVar = day;
  }
  
  // Check if it's on the last day of a month
  if ((month == 5 || month == 7 || month == 10 || month == 12) && (day <= 0)) {
    tempVar = num;
    if (num <= 0) {
      num = num + 30;
      tempVar = num;
    }
    --month;
  }
  else if (month == 3 && day <= 0) {
    tempVar = num;
    if (num <= 0) {
      num = num + 28;
      tempVar = num;
    }
    --month;
  }
  else if ((month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11) && (day <= 0)) {
    tempVar = num;
    if (num <= 0) {
      num = num + 31;
      tempVar = num;
    }
    month = 12;
    --year;
  }
  else if (month == 1 && day <= 0) {
    tempVar = num;
    if (num <= 0) {
      num = num + 31;
      tempVar = num;
    }
    month = 12;
    --year;
  }

  // Make object to change and return new date
  Date newDate;
  newDate.setDay(day);
  newDate.setMonth(month);
  newDate.setYear(year);
  return newDate;
}

// Method to decrement days, months, years postfix
Date Date :: operator--(int) {

  // Make object to change
  Date newDate;
  newDate.setDay(day);
  newDate.setMonth(month);
  newDate.setYear(year);
  
  // Make a variable to hold day of week
  string weekday = getDayOfWeek();
  int tempVal = day;
  int num;

  // See what day of the week user picked, and increment accordingly
  if (weekday == "Monday") {
      day--;
      day--;
      day--;
      num = tempVal - 3;
      tempVal = num;
    }
  else if (weekday == "Sunday") {
      day--;
      day--;
      num = tempVal - 2;
      tempVal = num;
  }
  else {
    day--;
    num = tempVal - 1;
    tempVal = num;
  }

  // Check if it's on the last day of a month
  if ((month == 5 || month == 7 || month == 10 || month == 12) && day <= 0) {
    tempVal = num;
    if (num <= 0) {
      num = num + 30;
      tempVal = num;
    }
    month--;
  }
  else if ((month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11) && day <= 0) {
    tempVal = num;
    if (num <= 0) {
      num = num + 31;
      tempVal = num;
    }
    month--;
  }
  else if (month == 3 && day <= 0) {
    tempVal = num;
    if (num <= 0) {
      num = num + 28;
      tempVal = num;
    }
    month--;
  }
  else if (month == 1 && day <= 0) {
    tempVal = num;
    if (num <= 0) {
      num = num + 31;
      tempVal = num;
    }
    month = 12;
    year--;
  }
  
  day = tempVal;

  // Return new date
  return newDate;
}
