#include<bits/stdc++.h>

using namespace std;


vector<unordered_map<string, int>> mp;

int calculate(vector<pair<int, int>> &foodPackets, pair<int, int> source, int sourceindex, pair<int, int> destination, string s, int curr){
	
	
	if(curr == foodPackets.size()) {

		return abs(source.first - destination.first) + abs(source.second - destination.second);
	}

	if(mp[sourceindex].find(s) != mp[sourceindex].end()) return mp[sourceindex][s];
	
	int ans = INT_MAX;
	
	int n = foodPackets.size();
	for(int i=0; i<n; i++) {
	
		if(s[i] == '0') {
			s[i] = '1';
			ans = min(ans, abs(source.first - foodPackets[i].first) + abs(source.second - foodPackets[i].second) + calculate(foodPackets, foodPackets[i], i+1, destination, s, curr+1));
			s[i] = '0';
		}
	}
	
	
	
	return mp[sourceindex][s] = ans;
	

}

int main() {
	
	vector<vector<int>> matrix(4, vector<int>(4));
	
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			int k;
			cin >> k;
			matrix[i][j] = k;
			cout<< "here" << endl;
		}
		cout << "out "<< i << endl;
	}
	
	pair<int, int> source;
	pair<int, int> destination;
	vector<pair<int, int>> foodPackets;
	
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			if(matrix[i][j] == 1) {
				source = make_pair(i, j);
			}
			else if(matrix[i][j] == 3) {
				destination = make_pair(i, j);
			}
			else if(matrix[i][j] == 2) {
				foodPackets.push_back({i, j});
			}
		}
	}
	
	unordered_set<int> s1;
	
	string s = "";
	for(int i=0; i<foodPackets.size(); i++) {
		s += "0";
	}
	
	int currsize = foodPackets.size();
	
	mp.resize(currsize+1);
	
	cout << calculate(foodPackets, source, 0, destination, s, 0) << endl;
	
	
}
