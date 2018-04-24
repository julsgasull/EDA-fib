//
//  P37064.cpp
//  EDA
//
//  Created by Júlia Gasull Navarro on 20/2/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;



int main()
{
    cout.setf(ios::fixed);
    cout.precision(4);
    
    string s;
    int n;
    int count = 0;
    double ave = 0;
    
    map<int,int> M;
    map<int,int>::iterator it;
    
    while (cin >> s) {
        if (s == "number") {
            cin >> n;
            it = M.find(n);
            if (it != M.end()) it->second += 1;
            else M.insert(make_pair(n, 1));
            ave += n;
            ++count;
        }
        else {
            if (!M.empty()) {
                it = M.begin();
                ave -= it->first;
                --count;
                if (it->second == 1) M.erase(it);
                else it->second -= 1;
            }
        }
        if (M.empty()) cout << "no elements" << endl;
        else {
            it = M.end();
            --it;
            cout << "minimum: " << M.begin()->first;
            cout << ", maximum: " << it->first;
            cout << ", average: " << ave/count << endl;
        }
    }
}
