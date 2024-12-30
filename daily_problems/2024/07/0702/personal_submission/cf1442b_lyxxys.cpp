#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+5, inf = 1e9, mod = 998244353;

void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> a(n+1), b(m+1), posA(n+1), chose(n+1);
    vector <int> last(n+1), next(n+1);
    for (int i = 1; i <= n; ++ i) cin >> a[i], posA[a[i]] = i, last[i] = i-1, next[i] = i+1;
    for (int i = 1; i <= m; ++ i) cin >> b[i], chose[posA[b[i]]] = 1;

    auto dele = [&](int i)->void{
        if (last[i] >= 1) next[last[i]] = next[i];
        if (next[i] <= n) last[next[i]] = last[i];
    };
    int res = 1;
    for (int i = 1; i <= m; ++ i){
        int pos = posA[b[i]];
        int ct1 = 0, ct2 = 0;
        if (last[pos] >= 1 && !chose[last[pos]]) ++ ct1;
        if (next[pos] <= n && !chose[next[pos]]) ++ ct2;
        res *= (ct1+ct2), res %= mod;
        dele(pos);
    }
    cout << res << "\n";
}
