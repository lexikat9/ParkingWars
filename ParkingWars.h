/* Lexi Katramados                                                                                                                              
   CPSC 1070: 005                                                                                                                               
   E2: Runtime Terror                                                                                                                           
   3/10/23 */

#ifndef PARKINGWARS_H // used to prevent a header file from being inlcuded twice
#define PARKINGWARS_H
#include <fstream> // allows us to make an object so we can output a file
#include "Date.h" // allows us to make objects of date class
using namespace std;

class ParkingWars {

public:
  ParkingWars();
  void runSimulation();
  void runMonthSimulation(Date *startDatePtr); 
  void updateDateArray(Date *newDatePtr);  
  bool runDaySimulation(Date *datePtr);
  int calculateParkingTicketsGiven();
  int calculateStudentsParkingWithoutPermit(); 
  void writeToFile(Date *datePtr, bool studentsWon); 

private:
  Date *datesToSimulate;
  int arraySize;
  ofstream outFile;
};

#endif
