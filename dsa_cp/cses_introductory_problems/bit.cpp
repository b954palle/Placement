#include<bits/stdc++.h>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	int ans = 1;
	int mod = 1e9+7;
	while(n--) {
		(ans *= 2)%= mod;
	}
	cout << ans << endl;
}
