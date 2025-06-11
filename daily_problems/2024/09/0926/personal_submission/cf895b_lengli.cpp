/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,x,k;
    std::cin>>n>>x>>k;
    std::vector<int> a(n);
    for(int i=0;i<n;i++) std::cin>>a[i];
    sort(all(a));

    auto get=[&](int l,int r){
        int res=r/x-(l-1)/x;
        return res;
    };

    std::vector<int> f(n);
    f[n-1]=n-1;
    for(int i=n-2;i>=0;i--){
        if(a[i]==a[i+1]) f[i]=f[i+1];
        else f[i]=i;
    }
    
    auto getl=[&](int idx){
        int l=0,r=f[idx];
        while(l<r){
            int mid=(l+r)/2;
            if(get(a[mid],a[idx])<=k) r=mid;
            else l=mid+1;
        }
        return r;
    };

    auto getr=[&](int idx){
        int l=0,r=f[idx];
        while(l<r){
            int mid=(l+r+1)/2;
            if(get(a[mid],a[idx])>=k) l=mid;
            else r=mid-1;
        }
        return l;
    };

    long long res=0;
    for(int i=0;i<n;i++){
        int L=getl(i),R=getr(i);
        if(get(a[L],a[i])==k) res+=R-L+1;
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
