#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve(){

    string s;
    cin >> s;

    int n = s.size();
    ll res = 0;
    for (int i = 0; i < n; ++ i){
        int cnt = 0, cntb = 0;
        for (int j = i; j < n; ++ j){
            if (s[j] == '(') ++ cntb;
            else if (s[j] == ')') -- cntb;
            else -- cntb, ++ cnt;
            if (cntb < 0){
                if (cnt <= 0) break;
                -- cnt, cntb += 2;
                }
            if (!cntb) ++ res;
        }
    }

    cout << res << "\n";
}
