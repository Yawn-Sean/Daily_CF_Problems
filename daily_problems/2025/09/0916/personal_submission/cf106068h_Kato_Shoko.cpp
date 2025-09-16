#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e5 + 5, mod = 998244353, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int q;
    cin>>q;
    
    ll m=1000;
    if(n>=2*m){
        while(q--){
            int op;
            cin>>op;
            if(op==1){
                int i,val;
                cin>>i>>val;
                a[i]=val;
            }else{
                int i;
                cin>>i;
                cout<<(i>m?i-m:i+m)<<'\n';
            }
        }
    }else{
        while(q--){
            int op;
            cin>>op;
            if(op==1){
                int i,val;
                cin>>i>>val;
                a[i]=val;
            }else{
                ll i;
                cin>>i;
                ll ans=-1;
                for(ll j=1;j<=n;j++){
                    ll d=llabs(i-j);
                    d=d*d*d;
                    if(d>=a[j]){
                        ans=j;
                        break;
                    }
                }
                cout<<ans<<'\n';
            }
        }
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
