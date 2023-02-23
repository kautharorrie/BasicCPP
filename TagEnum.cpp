#include "TagEnum.h"
	
struct ORRKAU001::TagStruct tagstruct; 
//vector for the Tagstruct stuff
std::vector<std::string> TAGS;

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
	int firstPos = s.find(">");
	int secondPos = s.find("</");

	std::string tag = s.substr(1, firstPos-1);
	std::string text = s.substr(firstPos+1, secondPos-firstPos-1);
	std::cout << "tag: " << tag << std::endl;
	std::cout << "text: " << text << std::endl;

}

	
