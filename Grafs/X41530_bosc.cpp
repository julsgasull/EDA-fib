//
//  X41530_bosc.cpp
//  programes
//
//  Created by Júlia Gasull Navarro on 24/4/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//

/*------------------------------*/
/*----- Depth-First Search -----*/
/*------------------------------*/


#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph
{
    private:
    
        // number of vertices
        int n;
    
        // pointer -> array containing adjacency lists
        list<int> *adj;
    
        // DFS Search
        void DFS(int i, vector<bool> &visited)
		{
            visited[i] = true;
            for (auto j = adj[i].begin(); j != adj[i].end(); ++j) {
                if (not visited[(*j)]) {
                    DFS((*j), visited);
                }
            }
        }
    
    public:
    
        // Constructor
		Graph(int num_node)
        {
			n = num_node;
            adj = new list<int> [n];
        }
    
        // Add edge
        void add_edge(int n1, int n2)
		{
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }
    
        // Returns number of connected components
        int connected_components()
		{
			// Initialize visited vector
            vector<bool> visited(n, false);
            int cc = 0;
			
            for (int i = 0; i < n; i++) {
                if (not visited[i]) {
					DFS(i, visited);
                    ++cc;
                }
			}
            return cc;
        }
};


int main()
{
	int n, m;
    while (cin >> n >> m)
	{
        Graph g(n);
        
        for (int i = 0; i < m; ++i)
		{
			int n1, n2;
			cin >> n1 >> n2;
            g.add_edge(n1, n2);
        }
        
        int cc = g.connected_components();
        
        if (n - cc == m) cout << cc << endl;	// n = m + cc if they are all trees
        else cout << "no" << endl;
    }
}


