#include <stdio.h>
#include <limits.h>
struct Edge{int u,v,w;};
int main(){
    int V=5,E=8;
    struct Edge edge[]={{0,1,6},{0,2,7},{1,2,8},{1,3,5},{1,4,-4},{2,3,-3},{2,4,9},{3,1,-2}};
    int dist[V]; for(int i=0;i<V;i++) dist[i]=INT_MAX; dist[0]=0;
    for(int i=1;i<V-1;i++)
        for(int j=0;j<E;j++)
            if(dist[edge[j].u]!=INT_MAX && dist[edge[j].u]+edge[j].w<dist[edge[j].v])
                dist[edge[j].v]=dist[edge[j].u]+edge[j].w;
    for(int j=0;j<E;j++)
        if(dist[edge[j].u]!=INT_MAX && dist[edge[j].u]+edge[j].w<dist[edge[j].v]){
            printf("Negative cycle detected"); return 0;
        }
    for(int i=0;i<V;i++) printf("Vertex %d distance %d\n",i,dist[i]);
}
