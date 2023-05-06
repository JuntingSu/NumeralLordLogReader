#include<iostream>
#include<string>

int main()
{
    std::string str="12";
    str.append(std::to_string(3));
    str+=3;
    std::cout<<str<<std::endl;
    return 0;
}