/* Lexi Katramados                                                                                                                             
   CPSC 1070: 005                                                                                                                              
   E2: Runtime Terror                                                                                                                           
   3/10/23 */

// File headers
#include <iostream> // allows us to do input and output (cin and cout)
#include <cstdlib> // standard library
#include <string> // allows us to do mathematical functionsuse strings
#include <unistd.h> // allows us to use clock
#include <ctime> // allows us to do random number generation
#include <fstream> // allows us to output a file
#include "ParkingWars.h" // allows us to use the .h file for the class
#include "Date.h" // allows us to implement Date class
#include "MysteryMachine.h" // allows us to implement MysteryMachine class
using namespace std;

// Constuctor
ParkingWars :: ParkingWars (){
  arraySize = 0;
  datesToSimulate = new Date[arraySize];
  outFile.open("log.txt");
};

// Only method call in driver.cpp
void ParkingWars :: runSimulation() {

  // Print opening statements
  cout << "Welcome to Parking Wars!" << endl;
  cout << "This program simulates an epic battle between Parking Services and students at Clementine University." << endl << endl;

  // Declare seed for randomizer
  srand(time(0));

  // Declare local variables                                   
  int month;
  int day;
  int year;

  // Prompt user for date, read in input, and check for validity                                                        
  cout << "Please enter the data you'd like to start the simulation in MM DD YYYY format: ";
  cin >> month;
  cin >> day;
  cin >> year;

  // Put user info in an object and make a pointer to that object
  Date userDate(month, day, year);
  Date *userDatePtr = &userDate;
  
  // Call function
  runMonthSimulation(userDatePtr);
}

// Runs the simulation from the start date to the end of the month and writes the results to a file and prints a summary to the console
void ParkingWars :: runMonthSimulation(Date *startDatePtr) {

  // Get month, day, and year and store it in variables we're starting with (because it will change by the end)
  int currMonth = startDatePtr->getMonth();
  int ogDay = startDatePtr->getDay();
  int ogYear = startDatePtr->getYear();

  // Create boolean and new pointer and nullify
  bool sameMonth = true;
  Date *newDatePtr = nullptr;

  // Make an if statement to skip weekend if it starts on one
  if ((startDatePtr->getDayOfWeek() == "Saturday") || (startDatePtr->getDayOfWeek() == "Sunday")) {
    startDatePtr->operator++();
  }

  // Execute this do-while loop until the end of the month
  do {
    arraySize++;
    // Put object in the new pointer and start at the starting date that user inputed
    newDatePtr = new Date;
    newDatePtr->setMonth(startDatePtr->getMonth());
    newDatePtr->setDay(startDatePtr->getDay());
    newDatePtr->setYear(startDatePtr->getYear());

    // If statement to enter date into array and increment the day as long as we're in the same month we started in; else, exit loop
    if (newDatePtr->getMonth() == currMonth) {
      updateDateArray(newDatePtr);
      startDatePtr->operator++();
    }
    else {
      sameMonth = false;
    }
  } while (sameMonth);

  // Make new pointer to point to array
  Date *arrayPtr = nullptr;
  int parkingDubs = 0;
  int studentDubs = 0;
  bool whoWon = false;

  // Iterate through entire array and calculate and print who won
  for (int i = 0; i < arraySize - 1; ++i) {

    // Use pointer to hold datesToSimulate but add i to it
    arrayPtr = datesToSimulate + i;
    // Call run day and get who won that and set that equal to the boolean
    whoWon = runDaySimulation(arrayPtr);
    // Send info to file so we can print it out there
    writeToFile(arrayPtr, whoWon);

    // Print who won: students or parking services
    if (whoWon) {
      cout << "\tStudents won!" << endl << endl;
      studentDubs += 1;
    }
    else {
      cout << "\tParking won!" << endl << endl;
      parkingDubs += 1;
    }
  }
  
  // Print out statements that go at end (summary of month)
  cout << "Summary for starting on " << currMonth << "/" << ogDay << "/" << ogYear << ":" << endl;
  cout << "Students won a total of " << studentDubs << " days!" << endl;
  cout << "Parking won a total of " << parkingDubs << " days!" << endl;

  // Delete array to stop leak and free space
  delete [] datesToSimulate;

  // Close outfile
  outFile.close();

}

