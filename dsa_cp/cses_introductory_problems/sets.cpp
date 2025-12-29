#include<bits/stdc++.h>

using namespace std;


int main() {
	
	int n;
	cin >> n;
	
	long long sum = (1LL*n*(n+1))/2;
	if(sum %2 != 0) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	sum /= 2;
	long long currsum = 0;
	int i=n;
	vector<bool> set1(n+1, false);
	int count = 0;
	for(; i>=1; i--) {
		if(currsum + i >= sum) {
			set1[(sum-currsum)] = true;
			count++;
			break;
		}
		else {
			currsum += i;
			count++;
			set1[i] = true;
		}
	}
	
	cout << count << endl;
	for(int i=1; i<=n; i++) {
		if(set1[i]) cout << i << " ";
		
	}
	cout << endl;
	cout << n - count << endl;
	for(int i=1; i<=n; i++) {
		if(!set1[i]) cout << i << " ";
	}
	cout << endl;
}
