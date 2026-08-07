
/*
Problem 1: The Kingdom’s Relay Protocol
Topic: BFS / Shortest Path in Unweighted Graph
Story:
In the digital realm of Cyberia, the central server needs to broadcast an emergency patch across a decentralized peer-to-peer
network of routers. Because the network is vulnerable, data packets can only move between directly connected routers in 1 second 
intervals. However, certain routers are "high-latency relay stations" that double the communication steps if not bypassed.You are 
given a network map represented as an undirected graph with N routers (numbered 0 to N-1) and a list of direct connections. 
Given a starting router ID representing the root server, find the minimum time (in seconds) required for the patch to reach every 
single router in the network. If the network is partitioned and some routers cannot be reached, return -1.

Example 1
Input: N = 4, edges = [[0, 1], [1, 2], [2, 3], [0, 2]], start = 0
Output: 2
Explanation: Router 0 reaches Routers 1 and 2 in 1 second. From Router 2, it reaches Router 3 in the 2nd second. Maximum time is 
2 seconds.
Example 2:
Input: N = 3, edges = [[0, 1]], start = 0
Output: -1
Explanation: Router 2 is completely isolated, so the patch cannot reach all nodes.

Constraints:
1 ≤ N ≤ 10^5
0 ≤ edges.length ≤ 2 × 10^5
All nodes are indexed from 0 to N - 1.

*/

#include <bits/stdc++.h>
using namespace std ;

int solve(int V, unordered_map<int, vector<int>>&adj , int src){
    
    vector<bool>visited(V, false) ;
    queue<int>q ;
    q.push(src) ;
    visited[src] = true ;

    int time = -1;
    int count = 0;

    while(!q.empty()){

        int sz = q.size();

        while(sz--){

            int node = q.front();
            q.pop();

            count++ ;

            for(auto neigh : adj[node]){

                if(!visited[neigh]){

                    q.push(neigh) ;
                    visited[neigh] = true ;
                }
            }
        }

        time++ ;
    }

    return count == V ? time : -1 ;
}

int main(){

    int V, E ;
    cin >> V >> E ;

    vector<vector<int>> edges(E, vector<int>(2));

    for(int i = 0; i < E; i++){
       
        cin >> edges[i][0] >> edges[i][1] ;
    }

    unordered_map<int, vector<int>>adj ;

    for(int i = 0; i<edges.size(); i++){

        int u = edges[i][0] ;
        int v = edges[i][1] ;

        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    int ans = solve(V, adj, 0) ;

    cout<<"Minimum Time Is: "<< ans << endl ;

    return 0 ;
}

