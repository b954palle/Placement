#include<bits/stdc++.h>


using namespace std;


int partition(vector<int>&arr, int low, int high) 
{
	int pivot = arr[low];
	
	int i = low;
	int j = high;
	
	while(i < j) {
		
		while(i<= high && arr[i] <= pivot) i++;
		
		while(j>=low && arr[j] > pivot) j--;
		
		if(i<j) swap(arr[i], arr[j]);
	}
	swap(arr[low], arr[j]);
	
	return j;
}

void quicksort(vector<int>&arr, int low, int high) 
{
	
	if(low >= high) return;
	
	int pindex = partition(arr, low, high);
	
	quicksort(arr, low, pindex-1);
	quicksort(arr, pindex+1, high);
	
}

int main() {
	
	vector<int> arr = {1, 4, 2, 1, 3};
	
	quicksort(arr, 0, 4);
	
	for(int i=0; i<5; i++) cout << arr[i] << " ";
	
	cout << endl;
}
