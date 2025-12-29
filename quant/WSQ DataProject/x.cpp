#include<iostream>

using namespace std;


int calculate(int x) {
	
	int first = 0;
	int second = 1;
	
	if(x == first || x == second) return 0;
	
	int mini = 1e6;
	
	while(true) {
		
		int curr = first + second;
		
		int diff = abs(curr - x);
		
		if(mini < diff) break;
		else mini = diff;
		
		second = first;
		first = curr;
	}
	
	return mini;
}
int main() {
	
	cout << calculate(13) << endl;
}
