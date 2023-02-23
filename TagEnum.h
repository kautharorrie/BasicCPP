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

namespace ORRKAU001
{
	std::vector<std::string> extractFileContents(std::string filename); // method for extracting file contents
	
	void createTagVector(std::string tag); //method to add tag to struct 	
	
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
