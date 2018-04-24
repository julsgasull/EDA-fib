//
//  P90766_TresorsMapa3.cpp
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

int count_treasures(vector<vector<char>> &M, int f, int c)
{
    if (f < 0 or c < 0 or f >= M.size() or c >= M[0].size()) return 0;  //wrong position
    if (M[f][c] == 'X') return 0;
    
    int cont = 0;
    if (M[f][c] == 't') ++cont;
    
    M[f][c] = 'X'; //mark cell visited
    return (cont + count_treasures(M, f+1, c) + count_treasures(M, f-1, c) + count_treasures(M, f, c+1) + count_treasures(M, f, c-1));
}

int main()
{
    int f, c; cin >> f >> c;
    vector<vector<char>> M(f, vector<char>(c));
    readM(f, c, M);
    
    int f0, c0; cin >> f0 >> c0;
    cout << count_treasures(M, f0-1, c0-1) << endl;
}
