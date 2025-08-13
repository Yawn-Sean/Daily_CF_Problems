#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e5 + 5, mod = 998244353, inf = 2e18;
const double esp=1e-3;
double PI=3.1415926;

il void solve(){
    ll t1,t2,x1,x2,t0;
    cin>>t1>>t2>>x1>>x2>>t0;
    ll ans1=0,ans2=x2;
    double best_diff=inf;
    ll maxx=-1;//流量
    
    for(ll y1=0;y1<=x1;y1++){
        ll y2;
        if(t2==t0){
            y2=x2;
        }else{
            ll num=(t0-t1)*y1;
            ll d=t2-t0;
            if(d==0)continue;
            y2=(num+d-1)/d;
        }

        if(y2<0)y2=0;
        if(y2>x2)continue;

        double T=double(t1*y1+t2*y2)/(y1+y2);
        double diff=fabs(T-t0);

        if(diff<best_diff||(fabs(diff-best_diff)<1e-10&&y1+y2>maxx)){
            best_diff=diff;
            maxx=y1+y2;
            ans1=y1;
            ans2=y2;
        }
    }
    cout<<ans1<<" "<<ans2;
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
