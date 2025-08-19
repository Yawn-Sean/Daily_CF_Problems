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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll>a(n+1),d(m+1),f(k+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>d[i];
    for(int i=1;i<=k;i++)cin>>f[i];

    ll maxx=0,L=0,R=0,cnt=0;
    for(int i=2;i<=n;i++){
        ll diff=a[i]-a[i-1];
        if(diff>maxx){
            maxx=diff;
            L=a[i-1],R=a[i];
            cnt=1;
        }else if(diff==maxx)cnt++;
    }

    if(maxx==0){
        cout<<0<<'\n';
        return ;
    }
    if(cnt>1){
        cout<<maxx<<'\n';
        return ;
    }

    ll secon=0;
    for(int i=2;i<=n;i++){
        ll diff=a[i]-a[i-1];
        if(diff==maxx)continue;
        secon=max(secon,diff);
    }

    //[L,R]
    sort(d.begin()+1,d.end());
    sort(f.begin()+1,f.end());

    ll mid=(L+R+1)>>1;
    ll ans=maxx;
    for(int i=1;i<=m;i++){
        if(d[i]>=R)break;
        ll add=d[i];
        ll need=mid-add;
        auto it=lower_bound(f.begin()+1,f.end(),need);
        //>mid,<mid,=mid
        if(it==f.end())it--;
        if(*it==need){//已经最优
            ans=min(ans,max({secon,mid-L,R-mid}));
            break;
        }else{
            ll now=add+*it;
            if(now>=L&&now<=R){
                ans=min(ans,max({secon,add+*it-L,R-(add+*it)}));
            }
            if(it!=f.begin()+1){
                it--;
                now=add+*it;
                if(now>=L&&now<=R){
                    ans=min(ans,max({secon,add+*it-L,R-(add+*it)}));
                }
            }
        }
    }
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
