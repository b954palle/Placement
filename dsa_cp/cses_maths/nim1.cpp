#include<bits/stdc++.h>

using namespace std;


int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	
		int n;
		cin >> n;
		
		int nimsum = 0;
		for(int i=0; i<n; i++) {
			int k;
			cin >> k;
			nimsum ^= k;
		}

		if(nimsum != 0) cout << "first" << endl;
		else cout << "second" << endl;
		
	}
	
	
}
