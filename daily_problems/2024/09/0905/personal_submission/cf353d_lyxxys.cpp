#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int f = 0;
    for (int i = 0, M = 0; i < n; ++ i){
        if (s[i] == 'M') ++ M;
        else if (M > 0) f = max(f+1, M);
    }
    cout << f << "\n";
}
