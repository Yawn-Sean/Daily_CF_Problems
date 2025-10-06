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
    ll n;
    cin>>n;
    if(n==1){
        cout<<"N";
        return ;
    }
    ll x=n;
    vector<pair<ll,ll>>fac;
    for(ll p=2;p*p<=x;p++){
        if(x%p)continue;
        int cnt=0;
        while(x%p==0){
            cnt++;
            x/=p;
        }
        fac.push_back({p,cnt});
    }
    if(x>1)fac.push_back({x,1});
    
    if(fac.size()==1){
        auto [x,y]=fac.back();
        cout<<(y&1?"Y":"N");
    }else if(fac.size()==2){
        if(fac[0].second==1&&fac[1].second==1){
            cout<<"Y";
        }else{
            cout<<"N";
        }
    }else{
        cout<<"N";
    }
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
