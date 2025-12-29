#include<bits/stdc++.h>

using namespace std;


int solve(long long k) {
	
	int d = log10(k);
	
	long long prev = pow(10, d) - 1;
	
	k -= prev;
	
}

int main() {
	
	int q;
	cin >> q;
	while(q--) {
		long long k;
		cin >> k;
		solve(k);
	}
}
