#include<bits/stdc++.h>

using namespace std;

string solve() {
	
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}
	for(int i=n-2; i>=0; i--) {
		int k = v[i];
		int index = upper_bound(v.rbegin(), v.rbegin()+n-i-1, k) - v.rbegin();	
		index = (n-1) - index;
		if(index != i) {
			int k = v[i];
			v[i] = v[index];
			v[index] = k;
			sort(v.begin()+i+1, v.end());
			string s = "";
			for(auto i: v){
				s += to_string(i);
			}
			return s;		
		}
	}
	return "-1";
}

int main() {
	
	int t;
	cin >> t;
	vector<string> s;
	while(t--){
		s.push_back(solve());
	}
	for(auto v: s) {
		
		cout << v << endl;
	}
}
