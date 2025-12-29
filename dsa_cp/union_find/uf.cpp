#include<iostream>
#include<vector>

using namespace std;

// is basically used when edges are given and number of components to be found. 
class UF {
	
	public:
		
		vector<int> parent;
		vector<int> rank;
		UF(int v) {
			parent.resize(v+1, -1);
			rank.resize(v+1, -1);
		}
		
		void make_set(int v) {
			
			parent[v] = v;
			rank[v] = 1; 
		}
		
		int find_set(int v) {
			
			if(v == parent[v]) return v;
			
			return parent[v] = find_set(parent[v]); // Path Compression Optimization
		}
		
		void union_sets(int a, int b) {
			
			a = find_set(a);
			b = find_set(b);
			if(a != b){
			   // Union by size/rank. 
			   if(rank[a] < rank[b]) { // size optimization 
			   	swap(a, b);
			   }
			   parent[b] = a;
			   rank[a] += rank[b];
			}
		}

};

int main() {
}
