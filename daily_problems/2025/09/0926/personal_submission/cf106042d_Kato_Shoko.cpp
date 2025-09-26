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
    ll n,x,y;
    cin>>n>>x>>y;
    vector<ll>a(n);
    for(auto &i:a)cin>>i;
    ll sum=accumulate(a.begin(),a.end(),0ll);

    vector<ll>d(n);
    for(int i=0;i<n;i++)d[i]=(a[i]&y)-a[i];

    ll max1=-inf,max2=-inf;
    int idx1=-1,cnt_max1=0;

    for(int i=0;i<n;i++){
        if(d[i]>max1){
            max2=max1;
            max1=d[i];
            idx1=i;
            cnt_max1=1;
        }else if(d[i]==max1){
            cnt_max1++;
        }else if(d[i]>max2){
            max2=d[i];
        }
    }

    if(n==1){
        max2=-inf/4;
    }else if(max2==-inf){
        max2=-inf/4;
    }

    ll ans=inf;
    for(int i=0;i<n;i++){
        ll ai=a[i],ai_or=a[i]|x;
        ll gain=ai_or-ai;
        ll di=(ai_or&y)-ai_or;

        ll best=max1;
        if(i==idx1&&cnt_max1==1)best=max2;
        ll del=max(best,di);
        ll res=sum+gain+del;
        ans=min(ans,res);
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
