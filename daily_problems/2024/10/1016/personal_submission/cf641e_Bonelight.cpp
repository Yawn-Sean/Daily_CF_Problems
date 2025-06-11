/*
    Bonelight * v *
    20241014：CF,Goodnight
    No Coding , No Bug
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

class Fenwick{
    public:
        int n; vector<int> tr;
        Fenwick(){}
        Fenwick(int n_): n(n_),tr(n+1) {}
        void add(int x, int v){
            for(int i = x; i <= n; i += i & -i) tr[i] += v;
        }
        int query(int x){
            int res = 0;
            for(int i = x; i >= 1; i -= i & -i) res += tr[i];
            return res;
        }
};

void solve(){
    int n; cin >> n;
    map<int,vector<array<int,3>>> mp;
    for(int i = 0; i < n; i ++){
        int a,t,x; cin >> a >> t >> x;
        mp[x].push_back({a,t,i});
    }

    vector<int> ans(n + 1, -INF);
    for(auto &[x,y]:mp){
        vector<int> times;
        for(auto uni:y) times.push_back(uni[1]);
        sort(begin(times),end(times));

        Fenwick tr(times.size());

        for(auto uni:y){
            int idx = lower_bound(begin(times),end(times),uni[1]) - times.begin() + 1;
            if(uni[0] == 1) tr.add(idx, 1);
            else if(uni[0] == 2) tr.add(idx, -1);
            else ans[uni[2]] = tr.query(idx);
        }
    }

    for(auto i:ans){
        if(i != -INF) cout << i << endl; 
    }
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
