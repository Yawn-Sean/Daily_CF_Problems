/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

void solve(){
    int a,b,c;
    i64 k;
    std::cin>>a>>b>>c>>k;

    int la=1,lb=1,lc=1;
    for(int i=2;i<=a;i++) la*=10;
    for(int i=2;i<=b;i++) lb*=10;
    for(int i=2;i<=c;i++) lc*=10;

    auto getl=[&](int x,int vl,int vr,int limit){
        int l=vl,r=vr;
        while(l<r){
            int mid=(l+r)/2;
            if(x+mid>=limit) r=mid;
            else l=mid+1;
        }
        return x+r>=limit ? r : -1;
    };

    auto getr=[&](int x,int vl,int vr,int limit){
        int l=vl,r=vr;
        while(l<r){
            int mid=(l+r+1)/2;
            if(x+mid<=limit) l=mid;
            else r=mid-1;
        }
        return x+l<=limit ? l : -1;
    };

    i64 sum=0;

    for(int i=la;i<la*10;i++){
        int l=getl(i,lb,lb*10-1,lc);
        int r=getr(i,lb,lb*10-1,lc*10-1);
        if(i+l>=lc and i+r<=lc*10-1){
            int hv=r-l+1;
            if(sum+hv<k){
                sum+=hv;
                continue;
            }else{
                int cnt=k-sum;
                std::cout<<i<<" + "<<l+cnt-1<<" = "<<i+l+cnt-1<<"\n";
                return;
            }
        }
    }
    std::cout<<"-1"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
