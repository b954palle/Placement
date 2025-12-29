// Write your code here
// You can set your Template at profile settings [https://maang.in/profile/template-code]


#include<bits/stdc++.h>

using namespace std;

vector<int> arr;
vector<long long>tree;

void build(int index, int l, int r) {
    if(l == r) {
        tree[index] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*index+1, l, mid);
    build(2*index+2, mid+1, r);
    tree[index] = tree[2*index+1]+tree[2*index+2];
    return;
}

void update(int index, int l, int r, int pos, int val) {
    if(r < pos || l > pos) return;
    if(l == r) {
        tree[index] = val;
        arr[pos] = val;
        return;
    }
    int mid = (l+r)/2;
    update(2*index+1, l, mid, pos, val);
    update(2*index+2, mid+1, r, pos, val);
    tree[index] = tree[2*index+1] + tree[2*index+2];
    return;
}


long long query(int index, int l, int r, int lq, int rq) {
    if(r < lq || l > rq) return 0;

    if(lq <= l && r<=rq) return tree[index];

    int mid = (l+r)/2;
    return query(2*index+1, l, mid, lq, rq) + query(2*index+2, mid+1, r, lq, rq);
}

int main() {
    int n, q;
    cin >> n >> q;
    arr.resize(n, 0);
    tree.resize(4*n, 0);
    for(int i=0; i<n; i++) cin >> arr[i];

    build(0, 0, n-1);
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int i, x;
            cin >> i >> x;
            update(0, 0, n-1, i-1, x);
        }
        else {
            int i, j;
            cin >> i >> j;
            cout << query(0, 0, n-1, i-1, j-1)<<endl;
        }
    }
}
