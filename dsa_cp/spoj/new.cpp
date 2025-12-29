#include<bits/stdc++.h>

using namespace std;

void solve() {

	int n;
	cin >> n;
	string s = "";
	int evencount = 0;
	cin >> s;
	for(int i=0; i<n; i++) {
		if(s[i] == '0') evencount++;
	}
	int misplaced = 0;
	for(int i=0; i<evencount; i++) {
		if(s[i] == '1' ) misplaced++;
	}
	cout << misplaced << endl;
}
int main() {
	int t;
	cin >> t;
	for(int i=0; i<t; i++) {
		
		solve();
	}
}
