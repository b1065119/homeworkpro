void fill_candy(struct map A[][col]);
int random(int *ptr,int max,int min);
void show_map(struct map A[][col]);
void swap(int *p1,int *p2);
void check_row_and_polygon(struct map A[][col]);
void check_col(struct map A[][col]);
void filled_zero(int *p1);
int countinued_turned_zero(struct map A[][col],int num1,int num2,int row1,int col1,int temp);
int decide_num(int num,int variable);
void check_row_col_polygon(struct map A[][col]);
int check_col_zero(struct map A[][col],int col1);
void sort_zero(struct map A[][col]);
int check_zero(struct map A[][col]);
void falled_rand(struct map A[][col]);
int cycle_check1(struct map A[][col]);
void cycle_check2(struct map A[][col]);
int point_candy(struct map A[][col]);
void switch_candy(struct map A[][col]);
int check_col_switch(struct map A[][col]);
int check_row_switch(struct map A[][col]);
int check_direction(int count1,int count2);
int select_direction(int ch,struct map A[][col],int x,int y);
void game(struct map A[][col],struct player B[],struct player C[],int turn,int target);
void title(int time);
void derect_win_loss(struct player B[],int target);
int determine_wrong_move(int row1,int col1);
int double_check_switch(struct map A[][col],int row1,int col1,int row2,int col2);
