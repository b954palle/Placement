#include<bits/stdc++.h>

using namespace std;

int solve(string s, vector<char>&chars, vector<string>& ans) {
	if(chars.size() == 0) {
		ans.push_back(s);
		return 1;
	}
	
	int count = 0;
	for(int j=0; j<chars.size(); j++) {
		if(j != 0 && chars[j] == chars[j-1]) {
			continue;
		}
		char c = chars[j];
		string s1 = s + c;
		chars.erase(chars.begin()+j);
		count += (solve(s1, chars, ans));
		chars.insert(chars.begin()+j, c);
	}
	
	return count;
}

int main() {
	
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	vector<char> chars;
	for(int i=0; i<s.size(); i++) {
		chars.push_back(s[i]);
	}
	
	vector<string> ans;
	cout << solve("", chars, ans) << endl;
	
	for(auto a: ans) cout << a << endl;
}
