#include<bits/stdc++.h>

using namespace std;


void bfs(int start, vector<vector<int>> &adj) {
    
    int n = adj.size();
    vector<int> visited(n, 0);
    queue<int> q;

    q.push(start);
    visited[start] = 1;

    while(!q.empty()) {
        int node = q.front();
        cout << node << endl;
        q.pop();
        for(auto e: adj[node]) {
            if(!visited[e]) {
                q.push(e);
                visited[e] = 1;
            }
        }
    }

}

int main() {

    vector<vector<int>> adj = {{1, 2}, {2, 0}, {0, 1}};
    bfs(1, adj);
}