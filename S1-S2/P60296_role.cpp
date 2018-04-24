//
//  P60296_role.cpp
//  EDA
//
//  Created by Júlia Gasull Navarro on 21/2/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// elo = puntuacio
// punts inicials = 1200 -> mai menys
// guanyador -> +10
// perdedor -> -10
// elo es mante

// Instruccions
/*
    LOGIN j
    LOGOUT j
    PLAY j1 j2 (j1 guanya) -> si ji no esta connectat -> error
    GET_ELO j
 */

struct stats
{
    bool connected;
    int elo;
};

bool compare_score(pair<int, string> p1, pair<int, string> p2) {
    if (p1.first > p2.first) return true;
    else {
        if (p1.first < p2.first) return false;
        else return (p1.second < p2.second);
    }
}

int main() {
    string action, p1, p2;
    stats s;
    map<string, stats> M;
    map<string, stats>::iterator it;
    
    while (cin >> action)
    {
        cin >> p1;                                  // jugador 1
        it = M.find(p1);
        
        if (action == "LOGIN")
        {
            if (it == M.end())                      // si no hi es
            {
                s.connected = true;
                s.elo = 1200;
                M.insert(make_pair(p1, s));
            }
            else {                                  // si ja hi es
                it->second.connected = true;
            }
        }
        else if (action == "LOGOUT")
        {
            if (it != M.end()) {                    // si hi es
                it->second.connected = false;
            }
        }
        else if (action == "GET_ELO")
        {
            cout << it->first << " " << it->second.elo << endl;
        }
        else
        {
            cin >> p2;                              // jugador 2
            
            map<string, stats>::iterator it2 = M.find(p2);
            
            if ((it != M.end() && it2 != M.end()) && (it->second.connected && it2->second.connected))
            {   // si existeixen i estan connectats
                it->second.elo += 10;
                it2->second.elo -= 10;
                if (it2->second.elo < 1200) it2->second.elo = 1200;
            }
            else cout << "jugador(s) no connectat(s)" << endl;
        }
    }
    
    // calculo ranking
    int tam = int(M.size());
    vector< pair<int,string> > v(tam);
    int i = 0;
    for (it = M.begin(); it != M.end(); ++it)       // els passo al vector
    {
        v[i].first = it->second.elo;
        v[i].second = it->first;
        ++i;
    }
    sort(v.begin(), v.end(), compare_score);        // els ordeno al vector
    
    // escric ranking
    cout << endl << "RANKING" << endl;
    for (i = 0; i < v.size(); ++i) cout << v[i].second << " " << v[i].first << endl;
}

//JosepRivaille

