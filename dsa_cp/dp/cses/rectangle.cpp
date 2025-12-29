#include<bits/stdc++.h>


using namespace std;


int main() {

	int a, b;
	cin >> a >> b;
	
	vector<vector<int>> dp(a+1, vector<int>(b+1, INT_MAX));
	
	for(int i=0; i<=min(a, b); i++) dp[i][i] = 0;
	
	for(int i=1; i<=a; i++) {
		for(int j=1; j<=b; j++) {
			for(int k1=1; k1<i; k1++) {
				dp[i][j] = min(dp[i][j], 1+dp[k1][j]+dp[i-k1][j]);
			}
			for(int k2=1; k2<j; k2++) {
				dp[i][j] = min(dp[i][j], 1+dp[i][k2] + dp[i][j-k2]);
			}
		}
	}
	
	cout << dp[a][b] << endl;
}

