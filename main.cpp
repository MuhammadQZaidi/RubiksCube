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
    cube.display_cube();
    cube.D();
    cube.U();
    cube.F();
    cube.turn_cube_left();
    cube.bring_bottom_up();
    cube.display_cube();
    return 0;
}

