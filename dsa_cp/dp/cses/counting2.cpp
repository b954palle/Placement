#include<bits/stdc++.h>

using namespace std;


int main() {
	long long a, b;
	cin >> a >> b;
	
	vector<bool> dp(b+1);
	
	for(int i=0; i<=9; i++) dp[i] = true;
	
	for(long long i=10; i<=b; i++) {
		int r = i%10;
		long long remaining = i/10;
		if(!dp[remaining]) {
			dp[i] = false;
		}
		else {
			int r2 = remaining%10;
			if(r2 == r) dp[i] = false;
			else dp[i] = true;	
		}
	}
	
	int count =0;
	for(int i=a; i<=b; i++) {
		if(dp[i]) count++;
	}
	
	cout << count << endl;
}
