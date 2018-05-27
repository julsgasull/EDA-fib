//
//  P60796_TresorsMapa(2).cpp
//  programes
//
//  Created by Júlia Gasull Navarro on 27/5/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//

#include <vector>
#include <iostream>
#include <queue>
using namespace std;

typedef vector<vector<char>> Graph;

/*
 	Feu un programa que, donat un mapa amb tresors i obstacles,
 	digui a quina distància es troba el tresor accessible més
 	proper a una posició inicial donada. Els moviments permesos
 	són horitzontals o verticals, però no diagonals.
 
 	Entrada
 		L’entrada comença amb el nombre de files n > 0 i de
 		columnes m > 0 del mapa. Segueixen n files amb m
 		caràcters cadascuna. Un punt indica una posició buida,
		una ‘X’ indica un obstacle, i una ‘t’ indica un tresor.
 		Finalment, un parell de nombres f i c indiquen la fila
		i columna inicials (ambdues començant en 1) des de les
 		quals cal començar a buscar tresors. Podeu suposar que
 		f està entre 1 i n, que c està entre 1 i m, i que la
 		posició inicial sempre està buida.
 
 	Sortida
 		Escriviu el nombre mínim de passos des de la posició
 		inicial fins a arribar a un tresor. Si no es pot arribar
 		a cap tresor, cal indicar-ho.
*/

static constexpr int I[4] = { 1, 0, -1,  0};
static constexpr int J[4] = { 0, 1,  0, -1};

bool pos_ok(int i, int j, const Graph &G)
{
	return 	(	(i < G.size())    and (i >= 0) 	and
			 	(j < G[0].size()) and (j >= 0) 	and
				(G[i][j] != 'X'));
}

int min_dist_to_first_trasure(int i, int j, Graph &G)
{
	vector<vector<int>> dist(G.size(), vector<int>(G[0].size(), -1));
	dist[i][j] = 0;
	
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	
	while(not q.empty())
	{
		pair<int, int> p = q.front();
		int new_i = p.first;
		int new_j = p.second;
		q.pop();
		
		if (G[new_i][new_j] == 't') return dist[new_i][new_j];
		
		G[new_i][new_j] = 'X';		// marcar com a visitat
		
		for (int x = 0; x < 4; x++)
		{
			int ii = new_i + I[x];
			int jj = new_j + J[x];
			if (pos_ok(ii, jj, G))
			{
				q.push(make_pair(ii, jj));
				dist[ii][jj] = dist[new_i][new_j] + 1;
			}
		}
	}
	return -1;
}


void read_graph(Graph &G)
{
	for (int i = 0; i < int(G.size()); i++) for (int j = 0; j < int(G[0].size()); j++) cin >> G[i][j];
}


int main()
{
	int n, m;
	cin >> n >> m;
	Graph G(n, vector<char>(m));
	read_graph(G);
	int i, j;
	cin >> i >> j;
	int dist = min_dist_to_first_trasure(i-1, j-1,G);
	if (dist == -1) cout << "no es pot arribar a cap tresor" << endl;
	else cout << "distancia minima: " << dist << endl;
}
