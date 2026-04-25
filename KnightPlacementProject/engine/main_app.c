#include <stdio.h>

#define N 8

void knight(int mat[N][N],int *r,int *c);

int main() {

    int board[N][N] = {0};

    int r = N;
    int c = N;

    knight(board,&r,&c);

    return 0;
}
