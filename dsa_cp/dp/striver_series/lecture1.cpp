#include<bits/stdc++.h>

using namespace std;

// Memotization 

// TC -- O(n) and SC -- O(n) (array) + O(n) (stack)
int f(int n, vector<int>&dp) {
	if(n <=1) return n;
	
	if(dp[n] != -1) return dp[n];
	
	return dp[n]  = f(n-1, dp) + f(n-2, dp);	
}

// using Tabulation -- Bottom up dynamic programming

// TC -- O(n) and SC -- O(n) (array)

int f2(int n) {
	
	vector<int> dp(n+1, -1);
	dp[0] = 0;
	dp[1] = 1;
	for(int i=2; i<=n; i++) {
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}

// space optimization

// TC -- O(n) and SC -- O(1) -- optimized using variables. 

int f3(int n) {
	
	if(n <=1) return n;
	int prev2 = 0;
	int prev1 = 1;
	for(int i=2; i<=n; i++) {
		int curr = prev1 + prev2;
		prev2 = prev1;
		prev1 = curr;
	}
	return prev1;
	
}

int main() {
	
	int n;
	cin >> n;
	vector<int> dp(n+1, -1);
	cout << f(n, dp) << endl;
	cout << f2(n) << endl;
	cout << f3(n) << endl;
	return 0;
}
