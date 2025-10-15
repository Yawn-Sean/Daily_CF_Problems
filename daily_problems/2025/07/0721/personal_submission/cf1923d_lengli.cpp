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
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    std::vector<i64> same(n+2),sum(n+2);
    for(int i=1;i<=n;i++){
        same[i]=same[i-1];
        sum[i]=sum[i-1]+a[i];
        if(a[i]!=a[i-1]) same[i]++;
    }

    std::vector<int> L(n+2,-1),R(n+2,-1);
    for(int i=2;i<=n;i++){
        int l=1,r=i-1;

        auto check=[&](int ll,int rr)->bool{
            if(ll!=rr and !(same[rr]-same[ll])) return 0;
            if(sum[rr]-sum[ll-1]>a[i]) return 1;
            return 0;
        };

        while(l<r){
            int mid=(l+r+1)/2;
            if(check(mid,i-1)) l=mid;
            else r=mid-1;
        }
        if(a[i-1]>a[i]) l=i-1;
        if(check(l,i-1)) L[i]=l;
    }

    for(int i=n-1;i>=1;i--){
        int l=i+1,r=n;

        auto check=[&](int ll,int rr)->bool{
            if(ll!=rr and !(same[rr]-same[ll])) return 0;
            if(sum[rr]-sum[ll-1]>a[i]) return 1;
            return 0;
        };

        while(l<r){
            int mid=(l+r)/2;
            if(check(i+1,mid)) r=mid;
            else l=mid+1;
        }
        if(a[i+1]>a[i]) r=i+1;
        if(check(i+1,r)) R[i]=r;
    }


    for(int i=1;i<=n;i++){
        if(L[i]==-1 and R[i]==-1) std::cout<<"-1"<<" ";
        else if(L[i]==-1) std::cout<<R[i]-i<<" ";
        else if(R[i]==-1) std::cout<<i-L[i]<<" ";
        else std::cout<<std::min(R[i]-i,i-L[i])<<" "; 
    }std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
