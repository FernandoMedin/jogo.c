#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//int score(int x1,int y1,int x2,int y2)
//{
 //   int score;
  //  score=pow(x2-x1,2)+pow(y2-y1,2);
   // score<0? score=score*-1 : score;
  //  score=sqrt(score);
  //  score=1000-score;
//    return score;
//}

int randompoint()
{
   time_t t;
   srand((unsigned) time(&t));
   return rand()%26+1;
}

float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

bool ddt(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)//dentro do triângulo?
{   
   //Área ABC
   float A = area (x1, y1, x2, y2, x3, y3);

   //Área PBC
   float A1 = area (x, y, x2, y2, x3, y3);

   //Área PAC  
   float A2 = area (x1, y1, x, y, x3, y3);

   //Área PAB 
   float A3 = area (x1, y1, x2, y2, x, y);

   return (A == A1 + A2 + A3);
}



int brasil(int x,int y,int estado)
{
switch (estado){

case 1:
	if(ddt(21,209,109,244,104,84,x,y) ||ddt(77,89,175,230,222,124,x,y) ||ddt(121,104,162,84,177,159,x,y) ||ddt(202,122,214,119,220,156,x,y))
	{
  printf("Rio Grande do sul\n");	
	return 0;
	}

}

} 
