#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 3e5+11, mod = 1e9+7, inf = 1e9;
struct dsu {
    vector <int> p, sz, add;
    dsu(){}
    dsu(int n): p(n+1), sz(n+1, 1){
        iota(p.begin(), p.end(), 0);
    }
    void init(int x){
        p[x] = x, sz[x] = 1;
    }
    int root(int x){
        return p[x] = x==p[x] ? x : root(p[x]);
    }
    int size(int x){
        return sz[root(x)];
    }
    bool merge(int x, int y){
        x = root(x), y = root(y);
        if (x == y) return false;
        if (size(x) < size(y)) swap(x, y);
        sz[x] += sz[y], p[y] = x;
        return true;
    }
};

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector <ll> nums(n);
    for (auto &x : nums) cin >> x;

    vector <int> us(m), vs(m);
    map <ll, vector<int>> mps;

    for (int i = 0; i < m; ++ i){
        int u, v;
        cin >> u >> v;
        -- u, -- v;
        us[i] = u, vs[i] = v;
        mps[nums[u]^nums[v]].push_back(i);
    }

    vector <int> pow2(n+1,1);
    for (int i = 0; i < n; ++ i){
        pow2[i+1] = pow2[i]*2%mod;
    } 
    int ans = ((1ll<<k) - mps.size())%mod * pow2[n]%mod;
    
    dsu Y(n);

    for (auto &it : mps){
        auto mp = it.second;
        int All = n;
        for (auto &i : mp){
            if (Y.merge(us[i], vs[i])){
                -- All;
            }
        }
        (ans += pow2[All]) %= mod;
        for (auto &i : mp)
            Y.init(us[i]), Y.init(vs[i]);
    }

    cout << ans << "\n";
}
