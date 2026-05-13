#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dx[8]={1,-1,1,-1,0,1,-1,0};
int dy[8]={1,-1,-1,1,1,0,0,-1};

int dfs(char **mat,int n,char *s,int x,int y,int index) {
    if (s[index]=='\0')
        return 1;

    if (x<0 || x>=n || y<0 || y>=n)
        return 0;

    if (mat[x][y] != s[index])
        return 0;

    for (int d=0; d<8; d++) {
        if (dfs(mat,n,s,x+dx[d],y+dy[d],index+1))
            return 1;
    }

    return 0;
}

int word_search(char **mat,int n,char *s) {
    if (!strlen(s))
        return 1;

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (dfs(mat,n,s,i,j,0))
                return 1;
        }
    }

    return 0;
}

int main(void) {
    char mat[4][4] = {
        {'a','b','c','e'},
        {'x','e','c','s'},
        {'t','d','e','f'},
        {'x','y','v','w'}
    };

    char **matt = malloc(sizeof(char*)*4);
    if (!matt) return -1;

    for (int i=0;i<4;i++)
        matt[i]=mat[i];

    int d = word_search(matt,4,"see");
    printf("%d\n",d);

    free(matt);
    return 0;
}
