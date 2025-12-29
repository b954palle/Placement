#include<bits/stdc++.h>


using namespace std;



void merge(vector<int> &arr, int left, int mid, int right) 
{
	
	int p1 = left;
	int p2 = mid+1;
	
	vector<int> temp;
	while(p1 <= mid && p2<=right) {
		if(arr[p1] > arr[p2]) {
			temp.push_back(arr[p2]);
			p2++;
		}
		else {
			temp.push_back(arr[p1]);
			p1++;
		}
	}
	
	while(p1 <=mid) temp.push_back(arr[p1++]);
	
	while(p2 <= right) temp.push_back(arr[p2++]);
	
	for(int i=left; i<=right; i++) arr[i] = temp[i-left];
}


void mergesort(vector<int>&arr, int left, int right) 
{
	
	if(left >= right) return;
	
	int mid = (left+right)/2;
	
	mergesort(arr, left, mid);
	mergesort(arr, mid+1, right);
	merge(arr, left, mid, right);
}

int main() {
	
	vector<int> arr = {1, 2, 4, 3, 1};
	
	mergesort(arr, 0, 4);
	
	for(int i=0; i<5; i++) cout << arr[i] << " ";
	
	cout << endl;
	
}
