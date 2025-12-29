#include<bits/stdc++.h>

using namespace std;


const int N = 200010;

long long arr[N];
long long tree[4*N];


void build(int index, int l, int r){
	

	if(l == r){
		tree[index] = arr[l];
		return;
	}
	int mid = (l+r)/2;
	build(2*index, l, mid);
	build(2*index+1, mid+1, r);
	
	tree[index] = tree[2*index] + tree[2*index+1];
	return;
}

void update(int index, int l, int r, int lq, int rq, int u){
	
	
	
	if(rq < l || r < lq) return;
	
	if(l == r) {
		tree[index] += u;	
		arr[l] = tree[index];
		return;
	}
	
	int mid = (l+r)/2;
	
	update(2*index, l, mid, lq, rq, u);
	update(2*index+1, mid+1, r, lq, rq, u);
	tree[index] = tree[2*index] + tree[2*index+1];
}

int main() {
	
	int n, q;
	cin >> n>>q;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	build(1, 0, n-1);
	while(q--){
		
		int type;
		cin >> type;
		if(type == 1){
			int a, b, u;
			cin >> a >> b >> u;
			update(1, 0, n-1, a-1, b-1, u);
		}
		else{
			int k;
			cin >> k;
			cout << arr[k-1] << endl;
		}
	}
	
}
