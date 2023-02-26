Assignment 1 - C++ Basic I/O 
Name: Kauthar Orrie 
Student No.: ORRKAU001
Date: 26/02/23

Files included in submission:
 
- TagEnum.cpp (source file)
	- includes the methods needed for the program
	- defines the methods used in the driver file like reading the file contents, creating a TagStruct vector
	and implements user input r, p, d, l. 

- TagEnum.h (header file)
	- declares my namespace which 
	- declares all the required methods which is defined within TagEnum.cpp (source file)
	- declares all the '#include' files

- driver.cpp (driver file)
	- the main includes the command loop to handle the user input and output
	- includes and implements methods from the source file TagEnum.cpp

- makefile 
	- compiles the program

How to run the program: 
- type 'make' in the terminal to compile the files and create binary files
- run program with using " ./driver.exe " to run the program
	- in the make file the run is configured with 'driver.exe'