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

    std::vector<std::array<int,2>> res;

    std::vector<int> pre(n+2,0),f(n+2,0);

    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            int len=i-j;
            if(f[j]+len*len>f[i]){
                f[i]=f[j]+len*len;
                pre[i]=j;
            }
        }
        if(f[i-1]+a[i]>f[i]){
            f[i]=f[i-1]+a[i];
            pre[i]=i-1;
        }
    }


    auto modify=[&](int l,int r){
        std::set<int> s;
        for(int i=l;i<=r;i++) s.insert(a[i]);
        int mex=0;
        while(s.count(mex)) mex++;
        for(int i=l;i<=r;i++) a[i]=mex;
        res.pb({l,r});
    };
    auto dfs=[&](auto self,int l,int r)->void{
        if(l==r){
            if(a[r]!=0) modify(l,r);
            return;
        }
        int len=r-l+1;
        int target=len-1;
        if(a[l]!=target){
            if(a[l]>target) modify(l,l);
            self(self,l+1,r);
            modify(l,r);
        }
        self(self,l+1,r);
    };

    int idx=n;
    while(idx){
        int l=pre[idx]+1;
        if(l!=idx or a[l]==0){
            dfs(dfs,l,idx);
            modify(l,idx);
        }
        idx=pre[idx];
    }

    std::cout<<f[n]<<" "<<res.size()<<"\n";
    for(auto [l,r]:res) std::cout<<l<<" "<<r<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
