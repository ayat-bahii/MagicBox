#include <iostream>
#include "mylib.h"

void gotoxy(int x, int y)
{
    x= x*4;
    y= y*2;    
    std::cout << "\033[" << y << ";" << x << "H"; //ANSI Escape Sequence
    std::cout.flush();
}
