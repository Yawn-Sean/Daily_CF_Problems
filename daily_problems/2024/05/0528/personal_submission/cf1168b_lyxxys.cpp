#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5050, mod = 998244353;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    ll res = 0;
    int p = n+1;
    for (int l = n; l; -- l){
        for (int half = 1; l+2*half <= n; ++ half)
            if (s[l] == s[l+half] && s[l+half] == s[l+2*half]){
                p = min(p, l+2*half);
                break;
            }
        res += n-p+1;
    }
    cout << res << "\n";
}  
