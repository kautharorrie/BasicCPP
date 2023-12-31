#include "TagEnum.h"
	
struct ORRKAU001::TagStruct tagstruct; //tagstruct variable to store tag data

//vector for the Tagstruct type objects for each tag
//stores instances/data of the TagStuct type objects
std::vector<ORRKAU001::TagStruct> TAGS;

//method to create a vector with TagStuct type objects
void ORRKAU001::createTagVector(std::string ss)
{
	std::string s = ss.substr(1, ss.length()-1);
	while (s.length() != 0){
		int firstPos = s.find(">"); // get the index of the Tag
		int secondPos = s.find("<"); // get the index of where the tag ends

		std::string tag = s.substr(0, firstPos); // split string to find the TAG
		std::string tag2 = s.substr(secondPos+2, tag.length()); //split string using the indexes to find the text
		std::string text = s.substr(firstPos+1, secondPos-firstPos-1); //split string using the indexes to find the text
		
		// if the tags are equal eg:  <T1></T1> then go to this part of the branch
		if (tag == tag2)
		{
			std::string restOfText = s.substr(secondPos+tag.length()+4, s.length()-3 ); //move to the next part of the string
			s = restOfText; // update the string
			
			// add the TAGstruct 
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
				//add the new Tag data to the Tagstruct vector
				tagstruct.tagName = tag;
				tagstruct.numberOfPairs = 1;
				tagstruct.text = text;
				TAGS.push_back(tagstruct);
			}
		}
		//handles the out of index boundries
		else if (s.length() <= tag.length()+4)
		{
			break;
		}
		//if the tags don't match - used for nested tags
		else
		{
			std::string restOfText = s.substr(secondPos+1, s.length()-secondPos-1 );//move to the next part of the string
			s = restOfText; // update the string
			
			if (ORRKAU001::checkIfTagExists(tag2))
			{
				for (auto & element : TAGS) // loop through the vector to check
				{
				if (element.tagName == tag2) //if the current tag is equal to the tag in question
				{
					element.numberOfPairs++; //increment the number of tags
					element.text += ":" + text; // concatenate the text 
				}
				}

			}
			else
			{
				//add the new Tag data to the Tagstruct vector
				tagstruct.tagName = tag;
				tagstruct.numberOfPairs = 1;
				tagstruct.text = text;
				TAGS.push_back(tagstruct);
			}


		}
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

// handles the 'r' input from the user
// reads in a file and saves a tagstruct vector
std::string ORRKAU001::readAndParseFile(std::string filename)
{
	std::cout << "The file is being read..." << std::endl;
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
	return f;
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
	std::cout << "Writing to tag.txt." << std::endl;
	std::ofstream myfile;
  	myfile.open ("tag.txt");
	for (auto & element : TAGS)
	{
		myfile << "'" + element.tagName + "' ,"; 
		myfile << element.numberOfPairs; 
		myfile << ", '" + element.text + "' \n";
	}
  	myfile.close();
	std::cout << "Done writing to tag.txt file." << std::endl;

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

//clears the screen/terminal input
void ORRKAU001::clear(void) 
{ 
	system("clear"); 
} 

/*
* contains tester methods only
*/

//method to create a vector with TagStuct type objects
void ORRKAU001::tester(std::string s)
{
	while (s.length() != 0){
		int firstPos = s.find(">"); // get the index of the Tag
		int secondPos = s.find("<"); // get the index of where the tag ends

		std::string tag = s.substr(0, firstPos); // split string to find the TAG
		std::string tag2 = s.substr(secondPos+2, tag.length()); //split string using the indexes to find the text
		std::string text = s.substr(firstPos+1, secondPos-firstPos-1); //split string using the indexes to find the text
		
		if (tag == tag2)
		{
			std::string restOfText = s.substr(secondPos+tag.length()+4, s.length()-3 );
			std::cout << "Matched! " << std::endl;
			s = restOfText;
			std::cout <<"Tag: " << tag << " Text: " << text << std::endl;

			// add the TAGstruct 
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
			

			// check if it already exists
		}
		else if (s.length() <= tag.length()+4)
		{
			break;
		}
		else
		{
			std::string restOfText = s.substr(secondPos+1, s.length()-secondPos-1 );
			std::cout << "No match:    "<< restOfText << std::endl;
			s = restOfText;
			std::cout <<"Tag: " << tag << " Text: " << text << std::endl;
			
			if (ORRKAU001::checkIfTagExists(tag2))
			{
				for (auto & element : TAGS) // loop through the vector to check
				{
				if (element.tagName == tag2) //if the current tag is equal to the tag in question
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
	}
}

//a method to extract the file contents and return a vector with each line
//this was initially a tester method, no real functionality in the whole program
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

	
