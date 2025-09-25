#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e5 + 5, mod =1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    ll n,k;
    cin>>n>>k;
    ll l=n*k;
    vector<ll>a(l),b(l);
    for(auto &i:a)cin>>i;
    for(auto &i:b)cin>>i;
    vector<vector<int>>pos(n+1);
    for(int i=0;i<l;i++){
        pos[b[i]].push_back(i+1);
    }

    vector<int>seq;
    for(int i=0;i<l;i++){
        auto &v=pos[a[i]];

        for(int j=v.size()-1;j>=0;j--){
            seq.push_back(v[j]);
        }
    }

    vector<int>dp;
    for(auto x:seq){
        auto it=lower_bound(dp.begin(),dp.end(),x);
        if(it==dp.end())dp.push_back(x);
        else *it=x;
    }
    cout<<dp.size()<<'\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    //cin >> t;

    while (t--) {

        solve();

    }

    return 0;
}
