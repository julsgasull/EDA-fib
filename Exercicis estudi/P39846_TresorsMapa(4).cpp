//	Breadth-First Search
//  P39846_TresorsMapa(4).cpp
//  programes
//
//  Created by Júlia Gasull Navarro on 26/5/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//

#include <vector>
#include <queue>
#include <iostream>
using namespace std;


void read_matrix(int n, int m, vector< vector<char> > &M)
{
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> M[i][j];
}

int pos_ok(int f, int c, const vector< vector<char> > &M)
{
	return (f >= 0 and f < int(M.size()) and c >= 0 and c < int(M[0].size()) and M[f][c] != 'X');
}

int is_treasure(int f, int c, const vector< vector<char> > &M)
{
	return (M[f][c] == 't');
}

int min_distance_to_furthest(int source_f, int source_c, const vector< vector<char> > &M)
{
	int max_dist = -1;
	int rows = int(M.size());
	int cols = int(M[0].size());
	
	queue< pair<int, int> >	Q;										//position queue
	vector< vector<int> > dist(rows, vector<int> (cols, -1));		//matrix with distances to positions
	
	Q.push(make_pair(source_f, source_c));
	dist[source_f][source_c] = 0;
	
	while (not Q.empty())
	{
		pair<int, int> position = Q.front();
		int i = position.first;
		int j = position.second;
		Q.pop();
		
		if (is_treasure(i, j, M) and dist[i][j] > max_dist) max_dist = dist[i][j];		// treasure
		
		// UP
		if (pos_ok(i-1, j, M) and dist[i-1][j] == -1)
		{
			Q.push(make_pair(i-1, j));
			dist[i-1][j] = dist[i][j] + 1;
		}
		
		// DOWN
		if (pos_ok(i+1, j, M) and dist[i+1][j] == -1)
		{
			Q.push(make_pair(i+1, j));
			dist[i+1][j] = dist[i][j] + 1;
		}
		
		// RIGHT
		if (pos_ok(i, j+1, M) and dist[i][j+1] == -1)
		{
			Q.push(make_pair(i, j+1));
			dist[i][j+1] = dist[i][j] + 1;
		}
		
		// LEFT
		if (pos_ok(i, j-1, M) and dist[i][j-1] == -1)
		{
			Q.push(make_pair(i, j-1));
			dist[i][j-1] = dist[i][j] + 1;
		}
	}
	return max_dist;
}

int main()
{
	int n, m; cin >> n >> m;		// matrix rows and cols
	vector< vector<char> > M(n, vector<char>(m));
	read_matrix(n, m, M);
	
	int f, c;						// inicial position
	cin >> f >> c;
	
	int dist = -1;
	if (pos_ok(f-1, c-1, M)) dist = min_distance_to_furthest(f-1, c-1, M);
	
	if (dist == -1) cout << "no es pot arribar a cap tresor" << endl;
	else cout << "distancia maxima: " << dist << endl;
}
