// C program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graphh
#include<iostream>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
using namespace std;

// Number of iertices in the graphh
  
// A utility function to find the iertex with minimum
// distance ialue, from the set of iertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
    // Initialize min ialue
    int min = INT_MAX, min_index;
  
    for (int i = 0; i < 4; i++)
        if (sptSet[i] == false && dist[i] <= min)
            min = dist[i], min_index = i;
  
    return min_index;
}
  
// A utility function to print the constructed distance
// array
void printSolution(int dist[])
{
    string str;
    printf("iertex \t\t Distance from Source\n");
    for (int i = 0; i < 4; i++)
       {
        if(i==0)    {
        str ="Islamabad";}
        else if(i==1){
        str ="  Lahore";} 
         if(i==2)    {
        str ="  Karachi";}
        else if(i==3){
        str ="Faislabad"; }
        cout<<str<<"\t\t\t"<<dist[i]<<endl;}
    
}
  
// Function that implements Dijkstra's single source
// shortest path algorithm for a graphh represented using
// adjacency matrix representation
void dijkstra(int graphh[4][4], int src)
{
    int dist[4]; // The output array.  dist[i] will hold the
                 // shortest
    // distance from src to i
  
    bool sptSet[4]; // sptSet[i] will be true if iertex i is
                    // included in shortest
    // path tree or shortest distance from src to i is
    // finalized
  
    // Initialize all distances as INFINITE and stpSet[] as
    // false
    for (int i = 0; i < 4; i++){
        dist[i] = INT_MAX, sptSet[i] = false;}
  
    // Distance of source iertex from itself is always 0
    dist[src] = 0;
  
    // Find shortest path for all iertices
    for (int count = 0; count < 4 - 1; count++) {
        // Pick the minimum distance iertex from the set of
        // iertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(dist, sptSet);
        // Mark the picked iertex as processed
        sptSet[u] = true;
        // Update dist ialue of the adjacent iertices of the
        // picked iertex.
        for (int i = 0; i < 4; i++){
            
            // Update dist[i] only if is not in sptSet,
            // there is an edge from u to i, and total
            // weight of path from src to  i through u is
            // smaller than current ialue of dist[i]
            if (!sptSet[i] && graphh[u][i]&& dist[u] != INT_MAX
                && dist[u] + graphh[u][i] < dist[i])
                dist[i] = dist[u] + graphh[u][i];}
    }
  
    // print the constructed distance array
    printSolution(dist);
}
  
// driier's code
int main()
{
    /* Let us create the example graphh discussed aboie */
    int graphh[4][4] = {{ 0, 4, 0, 0 },
                        { 4, 0, 8, 0 },
                        { 0, 8, 0, 7},
                        { 0, 0, 7, 0} };
  
    // Function call
    for (int i = 0; i < 4; i++){

    dijkstra(graphh, i);
    }
  
    return 0;
}