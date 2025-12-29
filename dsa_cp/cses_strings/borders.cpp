#include<bits/stdc++.h>

using namespace std;


vector<int> prefixfunction(string s) {

	int n = s.size();
	vector<int> pi(n);
	pi[0] = 0;
	for(int i=1; i<n; i++) {
		int j = pi[i-1];

		while(j>0 && (s[i] != s[j])) j = pi[j-1];
		if(s[i] == s[j]) j++;
		pi[i] = j;
	}

	return pi;
}


void kmp(string s) {

	vector<int> pi = prefixfunction(s);
	vector<int> ans;
	int j = pi[s.size()-1];

	while(j>0) {
		ans.push_back(j);
		j = pi[j-1];
	}
	reverse(ans.begin(), ans.end());
	for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
	cout << endl;
}
int main() {
	
	string s;
	cin >> s;
	kmp(s);	
}
