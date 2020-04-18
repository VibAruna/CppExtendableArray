/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include "ResArray.h"
#include <iostream>

int main()
{
    ResArray<int> x(12);
    for(int i = 0; i < 10; i++)
    {
        x.add(i+5);
    }
    for(int i = 0; i < 5; i++)
    {
        x.add(i+2, i);
    }
    x.set(13, 20);
    for(int i = 0; i < x.size(); i++)
    {
        std::cout << x.get(i) <<std::endl;
    }
    
    x.remove_element(10);
    for(int i = 0; i < x.size(); i++)
    {
        // std::cout << x.get(i) <<std::endl;
        std::cout << x[i] <<std::endl;
    }
    std::cout << "x[6] before editing : " << x[6] <<std::endl;
    x[6] = 25;
    std::cout << "x[6] after editing : " << x[6] <<std::endl;
    // std::cout << x.indexOf(20) <<std::endl;
    std::cout << x.contains(20) <<std::endl;
    std::cout << x.contains(40) <<std::endl;
    // printf("Hello World");
    
    return 0;
}
