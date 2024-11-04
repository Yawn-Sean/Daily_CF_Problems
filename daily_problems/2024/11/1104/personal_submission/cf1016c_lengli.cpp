/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

using i64=long long;

constexpr int N=1000010;

i64 n;
i64 a[N],b[N];
i64 al[N],ar[N],bl[N],br[N];
i64 sal[N],sar[N],sbl[N],sbr[N];

i64 get(int l,int r,bool flag){
    i64 res=0,sum=0;
    if(!flag){
        i64 val_a=sal[r]-sal[l-1];
        i64 sum_a=al[r]-al[l-1];
        val_a-=1ll*(l-1)*sum_a;
        i64 val_b=sbr[l]-sbr[r+1];
        i64 sum_b=br[l]-br[r+1];
        val_b+=1ll*(r-l+1)*sum_b;
        res=val_a+val_b;
        sum=sum_a+sum_b;
    }else{
        i64 val_b=sbl[r]-sbl[l-1];
        i64 sum_b=bl[r]-bl[l-1];
        val_b-=1ll*(l-1)*sum_b;
        i64 val_a=sar[l]-sar[r+1];
        i64 sum_a=ar[l]-ar[r+1];
        val_a+=1ll*(r-l+1)*sum_a;
        res=val_a+val_b;
        sum=sum_a+sum_b;
    }
    res+=2ll*(l-1)*sum;
    return res;
}

void solve(){
    std::cin>>n;
    for(int i=1;i<=n;i++) std::cin>>a[i];
    for(int i=1;i<=n;i++) std::cin>>b[i];

    for(int i=1;i<=n;i++){
        sal[i]=sal[i-1]+a[i]*(i-1);
        al[i]=al[i-1]+a[i];
        sbl[i]=sbl[i-1]+b[i]*(i-1);
        bl[i]=bl[i-1]+b[i];
    }
    for(int i=n;i>=1;i--){
        sar[i]=sar[i+1]+a[i]*(n-i);
        ar[i]=ar[i+1]+a[i];
        sbr[i]=sbr[i+1]+b[i]*(n-i);
        br[i]=br[i+1]+b[i];
    }
    i64 flag=0;
    i64 res=0,sum=0;

    for(int i=1;i<=n;i++,flag^=1){
        i64 ans=get(i,n,flag);
        res=std::max(res,ans+sum);
        if(!flag) sum+=2ll*(i-1)*a[i]+2ll*(i-1)*b[i]+b[i];
        else sum+=2ll*(i-1)*a[i]+2ll*(i-1)*b[i]+a[i];
    }
    res=std::max(res,sum);
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
