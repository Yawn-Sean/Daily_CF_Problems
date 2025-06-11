/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long

void solve(){
    int n,k;
    std::cin>>n>>k;
    std::vector<int> a(n+2),b(n+2,0);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    sort(a.begin()+1,a.begin()+n+1);
    for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];

    int res=-1,ans=-1;
    for(int i=1;i<=n;i++){
        int l=1,r=i;

        auto check=[&](int x){
            int sum=b[i]-b[x-1];
            if((i-x+1)*a[i]-sum<=k) return 1;
            return 0;
        };

        while(l<r){
            int mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        if(check(r)) {
            int len=i-r+1;
            if(len>res) res=len,ans=a[i];
        }
    }
    std::cout<<res<<" "<<ans<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
