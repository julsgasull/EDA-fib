//
//  P24674_Permutacions.cpp
//  programes
//
//  Created by Júlia Gasull Navarro on 22/5/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//

/*------------------------------------------*/
/*---- Exhaustive search and generation ----*/
/*------------------------------------------*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;



void escriu_permutacions(const vector<string> &paraules, vector<bool> &usat, vector<string> &resultat)
{
	if (resultat.size() == paraules.size())	//cas base -> escriure
	{ 	//(hola,adeu,hi)
		cout << "(" << resultat[0];
		for (int i = 1; i < resultat.size(); i++) cout << "," << resultat[i];
		cout << ")" << endl;
	}
	else // cas inductiu
	{
		for (int j = 0; j < paraules.size(); j++)
		{
			if (not usat[j])
			{
				resultat.push_back(paraules[j]);
				usat[j] = true;
				escriu_permutacions(paraules, usat, resultat);
				usat[j] = false;	//per mirar permutació amb la seguent paraula
				resultat.pop_back();
			}
		}
	}
}


int main()
{
	//llegir entrada
	int n; cin >> n;
	vector<string> paraules(n);
	for (int i = 0; i < n; i++) cin >> paraules[i];
	
	//resultat
	vector<string> resultat(0);
	vector<bool> usat(n, false);
	escriu_permutacions(paraules, usat, resultat);
	
}



