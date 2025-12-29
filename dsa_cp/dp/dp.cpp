#include <bits/stdc++.h>

using namespace std;

vector<int> a;
vector<vector<int>> dp;
int helper(int i, int prev_day) {
    if(i == a.size()) return 0;
    if(dp[i][prev_day] != -1) return dp[i][prev_day];
    if(a[i] == 0) {
        dp[i][prev_day] = 1 + helper(i+1, 0);
    }
    else if(a[i] == 1) {
        if(prev_day == 1)   dp[i][prev_day]  = 1 + helper(i+1, 0);
        else  dp[i][prev_day] =  helper(i+1, 1);
    }
    else if(a[i]==2) {
        if(prev_day == 2)  dp[i][prev_day]  = 1+helper(i+1, 0);
        else  dp[i][prev_day]  =  helper(i+1, 2);
    }
    else {
        if(prev_day == 1)  dp[i][prev_day]  =  helper(i+1, 2);
        else if(prev_day == 2)  dp[i][prev_day]  =  helper(i+1, 1);
        else  dp[i][prev_day]  = min(helper(i+1, 2), helper(i+1, 1));
    }
    return  dp[i][prev_day] ;
}
int main() {
    int n;
    cin >> n;
    a.resize(n);
    dp.resize(n, vector<int>(3,-1));
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << helper(0, 0) << endl;
}