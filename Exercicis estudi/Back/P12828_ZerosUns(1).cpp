//
//  P12828_ZerosUns(1).cpp
//  programes
//
//  Created by Júlia Gasull Navarro on 27/5/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


void write(const vector<int> &A)
{
	cout << A[0];
	for (int i = 1; i < int(A.size()); i++) cout << " " << A[i];
	cout << endl;
}

void write_combinations(vector<int> &A, int i, int z, int u)
{
	if (z + u == int(A.size())) write(A);
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
	cin >> n;
	vector<int> A(n);
	write_combinations(A, 0, 0, 0);
}
