#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include<sstream>
#include<vector>
class Inter 
{
	public:
	Inter(std::string file_name)
	{
		std::fstream fin ;
		fin.open(file_name);
		if(fin.is_open())
		{
			while(!fin.eof())
			{
				
				std::string tmp;
				while(tmp != ";")
				{
					fin >> tmp ; 	
					vec.push_back(tmp);
		 	      	}
				fin >> tmp ;
				if( vec[0] == "number"){add_number();std::cout << "num" << std::endl;}
				else if ( vec[0] == "dnumber"){add_dnumber();std::cout <<"dnum"  << std::endl;}
				else if ( vec[0] == "text"){ add_text();std::cout << "text" << std::endl; }
				else {for_oll();}	
			vec.clear() ;	
			vec.push_back(tmp);
/*			if(tmp == "condition")
			{
				while(tmp != ">")
				{
						while(tmp != ";")
						{
						fin >> tmp ; 	
						vec.push_back(tmp);
						}
						vec_2.push_back(vec);
						vec.clear();
				}
			std::cout << vec[0][3] << std::endl ;
			//	for_condition();
				vec.clear() ;	
				vec.push_back(tmp);
			}
			if(tmp == "loop")
			{
				while(tmp != "$")
				{	while(tmp != ";"){
						fin >> tmp ; 	
						vec.push_back(tmp);
						}
					vec_2.push_back(vec);
				}
			//	for_loop();
				vec.clear() ;	
				vec.push_back(tmp);
			}*/
			}
			fin.close();
	
		}else{std::cout << "Fils can't open" << std::endl;}
	}
	private:
	std::vector <std::vector <std::string> > vec_2;
	std::vector <std::string> vec;
	std::map<std::string,int>num_map ;
	std::map<std::string,double>dnum_map ;
	std::map<std::string,std::string>text_map ;
	//function
/*	void for_condition()
	{
			bool tmp ;
			auto it_1 = num_map.find(vec_2[0][2]);
			auto it_2 = num_map.find(vec_2[0][4]);
			int tmp_2;
			int tmp_4;
			std::istringstream(vec_2[0][2]) >> tmp_2;
			std::istringstream(vec_2[0][4]) >> tmp_4;

			if(vec_2[0][3]== ">")
			{
				if(it_1 != num_map.end() && it_2 != num_map.end())
				{
					 tmp =(bool)  it_1->second > it_2->second;
					 std::cout << "ba jan" << std::endl;
				}
				else if(it_1 != num_map.end() && it_2 == num_map.end())
				{
					 tmp =(bool)  it_1->second > tmp_4;
				}
				else if(it_1 == num_map.end() && it_2 != num_map.end())
				{
					 tmp =(bool)  tmp_2 > it_2->second;
				}
				else if(it_1 == num_map.end() && it_2 == num_map.end())
				{
					 tmp = (bool)  tmp_2 > tmp_4;
				}

			}
			else if(vec_2[0][3]== "<")
			{
				if(it_1 != num_map.end() && it_2 != num_map.end())
				{
					tmp =(bool)  it_1->second < it_2->second;
				}
				else if(it_1 != num_map.end() && it_2 == num_map.end())
				{
					tmp =(bool)  it_1->second < tmp_4;
				}
				else if(it_1 == num_map.end() && it_2 != num_map.end())
				{
					tmp =(bool)  tmp_2 < it_2->second;
				}
				else if(it_1 == num_map.end() && it_2 == num_map.end())
				{
					tmp = (bool)  tmp_2 < tmp_4;
				}

			}
			else if(vec_2[0][3]== "==")
			{
				if(it_1 != num_map.end() && it_2 != num_map.end())
				{
					tmp =(bool)  it_1->second == it_2->second;
				}
				else if(it_1 != num_map.end() && it_2 == num_map.end())
				{
					tmp =(bool)  it_1->second == tmp_4;
				}
				else if(it_1 == num_map.end() && it_2 != num_map.end())
				{
					tmp =(bool)  tmp_2 == it_2->second;
				}
				else if(it_1 == num_map.end() && it_2 == num_map.end())
				{
					tmp = (bool)  tmp_2 == tmp_4;
				}

			}

	}*/
	void add_number()
	{
		if(num_map.find(vec[1]) != num_map.end()){std::cout << "number error  " << std::endl;}
		else
       		{
			if(vec[2] == "=" )
			{
				int tmp_i;
				std::istringstream(vec[3]) >> tmp_i;
				num_map.emplace(vec[1],tmp_i);
			}
			else{num_map.emplace(vec[1],NULL);}
	
		}
	}
	void add_dnumber()
	{
		if(dnum_map.find(vec[1]) != dnum_map.end()){std::cout << "double error" << std::endl;}
		else
		{
			if(vec[2] == "=" )
			{
				double tmp_d;
				std::istringstream(vec[3]) >> tmp_d;
				dnum_map.emplace(vec[1],tmp_d);
			}
			else{dnum_map.emplace(vec[1],NULL);}
		}
	}
	void add_text()
	{
		if( text_map.find(vec[1]) != text_map.end()){std::cout << "text  error" << std::endl;}
		else
       		{
			if(vec[2] == "=" )
			{
				std::string Text = vec[3];
				for (int i = 4; vec[i] != ":";++i){ Text += " "; Text += vec[i]; }
				text_map.emplace(vec[1],vec[3]);
			}
			else{text_map.emplace(vec[1],nullptr);}
		}
	}
	void for_oll()
	{
		if(num_map.find(vec[0]) == num_map.end())
		{
			auto it = num_map.find(vec[0]);
			auto it_1 = num_map.find(vec[2]);
			auto it_2 = num_map.find(vec[4]);
			int tmp_2;
			int tmp_4;
			std::istringstream(vec[2]) >> tmp_2;
			std::istringstream(vec[4]) >> tmp_4;
			if(vec[3] == "+" ){
			if(it_1 != num_map.end() && it_2 != num_map.end())
			{
			       	it->second =  it_1->second + it_2->second;
			}
			else if(it_1 != num_map.end() && it_2 == num_map.end())
			{
			       	it->second =  it_1->second + tmp_4;
			}
			else if(it_1 == num_map.end() && it_2 != num_map.end())
			{
			       	it->second =  tmp_2 + it_2->second;
			}
			else if(it_1 == num_map.end() && it_2 == num_map.end())
			{
			       	it->second =  tmp_2 + tmp_4;
			}
			}
			else if(vec[3] == "-" ){
			if(it_1 != num_map.end() && it_2 != num_map.end()){ it->second =  it_1->second - it_2->second;}
			else if(it_1 != num_map.end() && it_2 == num_map.end()){ it->second =  it_1->second - tmp_4;}
			else if(it_1 == num_map.end() && it_2 != num_map.end()){ it->second =  tmp_2 - it_2->second;}
			else if(it_1 == num_map.end() && it_2 == num_map.end()){ it->second =  tmp_2 - tmp_4;}
			}
			else if(vec[3] == "*" ){
			if(it_1 != num_map.end() && it_2 != num_map.end()){ it->second =  it_1->second * it_2->second;}
			else if(it_1 != num_map.end() && it_2 == num_map.end()){ it->second =  it_1->second * tmp_4;}
			else if(it_1 == num_map.end() && it_2 != num_map.end()){ it->second =  tmp_2 * it_2->second;}
			else if(it_1 == num_map.end() && it_2 == num_map.end()){ it->second =  tmp_2 * tmp_4;}
			}
			else if(vec[3] == "/" ){
			if(it_1 != num_map.end() && it_2 != num_map.end()){ it->second =  it_1->second / it_2->second;}
			else if(it_1 != num_map.end() && it_2 == num_map.end()){ it->second =  it_1->second / tmp_4;}
			else if(it_1 == num_map.end() && it_2 != num_map.end()){ it->second =  tmp_2 / it_2->second;}
			else if(it_1 == num_map.end() && it_2 == num_map.end()){ it->second =  tmp_2 / tmp_4;}
			}
			num_map[vec[0]]= it->second ;
			return ;
		}
		else if(dnum_map.find(vec[0])==dnum_map.end())
		{
		
			auto it = dnum_map.find(vec[0]);
			auto it_1 = dnum_map.find(vec[2]);
			auto it_2 = dnum_map.find(vec[4]);
			double tmp_2;
			double tmp_4;
			std::istringstream(vec[2]) >> tmp_2;
			std::istringstream(vec[4]) >> tmp_4;
			if(vec[3] == "+" ){
			if(it_1 != dnum_map.end() && it_2 != dnum_map.end()){ it->second =  it_1->second + it_2->second;}
			else if(it_1 != dnum_map.end() && it_2 == dnum_map.end()){ it->second =  it_1->second + tmp_4;}
			else if(it_1 == dnum_map.end() && it_2 != dnum_map.end()){ it->second =  tmp_4 + it_2->second;}
			else if(it_1 == dnum_map.end() && it_2 == dnum_map.end()){ it->second =  tmp_2 + tmp_4;}
			}
			else if(vec[3] == "-" ){
			if(it_1 != dnum_map.end() && it_2 != dnum_map.end()){ it->second =  it_1->second - it_2->second;}
			else if(it_1 != dnum_map.end() && it_2 == dnum_map.end()){ it->second =  it_1->second - tmp_4;}
			else if(it_1 == dnum_map.end() && it_2 != dnum_map.end()){ it->second =  tmp_2 - it_2->second;}
			else if(it_1 == dnum_map.end() && it_2 == dnum_map.end()){ it->second =  tmp_2 - tmp_4;}
			}
			else if(vec[3] == "*" ){
			if(it_1 != dnum_map.end() && it_2 != dnum_map.end()){ it->second =  it_1->second * it_2->second;}
			else if(it_1 != dnum_map.end() && it_2 == dnum_map.end()){ it->second =  it_1->second * tmp_4;}
			else if(it_1 == dnum_map.end() && it_2 != dnum_map.end()){ it->second =  tmp_2 * it_2->second;}
			else if(it_1 == dnum_map.end() && it_2 == dnum_map.end()){ it->second =  tmp_2 * tmp_4;}
			}
			if(vec[3] == "/" ){
			if(it_1 != dnum_map.end() && it_2 != dnum_map.end()){ it->second =  it_1->second / it_2->second;}
			else if(it_1 != dnum_map.end() && it_2 == dnum_map.end()){ it->second =  it_1->second / tmp_4;}
			else if(it_1 == dnum_map.end() && it_2 != dnum_map.end()){ it->second =  tmp_2 / it_2->second;}
			else if(it_1 == dnum_map.end() && it_2 == dnum_map.end()){ it->second =  tmp_2 / tmp_4;}
			}	
			dnum_map[vec[0]] = it->second ;
			return ; 
		}
		else {std::cout << "my Inter dont undersdend you" << std::endl;}
	}
};

int main()
{
	std::string name = "text.txt";
	Inter a ( name );
	return 0 ;
}
