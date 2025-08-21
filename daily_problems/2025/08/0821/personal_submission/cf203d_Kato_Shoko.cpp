#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e6 + 5, mod = 1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    double a,b,m,vx,vy,vz;
    cin>>a>>b>>m>>vx>>vy>>vz;
    vy=fabs(vy);
    double t=m/vy;

    double dx=fabs(vx*t),dz=fabs(vz*t);
    
    ll cntz=dz/(2*b);
    dz-=cntz*2*b;
    double z;
    if(dz>b){
        z=2*b-dz;
    }else{
        z=dz;
    }

    ll cntx=dx/(2*a);
    dx-=cntx*2*a;
    double x;
    if(vx<0){
        if(dx>=a){
            x=dx-a+a/2;
        }else{
            if(dx>=a/2){
                x=dx-a/2;
            }else{
                x=a/2-dx;
            }
        }
    }else{
        if(dx>=a){
            x=a/2-(dx-a);
        }else{
            if(dx>=a/2){
                x=a-(dx-a/2);
            }else{
                x=a/2+dx;
            }
        }
    }
    cout<<fixed<<setprecision(6)<<fabs(x)<<" "<<fabs(z);
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
