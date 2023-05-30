compile: date parkingWars
	g++ -Wall Driver.cpp ParkingWars.o Date.o MysteryMachine.o -o battle.out
date:
	g++ -Wall Date.cpp -c
parkingWars:
	g++ -Wall ParkingWars.cpp -c
run:
	./battle.out
clean:
	rm *.out
