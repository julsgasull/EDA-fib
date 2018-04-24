//
//  P70690_TresorsMapa.cpp
//  EDA
//
//  Created by Júlia Gasull Navarro on 24/4/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//


/*------------------------------*/
/*----- Depth-First Search -----*/
/*------------------------------*/


/*HORITZONTALS O VERTICALS (NO diagonals)*/

#include <iostream>
#include <vector>
using namespace std;

void readM(int f, int c, vector<vector<char>> &M)
{
    for (int i = 0; i < f; i++) for (int j = 0; j < c; j++) cin >> M[i][j];
}

bool reachable(vector<vector<char>> &M, int f, int c)
{
    if (f < 0 or c < 0 or f >= M.size() or c >= M[0].size()) return false;  //wrong position
    if (M[f][c] == 'X') return false;
    if (M[f][c] == 't') return true;
    
    M[f][c] = 'X'; //mark cell visited
    return (reachable(M, f+1, c) or reachable(M, f-1, c) or reachable(M, f, c+1) or reachable(M, f, c-1));
}

int main()
{
    int f, c; cin >> f >> c;
    vector<vector<char>> M(f, vector<char>(c));
    readM(f, c, M);
    
    int f0, c0; cin >> f0 >> c0;
    
    if (reachable(M, f0-1, c0-1)) cout << "yes" << endl;
    else cout << "no" << endl;
}
