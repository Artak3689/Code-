#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<ostream>
class TexT_Redactor
{
	public:
	TexT_Redactor(std::string text)
	{
		fs.open(text,std::fstream::in | std::fstream::out | std::fstream::app);
		if(fs.is_open())
		{
			std::cout << "File is open" << std::endl ;
			while(!fs.eof())
			{
				tmp = " ";
				fs >> tmp;
				excheng_Word();
				vec.push_back(tmp);
//				std::cout << tmp <<std::endl;
			}
			fs.clear();
			for(int i = 0 ; i < vec.size();++i)
			{
				fs << vec[i] << " " ;
			}
		}
		else
		{
			std::cout << "My Text_Redactor can not open your file :" <<std::endl;
			abort;
		}
	}
	~TexT_Redactor()
	{
		fs.close();
	}
	private:
	std::vector <std::string> vec ;
	std::fstream fs ;
	std::string tmp ;
	private:
	void excheng_Word()
	{
		int k = tmp.size()-1;
		if(tmp[0]>= 97 && tmp[0]<= 122)
		{
			tmp[0]=(int) tmp[0] - 32 ;
		}
		if(tmp[k]>= 97 && tmp[k]<= 122)
		{
			tmp[k]=(int) tmp[k] - 32 ;
		}
	}
	
};
int main()
{
	std::string text = "text.txt";
	TexT_Redactor a(text);
	return 0 ;
}
