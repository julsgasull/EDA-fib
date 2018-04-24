//
//  P33412_ResistantDichotomicSearch.cpp
//  EDA
//
//  Created by Júlia Gasull Navarro on 19/3/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool i_resistant_search(double x, const vector<double> &v, int esq, int dre)
{
    int m = (dre - esq - 1)/ 2 + esq;
    
    if (dre < esq) return false;
    if (v[m] == x) return true;
    
    if (m > 0 and v[m - 1] == x) return true;
    if (m < v.size() - 1 and v[m + 1] == x) return true;
    
    if (v[m] > x) return i_resistant_search(x, v, esq, m - 2);
    return i_resistant_search(x, v, m + 2, dre);
}

bool resistant_search(double x, const vector<double>& v)
{
    return i_resistant_search(x, v, 0, int(v.size()-1));
}

