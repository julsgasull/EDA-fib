//
//  P84219_FirstOccurrence.cpp
//  EDA
//
//  Created by Júlia Gasull Navarro on 19/3/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//


#include<iostream>
#include<vector>
using namespace std;

int i_first_occurrence(double x, const vector<double>& v, int esq, int der) {
    if (esq > der) return -1;
    else {
        int pos = (esq + der)/2;
        if (x < v[pos]) return i_first_occurrence(x,v,esq,pos-1);
        else if (x > v[pos]) return i_first_occurrence(x,v,pos+1,der);
        else if (pos > 0 and v[pos-1] == x) return i_first_occurrence(x,v,esq,pos-1);
        else return pos;
    }
}

int first_occurrence(double x, const vector<double>& v) {
    return i_first_occurrence(x, v, 0, int(v.size()-1));
}

