#include<bits/stdc++.h>

using namespace std;

typedef long long ll;



void calculate() {
	
	int x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	
	ll value1 = 1LL*(x2-x1)*y3 - 1LL*(y2-y1)*x3 - (1LL*x2*y1 - 1LL*x1*y2);
	
	ll value2 = 1LL*(x2-x1)*y4 - 1LL*(y2-y1)*x4 - (1LL*x2*y1 - 1LL*x1*y2);
	
	if(value1 * value2 <= 0)  cout << "YES" << endl;
	else cout << "NO" << endl;
	
	
}
int main() {
	
	int t;
	cin >> t;
	while(t--) {
		
		calculate();
	}
}
