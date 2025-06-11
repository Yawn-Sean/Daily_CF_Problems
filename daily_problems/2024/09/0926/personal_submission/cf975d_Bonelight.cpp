/*
    Bonelight * v *
    20240926：Good morning
    No Coding , No Bug
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n,a,b; cin >> n >> a >> b;
    vector<array<int,3>> g(n); 
    map<int,int> mp;
    map<pii,int> mp2;
    
    int ans = 0;
    for(auto &[x,vx,vy]:g){
        cin >> x >> vx >> vy;
        
        ans += mp[vy - a * vx];
        ans -= mp2[{vx,vy}];

        mp[vy - a * vx] ++;
        mp2[{vx,vy}] ++;
    } 

    cout << ans * 2 << endl;
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
