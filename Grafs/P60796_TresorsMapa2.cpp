//
//  P60796_TresorsMapa2.cpp
//  programes
//
//  Created by Júlia Gasull Navarro on 8/5/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool ok(int x, int y, const vector< vector<char> > &M)
{	//retorna si una posico es possible
	return (x >= 0 and x < int(M.size()) and y >= 0 and y < int(M[0].size()) and M[x][y] != 'X');
}

int min_dis(int Ox, int Oy, vector< vector<char> > &M)
{
	//mides
	int files = int(M.size());
	int columnes = int(M[0].size());
	
	// cua de parells
	queue< pair<int, int> > Q;
	
	//matriu nxm plena de -1
	vector< vector<int> > dist(files, vector<int> (columnes, -1));
	
	//distancia inicial
	Q.push({Ox,Oy});
	dist[Ox][Oy] = 0;
	
	while (Q.size() > 0)
	{
		pair<int, int> punt = Q.front();
		int x = punt.first;
		int y = punt.second;
		Q.pop();
		
		// Cas base -> tresor
		if(M[x][y] == 't') return dist[x][y];
		M[x][y] = 'X';		//visitat
		
		// Cas inductiu -> punt
		if (ok(x+1, y, M))
		{
			Q.push({x+1, y});
			dist[x+1][y] = dist[x][y] + 1;
		}
		if (ok(x, y+1, M))
		{
			Q.push({x, y+1});
			dist[x][y+1] = dist[x][y] + 1;
		}
		if (ok(x, y-1, M))
		{
			Q.push({x, y-1});
			dist[x][y-1] = dist[x][y] + 1;
		}
		if (ok(x-1, y, M))
		{
			Q.push({x-1, y});
			dist[x-1][y] = dist[x][y] + 1;
		}
	}
	return -1;
}

int main()
{
	//llegir mides i crear matriu nxm
	int n, m;
	cin >> n >> m;
	vector< vector<char> > M(n, vector<char>(m));
	
	//llegir matriu
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) cin >> M[i][j];
	}

	//posició inicial
	int Ox, Oy;
	cin >> Ox >> Oy;
	
	//calcular distancia minima a un tresor
	int dist = min_dis(Ox-1, Oy-1, M);
	
	//conclusions
	if(dist == -1) cout << "no es pot arribar a cap tresor" << std::endl;
	else cout << "distancia minima: " << dist << std::endl;
}
