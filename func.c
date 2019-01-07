#include"header.h"
#include"func.h"

void fill_candy(struct map A[][col])
//Array filled with candy
//input Array
//output Array filled with candy
{
    int i,j;
    for(i=0; i<row; i=i+1)
    {
        for(j=0; j<col; j=j+1)
        {
            A[i][j].candy=random(&A[i][j].candy,5,1);        //the random number is from 5 to 1
        }
    }
}

int random(int *ptr,int max,int min)
//Random number with upper and lower bounds
//input Upper and lower bound and pointer
//output Random number;
{
    int i,random;
    i=max-min;
    random=(rand()%(i+1))+1;
    *ptr=random+min-1;

    return *ptr;
}

void show_map(struct map A[][col])
//Show candy
//input Array
//output show Array

{
    int i,j;
    printf("\t\tcol\n     0  1  2  3  4  5  6  7  8\n    --------------------------\n");
    for(i=0; i<row; i=i+1)
    {
        if(i==(row/3))
            printf("r %d|",i);
        else if(i==(row/3)+1)
            printf("o %d|",i);
        else if(i==(row/3)+2)
            printf("w %d|",i);
        else
            printf("  %d|",i);
        for(j=0; j<col; j=j+1)
        {
            printf(" %d ",A[i][j].candy );
        }
        printf("\n");
    }
}

void swap(int *p1,int *p2)
//Exchange two locations
//Input Two locations
//Output Exchange two locations
{
    int temp;                        //Temporary location
    temp=*p1;
    *p1=*p2;
    *p2=temp;
}

void check_row_and_polygon(struct map A[][col])
//Three or more consecutive row candy and trapezoidal judgments are eliminated
//Input Array
//Output Three or more consecutive candy and trapezoids become eliminated mode
{
    int i,j;
    int a;
    int temp,end,cont;
    int vary1,vary2,vary3;                           //Cumulative variable

    for(i=0; i<row; i=i+1)
    {
        a=row-1-i;                                   //New row

        for(j=0; j<col-2; j=j+1)
        {
            temp=0;                                  //Temporary location
            if( (A[a][j].candy==A[a][j+1].candy) && (A[a][j+1].candy==A[a][j+2].candy) )       //If three continued are the same
            {
                temp=A[a][j].candy;                  //Temporary location
                filled_zero(&A[a][j].candy);
                filled_zero(&A[a][j+1].candy);
                filled_zero(&A[a][j+2].candy);
            }

            vary1=1;                                 //Calculative variable
            if(temp != 0)
            {
                end=countinued_turned_zero(A,0,vary1,a,j+2,temp);                               //Find the last col of continued candy

                for(cont=j; cont<end; cont=cont+1)
                {
                    vary2=1;                         //Calculative variable
                    vary3=-1;                        //Calculative variable

                    if( (A[a+vary3][cont].candy==temp) && (A[a+vary2][cont].candy==temp) )      //up and down the same
                    {
                        countinued_turned_zero(A,vary2,0,a,cont,temp);
                        countinued_turned_zero(A,vary3,0,a,cont,temp);
                    }

                    if( (A[a+vary2][cont].candy==temp) && (A[a+vary2+1][cont].candy==temp) )    //up and up the same
                    {
                        countinued_turned_zero(A,vary2,0,a,cont,temp);
                    }

                    if( (A[a+vary3][cont].candy==temp) && (A[a+vary3-1][cont].candy==temp) )    //down and down the same
                    {
                        countinued_turned_zero(A,vary3,0,a,cont,temp);
                    }



                }


            }
        }
    }
}

void check_col(struct map A[][col])
//Three or more consecutive col candy judgments are eliminated
//Input Array
//Output Three or more candy become eliminated mode
{
    int i,j;
    int temp;
    int vary1;
    for(i=0; i<col; i=i+1)
    {

        for(j=0; j<row-2; j=j+1)
        {
            temp=0;                                  //Temporary location
            if( (A[j][i].candy==A[j+1][i].candy) && (A[j+1][i].candy==A[j+2][i].candy) )         //If three continued are the same
            {
                temp=A[j][i].candy;
                filled_zero(&A[j][i].candy);
                filled_zero(&A[j+1][i].candy);
                filled_zero(&A[j+2][i].candy);
            }

            vary1=1;                                //Calculative variable
            if(temp != 0)
            {
                countinued_turned_zero(A,vary1,0,j+2,i,temp);
            }

        }
    }
}

void filled_zero(int *p1)
//Candy turned to eliminated mode
//Input candy
//Output eliminated mode
{
    *p1=0;
}

