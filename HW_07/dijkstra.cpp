//Created by Bradley Morton Dec 14 2019
//Created for CS411, taught by Dr. Hartman

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;



//This function assumes that the graph is connected and that the total length for the longest path is below 999999999
//This also assumes that the root is vertex 0 and that the graph has at least one vertex.
vector<int> dijkstra(const vector<vector<int>> & graph)
{
    vector<int> distances(graph.size());
    vector<bool> visited(graph.size());
    visited[0]=true;
    for(auto i=0;i<graph.size();i++)
    {
        distances[i]=999999999;
    }
    distances[0]=0;
    for(auto i=0;i<graph.size();i++)
    {
        int minimum=999999999;
        int l = 0; // l is short for location; I refactored it after it made the accesses below very long
        for(auto j=0; j<graph.size(); ++j)
        {
            //iterate through graph, looking for minimum addition
            if(visited[j]==false && distances[j]<minimum)
            {
                minimum=distances[j];
                l=j;
            }
        }
        visited[l]=true;
        for(auto j=0;j<graph.size();j++)
        {
            if(!visited[j] && bool(graph[l][j]) && distances[l]!=999999999 && distances[l]+graph[l][j]<distances[j])
                distances[j]=distances[l]+graph[l][j];
        }
    }
    return distances;
}





//Graph data taken from https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/ to have validation
int main()
{
        vector<vector<int>> graph{
                { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

        auto distances = dijkstra(graph);

        for(int i=0; i<graph.size(); ++i)
        {
            cout<< "Distance to "<<i<<": "<<distances[i]<<endl;
        }

        return 0;
}