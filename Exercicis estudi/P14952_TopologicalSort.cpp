//  Topological Sort
//  P14952_TopologicalSort.cpp
//  programes
//
//  Created by Júlia Gasull Navarro on 26/5/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//

#include <vector>
#include <queue>
#include <iostream>
using namespace std;


typedef vector< vector<int> > Graph;

/*
 	Cal realitzar n tasques, d’una en una. A més, cal fer algunes tasques abans que altres:
 	hi ha m relacions de precedència entre les tasques. Feu un programa que escrigui una
 	manera d’ordenar les n tasques d’acord amb les m precedències donades.

 	Entrada
 		L’entrada consisteix en diversos casos. Cada cas comença amb n, seguit de m, seguit
 		de m parells diferents x y, que indiquen que cal realitzar la tasca x abans que la y.
 		Suposeu 1 ≤ n ≤ 104, 0 ≤ m ≤ 10n, i que les tasques es numeren entre 0 i n − 1
 
 	Sortida
 		Per a cada cas, escriviu la manera més petita lexicogràficament d’ordenar les n
		tasques d’acord amb les m precedències donades. Sempre hi haurà, com a mínim, una
 		solució.

*/

void topological_sort(Graph &G, vector<int> & v)
{
	int n = int(G.size()); 		// mida graf
	vector<int> sorted;
	priority_queue< int, vector<int>, greater<int> > pQ;
	
	for (int i = 0; i < n; i++)
	{
		if (v[i] == 0) pQ.push(i);		// no arrows arrive to it
	}
	
	while (not pQ.empty())
	{
		int act = pQ.top();
		pQ.pop();
		sorted.push_back(act);
		for (int ii = 0; ii < int(G[act].size()); ii++)
		{
			if (--v[G[act][ii]] == 0) pQ.push(G[act][ii]);		// if no more arrows arrive to it
		}
	}
	cout << sorted[0];
	for (int i = 1; i < n; ++i) cout << " " << sorted[i];
	cout << endl;
}

int main()
{
	int n, m, x, y;
	while(cin >> n >> m)
	{
		Graph G(n);
		vector<int> v(n);
		for (int i = 0; i < m; i++)
		{
			cin >> x >> y;
			G[x].push_back(y);
			++v[y];
		}
		topological_sort(G, v);
	}
}
