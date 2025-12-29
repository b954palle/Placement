#include<bits/stdc++.h>

using namespace std;



int main() {
	
	int t;
	cin >> t;
	
	while(t--) {
		int i, j;
		cin >> i >> j;
		long long boundary = max(i, j);
		if(i >= j) {
			if(i%2 == 0) {
				cout << boundary*boundary - (j-1) << endl;
			}
			else {
				cout << boundary*boundary - (i-1) - (i-j) << endl;
			}
		}
		else {	
			if(j%2 == 1) {
				cout << boundary*boundary - (i-1) << endl;
			}
			else {
				cout << boundary*boundary - (j-1)-(j-i) << endl;
			}
		}
		
	}
}
