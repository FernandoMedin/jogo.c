#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int score(int x1,int y1,int x2,int y2)
{
    int score;
    score=pow(x2-x1,2)+pow(y2-y1,2);
    score<0? score=score*-1 : score;
    score=sqrt(score);
    score=1000-score;
    return score;
}

int randompoint(int n)
{
   time_t t;
   srand((unsigned) time(&t));
   return rand()%27;
}