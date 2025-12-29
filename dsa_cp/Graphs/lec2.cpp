#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> vis;
vector<int> node_count;

void dfs(int node) {
    vis[node] = 1;
    node_count.emplace_back(node);
    for(auto v: g[node]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
}

void solve() {
    cin >> n >> m;
    g.resize(n+1);
    vis.resize(n+1);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    vector<vector<int>> no_nodes;
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            node_count.clear();
            dfs(i);
            no_nodes.push_back(node_count);
        }
    }
    // size of vector no_nodes gives number of components.
    cout << "Number of Components " << no_nodes.size() << endl;

    for(int i=0; i<no_nodes.size(); i++) {
        cout << "Component " << i + 1 << " :\n";
        for(auto v: no_nodes[i]) {
            cout << v << ", ";
        }
        cout << "\n";
    }

    long long ans = 0;
    for(auto v: no_nodes) {
        ans += 1LL * (v.size())*(n-v.size());
    }
    ans = ans/2;
    cout << "Number of such edges " << ans << endl;
}

// why is emplace back faster than push back?

int main() {
    solve();
    return 0;
}
// return 0, 0 means successfully run.