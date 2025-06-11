#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7, N = 1e6+11;
int tr[N], pre[N];
bool vis[N];

void add(int x, int c){
    while (x < N) tr[x] = (tr[x]+c)%mod, x += x&-x;
}
ll qry(int x){
    ll res = 0;
    while (x) res = (res+tr[x])%mod, x -= x&-x;
    return res; 
}

void solve(){
    int n;
    cin >> n;
    vector <ll> f(n+1);
    add(1, 1);  // dp的初始化，以序列 1 开始转移
    for (int i = 1, x; i <= n; ++ i){
        cin >> x;
        f[i] = 1ll*qry(x)*x%mod;
        if (pre[x]) add(x, -f[pre[x]]), f[pre[x]] = 0;  减去相同以x结尾的子序列，并将上一次出现x的f[i]置0
        pre[x] = i;
        add(x, f[i]);
    }
    ll res = 0;
    for (auto &x : f) res = (res+x)%mod;
    cout << (res+mod)%mod << "\n";
}
