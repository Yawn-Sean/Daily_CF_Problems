#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long LL;

void solve(){
    int n,k;cin>>n>>k;
    std::vector<int>a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    LL ans=0;
    for(int i=1;i<n;i++){
        ans+=abs(a[i+1]-a[i]);
    }
    int mn=*min_element(a.begin()+1,a.end());
    int mx=*max_element(a.begin()+1,a.end());
    if(mn>1){
        int res=min(a[1]-1,a[n]-1);
        for(int i=2;i<=n;i++){
            res=min(res,a[i-1]+a[i]-2-abs(a[i]-a[i-1]));
        }
        ans+=res;
    }

    if(mx<k){
        int res=min(k-a[1],k-a[n]);
        for(int i=2;i<=n;i++){
            res=min(res,k-a[i]+k-a[i-1]-abs(a[i]-a[i-1]));
        }
        ans+=res;
    }
    cout<<ans<<"\n";

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;cin>>tt;
    while(tt--)
        solve();
    return 0;
}
