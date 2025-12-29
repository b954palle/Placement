#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> weights(n);
    for(int i=0; i<n; i++) {
        cin >> weights[i].first;
        cin >> weights[i].second;
    }
    vector<long> dp(100001,INT_MAX);
    dp[weights[n-1].second] = weights[n-1].first;
    dp[0] = 0;
    for(int i=n-2; i>=0; i--) {
        for(int j=100000; j>=weights[i].second; j--) {
            dp[j] = min( dp[j], weights[i].first + dp[j-weights[i].second]);
        }
    }
    for(int j=100000; j>=0; j--) {
        if(dp[j] <= w && dp[j] != INT_MAX) {
            cout << j << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}