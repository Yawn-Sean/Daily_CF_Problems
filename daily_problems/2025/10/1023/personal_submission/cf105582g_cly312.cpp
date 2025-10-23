#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,a,b;
    cin>>n>>a>>b;
    vector<pair<ll,ll>> g(n);
    for(auto &[g1,g2]:g) cin>>g1>>g2;
    int L=n/2,R=n-L;
    unordered_map<ll,ll> l,r;
    for(int m=0;m<(1<<L);m++){
        ll s=0,t=0;
        for(int i=0;i<L;i++) if(m>>i&1){
            s+=g[i].first;
            t+=g[i].second;
        }
        l[b*s-a*t]++;
    }
    for(int m=0;m<(1<<R);m++){
        ll s=0,t=0;
        for(int i=0;i<R;i++) if(m>>i&1){
            s+=g[L+i].first;
            t+=g[L+i].second;
        }
        r[b*s-a*t]++;
    }
    ll ans=-1;
    for(auto &[k,v]:l) ans+=v*r[-k];
    cout<<ans;
}
