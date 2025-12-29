#include<bits/stdc++.h>

using namespace std;


const int N = 200010;

int arr[N];
int tree[4*N];


void build(int index, int l, int r) {

	if(l == r) {
		tree[index] = arr[l];
		return;
	}
	int mid = (l+r)/2;
	
	build(2*index, l, mid);
	build(2*index+1, mid+1, r);
	
	tree[index] = min(tree[2*index], tree[2*index+1]);
	
	return;
}

int query(int index, int l, int r, int lq, int rq) {
	
	if(l > rq || r < lq) return INT_MAX;
	
	if(l >= lq && r <= rq) return tree[index];
	
	int mid = (l+r)/2;
	
	return min(query(2*index, l, mid, lq, rq), query(2*index+1, mid+1, r, lq, rq));
}

int main() {

	int n, q;
	cin >> n >> q;
	
	for(int i=0; i<n; i++) cin >> arr[i];
	
	build(1, 0, n-1);
	
	while(q--) {
	
		int a, b;
		cin >> a >> b;
		a--; b--;
		cout << query(1, 0, n-1, a, b) <<endl;
	}
}
