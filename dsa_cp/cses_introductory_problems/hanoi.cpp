#include<bits/stdc++.h>

using namespace std;




int solve(int n, int start, int end, int middle, vector<pair<int, int>> &moves) {

	if(n <= 0) return n;
	
	int s1 = solve(n-1, start, middle, end, moves);
	
	moves.push_back({start, end});

	int s2 = solve(n-1, middle, end, start, moves);
	
	return s1+s2+1;
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> moves;
	cout << solve(n, 1, 3, 2, moves) << endl;
	
	for(auto p: moves) {
		cout << p.first << " " << p.second << endl;
	}
}
