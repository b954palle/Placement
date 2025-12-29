#include<bits/stdc++.h>

using namespace std;


int main() {
	int n;
	cin >> n;
	
	for(int i=1; i<=n; i++) {
		long long k = i;
		
		long long total = (k*k*(k*k-1))/2;
		long long collision =  0;
		if(k >=3) collision = 2*2*(k-2)*(k-1);
		
		cout << total - collision << endl;
		
	}
}

