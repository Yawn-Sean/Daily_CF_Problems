#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int limi = 1e9, N = 1e7+1;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> p(n), A(n);
    iota(p.begin(), p.end(), 0);
    function<int(int)> find = [&](int x){
        return p[x] = p[x]==x ? x : find(p[x]);
    };
    auto merge = [&](int x, int y)->void{
        x = find(x), y = find(y);
        if (x == y) return;
        p[y] = x;
        return;
    };

    for (auto &x : A) cin >> x;

    while (m--){
        int x, y;
        cin >> x >> y;
        x -= 1, y -= 1;
        merge(x, y);
    }
    
    vector <int> sz(n);
    map <int, int> mps[n];
    
    for (int i = 0; i < n; ++ i){
        int x = find(i);
        mps[x][A[i]] += 1;
        sz[x] += 1;
    }
    int res = 0;
    for (int i = 0; i < n; ++ i){
        if (mps[i].size()){
            int Max = 0;
            for (auto &it : mps[i]){
                Max = max(Max, it.second);
            }
            res += sz[i] - Max;
        }
    }
    cout << res << "\n";
}
 
