#include <stdio.h>
int N=4, sol=0;

int safe(int board[4][4],int r,int c){
    for(int i=0;i<c;i++) if(board[r][i]) return 0;
    for(int i=r,j=c;i>=0&&j>=0;i--,j--) if(board[i][j]) return 0;
    for(int i=r,j=c;i<N&&j>=0;i++,j--) if(board[i][j]) return 0;
    return 1;
}

void printBoard(int board[4][4]){
    sol++;
    printf("\nSolution %d:\n",sol);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]==1) printf("Q ");
            else printf(". ");
        }
        printf("\n");
    }
}

void solve(int board[4][4],int c){
    if(c==N){ printBoard(board); return; }
    for(int i=0;i<N;i++){
        if(safe(board,i,c)){
            board[i][c]=1;
            solve(board,c+1);
            board[i][c]=0;
        }
    }
}

int main(){
    int board[4][4]={0};
    solve(board,0);
    printf("\nTotal solutions = %d\n",sol);
    return 0;
}
