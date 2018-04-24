//
//  P58512_InterestRates.cpp
//  EDA
//
//  Created by Júlia Gasull Navarro on 2/4/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

#define MAX_DIA 100000000
#define MIN_DIA 1

double exp_rapida(double n, int k){
    if(k == 0) return 1;
    else{
        double a = exp_rapida(n,k/2);
        if(k % 2 == 0){
            return (a * a);
        }else{
            return (a * a * n);
        }
    }
}

int buscar_dia(int min, int max, double bank_dia, double q, double f){
    if(min <= max){
        int m = (max + min)/2; //dias a ver
        double retornar_bank = exp_rapida(bank_dia,m)*q;
        double retornar_pavo = f*m + q;
        if(retornar_pavo > retornar_bank){
            return buscar_dia(m+1,max,bank_dia,q,f);
        }
        else if(retornar_pavo < retornar_bank){
            return buscar_dia(min,m-1,bank_dia,q,f);
        }
        else return m;
    }
    else return min;
}


int main(){
    //f*dias + m < bank_daily^dias * m
    double m,f,r;
    while(cin >> m >> f >> r){
        double bank_daily_int = (r / 100)+1;
        cout << buscar_dia(MIN_DIA,MAX_DIA,bank_daily_int,m,f) << endl;
    }
}
