#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e5 + 5, mod = 1e9+7, inf = 1e18;
const double esp=1e-3;
double PI=3.1415926;

il void solve(){
    int n,m;
    cin>>n>>m;
    //最大子段段和，最大前缀，最大后缀,和
    vector<ll>sum(n+1),per(n+1,-inf),suf(n+1,-inf),total(n+1);

    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        vector<ll>a(k+1);
        ll ans=-inf,res=0;
        for(int j=1;j<=k;j++){
            cin>>a[j];
            if(j==1) res=a[j];
            else res=max(res+a[j],a[j]);
            ans=max(ans,res);
        }
        sum[i]=ans;

        ll tot=0;
        for(int j=1;j<=k;j++){
            tot+=a[j];
            per[i]=max(per[i],tot);
        }
        total[i]=tot;
        tot=0;
        for(int j=k;j>=1;j--){
            tot+=a[j];
            suf[i]=max(suf[i],tot);
        }
    }

    ll cur_suf=-inf,ans=-inf;
    while(m--){
        int idx;
        cin>>idx;
        ans=max(ans,sum[idx]);
        ans=max(ans,cur_suf+per[idx]);
        cur_suf=max(cur_suf+total[idx],suf[idx]);
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
