#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "?" + s + "?";
    int c1 = 0;
    vector <int> F1(n+2), F2(n+2);
    int res = 0;
    for (int i = 1; i <= n; ++ i){
        if (s[i] == 'G'){
            F1[i] = F1[i-1] + 1;
            res = max(res, F1[i]);
            ++ c1;
        }
    }
    for (int i = n; i >= 1; -- i){
        if (s[i] == 'G'){
            F2[i] = F2[i+1] + 1;
        }
    }
    if (c1 == n) return cout << n << "\n", void();
    for (int i = n; i >= 1; -- i){
        if (s[i] == 'S' && (s[i-1] == 'G' || s[i+1] == 'G')){
            int cnt = F1[i-1] + F2[i+1];
            if (cnt < c1) res = max(res, cnt+1);
            else res = max(res, cnt);
        }
    }

    cout << res << "\n";
}
 
