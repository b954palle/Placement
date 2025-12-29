#include<bits/stdc++.h>

using namespace std;
vector<int> intital;
vector<vector<int>> dp;
long helper(int index, int pos) {
    if(index == intital.size()) return 0;
    if(pos == intital.size() && intital[index] == 1) return INT_MAX;
    if(pos == intital.size()) return helper(index+1, pos);
    if(intital[index] == 0) return helper(index+1, pos);
    if(dp[index][pos] != -1) return dp[index][pos];
    long ans = INT_MAX;
    for(int i=pos; i< intital.size(); i++) {
        if(intital[i] == 0) {
            long k = helper(index+1, i+1);
            if(k != INT_MAX) ans = min(ans, (long) abs(i-index)+ k);
        }
    }
    dp[index][pos] = ans;
    return dp[index][pos];
}
int main() {
    int n;
    cin >> n;
    intital.resize(n);
    dp.resize(n, vector<int>(n, -1));
    for(int i=0; i<n; i++) {
        cin >> intital[i];
    }

    int index = 0;
    int pos = 0;
    cout << helper(index, pos) << endl;

}