#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i=0; i<n; i++) cin >> nums[i];
	
	vector<int> dp;
	for(int i=0; i<n; i++) {
		
		auto it= lower_bound(dp.begin(), dp.end(), nums[i]);
		
		if(it == dp.end()) {
			dp.push_back(nums[i]);
		}
		else *it = nums[i];
	}
	
	cout << dp.size() << endl;
}
