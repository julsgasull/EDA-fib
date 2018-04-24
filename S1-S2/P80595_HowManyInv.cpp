//
//  P80595_HowManyInv.cpp
//  EDA
//
//  Created by Júlia Gasull Navarro on 2/4/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& v, int left, int mid, int right)
{ //Return inversions and merged vector v[l..r] = v[l..m] ~ v[m+1..r]
    vector<int> z(right - left + 1);
    int i = left;
    int j = mid + 1;
    int k = 0;
    int count = 0;
    while (i <= mid and j <= right) {
        if (v[i] <= v[j]) z[k++] = v[i++];
        else {
            z[k++] = v[j++];
            count += (mid + 1 - i);
        }
    }
    while (i <= mid) z[k++] = v[i++];
    while (j <= right) z[k++] = v[j++];
    for (k = 0; k < z.size(); ++k) v[left+k] = z[k];
    return count;
}

int mergesort_inv(vector<int>& v, int left, int right)
//Return number of inversions of v[l..r]
//Total ammount of inversions will be inversions of left vector + right vector (recursivity) + merge process inversions
{
    int count = 0;
    if (left < right) {
        int mid = (left+right) / 2;
        count = mergesort_inv(v, left, mid) + mergesort_inv(v, mid+1, right) + merge(v, left, mid, right);
    }
    return count;
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> v(n); for (int i = 0; i < n; ++i) cin >> v[i];    //llegir vector
        cout << mergesort_inv(v, 0, int(v.size()-1)) << endl;   //num_inv
    }
}
