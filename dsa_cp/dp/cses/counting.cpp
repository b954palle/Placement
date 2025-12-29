#include<bits/stdc++.h>

using namespace std;


int main() {

	int t;
	cin >> t;
	int mod = 1e9 + 7;
	while(t--) {
	
		int n;
		cin >> n;
		int a1, b1;
		a1 = 1;
		b1 = 1;
		for(int i=2; i<=n; i++) {
			int anext = (2LL*a1+b1)%mod;
			int bnext = (4LL*b1 + a1)%mod;
			a1 = anext;
			b1 = bnext;
		}
		
		cout << (a1 + b1)%mod << endl;
	}
}
