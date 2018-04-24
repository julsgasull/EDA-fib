//
//  P50709.cpp
//  EDA
//
//  Created by Júlia Gasull Navarro on 20/2/18.
//  Copyright © 2018 Júlia Gasull Navarro. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;



//S x  -> guarda
//A    -> consulta més gran
//R    -> esborra més gran (només 1)
//I x  -> incrementa el més gran (només 1) en x unitats
//D x  -> decrementa el més gran (només 1) en x unitats


int main()
{
    priority_queue<int> pq;
    char c;
    int x;
    
    while (cin >> c)
    {
        if (c == 'S')
        {
            cin >> x;
            pq.push(x);
        }
        else if (c == 'A')
        {
            if (pq.empty()) cout << "error!" << endl;
            else cout << pq.top() << endl;
        }
        else if (c == 'R')
        {
            if (pq.empty()) cout << "error!" << endl;
            else pq.pop();
        }
        else if (c == 'I')
        {
            cin >> x;
            if (pq.empty()) cout << "error!" << endl;
            else
            {
                x += pq.top();
                pq.pop();
                pq.push(x);
            }
        }
        else    // c == 'D'
        {
            cin >> x;
            if (pq.empty()) cout << "error!" << endl;
            else
            {
                x = pq.top() - x;
                pq.pop();
                pq.push(x);
            }
        }
    }
}
