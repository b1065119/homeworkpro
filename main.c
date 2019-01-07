
#include"header.h"
#include"func.h"





int main(int argc, char *argv[ ])
{
    long seed;
    srand(time(NULL));
    int turn=strtol(argv[1], NULL, 10);
    int target=strtol(argv[2], NULL, 10);

    struct map A[row][col];
    struct player B[10];
    struct player C[10];
    game(A,B,C,turn,target);
    printf("12345");

    return 0;
}
