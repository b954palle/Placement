#include<bits/stdc++.h>

using namespace std;


int main() {
	
	int n, x;
	cin >> n >> x;
	vector<int> weights(n+1);
	for(int i=1; i<=n; i++) cin >> weights[i];
	
	vector<pair<int, long long>> dp(n+1);
	dp[0]= {0, 0};
	
	for(int i=1; i<=n; i++) {
		for(int j=0; j<i; j++) {
			pair<int, long long> p = dp[j];
			long long wt = p.second;
			if(wt + weights[i] <= x) {
				dp[i] = make_pair(p.first, wt + weights[i]);
			}
			else {
				dp[i] = make_pair(p.first+1, min(1LL*weights[i], p.second));
			}
		}
	}
	
	cout << dp[n].first << endl;
}
