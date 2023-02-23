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

std::vector<std::string> ORRKAU001::readAndParseFile(std::string filename)
{
	std::cout << "Read method." << std::endl;
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
	in.close();
	return test_vector;
}
void ORRKAU001::printAllTags()
{
	std::cout << "Print method." << std::endl;
}
void ORRKAU001::dumpTagsToFile()
{
	std::cout << "Dump method." << std::endl;
}
void ORRKAU001::listTagData(std::string tag)
{
	std::cout << "List method." << std::endl;
}

	
