#include <stdio.h>
int max(int a,int b){return (a>b)?a:b;}
int main(){
    int n=4,W=7;
    int wt[]={1,3,4,5}, val[]={1,4,5,7};
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++)
        for(int w=0;w<=W;w++)
            if(i==0||w==0) dp[i][w]=0;
            else if(wt[i-1]<=w) dp[i][w]=max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]);
            else dp[i][w]=dp[i-1][w];
    printf("Maximum value = %d",dp[n][W]);
}
