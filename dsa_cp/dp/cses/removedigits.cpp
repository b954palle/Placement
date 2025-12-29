#include<bits/stdc++.h>

using namespace std;


int main() {
	
	int n;
	cin >> n;
	
	vector<int> dp(n+1, INT_MAX);
	

	dp[0] = 0;
	for(int i=1; i<=n; i++) {
		int num = i;
		while(num != 0) {
			int d = num%10;
			if(dp[i-d] != INT_MAX) {
					dp[i] = min(dp[i], 1+ dp[i-d]);
			}
			num /= 10;
		}
	}
	
	cout << dp[n] << endl;
}
