#include<bits/stdc++.h>

using namespace std;








void helper(int index, int wordindex, int word, bool used, string &acm, vector<string> &words, int &ans) {

	if(index ==  acm.size() && word == words.size()) ans++;
	
	if(index == acm.size()  && word == words.size()-1 && used) ans++;
	
	if(index == acm.size() || word == words.size()) return;
	

	
	if(wordindex == words[word].size() ) {
		
		if(!used) return;
		
		helper(index, 0, word+1, false, acm, words, ans);
		return;
	}
	
	

	
	if(acm[index] == words[word][wordindex]){
		helper(index+1, wordindex+1, word, true, acm, words, ans);
		
	}
	
	helper(index, wordindex+1, word, used, acm, words, ans);
	
	
	 
}
void calculate(string acm, string phrase, unordered_set<string> &insignificant) {
	
	stringstream ss(phrase);
	

	vector<string> words;
	
	string tokens;
	
	
	while(ss >> tokens) {
		
		if(insignificant.find(tokens) == insignificant.end()) words.push_back(tokens);
	}
	
	
	string actual = acm;
	transform(acm.begin(), acm.end(), acm.begin(), ::tolower); 
	
	
	int ans = 0;
	helper(0, 0, 0, false, acm, words, ans);
	
	if(ans > 0) cout << actual << " can be formed in "  << ans << " ways" <<  endl;
	else cout << actual << " is not a valid abbreviation" << endl;
	

}


void calculate(string acm, string phrase, unordered_set<string> &insignificant) {
	
	stringstream ss(phrase);
	

	vector<string> words;
	
	string tokens;
	
	
	while(ss >> tokens) {
		
		if(insignificant.find(tokens) == insignificant.end()) words.push_back(tokens);
	}
	
	
	string actual = acm;
	transform(acm.begin(), acm.end(), acm.begin(), ::tolower); 
	
	
	vector<vector<int>> dp(151, vector<int>(151, 0));
	
	dp[0][0]=1;
	for(int i=1; i<=words.size(); i++) {
		
		for(int j=1; j<=acm.size(); j++) {
		
			int size = words[i].size();
			
			for(int k = 0; k<size; k++) {
				
				if(words[i][k]  == acm[j-1]) {
					dp[i][j] += dp[i-1][j-1];
				}
			}
		}
	}
	
	if(ans > 0) cout << actual << " can be formed in "  << ans << " ways" <<  endl;
	else cout << actual << " is not a valid abbreviation" << endl;
	

}


int main() {
	

	
	while(true) {
		
		int n;
		cin >>n;
		if(n ==0)break;
		unordered_set<string> insignificant;
		
		for(int i=0; i<n; i++) {
			string s;
			cin >> s;
			insignificant.insert(s);
		}
		

		while(true) {
		
			string s;
			cin >> s;
		
			string phrase;
			cin.ignore(1); // ignoring the space. 
			getline(cin, phrase);
			
			if(phrase == "CASE") break;
			else calculate(s, phrase, insignificant);
		}
		
	}
}
