#include<bits/stdc++.h>

using namespace std;


int main() {
	
	int n, m, q;
	cin >> n >> m >> q;
	
	vector<vector<long long>> cost(n+1, vector<long long>(n+1, LONG_MAX));
	
	for(int i=0; i<m; i++) {
		
		int a, b, c;
		cin >> a >> b >> c;
		cost[a][b] = min(cost[a][b], 1LL*c);
		cost[b][a] = cost[a][b];
	}
	
	
	
	for(int i=1; i<=n; i++) cost[i][i] = 0;
	
	for(int via=1; via <= n; via++) {
		for(int a=1; a<=n; a++) {
			for(int b=1; b<=n; b++) {
				if(cost[a][via] != LONG_MAX && cost[b][via] != LONG_MAX) {
					cost[a][b] = min(cost[a][b], cost[a][via] + cost[b][via]);
					cost[b][a] = cost[a][b];				
				}
			}
		}
	}
	
	while(q--) {
		
		int a, b;
		cin >> a >> b;
		
		if(cost[a][b] == LONG_MAX) cout << -1 << endl;
		else cout << cost[a][b] << endl;
	}
}
