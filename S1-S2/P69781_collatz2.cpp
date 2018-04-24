//
//  P69781.cpp
//  EDA
//
//  Created by Júlia Gasull Navarro on 20/2/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//

#include <iostream>
#include <map>
#define LIMIT 100000000
using namespace std;


int collatz(int n, int x, int y)
{
    if (n % 2 == 0) return n/2 + x;
    else return 3*n + y;
}

int main() {
    int n, x, y;
    map<int, int> m;
    
    while (cin >> x >> y >> n)
    {
        bool repetit = false;
        int cont = 0;
        while (not repetit and n <= LIMIT) {
            if (m.find(n) != m.end()) {
                cont = cont - m[n];
                repetit = true;
            }
            cont++;
            m[n] = cont;
            //n = (n % 2) ? 3 * n + y : n / 2 + x;
            n = collatz(n, x, y);
        }
        m.clear();
        if (repetit) cout << cont << endl;
        else cout << n << endl;
    }
}
