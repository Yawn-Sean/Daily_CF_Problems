/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=1e9;

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];

    auto check=[&](int l,int r){
        std::array<int,2> idx={-1,-1};
        for(int i=l;i<=r;i++){
            if(a[i]!=-1){
                if(idx[0]==-1) idx[0]=i;
                else if(idx[1]==-1) idx[1]=i;
                else break;
            }
        }
        if(idx[1]==-1) return 1;
        int dlt=a[idx[1]]-a[idx[0]];
        if(dlt%(idx[1]-idx[0])) return 0;
        dlt/=(idx[1]-idx[0]);
        i64 st=(i64)a[idx[1]]-1ll*dlt*(idx[1]-l);
        i64 ed=(i64)a[idx[0]]+1ll*dlt*(r-idx[0]);
        if(st<=0 or ed<=0) return 0;
        for(int i=l;i<=r;i++){
            if(a[i]==-1) continue;
            i64 v=st+1ll*(i-l)*dlt;
            if(a[i]!=v) return 0;
        }
        return 1;
    };

    int res=0;

    for(int i=1;i<=n;i++){
        int cnt=0;
        while(cnt<=20) {
            int t=i+(1<<cnt)-1;
            if(t>=n) break;
            if(check(i,t)) cnt++;
            else break;
        }
        
        int l=i,r=std::min(n,i+(1<<cnt)-1);
        while(l<r){
            int mid=(l+r+1)/2;
            if(check(i,mid)) l=mid;
            else r=mid-1;
        }
        i=l;
        res++;
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
