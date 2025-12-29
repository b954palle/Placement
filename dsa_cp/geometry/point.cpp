#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
	


	int t;
	cin >> t;
	
	while(t--){
		int x1, y1, x2, y2, x3, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		
		ll value = 1LL*(x2-x1)*y3 - 1LL*(y2-y1)*x3 - (1LL*x2*y1 - 1LL*x1*y2);
		
		if(value == 0) cout << "TOUCH" << endl;
		else if(value < 0) cout << "RIGHT" << endl;
		else cout << "LEFT" << endl;
	}
	
}
