#include<bits/stdc++.h>

using namespace std;


long long subsequences(vector<int>&weights, int i, long long currweight, long long totalweight) {
	
	if(i == weights.size()) return LONG_MAX;
	
	
	long long ans = abs(2*currweight - totalweight);
	
	ans = min(ans, subsequences(weights, i+1, currweight+weights[i], totalweight));
	ans = min(ans, subsequences(weights, i+1, currweight, totalweight));
	
	return ans;
}

int main() {
	int n;
	cin >> n;
	
	vector<int> weights(n);
	
	long long totalweight = 0;
	for(int i=0; i<n; i++) {
		cin >> weights[i];
		totalweight += weights[i];
	}
	
	cout << subsequences(weights, 0, 0, totalweight) << endl;
	
}
