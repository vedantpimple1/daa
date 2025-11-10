#include <stdio.h>
#define N 4
int INF=9999;
int graph[N][N]={{0,10,15,20},{10,0,35,25},{15,35,0,30},{20,25,30,0}};
int visited[N],minCost=INF;
void tsp(int city,int count,int cost){
    if(count==N && graph[city][0]){
        if(cost+graph[city][0]<minCost) minCost=cost+graph[city][0];
        return;
    }
    for(int i=0;i<N;i++){
        if(!visited[i] && graph[city][i]){
            visited[i]=1;
            tsp(i,count+1,cost+graph[city][i]);
            visited[i]=0;
        }
    }
}
int main(){
    visited[0]=1;
    tsp(0,1,0);
    printf("Minimum cost = %d",minCost);
}
