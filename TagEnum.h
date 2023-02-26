/**
 * .h file 
 * Simple Tag Enumeration Assignment 1 
 * CSC3022F 
 * Author: Kauthar Orrie
 *
 */
 
#ifndef TAGENUM_H
#define TAGENUM_H

//includes 
#include <string.h>
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>

//declaring my namespace with my student number
namespace ORRKAU001
{
	std::vector<std::string> extractFileContents(std::string filename); // method for extracting file contents
	
	void createTagVector(std::string ss); //method to add tag to struct 	
	
	void printOutVector(); //tester method to check if vector is populating

	bool checkIfTagExists(std::string tagname); // checks if the tag exists within the vector of Tagstructs
	
	std::string readAndParseFile(std::string); // reads in a file and saves a tagstruct vector

	void printAllTags(); //prints all the tags in the file

	void dumpTagsToFile(); // writes/dumps all tag data to a  file

	void listTagData(std::string tag); // lists the data of a given tag

	void clear(void); //clears the screen
	void tester(std::string s); //tester method, no funtionality

	//TagStruct struct
	// includes the tagName, number of pairs that consist of the tag within file, 
	// the text associated to the tag in thr file
	struct TagStruct
	{
		std::string tagName; 
		int numberOfPairs; 
		std::string text; 
	}; 
}

#endif
