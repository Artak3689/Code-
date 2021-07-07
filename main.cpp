#include<iostream>
char* recursiv(char*);
int main()
{
        char num[10];
        std::cin >> num ;
        char* tmp = & num [0];
        char* b = recursiv(tmp);
        std::cout << num << std::endl;
}

char* recursiv(char*a)
{
int tmp =0;
char* b = a;
while(*b!='\0'){
        ++tmp;
        ++b;
}
for(int i =0;i<tmp;++i){
        char tmp_2 = a[i];
        a[i] = a[tmp-1];
        a[tmp-1]=tmp_2;
        --tmp;
}
return a;
}
