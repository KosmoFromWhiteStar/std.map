#include <iostream>
#include <map>
#include <vector>

int main()
{
	std::map <char, int> word;
	std::string input_word;
	std::cout << "Input 1st word : " << std::endl;
	std::cin >> input_word;

	for (int i = 0; i < input_word.length(); i++)
	{
		std::pair<char, int> key_char_int_count(input_word[i], input_word.length());
		word.insert(key_char_int_count);
	}

	std::cout << "Input 1st word : " << std::endl;
	std::cin >> input_word;
	int i = 0;
	
	std::vector<std::map<char, int>::iterator> vec_pos_client;
	if (input_word.length() != word.size()) goto x; //Отбросить сразу если размер (кол-во букв) разное

	
	for (int i = 0; i < input_word.length(); i++)
	{
		for(std::map<char,int>::iterator im = word.begin();
			im != word.end(); im++)
		if (im->first == input_word[i] && im->second > 0)
		{
			im->second = -1;
			vec_pos_client.push_back(im);
			break;
		}
	}
	for (int i = 0; i < vec_pos_client.size(); i++)
	{
		word.erase(vec_pos_client[i]);
	}


	if (word.size() > 0) x: std::cout << "False";
	else std::cout << "True";
}