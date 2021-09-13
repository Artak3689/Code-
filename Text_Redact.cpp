#include<iostream>
#include<fstream>
#include<string>
#include<iterator>
#include<algorithm>
int di{};
void LineAnaliz(std::string&);
int main(int agrc , const char* agrv[])
{
	if(agrc < 2)
	{
		std::cout<< "giv me a File" << std::endl;
	}
	std::ifstream fin(agrv[1]);
	if(fin.is_open())
	{
		std::ofstream fout(agrv[1],std::ios_base::out | std::ios_base::in);
		if(fout.is_open()){
			while(!fin.eof())
			{
				std::string line ;
				std::getline(fin,line);
				LineAnaliz(line);
				std::cout<< line << std::endl;
				fout << line << "\n";
			}
		}
	}
	else
	{
		std::cout<< "File is a invalid !!!" << std::endl;
	}
}

class chlp
{
public:
	bool operator()(char tmp)
	{
               return (tmp < 'z' && tmp > 'a')||(tmp < 'Z' && tmp > 'A')||(tmp <'0' && tmp > '9')||(tmp == ' ');
	}
};

void LineAnaliz(std::string& line)
{
	std::remove(line.begin(), line.end(),chlp());
/*[]( char& tmp)
		 {return (tmp < 'z' && tmp > 'a')||(tmp < 'Z' && tmp > 'A')||(tmp <'0' && tmp > '9')||(tmp == ' ');}*/
}
