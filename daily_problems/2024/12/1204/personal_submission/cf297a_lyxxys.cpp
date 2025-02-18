#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    string s, t;
    cin >> s >> t;
    int c1 = 0, c2 = 0;
    for (auto &c : s) c1 += c == '1';
    for (auto &c : t) c2 += c == '1';

    cout << (((c1 >= c2) || (c1%2 && c1+1 == c2)) ? "YES\n" : "NO\n");
}
