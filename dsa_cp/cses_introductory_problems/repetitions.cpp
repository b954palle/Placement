#include<bits/stdc++.h>

using namespace std;

int main() {
	
	string s;
	cin >> s;
	char prev = 'X';
	int ans = 0;
	int curr = 0;
	for(int i=0; i<s.size(); i++) {
		if(prev == s[i]) {
			curr++;
		}
		else {
			ans = max(ans, curr);
			prev = s[i];
			curr = 1;
		}
	}
	ans = max(ans, curr);
	cout << ans << endl;
}
