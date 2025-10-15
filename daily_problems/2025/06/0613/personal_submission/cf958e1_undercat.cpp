#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve() {
    int n,k;cin>>n>>k;
    vector<pair<int,int>>a(n),b(k);
    for(auto&[x,y]:a)cin>>x>>y;
    for(auto&[x,y]:b)cin>>x>>y;
    
    if(n!=k)cout<<"No\n";
    else cout<<"Yes\n";
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--) 
        solve();
}