int countinued_turned_zero(struct map A[][col],int num1,int num2,int row1,int col1,int temp)
//Use the three connected candy to find the branch
//Input array,variable1,variable2,row,col,and the temporary location
//Output the branch of the same candy turned to eliminated mode
{
    int count1,count2;                          //record number
    int end;                                    //the last the same candy's location

    if( (num1>0) || (num2>0) )
    {
        do
        {
            count1=num1;
            count2=num2;

            if( ((count2+col1)== col) || (count1+row1)==row )           //if the location is over the map
            {
                goto start1;
            }

            if(A[row1+num1][col1+num2].candy==temp)                      //if there is the same candy
            {

                filled_zero(&A[row1+num1][col1+num2].candy);

                num1=decide_num(num1,1);
                num2=decide_num(num2,1);


            }
        }
        while( (num1>count1) || (num2>count2) );

        start1:
        end=count2+col1;
        return end;
    }
    if(num1<0)                             //if row variable number is negative
    {
        do
        {
            count1=num1;

            if( (row1+num1)<0 )
            {
                break;
            }

            if(A[row1+num1][col1].candy==temp)
            {
                filled_zero(&A[row1+num1][col1].candy);
                num1=decide_num(num1,-1);
            }
        }
        while(num1<count1);

    }
}

int decide_num(int num,int variable)
//Addition of variables
//Input the original variable and the addition
//output the Cumulative variable
{
    if(num != 0)
    {
        num=num+variable;
        return num;
    }
    else
    {
        return 0;
    }

}

void check_row_col_polygon(struct map A[][col])
//Check all shape
//Input Array
//Output the continued all turned to eliminated mode
{

    check_row_and_polygon(A);
    check_col(A);

}

int check_col_zero(struct map A[][col],int col1)
//check each col's zero
//Input array
//output how many zero
{
    int k;
    int count;

    count=0;

    for(k=0; k<row; k=k+1)
    {
        if(A[k][col1].candy==0)
        {
            count=count+1;       //how many zero
        }
    }
    return count;
}

void sort_zero(struct map A[][col])
//put zero on top
//input array
//output zero on top
{
    int i,j,k;
    int row1,count;

    for(i=0; i<col; i=i+1)
    {
        count=check_col_zero(A,i);

        for(k=0; k<count; k=k+1)
        {
            for(j=1; j<row; j=j+1)
            {
                row1=row-j;

                if(A[row1][i].candy==0)
                {
                    swap(&A[row1][i].candy,&A[row1-1][i].candy);      //falled
                }
            }
        }
    }
}

int check_zero(struct map A[][col])
//if there is eliminated mode return 1 else return 0
//input array
//output determine eliminated mode
{
    int i,j;
    int count;

    count=0;

    for(j=0; j<row; j=j+1)
    {
        for(i=0; i<col; i=i+1)
        {
            if(A[j][i].candy==0)
            {
                return 1;                   //if there is zero
            }
        }
    }

    return 0;

}

void falled_rand(struct map A[][col])
//if there is eliminated mode give it new rand
//input array
//output eliminated form turned to random
{
    int i,j;
    for(i=0; i<row; i=i+1)
    {
        for(j=0; j<col; j=j+1)
        {
            if(A[i][j].candy==0)                                //if there is eliminated form
            {
                A[i][j].candy=random(&A[i][j].candy,5,1);
            }
        }
    }
}
int point_candy(struct map A[][col])
//each eliminated mode give it score
//input array
//output point
{
    int i,j;
    int point;

    point=0;

    for(i=0; i<row; i=i+1)
    {
        for(j=0; j<col; j=j+1)
        {
            if(A[i][j].candy==0)
            {
                point=point+SCORE;
            }
        }
    }

    return point;
}

int cycle_check1(struct map A[][col])
//check candy until there is no three continued candy,and get the point
//input array
//output the point each step get
{
    int count,point;

    count=0;
    point=0;

    do
    {
        printf("\n");
        check_row_col_polygon(A);
        count=check_zero(A);                           //if there is eliminated form
        if(count==1)
        {
            show_map(A);
            printf("\n");
        }

        sort_zero(A);
        point=point+point_candy(A);
        falled_rand(A);

        show_map(A);

    }
    while(count==1);

    return point;
}

void cycle_check2(struct map A[][col])
//the start candy map
//input array
//output the map that is no three continued
{
    int count,point;

    count=0;
    point=0;

    do
    {
        check_row_col_polygon(A);
        sort_zero(A);
        count=check_zero(A);
        falled_rand(A);

    }
    while(count==1);
}

