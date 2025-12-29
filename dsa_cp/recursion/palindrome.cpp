#include<bits/stdc++.h>

using namespace std;


bool f(int i, string &s, int &n) {

	if(i >= n/2) return true;
	
	if(s[i] != s[n-1-i]) return false;
	
	
	return f(i+1, s, n);
}

int main() {
	
	int n;
	cin >> n;
	
	string s;
	cin >> s;

	cout << f(0, s, n) << endl;
}
