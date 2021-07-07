#include<iostream>
int main()
{
	int a = 0;
	int b = 1;
	int c ;
	std::cin>> c ;
	if(c == 0){std::cout<<a<<std::endl;}
	else if (c == 1){std::cout<<b<<std::endl;}
	else{
	for(int i=0;i<c-1;++i){
		int tmp = a+b;
		a = b ;
		b = tmp ;
	}
	std::cout << b <<std::endl;
	}
	return 0;
}
