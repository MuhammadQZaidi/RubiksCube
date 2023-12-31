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
        std::cout<<w;
        std::cout<<"bottom scanned"<<std::endl;

        if (w<4)
        {
            for (int i =0; i<4;i++)
            {
                if (cube.top[2][1]=='W')
                {
                    //std::cout<<std::endl<<"Found white"<<std::endl;
                    w++;
                    cube.F();cube.F();cube.D();
                    while (cube.top[2][1] =='W'){cube.F();cube.F();cube.D();}
                }
                cube.U();
            }
        }
        cube.display_cube();
        std::cout<<w;
        std::cout<<"top scanned"<<std::endl;

        if (w<4)
        {
            for (int i =0; i<4 && w<4; i++)
            {
                if (cube.front [1][0]=='W')
                {
                    w++;
                    cube.L();cube.D();cube.Lp();
                    if (cube.front [1][0]=='W' && w==4){cube.L();}
                    while (cube.front [1][0]=='W'&& w!=4){cube.L();cube.D();cube.Lp();}
                }
                if (cube.front [1][2]=='W' && w<4)
                {
                    w++;
                    cube.Rp();cube.D();cube.R();
                    if (cube.front [1][2]=='W'&& w==4){cube.Rp();}
                    while (cube.front [1][2]=='W' && w!=4){cube.Rp();cube.D();cube.R();}
                }
             //cube.display_cube();
                cube.turn_cube_left();
            }
            
            bool flag = true;
            while (flag)
            {
                flag = false;
                for (int i =0; i<4; i++)
                {
                    if (cube.front[1][0]=='W' || cube.front[1][2]=='W' )
                    {
                        flag = true;
                        break;
                    }
                    cube.turn_cube_left();
                }
                if (flag && cube.front [1][0]=='W')
                {
                     w++;
                    cube.L();cube.D();cube.Lp();
                    if (cube.front [1][0]=='W'&& w==4){cube.L();}
                    while (cube.front [1][0]=='W'&& w!=4){cube.L();cube.D();cube.Lp();}
                }
                else if (flag && cube.front [1][2]=='W')
                {
                    w++;
                    cube.Rp();cube.D();cube.R();
                    if (cube.front [1][2]=='W'&& w==4){cube.Rp();}
                    while (cube.front [1][2]=='W' && w!=4){cube.Rp();cube.D();cube.R();}
                }

            }
            
        }
        cube.display_cube();
        std::cout<<w;
        std::cout<<"row 2 scanned"<<std::endl;

        if (w<4)
        {
            for (int i = 0; i < 4; i++)
            {
                if (cube.front[2][1]=='W')
                {
                    w++;
                    cube.L();cube.L();cube.F();cube.L();cube.Fp();
                    if (cube.front[2][1]=='W'){cube.F();cube.F();}
                    while (cube.front[0][1] =='W'){cube.D();cube.L();cube.L();cube.Fp();cube.L();cube.F();}
                    if (cube.left[1][0]=='W')
                    {
                        while (cube.bottom[2][1]=='W')
                        {
                            cube.D();
                        }
                        cube.turn_cube_left();
                        cube.L();
                        cube.turn_cube_right();
                        w++;
                    }
                    if (cube.left[1][2]=='W')
                    {
                        while (cube.bottom[0][1]=='W')
                        {
                            cube.D();
                        }
                        cube.Fp();
                        w++;
                    }
                }
                cube.D();
                /*
                std::cout<<std::endl;
                cube.display_cube();
                std::cout<<std::endl;*/

            }
        }
        cube.display_cube();
        std::cout<<w;
        std::cout<<"row 3 scanned"<<std::endl;   

        if (w<4)
        {
            for (int i = 0; i < 4; i++)
            {
                if (cube.front[0][1]=='W')
                {
                    w++;
                    cube.L();cube.L();cube.Fp();cube.L();cube.F();
                    while (cube.front[0][1] =='W'){cube.D();cube.L();cube.L();cube.Fp();cube.L();cube.F();}
                    if (cube.left[1][0]=='W')
                    {
                        while (cube.bottom[2][1]=='W')
                        {
                            cube.D();
                        }
                        cube.turn_cube_left();
                        cube.L();
                        cube.turn_cube_right();
                        w++;
                    }
                    if (cube.left[1][2]=='W')
                    {
                        while (cube.bottom[0][1]=='W')
                        {
                            cube.D();
                        }
                        cube.Fp();
                        w++;
                    }
                    if (cube.right[1][0]=='W')
                    {
                        while (cube.bottom[0][1]=='W')
                        {
                            cube.D();
                        }
                        cube.F();
                        w++;
                    }
                    if (cube.right[1][2]=='W')
                    {
                        while (cube.bottom[2][1]=='W')
                        {
                            cube.D();
                        }
                        cube.turn_cube_right();
                        cube.Rp();
                        cube.turn_cube_left();
                        w++;
                    }
                }
                
                cube.U();
                /*
                std::cout<<std::endl;
                cube.display_cube();
                std::cout<<std::endl;*/

            }
        }
        cube.display_cube();
        std::cout<<w;
        std::cout<<"row 1 scanned"<<std::endl;

        w=0;
        while (w<4)
        {
            if (cube.front[2][1]==cube.front[1][1] && cube.bottom[2][1]=='W')
            {
                cube.F();cube.F();
                cube.turn_cube_left();
                w++;
            }
            else
            {
                cube.D();
            }
            //cube.display_cube();
        }

        
    
    cube.display_cube();
    
    return 0;
}

