
/*
*
* Author: Kauthar Orrie, ORRKAU001
* 21/02/23
* main file for Assigment 1
*/

#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include "string.h"
#include <vector>
#include "TagEnum.h"
#include <cstring>  

int main (int argc, char** argv)
{
	std::vector<std::string> input_vector;
	char mystring[100]; 
	std::cout << "Enter a string and press return: " << std::endl; //user input
	std::cin.getline(mystring,100);
	std::cout << "The string is :" << mystring << std::endl ;


	char *ptr; // declare a ptr pointer  
    ptr = strtok(mystring, " "); // use strtok() function to separate string using comma (,) delimiter.  
    std::cout << " \n Split string using strtok() function: " << std::endl;

	while (ptr != NULL)  
    {  
		input_vector.push_back(ptr);
		
        ptr = strtok (NULL, " ");  
    }  

	for (;;) { // loop forever

		std::vector<std::string> input_vector;

		char mystring[100]; // store the input inside this char

		std::cout << "r: Read and process tag file " << std::endl;
		std::cout << "p: Print all tags " << std::endl;
		std::cout << "d: dump/write tags and data to a file " << std::endl;
		std::cout << "l: list/print tag data for given tag " << std::endl;
		std::cout << "q: Quit " << std::endl; 
		std::cout << "Enter an option (r,p,d,l) or q to quit, and press return..." << std::endl; //user input
		std::cin.getline(mystring,100);
	
		char *ptr; // declare a ptr pointer  
		ptr = strtok(mystring, " "); // use strtok() function to separate string using comma (,) delimiter.  

		while (ptr != NULL)  
		{  
			input_vector.push_back(ptr);
			
			ptr = strtok (NULL, " ");  
		}  
		if (input_vector.at(0) == "r" ) {
			ORRKAU001::readAndParseFile("");
		}
		if (input_vector.at(0) == "p" ) {
			ORRKAU001::printAllTags();
		}
		if (input_vector.at(0) == "d" ) 
		{
			ORRKAU001::dumpTagsToFile();
		}
		if (input_vector.at(0) == "l" ) 
		{
			ORRKAU001::listTagData("");
		}
		if (input_vector.at(0) == "q" ) break;
	}
     
 
	
	
	
	//testing the i/o file functionality
	std::vector<std::string> test_vector;
	std::string filename = "simple.txt"; //assign the file to a string
	
	// use the method "extractFileContents" from the TagEnum.cpp function
	std::vector<std::string> contents = ORRKAU001::extractFileContents(filename); //extract file contents
	
	//looping through the vector (every line of the file) to add to the TagStruct vector
	for (auto & element : contents)
	{
		ORRKAU001::createTagVector(element); //using the method from TagEnum.cpp file
	}

	bool tf = ORRKAU001::checkIfTagExists("TXT");
	std::cout << tf << std::endl;
	return 0;
}
