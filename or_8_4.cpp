#include<iostream>
int main()
{
	int num;
	std::cin >> num ;
	while(num){
		std::cout << num << std::endl;
		--num;
	}
	return 0;
}
