
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

	// std::vector<std::string> contents; //vector to store the contents of the file; 

	// for (;;) { // loop forever

	// 	std::vector<std::string> input_vector;

	// 	char mystring[100]; // store the input inside this char

	// 	std::cout << "r: Read and process tag file " << std::endl;
	// 	std::cout << "p: Print all tags " << std::endl;
	// 	std::cout << "d: dump/write tags and data to a file " << std::endl;
	// 	std::cout << "l: list/print tag data for given tag " << std::endl;
	// 	std::cout << "q: Quit " << std::endl; 
	// 	std::cout << "Enter an option (r,p,d,l) or q to quit, and press return..." << std::endl; //user input
	// 	std::cin.getline(mystring,100);
	
	// 	char *ptr; // declare a ptr pointer  
	// 	ptr = strtok(mystring, " "); // use strtok() function to separate string using comma (,) delimiter.  

	// 	while (ptr != NULL)  
	// 	{  
	// 		input_vector.push_back(ptr); // seperate user input and add to a vector
			
	// 		ptr = strtok (NULL, " ");  
	// 	}  

	// 	//if the user selects the 'r' input along with the file
	// 	//extract the contents of the file and add it to the vector 
	// 	// create a TagStruct vector
	// 	if (input_vector.at(0) == "r" ) {
	// 		contents = ORRKAU001::readAndParseFile(input_vector.at(1));
	// 		//contents = ORRKAU001::extractFileContents("simple.txt"); //read file from user input
			
	// 		for (auto & element : contents)
	// 		{
	// 			ORRKAU001::createTagVector(element); //using the method from TagEnum.cpp file to create a TagStruct vector
	// 		}

	// 		//when the method is complete let the user choose to continue or not. 
	// 		std::cout << "Press enter to [RETURN] or continue..." << std::endl;
	// 		std::cin.getline(mystring,100);
	// 		ORRKAU001::clear();
	// 	}

	// 	//  if the user enters 'p'
	// 	if (input_vector.at(0) == "p" ) {
	// 		ORRKAU001::printAllTags(); // call the method within TagEnum.cpp

	// 		//when the method is complete let the user choose to continue or not. 
	// 		std::cout << "Press enter to [RETURN] or continue..." << std::endl;
	// 		std::cin.getline(mystring,100);
	// 		ORRKAU001::clear();
	// 	}

	// 	//  if the user enters 'd'
	// 	if (input_vector.at(0) == "d" ) 
	// 	{
	// 		ORRKAU001::dumpTagsToFile(); // call the method within TagEnum.cpp

	// 		//when the method is complete let the user choose to continue or not. 
	// 		std::cout << "Press enter to [RETURN] or continue..." << std::endl;
	// 		std::cin.getline(mystring,100);
	// 		ORRKAU001::clear();
	// 	}

	// 	//  if the user enters 'l'
	// 	if (input_vector.at(0) == "l" ) 
	// 	{
	// 		ORRKAU001::listTagData(input_vector.at(1)); // call the method within TagEnum.cpp

	// 		//when the method is complete let the user choose to continue or not. 
	// 		std::cout << "Press enter to [RETURN] or continue..." << std::endl;
	// 		std::cin.getline(mystring,100);
	// 		ORRKAU001::clear();			
	// 	}
	// 	if (input_vector.at(0) == "q" ) break;
	// }

	// std::string X = "buenos dias mi amigo", value;
	// std::istringstream iss(X);
	// while (!iss.eof())
	// {
	// iss >> value;
	// std::cout << "value =" << value << std::endl;
	// }

	std::string filename = "long_nested.txt";
	std::string f; 

	std::ifstream in(filename); // use the file for imports
	
	//if file does not exist do not open the file
	if(!in){std::cout << "Couldn't open file" << filename << std::endl; }
	
	//adding the items in the file into the vector
	std::string line; 
	while(std::getline(in, line))
    {
		f+=line;
	}
	f+=" ";

	std::cout << "Done. \n" << std::endl;
	in.close();


	std::string ss = "<title>Long Example</title><h1>Heading</h1><li>Item 1</li><li>Item 2</li><li>Item 3</li> ";
	std::string s = f.substr(1, f.length()-1); 
	ORRKAU001::tester(s);
	ORRKAU001::printAllTags();
	ORRKAU001::dumpTagsToFile();




	// //std::cout << s << std::endl;
	// while (s.length() != 0){
	// 	int firstPos = s.find(">"); // get the index of the Tag
	// 	int secondPos = s.find("<"); // get the index of where the tag ends

	// 	std::string tag = s.substr(0, firstPos); // split string to find the TAG
	// 	std::string tag2 = s.substr(secondPos+2, tag.length()); //split string using the indexes to find the text
	// 	std::string text = s.substr(firstPos+1, secondPos-firstPos-1); //split string using the indexes to find the text
		
	// 	if (tag == tag2)
	// 	{
	// 		std::string restOfText = s.substr(secondPos+tag.length()+4, s.length()-3 );
	// 		std::cout << "Matched! " << std::endl;
	// 		s = restOfText;
	// 		std::cout <<"Tag: " << tag << " Text: " << text << std::endl;

	// 		// add the TAGstruct 
			

	// 		// check if it already exists
	// 	}
	// 	else if (s.length() <= tag.length()+4)
	// 	{
	// 		break;
	// 	}
	// 	else
	// 	{
	// 		std::string restOfText = s.substr(secondPos+1, s.length()-secondPos-1 );
	// 		std::cout << "No match:    "<< restOfText << std::endl;
	// 		s = restOfText;
	// 		std::cout <<"Tag: " << tag << " Text: " << text << std::endl;
			 

	// 		// break;



	// 	}
	// }
		 
	return 0;
}
