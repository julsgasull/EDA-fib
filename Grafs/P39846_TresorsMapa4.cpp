//
//  P39846_TresorsMapa4.cpp
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
{
	return (x >= 0 and x < int(M.size()) and y >= 0 and y < int(M[0].size()) and M[x][y] != 'X');
}

int min_dis(int Ox, int Oy, vector< vector<char> > &M)
{
	//dist max
	int max_dist = -1;
	
	//mides matriu
	int files = int(M.size());
	int columnes = int(M[0].size());
	
	//cua de posicions
	queue< pair<int, int> > Q;
	
	//matriu plena amb -1
	vector< vector<int> > dist(files, vector<int> (columnes, -1));
	
	//puby inicial
	Q.push({Ox,Oy});
	dist[Ox][Oy] = 0;
	
	while (not Q.empty())
	{
		//punt actual
		pair<int, int> punt = Q.front();
		int x = punt.first;
		int y = punt.second;
		Q.pop();
		
		//actualitzar dist max
		if (M[x][y] == 't' and dist[x][y] > max_dist) max_dist = dist[x][y];
		
		
		//cas inductiu
		if(ok(x+1, y, M) and dist[x+1][y] == -1)
		{
			Q.push({x+1, y});
			dist[x+1][y] = dist[x][y] + 1;
		}
		if(ok(x, y+1, M) and dist[x][y+1] == -1)
		{
			Q.push({x, y+1});
			dist[x][y+1] = dist[x][y] + 1;
		}
		if(ok(x, y-1, M) and dist[x][y-1] == -1)
		{
			Q.push({x, y-1});
			dist[x][y-1] = dist[x][y] + 1;
		}
		if(ok(x-1, y, M) and dist[x-1][y] == -1)
		{
			Q.push({x-1, y});
			dist[x-1][y] = dist[x][y] + 1;
		}
		
	}
	return max_dist;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector< vector<char> > M(n, vector<char>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> M[i][j];
		}
	}
	int Ox, Oy;
	cin >> Ox >> Oy;
	--Ox;
	--Oy;
	
	int dist = min_dis(Ox, Oy, M);
	if(dist == -1){
		cout << "no es pot arribar a cap tresor" << endl;
	}
	else cout << "distancia maxima: " << dist << endl;
	}
