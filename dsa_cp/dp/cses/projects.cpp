#include<bits/stdc++.h>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	vector<pair<int, pair<int, int>>> projects(n+1);
	for(int i=1; i<=n; i++) {
		int start, end, award;
		cin >> start >> end >> award;
		projects[i] = {end, {start, award}};
	}
	
	sort(projects.begin(), projects.end());
	vector<long long> dp(n+1);
	
	dp[0] = 0;

	for(int i=1; i<=n; i++) {
		dp[i] = max(dp[i-1], 1LL*projects[i].second.second);
		int index = lower_bound(projects.begin(), projects.end(), make_pair(projects[i].second.first, make_pair(-1, -1))) - projects.begin();	
		dp[i] = max(dp[i], dp[index-1] + projects[i].second.second);

	}
	
	cout << dp[n] << endl;
}
