/*
    Bonelight * v *
    20241024：CF,Goodnight
    登神长阶， 灯 升 长 阶
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n,m,k; cin >> n >> m >> k;
    vector<pii> edge(m+1);
    vector<vector<int>> g(n + 1, vector<int>());

    for(int i = 1; i <= m; i ++){
        auto &[x,y] = edge[i];  cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> d(n + 1, INF);
    d[1] = 0;

    queue<int> q; q.push(1);
    
    while(q.size()){
        int o = q.front(); q.pop();
        for(auto p:g[o]){
            if(d[p] == INF){
                d[p] = d[o] + 1;
                q.push(p);
            }
        }
    }

    vector<vector<int>> tr(n + 1, vector<int>());
    for(int i = 1; i <= m; i ++){
        auto [x,y] = edge[i];
        if(d[x] + 1 == d[y]) tr[y].push_back(i);
        if(d[y] + 1 == d[x]) tr[x].push_back(i);
    }

    vector<int> f(n+1, 0);
    vector<string> ans;

    for(int i = 0; i < k; i ++){
        string s(m+1,'0');
        for(int j = 2; j <= n; j ++){
            s[tr[j][f[j]]] = '1';
        }
        ans.push_back(s.substr(1));

        bool ok = false;
        for(int j = 2; j <= n; j ++){
            if(f[j] + 1 < tr[j].size()){
                ok = true;
                f[j] ++;
                break;
            } else {
                f[j] = 0;
            }
        }
        if(!ok) break;
    }
    cout << ans.size() << endl;
    for(auto i:ans) cout << i << endl;
}

signed main(){
ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    cerr << "整个程序运行时间: " << double(clock()) << " ms" << endl;
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
