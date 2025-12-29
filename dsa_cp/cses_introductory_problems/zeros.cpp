#include<bits/stdc++.h>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	long long ans = 0;
	int power = 5;
	while(true) {
		int k =  (n/power);
		if(k == 0) break;
		ans += k;
		power *= 5;
	}
	cout << ans << endl;
}
