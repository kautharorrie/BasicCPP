
#include "TagEnum.h"


	
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


