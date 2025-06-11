#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

void solve(){
    int n, k;
    cin >> n >> k;
    string t;
    cin >> t;
    int m = t.size();

    vector <int> f(k), last(k, -1), p(k);

    for (int i = 0; i < m; ++ i){
        last[t[i]-'a'] = i;
    }

    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int x, int y){
        return last[x] < last[y];
    });

    int all = 0;
    for (auto &ch : t){
        int c = ch-'a';
        int v = all - f[c] + 1;
        if (v < 0) v += mod;
        f[c] = (f[c] + v) % mod;
        all = (all + v) % mod;
    }

    for (int i = 0; i < n; ++ i){
        int c = p[i%k];
        int v = all - f[c] + 1;
        if (v < 0) v += mod;
        f[c] = (f[c] + v) % mod;
        all = (all + v) % mod;
    }

    cout << (all+1) % mod << "\n";
}
