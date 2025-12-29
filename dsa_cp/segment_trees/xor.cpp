#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, q;
	cin >> n >> q;
	vector<int> xors(n, 0);
	int prevxor = 0;
	for(int i=0; i<n; i++) {	
		int x;
		cin >> x;
		prevxor ^= x;
		xors[i] = prevxor;

	}
	while(q--) {
		int i, j;
		cin >> i >> j;
		if(i==1){
			cout << xors[j-1]<<endl;
		}
		else {

			cout << (xors[j-1]^xors[i-2]) << endl;
		}
	}
	return 0;
}
