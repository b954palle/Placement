#include<bits/stdc++.h>

using namespace std;


int main() {
	
	int n;
	cin >> n;
	
	vector<string> v(2);
	v[0] = "0";
	v[1] = "1";
	for(int i=2; i<=n; i++) {
		int k = v.size();
		for(int j=k-1; j>=0; j--) {
			v.push_back(v[j]);
		}
		for(int i=0; i<k; i++) {
			v[i] += '0';
		}
		for(int i=k; i<2*k; i++) {
			v[i] += '1';
		}
	}
	
	for(auto s: v) cout << s << endl;	
}
