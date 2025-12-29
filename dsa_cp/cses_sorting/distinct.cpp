#include<bits/stdc++.h>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	vector<int> st(n);
	
	for(int i=0; i<n; i++) {
		cin >> st[i];
	}
	
	sort(st.begin(), st.end());
	
	int count = 1;
	int prev = st[0];
	
	for(int i=1; i<n; i++) {
		if(prev == st[i]) continue;
		prev = st[i];
		count++;
	}
	cout << count << endl;
	
}
