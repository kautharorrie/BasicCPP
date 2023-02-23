
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
	cout << "Hello World" << endl;
	ORRKAU001::createTagVector("Hello");
	
	//testing the i/o file functionality
	std::vector<std::string> test_vector;
	std::string filename = "simple.txt"; //assign the file to a string
	
	// use the method "extractFileContents" from the TagEnum.cpp function
	vector<std::string> contents = ORRKAU001::extractFileContents(filename); //extract file contents
	
	int position1;
	int position2;
	//looping through the vector to get each line and printing it out
	for (auto & element : contents)
	{
		ORRKAU001::createTagVector(element);
		// position1 = element.find(">"); 

		// std::string sub = element.substr(position1+1);
		
		// position2 = sub.find("</");
		// std::string sub2 = sub.substr(position2+1);
		// std::cout << position1 << std::endl;
		// std::cout << sub2 << std::endl;
		// std::cout << sub << std::endl;
	}
	



	//attempt to split the array
	char c;
	int i = 0;
	char str[] = "Hello World\n";
	
	while(str[i])
	{
		c = str[i];
		if (isblank(c)) 
			c='\n';
		putchar(c);
		i++;
	}
	return 0;
}
