#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector <array<int,2>> item(n), ans;
    for (auto &it : item) cin >> it[0] >> it[1];
    int m;
    cin >> m;
    vector <int> B(m), ps(m), vis(n);
    for (auto &x : B) cin >> x;

    iota(ps.begin(), ps.end(), 0);
    sort(ps.begin(), ps.end(), [&](int x, int y){
        return B[x] < B[y];
    });
    
    long long res = 0;
    for (auto &it : ps){
        int x = B[it];
        int p = -1;
        for (int i = 0; i < n; ++ i){
            if (vis[i] || item[i][0] > x) continue;
            if (p == -1 || item[i][1] > item[p][1]){
                p = i;
            }
        }
        if (p==-1) continue;
        vis[p] = 1;
        res += item[p][1];
        ans.push_back({p+1, it+1});
    }

    cout << ans.size() << " " << res << "\n";
    for (auto &it : ans) cout << it[0] << " " << it[1] << "\n";
}
 