// Runs the simulation from the start date to the end of the month and writes the results to a file and prints a summary to the console
void ParkingWars :: updateDateArray(Date *newDatePtr) {

  // Make new pointer and set equal to a new array
  Date *tempArray = nullptr;
  tempArray = new Date[arraySize];

  // Puts new date into the last position of the array
  tempArray[arraySize - 1] = *newDatePtr;

  // For loop to copy values from other date array into the new one using pointers
  for (int i = 0; i < arraySize - 1; ++i) {
    tempArray[i] = datesToSimulate[i];
  }

  // Set other array equal to tempArray using pointers (swap!)
  datesToSimulate = tempArray;
}

// Runs the simulation for a single day and returns the result true if students won or tied, false if parking won
bool ParkingWars :: runDaySimulation(Date *datePtr) {
  
  // Declare boolean
  bool whoWins;
  usleep(50000);

  // Print daily statement
  cout << "Running simulation for " << datePtr->getDayOfWeek() << " " << datePtr->getMonth() << "/" << datePtr->getDay() << "/" << datePtr->getYear() << endl;

  // Get # of tickets and illegal parking from the random generator methods and print
  int tickets = 0;
  int illegalPark = 0;

  // For loop to iterate 10 times
  for (int i = 0; i < 10; ++i) {
    usleep(50000);
    tickets += calculateParkingTicketsGiven();
    illegalPark += calculateStudentsParkingWithoutPermit();
  }

  // Print out
  cout << "Number of tickets given: " << tickets << endl;
  cout << "Number of students parking without permits: " << illegalPark << endl;

  // Return true or false depending on results
  if (illegalPark >= tickets) {
    whoWins = true;
  }
  else {
    whoWins = false;
  }

  return whoWins;
  
}

// Calculates tickets given out based on stats in directions
int ParkingWars :: calculateParkingTicketsGiven() {

  // Declare necessary variables to perform random number generation (seed to ensure randomization)
  int ticketsGiven = 0;
  int randNum = 0;
  randNum = rand() % 100 + 1;

  // Use random number generated to assign # of tickets based on stats given in instructions
  if (randNum >= 0 && randNum <= 35) {
    ticketsGiven = 0;
  }
  else if (randNum >= 36 && randNum <= 65) {
    ticketsGiven = 9;
  }
  else if (randNum >= 66 && randNum <= 95) {
    ticketsGiven = 1;
  }
  else {
    ticketsGiven = 12;
  }

  return ticketsGiven;
}

// Calculates # of illegally parked students based on stats in directions
int ParkingWars :: calculateStudentsParkingWithoutPermit() {

  // Declare necessary variables to perform random number generation (seed to ensure randomization)
  int noPermit = 0;
  int randNum = 0;
  randNum = rand() % 100 + 1;

  // Use random number generated to assign # of tickets based on stats given in instructions
  if (randNum >= 0 && randNum <= 50) {
    noPermit = 3;
  }
  else if (randNum >= 51 && randNum <= 85) {
    noPermit = 1;
  }
  else {
    noPermit = 6;
  }

  return noPermit;
  
}

// Writes to file in a format Date mm/dd/yyyy: Sutdents won!||Parking won.
void ParkingWars :: writeToFile(Date *datePtr, bool studentsWon) {

  // Send data into file
  outFile << datePtr->getDayOfWeek() << " " << datePtr->getMonth() << "/" << datePtr->getDay() << "/" << datePtr->getYear() << ": ";

  // Use boolean and if statement to print who won
  if (studentsWon) {
    outFile << "Students won!" << endl;
  }
  else {
    outFile << "Parking won." << endl;
  }
  
}
