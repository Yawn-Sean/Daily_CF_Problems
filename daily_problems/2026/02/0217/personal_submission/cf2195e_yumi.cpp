#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;

void solve(){
    int n;
    cin >> n;
    vector<int> l(n + 1), r(n + 1);
    vector<ll> sizes(n + 1, 0), ans(n + 1, 0);
    for(int i = 1;i <= n;i++){
        cin >> l[i] >> r[i];
    }
    auto dfs1 = [&](auto&& self, int u) -> void{
        if(l[u] == 0 && r[u] == 0){
            sizes[u] = 0;
            return;
        }
        self(self, l[u]);
        self(self, r[u]);
        sizes[u] = (4 + sizes[l[u]] + sizes[r[u]]) % MOD;
    };
    dfs1(dfs1, 1);
    ans[1] = (1 + sizes[1]) % MOD;
    auto dfs2 = [&](auto&& self, int u, int f) -> void{
        if(u == 0)  return;
        if(u != 1)  ans[u] = (sizes[u] + ans[f] + 1) % MOD;
        self(self, l[u], u);
        self(self, r[u], u);
    };
    dfs2(dfs2, 1, 0);
    for(int i = 1;i <= n;i++){
        cout << ans[i] << " ";
    }   cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}