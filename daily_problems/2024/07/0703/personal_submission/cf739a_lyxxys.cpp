#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 1e5+5, inf = 1e9, mod = 998244353;

void solve(){
    int n, m;
    cin >> n >> m;
    int res = inf;
    while (m--){
        int l, r;
        cin >> l >> r;
        res = min(res, r-l+1);
    }
    vector <int> ans;
    for (int i = 0; i < n; ++ i)
        ans.push_back(i%res);
    cout << res << "\n";
    for (auto &x : ans) cout << x << " ";
    cout << "\n";
}
