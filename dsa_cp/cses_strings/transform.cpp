#include<bits/stdc++.h>

using namespace std;


void solve(string s) {
	
	stack<string> st;
	
	string ans;
	for(int i=0; i<s.size(); i++) {
		string curr = "";
		curr += s[i];
		if(curr == ")") {
			string s1 = st.top(); st.pop();
			string s2 = st.top(); st.pop();
			string s3 = st.top(); st.pop();
			string total = s3 + s1 + s2;
			st.pop();
			st.push(total);
		}
		else {
			st.push(curr);
		}
	}
	cout << st.top() << endl;
}
int main() {
	
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		solve(s);
	}
}
