//
//  P40902.cpp
//  EDA
//
//  Created by Júlia Gasull Navarro on 20/2/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;

//enters -> entrar al casino
//leaves -> sortir del casino
//wins x -> guanya x diners (int x)

//cada cop que surti -> què ha guanyat

//al final posar els que hi tenia

int main()
{
    map<string, int> casino;
    string nom;
    string operacio;
    int x;
    
    while (cin >> nom >> operacio)
    {
        map<string,int>::iterator it = casino.find(nom);
        if (operacio == "enters")
        {
            if (it != casino.end()) cout << nom << " is already in the casino" << endl;
            else casino.insert(pair<string,int>(nom, 0));
        }
        else if (operacio == "wins")
        {
            cin >> x;
            if (it != casino.end()) it->second += x;
            else cout << nom << " is not in the casino" << endl;
        }
        else
        {
            if (it != casino.end()) {
                cout << nom << " has won " << it->second << endl;
                casino.erase(it);
            }
            else cout << nom << " is not in the casino" << endl;
        }
    }
    
    cout << "----------" << endl;
    map<string,int>::iterator it2 = casino.begin();
    while (it2 != casino.end())
    {
        cout << it2->first << " is winning " << it2->second << endl;
        ++it2;
    }
}
