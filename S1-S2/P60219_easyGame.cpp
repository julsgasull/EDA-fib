//
//  P60219_easyGame.cpp
//  EDA
//
//  Created by Júlia Gasull Navarro on 22/2/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;


struct strsize
{
    bool operator() (const string& a, const string& b) const
    {
        if (a.size() < b.size()) return true;
        else if (a.size() > b.size()) return false;
        else return a < b;
    }
};

int main()
{
    int count = 1;
    string s;
    set<string>::iterator it1;
    set<string, strsize>::iterator it2;
    while (s != "QUIT")
    {
        set<string> has;
        set<string,strsize> had;
        
        while (cin >> s and s != "END" and s != "QUIT")
        {
            it1 = has.find(s);
            if (it1 == has.end())
            { // si no hi es
                has.insert(it1,s);  //inserto
                it2 = had.find(s);  //el busco a had
                if (it2 != had.end()) had.erase(it2);   //si hi es el borro
            }
            else
            { // si hi es
                it2 = had.begin();
                had.insert(it2, *it1);  //inserto a had
                has.erase(it1);         //borro de has
            }
        }
        
        if (count > 1) cout << endl;
        cout << "GAME #" << count << endl << "HAS:" << endl;
        for (it1 = has.begin(); it1 != has.end(); ++it1) cout << *it1 << endl;
        cout << endl << "HAD:" << endl;
        for (it2 = had.begin(); it2 != had.end(); ++it2) cout << *it2 << endl;
        ++count;
    }
}
