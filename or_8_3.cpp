#include<iostream>
void rec(int);
int main()
{
	int num;
	std::cin >> num ;
	rec(num);
	return 0;
}

void rec(int num)
{
	if(num)
	{
		std::cout << num <<std::endl;
		rec(num-=1);
	}
}
