#include<bits/stdc++.h>

using namespace std;

struct Node {
	
	bool end;
	vector<Node*> next;
	Node() : end(false), next(26, nullptr) {}
};

class Trie{
	
	public:
	
	Node* root;
	
	Trie() {
		root = new Node();
	}
	
	void insertWord(string s) {
		
		Node* curr = root;
		int n = s.size();
		for(int i=0; i<n; i++) {
			if(curr->next[s[i]-'a'] == nullptr) {
				curr->next[s[i]-'a'] = new Node();
			}
			curr = curr->next[s[i]-'a'];
		}
		curr->end = true;
	}
	
	vector<int> possPos(string s, int idx) {
		int n = s.size();
		Node* curr = root;
		vector<int> result;
		for(int i=idx; i<n; i++) {
			if(curr->next[s[i]-'a'] == nullptr) {
				return result;
			}
			if(curr->next[s[i]-'a']->end) result.push_back(i);
			
			curr = curr->next[s[i]-'a'];
		}
		return result;
	}
};

int main() {
	
	string word;
	cin >> word;
	int k;
	cin >> k;
	Trie trie;
	while(k--) {
		string dictstr;
		cin >> dictstr;
		trie.insertWord(dictstr);
	}
	int mod = 1e9+7;
	
	int n = word.size();
	vector<int> dp(n, 0);
	
	for(int i=n-1; i>=0; i--) {

		int count = 0;
		vector<int> result = trie.possPos(word, i);
		for(auto j: result) {
			if(j <n-1) {
				count = (1LL*count+dp[j+1])%mod;
			}
			else count++;
		}
		dp[i] = count;
	}
	cout << dp[0] << endl;
}
