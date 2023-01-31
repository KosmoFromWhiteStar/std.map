#include <map>
#include <iostream>
#include <string>

int main()
{
	std::map <std::string, std::string> reg;
	int iter = 0;

	x:
	std::string name;
	std::cout << "<-: ";
	std::cin >> name;
	
	if (name != "next") 
	{
		std::string temp = name[0] + std::to_string(iter);
		std::pair <std::string, std::string > pers (temp, name);
		reg.insert(pers);
	}
	else if (name == "next")
	{
		if (reg.size() == 0)
		{
			std::cout << "Reg is empty";
			return 0;
		}
		std::map<std::string, std::string>::iterator i = reg.begin();
		std::cout << reg.begin()->second << std::endl;
		reg.erase(i);
	}
	iter++;
	goto x;
}