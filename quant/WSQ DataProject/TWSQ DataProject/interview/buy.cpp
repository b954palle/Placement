#include<bits/stdc++.h>

using namespace std;


int MaxProfit(vector<int>& A, int k) {
	
	int n = A.size();
	
	vector<vector<int>> dp(n, vector<int>(k+1, 0));
	
	for(int i = n-2; i>=0; i--) {
		for(int t = 1; t<=k; t++) {
			int maxp = dp[i+1][t];
			for(int j=i+1; j < n; j++) {
				if(A[i] < A[j]) maxp = max(maxp, A[j]-A[i]+dp[j][t-1]);
			}
			dp[i][t] = maxp;
		}
	}
	return dp[0][k];
}
int main(){
	
	vector<int> A = {2, 4, 1}; 
	int k = 2;
	cout << MaxProfit(A, k) << endl;
}
