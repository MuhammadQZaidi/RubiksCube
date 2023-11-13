#ifndef Rubix_H
#define Rubix_H
class Rubix
{
public:
  char top[3][3]={}, front[3][3] = {}, bottom[3][3] = {}, left[3][3] = {}, right[3][3] = {}, back[3][3] = {};
  void make_cube(char , char , char , char , char , char);
  Rubix();
  
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
#endif