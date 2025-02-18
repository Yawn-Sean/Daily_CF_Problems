#include <bits/stdc++.h>
using namespace std;

void solve(){
    int v0 = 0, v1 = 1023;
    int n;
    cin >> n;
    for (int i = 0, x; i < n; ++ i){
        char ch;
        cin >> ch >> x;
        if (ch == '|') v0 |= x, v1 |= x;
        else if (ch == '&') v0 &= x, v1 &= x;
        else v0 ^= x, v1 ^= x;
    }

    cout << 2 << "\n";
    cout << "& " << (v0^v1) << "\n";
    cout << "^ " << (v0) << "\n";
}