void switch_candy(struct map A[][col])
//switch two candy and determine whether it is correct
//input array
//output move
{
    int x,y;
    int ch;
    int count;

    do
    {
        printf("input row:");
        scanf("%d", &x);                           //input row
        printf("input col:");
        scanf("%d", &y);                           //input col

        if((x>=0&&x<row)&&(y>=0&&y<col))//make sure the row and col in this range
        {
            printf("enter your direction ");
            scanf("%d", &ch);

            count=select_direction(ch,A,x,y);      //determine correct move

            if(count==0)
            {
                printf("wrong direction or wrong exchange,please again \n");
            }
        }

        else//if your row and col are not in 0~8
        {
            printf("please re-input your row and col\n");
            count=0;
        }
    }
    while(count==0);
}

int select_direction(int ch,struct map A[][col],int x,int y)
//direction whether it is correct or not
//input the direction array and the row col
//output the variable which represent is it correct
{
    int count;

    if(ch==8)                                    //up
    {
        count=double_check_switch(A,x,y,x-1,y);
        return count;
    }
    if(ch==4)                                   //left
    {
        count=double_check_switch(A,x,y,x,y-1);
        return count;
    }
    if(ch==6)                                   //right
    {
        count=double_check_switch(A,x,y,x,y+1);
        return count;
    }
    if(ch==2)                                   //down
    {
        count=double_check_switch(A,x,y,x+1,y);
        return count;
    }

    return 0;
}

int double_check_switch(struct map A[][col],int row1,int col1,int row2,int col2)
//check everything after you switch
//input array row col and new row new col
//output determine whether it is correct
{
    int count1,count2,count3,count4;

    count4=determine_wrong_move(row2,col2);  //over map
    if(count4==0)
    {
        return 0;
    }
    swap(&A[row1][col1].candy,&A[row2][col2].candy);
    count1=check_row_switch(A);                   //check row
    count2=check_col_switch(A);                   //check col
    count3=check_direction(count1,count2);        //check row and col
    if(count3==0)
    {
        swap(&A[row1][col1].candy,&A[row2][col2].candy);      //if it is not legal switch to original
    }
    return count3;
}

int check_row_switch(struct map A[][col])
//check row
//input array
//output is it correct
{
    int i,j;
    for(i=0; i<row; i=i+1)
    {
        for(j=0; j<col-2; j=j+1)
        {
            if( (A[i][j].candy==A[i][j+1].candy) && (A[i][j+1].candy==A[i][j+2].candy) )
            {
                return 1;
            }
        }
        printf("\n");
    }

    return 0;
}

int check_col_switch(struct map A[][col])
//check col
//input array
//output is it correct
{
    int i,j;
    for(i=0; i<col; i=i+1)
    {
        for(j=0; j<row-2; j=j+1)
        {
            if( (A[j][i].candy==A[j+1][i].candy) && (A[j+1][i].candy==A[j+2][i].candy) )
            {
                return 1;
            }
        }
    }

    return 0;
}

int check_direction(int count1,int count2)
//check row and col
//input two determine variable
//output is it legal
{
    if( (count1==1) || (count2==1) )
    {
        return 1;
    }

    return 0;
}

void title(int time)
//title
//input the step
//output title
{
    printf("remain %d step \n\n",time);
    printf("input 8 up \n");
    printf("input 2 down \n");
    printf("input 6 right \n");
    printf("input 4 left \n\n\n");
}

void derect_win_loss(struct player B[],int target)
//determine win or lost
//input player information
//output win or lose
{

        if(B[0].point>=target)
        {
            printf("You win \n");
        }
        else
        {
            printf("You lose \n");
        }

}


int determine_wrong_move(int row1,int col1)
//the move is over the map
//input row and col
//output is it correct
{
    if( (row1<0 || row1>=row) || (col1<0 || col1>=col) )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void game(struct map A[][col],struct player B[],struct player C[],int turn,int target)
//candy crush
//input array player information
//output game
{
    FILE *fptr;
    fptr=fopen("BOARD.txt","a");
    int i,point,name[10],index=0,COUNT=1;
    long seed;
    point=0;
    for(i=0; i<=10; i++)
        B[i].point=0;
    seed=time(0);
    fill_candy(A);                          //Fill in candy
    cycle_check2(A);
    show_map(A);


    printf("\n");
    printf("WELCOME TO CANDY CRUSH \n\n\n");
    printf("the goal is %d \n\n",target);


    for(i=0; i<turn; i=i+1)
    {
        title(turn-i);
        switch_candy(A);
        point=point+cycle_check1(A);
        printf("the point is %d \n",point);
    }
    B[0].point=point;
    derect_win_loss(B,target);



    for(i=0; i<10; i++)
    {
        if(B[i].point>=target)
        {
            printf("your name:");
            scanf("%s",B[0].name);
            fprintf(fptr,"%10s%10d\t%s\n",B[i].name,B[i].point,ctime(&seed));
        }
    }

    fclose(fptr);

}


