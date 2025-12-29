#include<bits/stdc++.h>

using namespace std;


int MaxElem(vector<int>& A) {
	
	int k = A[0];
	
	if(k >= 5000) return 0;
	
	sort(A.begin()+1, A.end());
	
	k = 5000-k;
	
	int ans = 0;
	
	for(int i=1; i<A.size(); i++) {
		
		if(k - A[i] >=0) { ans++; k -= A[i];}
		else break;
	}
	
	return ans;
}
int main() {
	
	vector<int> A = {4950, 150, 150, 150};
	
	cout << MaxElem(A) << endl;
}
