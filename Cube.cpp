/*#include <iostream>
>>>>>>> 28dfc5cc5e3e9e433798b11768c6298364bddc2b
#include <iomanip>
#include <cstdlib>
#include <ctime>


  int width = 9;
  int rowlength = 3;
  int columnlength = 3;
  
  char white [3][3] =  {{'W','W','W'},
                        {'W','W','W'},
                        {'W','W','W'}};

  char orange [3][3] = {{'O','O','O'},
                        {'O','O','O'},
                        {'O','O','O'}};

  char green [3][3] =  {{'G','G','G'},
                        {'G','G','G'},
                        {'G','G','G'}};

  char red [3][3] =    {{'R','R','R'},
                        {'R','R','R'},
                        {'R','R','R'}};
        
  char blue [3][3] =   {{'B','B','B'},
                        {'B','B','B'},
                        {'B','B','B'}};

  char yellow [3][3] = {{'Y','Y','Y'},
                        {'Y','Y','Y'},
                        {'Y','Y','Y'}};


void printcube();
void F();
void Fp();
void R();
void Rp();
void L();
void Lp();
void U();
void Up();
void D();
void Dp();
void RotateSecondRow(char (*)[3], char (*)[3], char (*)[3], char(*)[3], char (*)[3]);
void scramblecube();
int main() 
{
   std::cout << "Starting Cube: " << std::endl << std::endl;
  printcube();

  std::cout << std::endl << "Cube after Running Scrambler" << std::endl << std::endl;
  scramblecube();
  printcube();
  
  //Phase 1.1 White Cross:

  //checking Yellow for white cross peices
  int w = 0;
  for (int i = 0; i < 4; i++)
  {
    //std::cout << yellow[0][1];
    if (yellow[0][1]=='W'){w++;}
    D();
  }
  //std::cout<<" "<< w << std::endl;
  std::cout << std::endl;

  //checking White side for white pieces of cross
  if (w<4)
  {
    for (int i = 0; i < 4; i++)
    {
      if (white[2][1]=='W')
      {
        std::cout<<std::endl<<"Found white"<<std::endl;
        w++;
        F();F();D();
        while (white[2][1] =='W'){F();F();D();}
      }
      U();
      /*
      std::cout<<std::endl;
      printcube();
      std::cout<<std::endl;*/

    /*}
>>>>>>> 28dfc5cc5e3e9e433798b11768c6298364bddc2b
  }
  if (w<4)
  {
    for (int i = 0; i < 4; i++)
    {
      if (green[0][1]=='W')
      {
        w++;
        L();L();Fp();L();F();
        while (green[0][1] =='W'){L();L();Fp();L();F();}
      }
      U();
      /*
      std::cout<<std::endl;
      printcube();
      std::cout<<std::endl;*/

    /*}
>>>>>>> 28dfc5cc5e3e9e433798b11768c6298364bddc2b
  } 
  //2nd row shenanigans
  if (w<4)
  {
    //green side
    if (green [1][0]=='W')
    {
      w++;
      L();D();Lp();
      if (green [1][0]=='W'){L();}
    }
    if (green [1][2]=='W' && w<4)
    {
      w++;
      Rp();D();R();
      if (green [1][0]=='W'){Rp();}
    }
  }


  printcube();




  return 0;
}


void printcube()
{

  for (auto &row : white)
  {
    std::cout << std::setfill(' ') << std::setw(width);
    for (auto &column : row)
    {
      std::cout << column << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  
  for (int row = 0; row < rowlength; row++)
  {
    
      for (int column = 0; column < columnlength; column++)
      {
        std::cout << orange[row][column] << " ";
      }
      
      std::cout << "\t";

      for (int column = 0; column < columnlength; column++)
      {
        std::cout << "" << green[row][column] << " ";
      }
      
      std::cout << "\t";


      for (int column = 0; column < columnlength; column++)
      {
        std::cout << red[row][column] << " ";
      }
      
      std::cout << "\t";

      for (int column = 0; column < columnlength; column++)
      {
        std::cout << "" << blue[row][column] << " ";
      }
      std::cout << std::endl;  
  }
  std::cout << std::endl;

  for (auto &row : yellow)
  {
    std::cout << std::setfill(' ') << std::setw(width);
    for (auto &column : row)
    {
      std::cout << column << " ";
    }
    std::cout << std::endl;
  }
}

//Cubic functions
//F
void F()
{
  RotateSecondRow(green, orange, red, white, yellow);
}
//F'
void Fp()
{
  F();
  F();
  F();
}
//R
void R()
{ char tempW[3][3]={{white[2][0],white[1][0],white[0][0]},
                    {white[2][1],white[1][1],white[0][1]},
                    {white[2][2],white[1][2],white[0][2]}};
  char tempY[3][3]={{yellow[0][2],yellow[1][2],yellow[2][2]},
                    {yellow[0][1],yellow[1][1],yellow[2][1]},
                    {yellow[0][0],yellow[1][0],yellow[2][0]}};
  RotateSecondRow(red,green,blue,tempW, tempY);
  
  white[0][0] =tempW[0][2];
  white[0][1] =tempW[1][2];
  white[0][2] =tempW[2][2];
  white[1][0] =tempW[0][1];
  white[1][2] =tempW[2][1];
  white[2][0] =tempW[0][0];
  white[2][1] =tempW[1][0];
  white[2][2] =tempW[2][0];

  yellow[0][0] =tempY[2][0];
  yellow[0][1] =tempY[1][0];
  yellow[0][2] =tempY[0][0];
  yellow[1][0] =tempY[2][1];
  yellow[1][2] =tempY[0][1];
  yellow[2][0] =tempY[2][2];
  yellow[2][1] =tempY[1][2];
  yellow[2][2] =tempY[0][2];
}
//R'
void Rp()
{
  R();
  R();
  R();
}
//F
void L()
{
  char tempY[3][3]={{yellow[2][0],yellow[1][0],yellow[0][0]},
                    {yellow[2][1],yellow[1][1],yellow[0][1]},
                    {yellow[2][2],yellow[1][2],yellow[0][2]}};
  char tempW[3][3]={{white[0][2],white[1][2],white[2][2]},
                    {white[0][1],white[1][1],white[2][1]},
                    {white[0][0],white[1][0],white[2][0]}};
  RotateSecondRow(orange,blue,green,tempW, tempY);
  
  yellow[0][0] =tempY[0][2];
  yellow[0][1] =tempY[1][2];
  yellow[0][2] =tempY[2][2];
  yellow[1][0] =tempY[0][1];
  yellow[1][2] =tempY[2][1];
  yellow[2][0] =tempY[0][0];
  yellow[2][1] =tempY[1][0];
  yellow[2][2] =tempY[2][0];

  white[0][0] =tempW[2][0];
  white[0][1] =tempW[1][0];
  white[0][2] =tempW[0][0];
  white[1][0] =tempW[2][1];
  white[1][2] =tempW[0][1];
  white[2][0] =tempW[2][2];
  white[2][1] =tempW[1][2];
  white[2][2] =tempW[0][2];
}
//L'
void Lp()
{
L();
L();
L();
}
//U
void U()
{
  //Do something
  char tempE = white[0][0];
  char tempM= white[0][1];
  white[0][0]=white[2][0];
  white[2][0]=white[2][2];
  white[2][2]=white[0][2];
  white[0][2]=tempE;
  white[0][1]=white[1][0];
  white[1][0]=white[2][1];
  white[2][1]=white[1][2];
  white[1][2]=tempM;

  char t1 = orange [0][0];
  char t2 = orange [0][1];
  char t3 = orange [0][2];

  orange[0][0]=green[0][0];
  orange[0][1]=green[0][1];
  orange[0][2]=green[0][2];
  
  green[0][0]=red[0][0];
  green[0][1]=red[0][1];
  green[0][2]=red[0][2];

  red[0][0]=blue[0][0];
  red[0][1]=blue[0][1];
  red[0][2]=blue[0][2];

  blue[0][0]=t1;
  blue[0][1]=t2;
  blue[0][2]=t3;

}
//U'
void Up()
{
  U();
  U();
  U();
}
//D
void D()
{
  char tempE = yellow[0][0];
  char tempM= yellow[0][1];
  yellow[0][0]=yellow[2][0];
  yellow[2][0]=yellow[2][2];
  yellow[2][2]=yellow[0][2];
  yellow[0][2]=tempE;
  yellow[0][1]=yellow[1][0];
  yellow[1][0]=yellow[2][1];
  yellow[2][1]=yellow[1][2];
  yellow[1][2]=tempM;

  char t1 = orange [2][0];
  char t2 = orange [2][1];
  char t3 = orange [2][2];

  orange[2][0]=blue[2][0];
  orange[2][1]=blue[2][1];
  orange[2][2]=blue[2][2];
  
  blue[2][0]=red[2][0];
  blue[2][1]=red[2][1];
  blue[2][2]=red[2][2];

  red[2][0]=green[2][0];
  red[2][1]=green[2][1];
  red[2][2]=green[2][2];

  green[2][0]=t1;
  green[2][1]=t2;
  green[2][2]=t3;
}
//Dp
void Dp()
{
  D();
  D();
  D();
}
//Generic Rotate all
void RotateSecondRow(char (*F)[3], char (*L)[3], char (*R)[3], char(*U)[3], char (*D)[3])
{
  char tempE = F[0][0];
  char tempM= F[0][1];
  char temp1=U[2][0];
  char temp2=U[2][1];
  char temp3=U[2][2];

  F[0][0]=F[2][0];
  F[2][0]=F[2][2];
  F[2][2]=F[0][2];
  F[0][2]=tempE;
  F[0][1]=F[1][0];
  F[1][0]=F[2][1];
  F[2][1]=F[1][2];
  F[1][2]=tempM;

  U[2][0]=L[2][2];
  U[2][1]=L[1][2];
  U[2][2]=L[0][2];

  L[2][2]=D[0][2];
  L[1][2]=D[0][1];
  L[0][2]=D[0][0];

  D[0][2]=R[0][0];
  D[0][1]=R[1][0];
  D[0][0]=R[2][0];
  
  R[0][0]=temp1;
  R[1][0]=temp2;
  R[2][0]=temp3;
}

void scramblecube()
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
*/