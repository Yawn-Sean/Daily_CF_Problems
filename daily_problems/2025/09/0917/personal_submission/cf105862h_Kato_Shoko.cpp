#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e5 + 5, mod = 1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

void get_div(ll idx,ll cur,const vector<pair<ll,ll>>&fac,vector<ll>&div){
    if(idx==fac.size()){
        div.push_back(cur);
        return ;
    }
    auto [p,e]=fac[idx];
    for(int i=0;i<=e;i++){
        get_div(idx+1,cur,fac,div);
        cur*=p;
    }
}

il ll quick_mi(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1){
            ans=ans*a%mod;
        }
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}

il void solve(){
    ll n;
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        sum=(sum+x)%mod;
    }
    ll m=n;
    vector<pair<ll,ll>>fac;
    for(ll p=2;p*p<=m;p++){
        if(m%p)continue;
        int cnt=0;
        while(m%p==0){
            cnt++;
            m/=p;
        }
        fac.push_back({p,cnt});
    }
    if(m>1)fac.push_back({m,1});

    vector<ll>div;
    get_div(0,1,fac,div);

    ll s=0;
    for(auto d:div){
        ll phi=d;
        for(auto [p,e]:fac){
            if(d%p==0){
                phi=phi/p*(p-1);
            }
        }
        s=(s+d%mod*phi%mod)%mod;
    }
    ll invn=quick_mi(n,mod-2);
    ll ans=sum*invn%mod*invn%mod*s%mod;
    cout<<ans<<'\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    cin >> t;

    while (t--) {

        solve();

    }

    return 0;
}
