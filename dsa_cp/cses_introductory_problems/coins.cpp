#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;
		if((a+b)%3 != 0) cout << "NO" << endl;
		else  {
			if(a < (a+b)/3 || b < (a+b)/3) cout << "NO" << endl;
			else cout << "YES" << endl;
		}
	}
	
}
