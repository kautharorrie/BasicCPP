/*
* Author: Kauthar Orrie, ORRKAU001
* 21/02/23
* main file for Assigment 1
*/

#include "TagEnum.h"
 
int main (int argc, char** argv)
{

	std::string contents; //vector to store the contents of the file; 

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
			input_vector.push_back(ptr); // seperate user input and add to a vector
			
			ptr = strtok (NULL, " ");  
		}  

		//if the user selects the 'r' input along with the file
		//extract the contents of the file and add it to the vector 
		// create a TagStruct vector
		if (input_vector.at(0) == "r" ) {
			contents = ORRKAU001::readAndParseFile(input_vector.at(1));
			//contents = ORRKAU001::extractFileContents("simple.txt"); //read file from user input
			
		
			ORRKAU001::createTagVector(contents); //using the method from TagEnum.cpp file to create a TagStruct vector
			

			//when the method is complete let the user choose to continue or not. 
			std::cout << "Press enter to [RETURN] or continue..." << std::endl;
			std::cin.getline(mystring,100);
			ORRKAU001::clear();
		}

		//  if the user enters 'p'
		if (input_vector.at(0) == "p" ) {
			ORRKAU001::printAllTags(); // call the method within TagEnum.cpp

			//when the method is complete let the user choose to continue or not. 
			std::cout << "Press enter to [RETURN] or continue..." << std::endl;
			std::cin.getline(mystring,100);
			ORRKAU001::clear();
		}

		//  if the user enters 'd'
		if (input_vector.at(0) == "d" ) 
		{
			ORRKAU001::dumpTagsToFile(); // call the method within TagEnum.cpp

			//when the method is complete let the user choose to continue or not. 
			std::cout << "Press enter to [RETURN] or continue..." << std::endl;
			std::cin.getline(mystring,100);
			ORRKAU001::clear();
		}

		//  if the user enters 'l'
		if (input_vector.at(0) == "l" ) 
		{
			ORRKAU001::listTagData(input_vector.at(1)); // call the method within TagEnum.cpp

			//when the method is complete let the user choose to continue or not. 
			std::cout << "Press enter to [RETURN] or continue..." << std::endl;
			std::cin.getline(mystring,100);
			ORRKAU001::clear();			
		}
		if (input_vector.at(0) == "q" ) 
		{
			break;
		}
		else 
		{
			std::cout << "Incorrect input please try again." << std::endl;
			std::cout << "Press enter to [RETURN] or continue..." << std::endl;
			std::cin.getline(mystring,100);
			ORRKAU001::clear();
		}
	}
		 
	return 0;
}
