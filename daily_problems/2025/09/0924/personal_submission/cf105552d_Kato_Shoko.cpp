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
    int n;
    double r;
    cin>>n>>r;
    double d=DBL_MAX;
    for(int i=0;i<n;i++){
        double a,b,c;
        cin>>a>>b>>c;
        double x=sqrtl(a*a+b*b);
        double y=fabs(c)/x;
        d=min(d,y);
    } 
    double ratio=d/r;
    double s=r*r*acos(ratio)-d*sqrtl(max(0.0,r*r-d*d));
    double sum=PI*r*r;
    double ans=s/sum;
    cout<<fixed<<setprecision(12)<<ans<<" "<<1-ans;
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
