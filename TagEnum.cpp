#include "TagEnum.h"
	
struct ORRKAU001::TagStruct tagstruct; //tagstruct variable to store tag details
//vector for the Tagstruct stuff
std::vector<ORRKAU001::TagStruct> TAGS;

//a method to extract the file contents and return a vector with each line
std::vector<std::string> ORRKAU001::extractFileContents(std::string filename)
{
	std::cout << filename << std::endl; //only a print to screen test if method works, no functionality
	
	std::vector<std::string> test_vector; //vector to store each line of the file
	
	std::ifstream in(filename); // use the file for imports
	
	//if file does not exist do not open the file
	if(!in){std::cout << "Couldn't open file" << filename << std::endl; }
	
	//adding the items in the file into the vector
	std::string line; 
	while(std::getline(in, line))
    {
		test_vector.push_back(line);
	}

	std::cout << "Done." << std::endl;
	in.close();

	return test_vector;

}

//method to create a vector with TagStuct type objects
void ORRKAU001::createTagVector(std::string s)
{
	std::cout << s << std::endl; // tester
	int firstPos = s.find(">"); // get the index of the Tag
	int secondPos = s.find("</"); // get the index of where the tag ends

	std::string tag = s.substr(1, firstPos-1); // split string to find the TAG
	std::string text = s.substr(firstPos+1, secondPos-firstPos-1); //split string using the indexes to find the text
	
	//if the tag exists, increment the tag and add the text
	if (ORRKAU001::checkIfTagExists(tag))
	{
		for (auto & element : TAGS) // loop through the vector to check
	{
		if (element.tagName == tag) //if the current tag is equal to the tag in question
		{
			element.numberOfPairs++; //increment the number of tags
			element.text += ":" + text; // concatenate the text 
		}
	}

	}
	else
	{
		tagstruct.tagName = tag;
		tagstruct.numberOfPairs = 1;
		tagstruct.text = text;
		TAGS.push_back(tagstruct);
	}
}

// checks if the tag exists within the vector of Tagstructs

bool ORRKAU001::checkIfTagExists(std::string tagname)
{
	for (auto & element : TAGS) // loop through the vector to check
	{
		if (element.tagName == tagname)
		{
			return true; // return true if the tag already exits
		}
	}
	return false; 
}

//this is a tester function to check if the vector of TagStructs is populating
void ORRKAU001::printOutVector()
{
	std::cout << "starting to read vector" << std::endl;
		
	for (auto & element : TAGS)
	{
		std::cout << "tag: " << element.tagName << std::endl;
		std::cout << "text: " << element.text << std::endl;
		std::cout << "no. : "  << element.numberOfPairs << std::endl;
	}

}

// handles the 'r' input from the user
// reads in a file and saves a tagstruct vector
std::vector<std::string> ORRKAU001::readAndParseFile(std::string filename)
{
	std::cout << "The file is being read..." << std::endl;

	std::vector<std::string> test_vector; //vector to store each line of the file
	
	std::ifstream in(filename); // use the file for imports
	//if file does not exist do not open the file
	if(!in){std::cout << "Couldn't open file" << filename << std::endl; }
	
	//adding the items in the file into the vector
	std::string line; 
	while(std::getline(in, line))
{
		test_vector.push_back(line);
	}
	in.close();
	std::cout << "The file was successfully read." << std::endl;
	
	return test_vector;
}

// handles the 'p' input from the user
//prints all the tags in the file
void ORRKAU001::printAllTags()
{
	std::cout << "All the tags in file: " << std::endl;
	int i = 1; 
	for (auto & element : TAGS)
	{
		std::cout << i << ". " <<  element.tagName << std::endl;
		i++;
		
	}
}

// handles the 'd' input from the user
// writes/dumps all tag data to a  file
void ORRKAU001::dumpTagsToFile()
{
	std::cout << "Dump method." << std::endl;
}

// handles the 'l' input from the user
// lists the data of a given tag
void ORRKAU001::listTagData(std::string tag)
{
	std::cout << "The data for the tag '" << tag << "' : " << std::endl;

	for (auto & element : TAGS) // loop through the vector to check
	{
		if (element.tagName == tag) //if the current tag is equal to the tag in question
		{
			std::cout << "Number of pairs for the tag '" << tag << "' is: " << element.numberOfPairs << std::endl; //increment the number of tags
			std::cout << "The text for the tag '" << tag << "' is:  " << element.text << std::endl; 
		}	
	}
}

	
