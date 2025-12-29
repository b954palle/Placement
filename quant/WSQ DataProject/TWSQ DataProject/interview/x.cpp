#include<bits/stdc++.h>

using namespace std;



void test(vector<int> &score) {
	
	int n = score.size();
	while(true) {
	
		vector<int> change(n, 0);
		for(int i=1; i<n-1; i++) {
			if(score[i] > score[i-1] && score[i] > score[i+1]) change[i]--;
			else if(score[i] < score[i-1] && score[i] < score[i+1]) change[i]++;
		}
		
		bool updated = false;
		
		for(int i=1; i<n-1; i++) {
			
			score[i] += change[i];
			if(change[i] != 0) updated = true;
			
		}
		
		if(!updated) break;
		
	}
	
}
int main() {

	vector<int> A = {100, 50, 40, 30};
	test(A);
	
	for(auto v: A) cout << v << endl;
}
