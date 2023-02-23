
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

int main (int argc, char** argv)
{
	using namespace std; 
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
