//	Depth-First Search
//  P29033_DosColors.cpp
//  programes
//
//  Created by Júlia Gasull Navarro on 27/5/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//



#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef vector< vector<int> > Graph;

/*
 	Feu un programa que, donat un graf no dirigit, digui si és possible pintar
	tots els seus vèrtexs només amb dos colors, de manera que no hi hagi dos
 	vèrtexs veïns del mateix color.

 	Entrada
 		L’entrada consisteix en diversos casos, cadascun amb el nombre de
 		vèrtexs n i el nombre d’arestes m, seguits de m parells x y indicant
 		una aresta entre x i y. Suposeu 1 ≤ n ≤ 104, 0 ≤ m ≤ 5n, que els vèrtexs
 		es numeren entre 0 i n − 1, x ≠ y, i que no hi ha més d’una aresta entre
 		tot parell x y.

 	Sortida
 		Per a cada cas, escriviu “yes” si el graf és dos-colorejable, i “no”
 		altrament.

 */

bool two_colours(const Graph &G)
{
	int n = int(G.size());
	vector<int> colours(n, -1);
	queue<int> Q;
	for (int i = 0; i < n; i++)
	{
		if (colours[i] < 0)
		{
			Q.push(i);
			colours[i] = 1;
			while (not Q.empty())
			{
				int v = Q.front();
				Q.pop();
				for (int j = 0; j < int(G[v].size()); j++)
				{
					if (colours[G[v][j]] == colours[v]) return false;
					if (colours[G[v][j]] < 0)
					{
						Q.push(G[v][j]);
						colours[G[v][j]] = 1 - colours[v];
					}
				}
			}
		}
	}
	return true;
}

void read_Graph (Graph &G, int m)
{
	int x, y;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
}

int main()
{
	int n, m;		// n = |V|, m = |A|
	while (cin >> n >> m)
	{
		Graph G(n);
		read_Graph(G, m);
		if (two_colours(G)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}
