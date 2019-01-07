
#include"header.h"
#include"func.h"





int main(int argc, char *argv[ ])
//cmd open this
{
    long seed;
    srand(time(0));
    int turn=strtol(argv[1], NULL, 10);
    int target=strtol(argv[2], NULL, 10);



    struct map A[ROW][COL];
    struct player B[10];
    struct player C[10];
    game(A,B,C,turn,target);

    return 0;
}
