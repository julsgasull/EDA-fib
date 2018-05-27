//  Exhaustive search and generation
//  P24674_PermutacionsDeParaules.cpp
//  programes
//
//  Created by Júlia Gasull Navarro on 27/5/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//


#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

/*
 	Feu un programa que, donades n paraules diferents s1, …, sn,
 	escrigui les permutacions que es poden formar amb les paraules.

 	Entrada
 		L’entrada consisteix en un nombre n > 0, seguit de s1, …, sn.

 	Sortida
 		Escriviu totes les permutacions que es poden formar amb s1,
 		…, sn.
*/


void write_permutations(const vector<string> &words, vector<string> &result, vector<bool> &seen)
{
	if (result.size() == words.size())
	{
		cout << "(" << result[0];
		for (int i = 1; i < int(result.size()); i++) cout << "," << result[i];
		cout << ")" << endl;
	}
	else
	{
		for (int j = 0; j < words.size(); j++)
		{
			if (not seen[j])
			{
				seen[j] = true;
				result.push_back(words[j]);
				write_permutations(words, result, seen);
				seen[j] = false;
				result.pop_back();
			}
		}
	}
}


void read_vector(vector<string> &words)
{
	for (int i = 0; i < int(words.size()); i++) cin >> words[i];
}


int main()
{
	int n; cin >> n;
	vector<string> words(n);
	read_vector(words);
	
	vector<string> result(0);
	vector<bool> seen(n, false);
	write_permutations(words, result, seen);
}
