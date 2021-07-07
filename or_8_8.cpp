#include<iostream>
#include<string>
void h_hak(std::string text)
{
	int j = text.size()-1;
	for(int i = 0 ;i<text.size()/2;++i)
	{
		char tmp = text[i];
		text[i] = text[j];
		text[j] = tmp;
		--j;
	}
	std::cout << text << std::endl;
}
int main()
{
	std::string text ;
	std::getline(std::cin,text);
	h_hak(text);
	return 0;
}
