#include<bits/stdc++.h>

using namespace std;

int main() {
	
	string s;
	cin >> s;
	vector<int> freq(26, 0);
	for(auto c: s) {
		freq[c-'A']++;
	}
	int count = 0;
	char left = 'X';
	for(int i=0; i<26; i++) {
		if(freq[i]%2 != 0) {
			count++;
			left = 'A' + i;
		}
	}
	if(count > 1) {
		cout << "NO SOLUTION" << endl;
		return 0;
	}
	
	
	string ans="";
	for(int i=0; i<26; i++) {	
		int freqc = freq[i]/2;
		for(int j=0; j<freqc; j++) ans += ('A'+i);
	}
	string leftpart = ans;
	reverse(ans.begin(), ans.end());
	
	string total = leftpart;
	if(left != 'X') total += left;
	total += ans;
	cout << total << endl; 
	
}
