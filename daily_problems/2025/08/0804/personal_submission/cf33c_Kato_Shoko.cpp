#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 6e5 + 5, mod = 1e9+7, inf = 1e18;
const double esp=1e-3;
double PI=3.1415926;

il void solve(){
    int n;
    cin>>n;
    vector<ll>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<ll>per(n+1);
    for(int i=1;i<=n;i++){
        per[i]=per[i-1]+a[i];
    }
    vector<ll>suf(n+5);
    for(int i=n;i>=1;i--){
        suf[i]=suf[i+1]+a[i];
    }

    vector<ll>min_suf(n+1,inf);
    min_suf[n]=0;
    for(int i=n-1;i>=0;i--){
        min_suf[i]=min(min_suf[i+1],suf[i+1]);
    }
    
    vector<ll>max_per(n+5,-inf);
    for(int i=n;i>=1;i--){
        max_per[i]=max(per[i],max_per[i+1]);
    }

    ll ans=per[n];

    for(int i=0;i<=n;i++){
        ans=max(ans,per[n]-2*per[i]-2*min_suf[i]);
        if(i)ans=max(ans,per[n]+2*max_per[i]-2*suf[i]-4*per[i-1]);
    }
    cout<<ans;
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
