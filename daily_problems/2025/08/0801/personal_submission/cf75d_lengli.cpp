/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr i64 inf=2e18;

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<i64> pre(n,-inf),suf(n,-inf);
    std::vector<i64> sum(n),md(n,-inf);
    i64 res=-inf;

    for(int i=0;i<n;i++){
        int k;
        std::cin>>k;
        std::vector<int> tmp(k);
        for(auto &x:tmp) std::cin>>x;
        i64 cur=0,s=0;
        for(int j=0;j<k;j++){
            cur+=tmp[j];
            s+=tmp[j];
            pre[i]=std::max(pre[i],s);
            md[i]=std::max(md[i],cur);
            if(cur<0) cur=0;
        }
        sum[i]=s;
        s=0;
        for(int j=k-1;j>=0;j--){
            s+=tmp[j];
            suf[i]=std::max(suf[i],s);
        }
    }

    std::vector<int> a(m);
    for(auto &x:a){
        std::cin>>x;
        x--;
    }
    i64 cur=0;
    for(auto &x:a){
        res=std::max(res,md[x]);
        res=std::max(res,cur+pre[x]);
        cur=std::max(cur+sum[x],suf[x]);
        res=std::max(res,cur);
        if(cur<0) cur=0;
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
