#include <iostream>
#include "sheird_ptr.h"
int main()
{
        Sheird_ptr<int> a(new int);
        Sheird_ptr<int> b;
        b=a;
	std::cout<< __LINE__ <<std::endl;
}
