#include<bits/stdc++.h>

using namespace std;


vector<int> prefix_function(string s) {
	
	int n = s.size();
	vector<int> pi(n);
	pi[0] = 0;
	for(int i=1; i<n; i++) {
		int j = pi[i-1];
		while(j>0 && s[i] != s[j]) 
			j = pi[j-1];
		if(s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

int kmp(string text, string pattern) {
	
	string total = pattern + '#' + text;
	
	int m = text.size();
	int n = pattern.size();
	
	vector<int> pi = prefix_function(total);
	
	int ans = 0;
	for(int i=n+1; i<m+n+1; i++) {
		
		if(pi[i] == n) {
			ans++;
		}
	}
	
	return ans;
	
	
}

int main() {
	

	string text;
	string pattern;
	cin >> text >> pattern;
	cout << kmp(text, pattern) << endl;

}
