#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e5 + 5, mod =1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    ll n,a,b;
    cin>>n>>a>>b;
    int len1=n/2,len2=n-len1;
    
    vector<pair<ll,ll>>p(len1),q(len2);

    for(auto &[x,y]:p){
        cin>>x>>y;
    }
    for(auto &[x,y]:q){
        cin>>x>>y;
    }

    map<ll,ll>mp;
    for(int mask=0;mask<1<<len1;mask++){
        ll x=0,y=0;
        for(int i=0;i<len1;i++){
            if((mask>>i)&1){
                x+=p[i].first;
                y+=p[i].second;
            }
        }
        mp[x*b-y*a]++;
    }

    ll ans=0;
    for(int mask=0;mask<1<<len2;mask++){
        ll x=0,y=0;
        for(int i=0;i<len2;i++){
            if((mask>>i)&1){
                x+=q[i].first;
                y+=q[i].second;
            }
        }
        ans+=mp[y*a-x*b];
    }
    cout<<--ans;
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
