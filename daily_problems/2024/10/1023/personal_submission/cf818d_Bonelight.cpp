/*
    Bonelight * v *
    20241023：CF,Goodnight
    No Coding , No Bug
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n,k; cin >> n >> k;
    map<int,vector<int>> g;
    for(int i = 0; i < n; i ++){
        int co; cin >> co;
        g[co].push_back(i);
    } 

    int cur = 0, cnt = 0;
    for(auto [i,uni]:g) if(i != k && g[i].size() >= g[k].size()){
        int p1 = 0, p2 = 0, ok = 1;
        while(p1 < g[i].size() && p2 < g[k].size()){
            if(g[i][p1] < g[k][p2]) p1 ++;
            else p2 ++;
            if(p1 < p2) {ok = false; break;}
        }
        if(ok) {return void(cout << i << endl);}
    }
    cout << -1 << endl;
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
