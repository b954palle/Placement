// #include<iostream>
#include<bits/stdc++.h>
// #include <algorithm> 

using namespace std;


int main() {
    int a[] = {2, 5, 6, 10, 19, 34, 48, 60};
    if(binary_search(a, a+8, 40)) {
        cout << "Number is present in the array\n";
    }
    else {
        cout << "Number is not present in the array\n";
    }

    vector<int> v = {2, 5, 6, 10, 19, 34, 40, 60};
    if(binary_search(v.begin(), v.end(), 40)) {
        cout << "Number is present in the array\n";
    }
    else {
        cout << "Number is not present in the array\n";
    }
    auto it = lower_bound(v.begin(), v.end(), 40);
    auto it2 = lower_bound(a, a+8, 40);
    cout << "Lower Bound in vector is " << (*it) << endl;
    cout << "Lower Bound in array is " << (*it2) << endl;

    it = upper_bound(v.begin(), v.end(), 40);
    it2 = upper_bound(a, a+8, 40);
    cout << "Upper Bound in array is " << (*it) << endl;
    cout << "Upper Bound in array is " << (*it2) << endl;

    vector<int> v2 = {3, 2, 99, 10, 5, 6};
    sort(v2.begin(), v2.end());
    for(int i=0; i<6; i++) {
        cout << v2[i] << " ";
    }
    cout << endl;
    return 0;  
}