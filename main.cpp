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
        //cube.display_cube();
        std::cout<<"bottom scanned"<<std::endl;


        if (w<4)
        {
            for (int i = 0; i < 4; i++)
            {
                if (cube.front[2][1]=='W')
                {
                    w++;
                    cube.L();cube.L();cube.F();cube.L();cube.Fp();
                    if (cube.front[2][1]=='W'){cube.F();cube.F();}
                    while (cube.front[0][1] =='W'){cube.F();cube.F();cube.D();cube.L();cube.L();cube.Fp();cube.L();cube.F();}
                }
                cube.U();
                /*
                std::cout<<std::endl;
                cube.display_cube();
                std::cout<<std::endl;*/

            }
        }
        std::cout<<"row 3 scanned"<<std::endl;

        if (w<4)
        {
            for (int i =0; i<4 && w<4; i++)
            {
                if (cube.front [1][0]=='W')
                {
                    w++;
                    cube.L();cube.D();cube.Lp();
                    if (w==4){cube.L();}
                    while (cube.front [1][0]=='W'&& w!=4){cube.L();cube.D();cube.Lp();}
                }
                if (cube.front [1][2]=='W' && w<4)
                {
                    w++;
                    cube.Rp();cube.D();cube.R();
                    if (w==4){cube.Rp();}
                    while (cube.front [1][2]=='W' && w!=4){cube.Rp();cube.D();cube.R();}
                }
            // cube.display_cube();
                cube.turn_cube_left();
            }
            
        }
        //cube.display_cube();
        std::cout<<"row 2 scanned"<<std::endl;

        if (w<4)
        {
            for (int i = 0; i < 4; i++)
            {
                if (cube.front[0][1]=='W')
                {
                    w++;
                    cube.L();cube.L();cube.Fp();cube.L();cube.F();
                    while (cube.front[0][1] =='W'){cube.D();cube.L();cube.L();cube.Fp();cube.L();cube.F();}
                }
                cube.U();
                /*
                std::cout<<std::endl;
                cube.display_cube();
                std::cout<<std::endl;*/

            }
        }
        //cube.display_cube();
        
        std::cout<<"row 1 scanned"<<std::endl;

        
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
        //cube.display_cube();
        std::cout<<"top scanned"<<std::endl;
    cube.display_cube();
    
    return 0;
}

