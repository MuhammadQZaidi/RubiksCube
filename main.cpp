#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

class Rubix
{
private:
    char top[3][3] = {}, front[3][3] = {}, bottom[3][3] = {}, left[3][3] = {}, right[3][3] = {}, back[3][3] = {};

public:
    void make_cube(char face1, char face2, char face3, char face4, char face5, char face6);
    void display_cube();
    void scramblecube();
    void rotate_180(char arr[][3]);
    void flip_cube_clockwise();
    void bring_bottom_up();
    void turn_cube_left();
    void turn_cube_right();
    void rotate_90(char arr[][3]);
    void rotate_90p(char arr[][3]);
    void transpose(char arr[][3]);
    void reverse_matrix_row(char arr[][3]);
    void reverse_matrix_column(char arr[][3]);
    void reverse_row(char arr[][3], int k);
    void reverse_column(char arr[][3], int k);
    void F();
    void Fp();
    void R();
    void Rp();
    void U();
    void Up();
    void L();
    void Lp();
    void D();
    void Dp();
};


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

void Rubix::make_cube(char face1, char face2, char face3, char face4, char face5, char face6)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            top[i][j] = face1, front[i][j] = face2, bottom[i][j] = face3, left[i][j] = face4, right[i][j] = face5, back[i][j] = face6;
        }
    }
}

void Rubix::display_cube()
{
    std::cout << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << std::setfill(' ') << std::setw(9);
        for (int j = 0; j < 3; j++)
        {
            std::cout << top[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << left[i][j] << " ";
        }
        std::cout << "\t";
        for (int j = 0; j < 3; j++)
        {
            std::cout << "" << front[i][j] << " ";
        }
        std::cout << "\t";
        for (int j = 0; j < 3; j++)
        {
            std::cout << right[i][j] << " ";
        }
        std::cout << "\t";
        for (int j = 0; j < 3; j++)
        {
            std::cout << "" << back[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for (int i = 2; i >= 0; i--)
    {
        std::cout << std::setfill(' ') << std::setw(9);
        for (int j = 2; j >= 0; j--)
        {
            std::cout << bottom[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Rubix::flip_cube_clockwise()
{
    rotate_180(front);
    rotate_180(back);
    rotate_180(left);
    rotate_180(right);


    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::swap(top[i][j], bottom[i][j]);
            std::swap(left[i][j], right[i][j]);
        }
    }
}

void Rubix::bring_bottom_up()
{
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::swap(back[i][j], bottom[i][j]);
            std::swap(top[i][j], front[i][j]);
            std::swap(back[i][j], front[i][j]);
        }
    }
    
    rotate_90p(left);
    rotate_90(right);
    reverse_matrix_column(back);
    reverse_matrix_column(front);
    reverse_matrix_row(back);
    reverse_matrix_row(front);
}


void Rubix::turn_cube_left()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::swap(back[i][j], left[i][j]);
            std::swap(front[i][j], right[i][j]);
            std::swap(right[i][j], left[i][j]);
        }
    }

    rotate_90(top);
    rotate_90p(bottom);
}

void Rubix::turn_cube_right()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::swap(left[i][j], right[i][j]);
            std::swap(right[i][j], front[i][j]);
            std::swap(left[i][j], back[i][j]);
        }
    }

    rotate_90p(top);
    rotate_90p(bottom);
}

void Rubix::rotate_90(char arr[][3])
{
   transpose(arr);
   reverse_matrix_row(arr);
    
}

void Rubix::transpose(char arr[][3])
{
 for(int i = 0; i < 3; i++)
    {
        for(int j = i + 1; j < 3; j++)
        {
            std::swap(arr[i][j], arr[j][i]);
        }
    }
}

void Rubix::reverse_matrix_row(char arr[][3])
{
for(int i = 0; i < 3; i++)
    {
        int start = 0, end = 2;
        while(start < end)
        {
            std::swap(arr[i][start], arr[i][end]);
            start++;
            end--;
        }
    }
}

void Rubix::reverse_matrix_column(char arr[][3])
{
for(int j = 0; j < 3; j++)
    {
        int start = 0, end = 2;
        while(start < end)
        {
            std::swap(arr[start][j], arr[end][j]);
            start++;
            end--;
        }
    }
}

void Rubix::rotate_90p(char arr[][3])
{
    transpose(arr);
    reverse_matrix_column(arr);   
}

void Rubix::rotate_180(char arr[][3])
{
   reverse_matrix_row(arr);
   reverse_matrix_column(arr);
}

