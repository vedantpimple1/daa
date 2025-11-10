#include <stdio.h>
int main(){
    int n=3; float W=50;
    float wt[]={10,20,30}, val[]={60,100,120}, ratio[3];
    for(int i=0;i<n;i++) ratio[i]=val[i]/wt[i];
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(ratio[i]<ratio[j]){
                float t=ratio[i];ratio[i]=ratio[j];ratio[j]=t;
                t=wt[i];wt[i]=wt[j];wt[j]=t;
                t=val[i];val[i]=val[j];val[j]=t;
            }
    float total=0.0, res=0.0;
    for(int i=0;i<n;i++){
        if(total+wt[i]<=W){ total+=wt[i]; res+=val[i]; }
        else{ res+=(W-total)*ratio[i]; break; }
    }
    printf("Maximum value = %.2f",res);
}
