/*
    Bonelight * v *
    20240927：Bad Day * ^ *
    No Coding , No Bug
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n; cin >> n; vector<int> peo(n),cost(n);
    for(int i = 0; i < n; i ++) cin >> peo[i] >> cost[i];
    
    int m; cin >> m; vector<int> tab(m), tab_idx(m);
    for(int i = 0; i < m; i ++) cin >> tab[i];
    iota(begin(tab_idx),end(tab_idx),0);
    
    sort(begin(tab_idx),end(tab_idx),[&](int x, int y){
        return tab[x] < tab[y];
    });
    sort(begin(tab),end(tab));
    vector<vector<int>> g(m, vector<int>());

    for(int i = 0; i < n; i ++){
        int idx = lower_bound(begin(tab),end(tab),peo[i]) - begin(tab);
        if(idx < m) g[idx].push_back(i);
    }

    priority_queue<pii> pq;
    
    vector<pii> ans;
    int ans_sum = 0;
    for(int i = 0; i < m; i ++){
        for(auto idx:g[i]){
            pq.push({cost[idx],idx});
        }
        if(pq.size()){
            int idx = pq.top().second;
            ans_sum += cost[idx];
            ans.push_back({idx,i});
            pq.pop();
        }
    }

    cout << ans.size() << ' ' << ans_sum << endl;
    for(auto [idx1,idx2]:ans) cout << idx1 + 1 << ' ' << tab_idx[idx2] + 1 << endl;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
