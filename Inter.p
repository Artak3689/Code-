#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<>
struct Type
{
std::string count;
std::string type;
};
class Inter
{
        public:
        Inter()
{
        fin.open(text.txt)
        if(fin.is_open())
        {
        while(!fin.eof())
                {
                        text = " ";
                        std::getline(fin,text);
                        sline(text);
                        text >> tmp;
                        std::switch(tmp)
                        {
                                case "amg":{
                                        amg_func();
                                        break;
                                        }
                        }
                }
        } 
}
        privat:
        std::map<std::string,Type> arr;
        std::string text ;
        std::string tmp ;
        std::ifstream fin ;
        void amg_func()
        {
                cline(text);
                cline >> tmp;
                auto it = arr.find(tmp);
                if(it->first == arr.end()){error();}
                else{
                        std::peir<std::string,Type>p;
                        p.first = (cline >> tmp );
                        cline >> tmp ;
                        if(tmp == '='){ 
                        p.secand.count = (cline >> tmp);
                        p.secand.type = 
                        }

 }
        }
        void error(){std::cout << "error" <<std::endl;exception;}
}
