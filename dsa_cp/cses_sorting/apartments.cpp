#include<bits/stdc++.h>

using namespace std;

int main() {
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<int> applications(n);
	for(int i=0; i<n; i++) {
		cin >> applications[i];
	}
	
	vector<int> apartments(m);
	for(int i=0; i<m; i++) {
		cin >> apartments[i];
	}
	
	sort(applications.begin(), applications.end());
	sort(apartments.begin(), apartments.end());
	
	int i=0, j=0;
	int ans = 0;
	while(i < n && j < m ) {
		
		if(abs(applications[i] - apartments[j]) <= k) {
			ans++;
			j++;
			i++;
		}
		else {
			if(applications[i] - apartments[j] > k) {
				j++;
			}
			else {
				i++;
			}
		}
	}
	
	cout << ans << endl;
}
