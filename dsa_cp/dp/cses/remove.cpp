#include<bits/stdc++.h>

using namespace std;

int main() {
	
	int n;
	cin >>n;
	vector<int> nums(n);
	
	for(int i=0; i<n; i++) {
		cin >> nums[i];
	}
	
	vector<vector<long long>> dp1(n+1, vector<long long>(n+1));
	vector<vector<long long>> dp2(n+1, vector<long long>(n+1));
	
	for(int i=0; i<=n; i++) {dp1[i][i] = nums[i]; dp2[i][i] = 0;}
	

	for(int i=2; i<=n; i++) {
		for(int j=0; j+i-1<n; j++) {
			int last = j+i-1;
			long long ans1 = 0;
			long long ans2 = 0;
			
			
			if(dp2[j+2][last] + nums[j+1] > dp2[j+1][last-1] + nums[last]) {
				if(i>2) {ans1 = dp1[j+2][last] + nums[j];
				ans2 = dp2[j+2][last] + nums[j+1];}
				else {
					ans1 = nums[j];
					ans2 = nums[j+1];
				}
			}
			else {
			
				if(i>2) {
					ans1 = dp1[j+1][last-1] + nums[j];
					ans2 = dp2[j+1][last-1] + nums[last];
				}
				else {
					ans1 = nums[j];
					ans2 = nums[last];
				}
			}
			
			
			if(dp2[j+1][last-1] + nums[j] > dp2[j][last-2] + nums[last-1]) {
				
				long long currans;
				if(i > 2)  currans = dp1[j+1][last-1] + nums[last];
				else currans =  nums[last];
				if(currans > ans1) {
					ans1 = currans;
					ans2 = dp2[j+1][last-1] + nums[j];
				}
			}  
			else {
				long long currans;
				if(i > 2)  currans = dp1[j][last-2] + nums[last];
				else currans =  nums[last];
				
				if(currans > ans1) {
					ans1 = currans;
					ans2  = dp2[j][last-2] + nums[last-1];
				}
			}

			
			dp1[j][last] = ans1;
			dp2[j][last] = ans2;
			
			
	
			
		}
	}
	
	cout << dp1[0][n-1] << endl;
}
