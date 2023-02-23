
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
	char mystring[100]; 
	std::cout << "Enter a string and press return: " << std::endl; //user input
	std::cin.getline(mystring,100);
	std::cout << "The string is :" << mystring << std::endl ;


	char *ptr; // declare a ptr pointer  
    ptr = strtok(mystring, " "); // use strtok() function to separate string using comma (,) delimiter.  
    std::cout << " \n Split string using strtok() function: " << std::endl;

	while (ptr != NULL)  
    {  
        std::cout << ptr  << std::endl; // print the string token  
		
        ptr = strtok (NULL, " ");  
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
