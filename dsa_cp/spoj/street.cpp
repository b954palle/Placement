#include<bits/stdc++.h>

using namespace std;

int main() {
	
	bool end = false;
	
	while(!end) {
		
		int n;
		cin >> n;
		if(n == 0){
			end = true;
			return false;
		}
		vector<int> v(n);
		for(int i=0; i<n; i++) {
			cin >> v[i];
		}
		vector<int> v2 = v;
		sort(v2.begin(), v2.end());
		stack<int> s;
		int j = 0;
		for(int i=0; i<n; i++) {
			if(v[i] == v2[j]) {
				j++;
			}
			else {
				if(!s.empty() && s.top() == v2[j]){
					i--;
					j++;
					s.pop();
				}
				else {
					s.push(v[i]);
				}
			}
		}
		while(!s.empty()) {
			if(s.top() != v2[j]) break;
			s.pop(); j++;
		}

		if(s.empty()) cout << "yes" << endl;
		else cout << "no" << endl;
		
	}	

}
