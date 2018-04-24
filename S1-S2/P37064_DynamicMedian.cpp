//
//  P37064.cpp
//  EDA
//
//  Created by Júlia Gasull Navarro on 20/2/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    
    set<string> seq;
    string s;
    bool senar = false; // if S.size() is odd
    
    set<string>::const_iterator med = seq.end(); // iterator to median
    while (cin >> s and s != "END") {
        // we can do first because we're sure that words are differents
        set<string>::const_iterator it = seq.insert(s).first; // first add the word
        senar = not senar;
        
        if (med == seq.end()) med = it; // if one word, median is obvious
        else if (not senar and s < *med) --med;
        else if (senar and s > *med) ++med;
        
        cout << *med << endl;
    }
}
