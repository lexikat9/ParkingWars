/* Lexi Katramados                                                                                                      
   CPSC 1071: 005                                                                                                       
   E2: Runtime Terror                                                                                                   
   3/10/23 */

// File headers
#include <iostream> // allows us to do input and output (cin and cout)
#include "Date.h" // allows us to implement the date class
#include "MysteryMachine.h" // allows us to implement mystery machine class
#include "ParkingWars.h" // allows us to implement parking wars class
using namespace std;

// Main method                                                                                                           
int main () {

  // Declare object of parking wars class and call run sim using it
  ParkingWars parkingObj;
  parkingObj.runSimulation();
  
  return 0;
}
