//
//  P69932_seqLlarga.cpp
//  EDA
//
//  Created by Júlia Gasull Navarro on 21/2/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//

#include <iostream>
#include <set>
#include <sstream>
using namespace std;

//Resumen: Se inserta cada línea en un set<int> y con la ayuda de
// 3 punteros, 2 para comparar y otro auxiliar para eliminar un número
// del set<int>; vamos comparando que cumplan las reglas del enunciado.


int main()
{
    int n;
    string s;
    
    while (getline(cin, s))
    {
        istringstream ss(s);
        set<int> conj_num;
        while (ss >> n) conj_num.insert(n);     // mentre entrin numeros de la linia -> els poso al set
        
        set<int>::iterator it1, it2, aux;       // 3 iterados pel set
        
        it1 = conj_num.begin();                 // it1 i it2 al principi
        it2 = it1;
        
        while (it2 != conj_num.end())
        {
            if (it1 == it2) ++it2;
            else
            {
                if ((*it1 + *it2) % 2 != 0)     // si tenen diferent paritat
                {
                    ++it1;
                    ++it2;
                }
                else                            // si tenen la mateixa paritat
                {
                    aux = it2;
                    ++it2;
                    conj_num.erase(aux);        // al no cumplir la regla de paridad se elimina del set<int>
                }
            }
        }
        cout << conj_num.size() << endl;
    }
}
