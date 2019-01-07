#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
#include<math.h>

#define row 9
#define col 9
#define SIZE 9
#define SCORE 5


#ifndef map
struct map
{
    int candy;
    int point;
};
#endif // map

#ifndef player
struct player
{
    int number;
    char name[10];
    int point;
    char time;
};
#endif
