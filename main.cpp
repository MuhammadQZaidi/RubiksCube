#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include "Rubix.cpp"
#include "Rubix.h"

int main()
{

    Rubix cube;
    cube.make_cube('W', 'G', 'Y', 'O', 'R', 'B');
    cube.scramblecube();
    cube.display_cube();

    int w = 0;
    for (int i = 0; i < 4 ; i++)
    {
        if (cube.bottom[0][1]=='W')
        {
            w++;
        }
        cube.D();
    }
    std::cout<<w;
    if (w<4)
    {
        for (int i =0; i<4;i++)
        {
            if (cube.top[2][1]=='W')
            {
                std::cout<<std::endl<<"Found white"<<std::endl;
                w++;
                cube.F();cube.F();cube.D();
                while (cube.top[2][1] =='W'){cube.F();cube.F();cube.D();}
            }
            cube.U();
        }
    }
    if (w<4)
    {
        for (int i = 0; i < 4; i++)
        {
        if (cube.front[0][1]=='W')
        {
            w++;
            cube.L();cube.L();cube.Fp();cube.L();cube.F();
            while (cube.front[0][1] =='W'){cube.L();cube.L();cube.Fp();cube.L();cube.F();}
        }
        cube.U();
        /*
        std::cout<<std::endl;
        printcube();
        std::cout<<std::endl;*/

        }
    }
    if (w<4)
    {
        //green side
        if (cube.front [1][0]=='W')
        {
        w++;
        cube.L();cube.D();cube.Lp();
        if (cube.front [1][0]=='W'){cube.L();}
        }
        if (cube.front [1][2]=='W' && w<4)
        {
        w++;
        cube.Rp();cube.D();cube.R();
        if (cube.front [1][0]=='W'){cube.Rp();}
        }
    }
    cube.display_cube();
    
    return 0;
}

