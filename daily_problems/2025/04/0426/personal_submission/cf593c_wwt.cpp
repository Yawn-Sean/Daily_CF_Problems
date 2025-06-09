#include<bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;

#include <iostream>
#include <map>
#include <string>


int main() {
   

    int n;
    cin >> n;

    vector<int> xs(n), ys(n);
    int r;
    for (int i = 0; i < n; i++)
        cin >> xs[i] >> ys[i] >> r;

    auto solve = [&](vector<int> lst) -> void {
        cout << string(n - 1, '(');
        for (int i = 0; i < n; i++) {
            if (i) cout << '+';
            cout << '(' << lst[i] / 2 << "*((1-abs((t-" << i << ")))+abs((1-abs((t-" << i << "))))))";
            if (i) cout << ')';
        }
        cout << '\n';
    };

    solve(xs);
    solve(ys);

    return 0;
}
