#include <iostream>
#include <map>
#include <vector>
#include <string>

int fnc(std::string str_line, std::string* num, std::string* name)
{
	bool space = false;
	for (int i = 0; i < str_line.length(); i++)
	{
		if (str_line[i] == ' ') space = true;
		else if (!space) (*num) += str_line[i];
		else if (space)
		{
			(*name) += str_line[i];
		}
	}
	if (*name == "") return 1; // cod for search
	if (*num != "" && *name != "") return 2; // cod for add
}
bool compare(std::string str, std::string str2)
{
	for (int i = 0; i < str.length() && i < str2.length(); i++)
	{
		if (str[i] != str2[i]) return false;
	}	
	return true;
}

int main()
{
	std::map <std::string, std::string> phonebook;
	x:	
	std::cout << "phonebook :\n";
	std::string input_str, number = "", name = "";
	std::getline(std::cin, input_str);
	int result = fnc(input_str, &number, &name);
	if (result == 2)
	{
		std::pair <std::string, std::string> para = { number, name };
		phonebook.insert(para);
	}
	else if (result == 1)
	{
		if (number[0] >= '0' && number[0] <= '9') // search name
		{
			std::map<std::string, std::string>::iterator it = phonebook.find(number);
			std::cout <<"Number " << it->first << " name: " << it->second << std::endl;
		} 
		if ((number[0] >= 'A' && number[0] <= 'Z') || (number[0] >= 'a' && number[0] <= 'z')) // search num
		{
			std::vector <std::map<std::string, std::string>::iterator> list_;
			for (std::map<std::string, std::string>::iterator it = phonebook.begin(); 
				 it != phonebook.end(); it++)
			{
				
				if (compare(it->second, number))
				{
					list_.push_back(it);
				}
	
			}
			for (int i = 0; i < list_.size(); i++)
			{
				std::cout << "Number: " << list_[i]->first << " name: " << list_[i]->second << std::endl;
			}
		} 
	}
	goto x;
}