void Rubix::F()
{
    rotate_90(front);
    for(int k = 0; k < 3; k++)
        {
            std::swap(left[k][2], right[k][0]);
            std::swap(right[k][0], top[2][k]);
            std::swap(left[k][2], bottom[2][k]);
        }
    reverse_row(top, 2);
    reverse_column(left, 2);

}

void Rubix::Fp()
{
    rotate_90p(front);
       for(int k = 0; k < 3; k++)
        {
            std::swap(bottom[2][k], left[k][2]);
            std::swap(top[2][k], right[k][0]);
            std::swap(right[k][0], left[k][2]);
        }
    reverse_column(left, 2);
    reverse_row(bottom, 2);
}

void Rubix::R()
{
    rotate_90(right);
    for(int k = 0; k < 3; k++)
        {
            std::swap(bottom[k][0], top[k][2]);
            std::swap(top[k][2], front[k][2]);
            std::swap(bottom[k][0], back[k][0]);
        }
    reverse_column(front, 2);
    reverse_column(back, 0);
  
}

void Rubix::Rp()
{
    rotate_90p(right);
    for(int k = 0; k < 3; k++)
        {
            std::swap(back[k][0], bottom[k][0]);
            std::swap(front[k][2], top[k][2]);
            std::swap(top[k][2], bottom[k][0]);
        }
    reverse_column(top, 2);
    reverse_column(bottom, 0);
}

void Rubix::U()
{
    rotate_90(top);
    for(int k = 0; k < 3; k++)
    {
        std::swap(back[0][k], left[0][k]);
        std::swap(front[0][k], right[0][k]);
        std::swap(right[0][k], left[0][k]);
    }
    
}

void Rubix::Up()
{
    rotate_90p(top);
    for(int k = 0; k < 3; k++)
    {
        std::swap(left[0][k], right[0][k]);
        std::swap(right[0][k], front[0][k]);
        std::swap(left[0][k], back[0][k]);
    }
}

void Rubix::L()
{
    rotate_90(left);
    for(int k = 0; k < 3; k++)
        {
            std::swap(back[k][2], bottom[k][2]);
            std::swap(front[k][0], top[k][0]);
            std::swap(top[k][0], bottom[k][2]);
        }
    reverse_column(top, 0);
    reverse_column(bottom, 2);
}

void Rubix::Lp()
{
    rotate_90p(left);
    for(int k = 0; k < 3; k++)
        {
            std::swap(bottom[k][2], top[k][0]);
            std::swap(top[k][0], front[k][0]);
            std::swap(bottom[k][2], back[k][2]);
        }
    reverse_column(front, 0);
    reverse_column(back, 2);
}

void Rubix::D()
{
    rotate_90(bottom);
    for(int k = 0; k < 3; k++)
    {
        std::swap(left[2][k], right[2][k]);
        std::swap(right[2][k], front[2][k]);
        std::swap(left[2][k], back[2][k]);
    }
}

void Rubix::Dp()
{
    rotate_90p(bottom);
    for(int k = 0; k < 3; k++)
    {
        std::swap(back[2][k], left[2][k]);
        std::swap(front[2][k], right[2][k]);
        std::swap(right[2][k], left[2][k]);
    }
}

void Rubix::reverse_row(char arr[][3], int k)
{
    int start = 0, end = 2;
        while(start < end)
        {
            std::swap(arr[k][start], arr[k][end]);
            start++;
            end--;
        }
}

void Rubix::reverse_column(char arr[][3], int k)
{
    int start = 0, end = 2;
        while(start < end)
        {
            std::swap(arr[start][k], arr[end][k]);
            start++;
            end--;
        }
}

void Rubix::scramblecube()
{

  srand(time(NULL));
  int move[20];
  for(int i = 0; i < 20; i++){

    move[i] = 1 + rand() % 10;
    
  }

    for(int i = 0; i < 20; i++){
      
      if(move[i] == 1){
        F();
      }
      else if(move[i] == 2){
        Fp();
      }
      else if(move[i] == 3){
        R();
      }
      else if(move[i] == 4){
        Rp();
      }
      else if(move[i] == 5){
        U();
      }
      else if(move[i] == 6){
        Up();
      }
      else if(move[i] == 7){
        L();
      }
      else if(move[i] == 8){
        Lp();
      }
      else if(move[i] == 9){
        D();
      }
      else{
        Dp();
      }
    }

}


