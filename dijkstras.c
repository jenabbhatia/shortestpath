#include<stdio.h>
#include<limits.h>
typedef enum {false, true} bool;

//number of vertices in the graph
#define V 9

int mindistance(int dist[],bool sptset[])
{
    
    int min=INT_MAX;
    int min_index,v;
    
    for(v=0;v<V;v++)
    {
        if(sptset[v] == false && dist[v] < min)
        {
         min=dist[v];
         min_index=v;
        }
    }
    return min_index;
    
}

void printsolution(int dist[],int n)
{
    int i;
   printf("Vertex       Distance from source\n");
   for(i=0;i<V;i++)
        printf("%d\t\t%d\n",i,dist[i]);
        
        
}

void dijkstra(int graph[V][V],int src)
{
    int dist[V];
    bool sptset[V];
    int i;
    
    //initialize distance of all vertices as infinite and sptset as false
    for(i=0;i<V;i++)
    {
        dist[i]=INT_MAX;
        sptset[i] = false;
    }
    //intitialize source vertex distance as zero
    dist[src]=0;
    int count;
    for(count=0;count<V;count++)
    {
        int u=mindistance(dist,sptset);
        
        sptset[u] = true;
        int v;
        //update distance of all adjacent vertices of the picked vertex
        for(v=0;v<V;v++)
        {
            if(!sptset[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
            {
                    dist[v]=dist[u]+graph[u][v];
            }
            
        }
    }
    printsolution(dist,V);
}
int main()
{
    //creating a example graph
    int graph[V][V]={{0,4,0,0,0,0,0,8,0},
                     {4,0,8,0,0,0,0,11,0},
                     {0,8,0,7,0,4,0,0,2},
                     {0,0,7,0,9,14,0,0,0},
                     {0,0,0,9,0,10,0,0,0},
                     {0,0,4,14,10,0,2,0,0},
                     {0,0,0,0,0,2,0,1,6},
                     {8,11,0,0,0,0,1,0,7},
                     {0,0,2,0,0,0,6,7,0}};
    dijkstra(graph,0);
        
    
}
