//
//  P81966_DichotomicSearch.cpp
//  EDA
//
//  Created by Júlia Gasull Navarro on 19/3/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//

#include<iostream>
#include<vector>
using namespace std;

int posicio(double x, const vector<double>& v, int esq, int dre)
{
    int pos = 0;
    bool trobat = false;
    
    while (not trobat and esq <= dre) {
        pos = (esq + dre) / 2;
        if (x < v[pos]) dre = pos - 1;
        else if (x > v[pos]) esq = pos + 1;
        else trobat = true;
    }
    if (trobat) return pos;
    else return -1;
}
