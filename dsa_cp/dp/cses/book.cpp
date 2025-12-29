#include<bits/stdc++.h>

using namespace std;


int main() {
	
	int n, x;
	cin >> n >> x;
	
	vector<int> prices(n);
	vector<int> pages(n);
	
	for(int i=0; i<n; i++) cin >> prices[i];
	for(int i=0; i<n; i++) cin >> pages[i];
	
	vector<int> dp(x+1, 0);
	
	for(int i=0; i<n; i++) {
		for(int val = x; val >=1; val--) {

			if(prices[i] -val > 0) break;
			if(i>0) dp[val] = max(pages[i]+dp[val-prices[i]], dp[val]);
			else dp[val] = max(dp[val], pages[i]);
		}
	}
	
	cout << dp[x] << endl;
}
