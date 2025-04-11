// Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge between the nodes u and v having w edge weight.
// You have to find the shortest distance of all the vertices from the source vertex src, and return an array of integers where the ith element denotes the shortest distance between ith node and source vertex src.

// Note: The Graph is connected and doesn't contain any negative weight edge.

// Examples:

// Input: V = 3, edges[][] = [[0, 1, 1], [1, 2, 3], [0, 2, 6]], src = 2
// Output: [4, 3, 0]
// Explanation:

// Shortest Paths:
// For 2 to 0 minimum distance will be 4. By following path 2 -> 1 -> 0
// For 2 to 1 minimum distance will be 3. By following path 2 -> 1
// For 2 to 2 minimum distance will be 0. By following path 2 -> 2
// Input: V = 5, edges[][] = [[0, 1, 4], [0, 2, 8], [1, 4, 6], [2, 3, 2], [3, 4, 10]], src = 0
// Output: [0, 4, 8, 10, 10]
// Explanation: 

// Shortest Paths: 
// For 0 to 1 minimum distance will be 4. By following path 0 -> 1
// For 0 to 2 minimum distance will be 8. By following path 0 -> 2
// For 0 to 3 minimum distance will be 10. By following path 0 -> 2 -> 3 
// For 0 to 4 minimum distance will be 10. By following path 0 -> 1 -> 4

class Solution {
    public:
      vector<int> dijkstra(int n, vector<vector<int>> &edges, int src) {
          vector<pair<int,int>>adj[n];
          for(auto it:edges){
              adj[it[0]].push_back({it[2], it[1]});
              adj[it[1]].push_back({it[2], it[0]});
          }
          
          priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
          
          vector<int>dist(n, 1e9);
          dist[src]=0;
          pq.push({0, src});
          
          while(!pq.empty()){
              int wt=pq.top().first;
              int node=pq.top().second;
              pq.pop();
              
              for(auto it:adj[node]){
                  if(dist[it.second] > wt + it.first){
                      dist[it.second] = wt+it.first;
                      pq.push({dist[it.second], it.second});
                  }
              }
          }
          for(int i=0;i<n;i++){
              if(dist[i]==1e9) dist[i]=-1;
          }
          return dist;
          
      }
  }
;