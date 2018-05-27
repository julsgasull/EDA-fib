//	Depth-First Search
//  P90766_TresorsMapa(3).cpp
//  programes
//
//  Created by Júlia Gasull Navarro on 26/5/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;


bool pos_ok(int i, int j, const vector<vector<char>> &M)
{
	return (i >= 0 and j >= 0 and i < int(M.size()) and j < int(M[0].size()) and M[i][j] != 'X');
}

int how_many_treasures(int src_i, int src_j, vector<vector<char>> &M)
{
	if (not pos_ok(src_i, src_j, M)) return 0;
	int treasures = 0;
	if (M[src_i][src_j] == 't') ++treasures;
	M[src_i][src_j] = 'X';
	
	return (treasures +
			how_many_treasures(src_i+1, src_j  , M) +
			how_many_treasures(src_i-1, src_j  , M) +
			how_many_treasures(src_i  , src_j+1, M) +
			how_many_treasures(src_i  , src_j-1, M)
		   );
}

void read_matrix(int rows, int cols, vector<vector<char>> &M)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) cin >> M[i][j];
}

int main()
{
	int rows, cols; cin >> rows >> cols;
	vector< vector<char> > M(rows, vector<char>(cols));
	read_matrix(rows, cols, M);
	int i, j; cin >> i >> j;
	cout << how_many_treasures(i-1, j-1, M) << endl;
	
}
