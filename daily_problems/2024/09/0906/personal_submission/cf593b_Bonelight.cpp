#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define pii pair<int,int>

void solve(){
    ll n,x1,x2; cin>>n>>x1>>x2;
    vector<pii> v;
    for(int i=1; i<=n; i++)
    {
        int k,b; cin>>k>>b;
        v.push_back({k*x1+b, k*x2+b});
    }
    sort(v.begin(),v.end());
    ll mab=-2e18;
    for (auto p : v)
    {
        ll b=p.second;
        if(b<mab)
        {
            cout<<"YES\n";
            return;
        }
        else
        {
            mab=b;
        }
    }
    cout<<"NO\n";
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
