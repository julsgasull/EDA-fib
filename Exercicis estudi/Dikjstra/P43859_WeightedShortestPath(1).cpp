//
//  P43859_WeightedShortestPath(1).cpp
//  programes
//
//  Created by Júlia Gasull Navarro on 26/5/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//

#include <vector>
#include <queue>
#include <iostream>
using namespace std;


typedef pair<double, int> WArc; // weighted arc
typedef vector<vector<WArc>> WGraph; // weighted digraf


/*
 	Write a program that, given a directed graph with positive costs at the arcs,
 	and two vertices x and y, computes the minimum cost to go from x to y.
 
 	Input
 		Input consists of several cases. Every case begins with the number of
 		vertices n and the number of arcs m. Follow m triples u, v, c, indicating that there is an arc u → v of cost c, where u ≠ v and 1 ≤ c ≤ 1000. Finally, we have x and y. Assume 1 ≤ n ≤ 104, 0 ≤ m ≤ 5n, and that for every pair of vertices u and v there is at most one arc of the kind u → v. All numbers are integers. Vertices are numbered from 0 to n−1.

Output

For every case, print the minimum cost to go from x to y, if this is possible. If there is no path from x to y, state so.
*/


int dijkstra(const WGraph &G, int x, int y)
{
	int n = int(G.size());
	vector<double> costos(n, -1);		// coste
	costos[x] = 0;
	vector<bool> S(n, false);		// vistos
	
	priority_queue<WArc, vector<WArc>, greater<WArc> > Q; 	//arestes
	Q.push(WArc(0, x));
	
	while (not Q.empty())
	{
		int u = Q.top().second;		// des don soc
		Q.pop();
		
		if (not S[u])			// no visto
		{
			S[u] = true;
			for (WArc a : G[u])	// arestes d'un vertex
			{
				int v = a.second;		// vertex al que va
				double c = a.first;		// cost per anar al vertex
				if ((costos[v] > costos[u] + c) or costos[v] == -1)		// si el cost és major (ja l'hem visitat pero ara hem trobat un cami amb menys cost) o no sé el seu cost
				{
					costos[v] = costos[u] + c;		// li poso el cost que li toca des don vinc
					Q.push(WArc(costos[v], v));		// seguent
					
				}
			}
		}
	}
	return costos[y];
}

void read (WGraph &G, int m)
{
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		double c;
		cin >> u >> v >> c;
		G[u].push_back(make_pair(c,v));
	}
}

int main ()
{
	int n, m;
	while (cin >> n >> m)
	{
		WGraph G(n);
		read(G, m);
		
		int x, y; cin >> x >> y;
		
		int c = dijkstra(G, x, y);
		
		if (c != -1) cout << c << endl;
		else cout << "no path from " << x << " to " << y << endl;
	} }
