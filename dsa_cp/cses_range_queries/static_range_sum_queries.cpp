#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	vector<long long> prefixsum(n);
	long long prevsum = 0;
	for(int i=0; i<n; i++) {
		int x;
		cin >> x;
		prevsum += x;
		prefixsum[i] = prevsum;
	}
	
	while(q--) {	
		int a, b;
		cin >> a >> b;
		a--; b--;
		if(a == 0) { cout << prefixsum[b] << endl;}
		else cout << prefixsum[b] - prefixsum[a-1] << endl;
	}
}
