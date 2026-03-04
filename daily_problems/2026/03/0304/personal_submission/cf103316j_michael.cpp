#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX = 1e5;
const int MOD = 1e9 + 7;
int fa[MAX + 1];
int sz[MAX + 1];

void build(int n){
    for(int i = 0; i <= n; ++i){
        fa[i] = i;
        sz[i] = 1;
    }
}

int find(int x){
    if(x != fa[x]){
        fa[x] = find(fa[x]);
    }
    return fa[x];
}

void uin(int i,int j){
    int fi = find(i);
    int fj = find(j);
    if(fi != fj){
        fa[fi] = fj;
        sz[fj] += sz[fi];
    }
}

int size(int x){
    return sz[find(x)];
}

long long quickPow(long long base, long long power, long long MOD) {
	if (power == 0) return 1 % MOD;
	long long cur = quickPow(base, power / 2, MOD);
	return power & 1 ? base * cur % MOD * cur % MOD : cur * cur % MOD; 
}

void solve(){
    int n;
    cin >> n;
    build(n);

    vector<int> num(n);
    for(int i = 0; i < n; ++i) cin >> num[i];
    vector<vector<int>> path(n);
    for(int i = 0 ; i < n - 1; ++i){
        int u,v;
        cin >> u >> v;
        u--,v--;
        path[u].emplace_back(v);
        path[v].emplace_back(u);
    }

    vector<int> order(n);
    iota(order.begin(),order.end(),0);
    sort(order.begin(),order.end(),[&](int i,int j){ return num[i] < num[j];} );

    int ans = 0;
    vector<int> vis(n);

    for(auto u : order){
        for(auto v : path[u]){
            if(vis[v]){
                ans += 1ll * num[u] * size(u) % MOD * size(v) % MOD;
                ans %= MOD;
                uin(u,v);
            }
        }
        vis[u] =  1;
    }

    build(n);
    reverse(order.begin(),order.end());
    for(int i = 0 ; i < n; ++i) vis[i] = 0;
    for(auto u : order){
        for(auto v : path[u]){
            if(vis[v]){
                ans += MOD - 1ll * num[u] * size(u) % MOD * size(v) % MOD;
                ans %= MOD;
                uin(u,v);
            }
        }
        vis[u] = 1;
    }
    cout << 1ll * ans * quickPow(1ll * n * (n - 1) / 2 % MOD, MOD - 2, MOD) % MOD;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    cout << flush;
    return 0;
}