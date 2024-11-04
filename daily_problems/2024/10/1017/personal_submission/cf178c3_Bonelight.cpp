/*
    Bonelight * v *
    20241017：CF,Goodnight
    No Coding , No Bug
*/
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#define endl '\n'
// #define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int h,m,q; cin >> h >> m >> q;
    vector<int> ids(h,-1),ps(h,-1);
    int k1 = 0, k2 = 0;

    for(int i = 0; i < h; i ++){ //环号，点号
        if(ids[i] == -1){
            k2 = 0;
            while(ids[i] == -1){
                ids[i] = k1;
                ps[i] = k2;
                k2 ++;
                i = (i + m) % h;
            }
            k1 ++;
        }
    }

    vector<set<int>> g(k1);
    map<int,int> mp;
    for(int i = 0; i < k1; i ++){
        for(int j = 0; j < k2; j ++){
            g[i].emplace(j);
        }
    }

    long long ans = 0;
    while(q --){
        char op; cin >> op;
        if(op == '+'){
            int id,hsh; cin >> id >> hsh;

            int o_id = ids[hsh], o_p = ps[hsh];
            int ne_p = 0;
            if(*g[o_id].rbegin() >= o_p){
                ne_p = *g[o_id].lower_bound(o_p);
            } else {
                ne_p = *g[o_id].begin();
            }

            ans += (ne_p - o_p + k2) % k2;

            g[o_id].erase(ne_p);
            mp[id] = o_id * k2 + ne_p;   
        } else {
            int id; cin >> id;
            int o_id = mp[id] / k2, o_p = mp[id] % k2;
            g[o_id].emplace(o_p);
        }
    } 
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
