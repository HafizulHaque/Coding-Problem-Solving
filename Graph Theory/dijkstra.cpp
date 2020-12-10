#include <bits/stdc++.h>
using namespace std;
#define V 9

int minDistance(int dist[], bool sptSet[]){
   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}

int printSolution(int dist[], int n){
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d  %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src){
     int dist[V];
     bool sptSet[V];

     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

     dist[src] = 0;

     for (int count = 0; count < V-1; count++){
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet);

       // Mark the picked vertex as processed
       sptSet[u] = true;

       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < V; v++)

         // Update dist[v] only if is not in sptSet, there is an edge from
         // u to v, and total weight of path from src to  v through u is
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }

     // print the constructed distance array
     printSolution(dist, V);
}


int main(){
    FILE *inp = freopen("dijsktra.txt", "r", stdin);
    int graph[V][V];

    for(int i = 0; i < V; ++i)
        for(int j = 0; j < V; ++j)
            cin>>graph[i][j];

    dijkstra(graph, 0);

    fclose(inp);
    return 0;
}
