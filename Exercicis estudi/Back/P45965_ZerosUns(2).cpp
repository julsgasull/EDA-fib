//
//  P45965_ZerosUns(2).cpp
//  programes
//
//  Created by Júlia Gasull Navarro on 27/5/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int k;

void write(const vector<int> &A)
{
	cout << A[0];
	for (int i = 1; i < int(A.size()); i++) cout << " " << A[i];
	cout << endl;
}

void write_combinations(vector<int> &A, int i, int z, int u)
{
	if (u > k or z > int(A.size()) - k) return;
	if (i == A.size()) write(A);
	else
	{
		A[i] = 0;
		write_combinations(A, i+1, z+1, u);
		
		A[i] = 1;
		write_combinations(A, i+1, z, u+1);
	}
}



int main()
{
	int n;
	cin >> n >> k;
	vector<int> A(n);
	write_combinations(A, 0, 0, 0);
}

