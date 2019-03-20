
#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>


int main() {
	int Length = 0;
	int Hight = 0;
	
	std::string file; 

	std::cout << "Enter name of your file with fonts or just press Enter (by default: style.txt):" << std::endl;
	getline(std::cin, file);
	
	if (file == "") // Default file with style
	{
		file = "style.txt"; // File with fonts by default
	}

	std::ifstream myfile;
	myfile.open(file);
	
	if (myfile.is_open())
	{
		std::string num;
		// Take from file info about length and hight of each letter
		getline(myfile, num);
		Length = stoi(num); // Covert string to integer value

		getline(myfile, num);
		Hight = stoi(num);

		// Hre we handle unpermissed value input. 
		if (Length <= 0 || Hight <= 0)
		{
			std::cout << "Unpermissed input. Zero and negative value are not permissed" << std::endl;
			return 1;
		}
		
		// Allocate in heap array of strings. Each array represent Hight of the letters
		std::string *A = new std::string[Hight];
		if (!A)
		{
			std::cout << "Can't allocate the mamory!" << std::endl;
			return 2;
		}

		for (int i = 0; i < Hight; i++)
		{
			std::string line;
			getline(myfile, line); // get single line from .txt till '\n'
			A[i] += line;
		}
		myfile.close();
		
		bool go_on = true;
		bool exit_input = true;
		do
		{
			// User input of text
			std::cout << "\nEnter your text:" << std::endl;
			std::string T; // input string
			getline(std::cin, T);
			std::cout << std::endl;

			////////////////////////////////////////////////////////////////////////////////
			// Alhorithm to convert user input to our own stile simbols and dicplay it.
			for (int i = 0; i < Hight; i++)
			{
				for (auto c : T)
				{
					int num = isalpha(c) ? toupper(c) - 'A' : (c == ' ') ? 27 : 26;
					std::cout << A[i].substr(Length * num, Length);
				}
				std::cout << std::endl;
			}
			////////////////////////////////////////////////////////////////////////////////
			
			// Ask user for exit
			do
			{
				std::cout << "\nExit? (yes/no):";
				getline(std::cin, num);
				std::string lowercase;
				for (auto c : num)
				{
					lowercase += tolower(c);
				}

				if (lowercase == "yes" || lowercase == "y" || lowercase == "no" || lowercase == "n")
				{
					if (lowercase[0] == 'y') // if yes -> exit; else -> go_on
					{
						go_on = false;
						exit_input = false;
					}
					else
					{
						exit_input = false;
					}
				}
				else
				{
					std::cout << "Please enter: \"yes\" or \"no\"" << std::endl;
				}
			} while (exit_input); // Repeat till exit_input won't be false
			
		} while (go_on);

		// Delete array from the Heap. And set pointer to zero.
		delete[] A;
		A = nullptr;
	}
	else
	{
		std::cout << "Can't open file " << file << std::endl;
		return 1;
	}
	return 0;
}


/*
Examples of fonts. You can create your own.

 #  ##   ## ##  ### ###  ## # # ###  ## # # #   # # ###  #  ##   #  ##   ## ### # # # # # # # # # # ### ###
# # # # #   # # #   #   #   # #  #    # # # #   ### # # # # # # # # # # #    #  # # # # # # # # # #   #   #
### ##  #   # # ##  ##  # # ###  #    # ##  #   ### # # # # ##  # # ##   #   #  # # # # ###  #   #   #   ##
# # # # #   # # #   #   # # # #  #  # # # # #   # # # # # # #    ## # #   #  #  # # # # ### # #  #  #
# # ##   ## ##  ### #    ## # # ###  #  # # ### # # # #  #  #     # # # ##   #  ###  #  # # # #  #  ###  #


 _   _   __  _   __  __  _  _ _ _   _ _ _ _   _ _  _   _   _   _   _   _  ___ _ _ _ _ _ _ _ _ _ _ __  __ 
|_| |_) |   | \ |__ |_  | _ |_| |   | |/  |   |V| | | / \ |_) / \ |_) (_   |  | | | | | | \_/ \_/  /  ?? 
| | |_) |__ |_/ |__ |   \_/ | | | [_/ |\_ |_] | | | | \_/ |   \_Q | \  _)  |  |_| \./ \^/ / \  |  /_  ?? 

*/