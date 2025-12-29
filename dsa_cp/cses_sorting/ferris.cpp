#include<bits/stdc++.h>

using namespace std;

int main() {
	
	int n,x;
	cin >> n >> x;
	
	vector<int> gandolas(n);
	for(int i=0; i<n; i++) {
		cin >> gandolas[i];
	}
	
	sort(gandolas.begin(), gandolas.end());
	int ans = 0;
	int i=0; 
	int j=n-1;
	
	while(j > i) {
		
		if(gandolas[i] + gandolas[j] <= x) {
			ans++;
			i++;
			j--;
		}
		else {
			j--;
			ans++;
		}
	}
	
	if(j==i) ans++;
	cout << ans << endl;
}
