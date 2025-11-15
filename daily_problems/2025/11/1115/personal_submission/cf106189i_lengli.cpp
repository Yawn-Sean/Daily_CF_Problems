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
    std::vector<std::vector<int>> f(n+2,std::vector<int> (n+2,0));

    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            f[l][r]=f[l+1][r-1];
            if(a[l]%a[r]==0 or a[r]%a[l]==0) f[l][r]+=2;
            for(int t=l;t<r;t++){
                f[l][r]=std::max(f[l][r],f[l][t]+f[t+1][r]);
            }
        }
    }

    std::vector<int> st(n+2);

    auto dfs=[&](auto self,int l,int r)->void{
        if(l>=r) return;
        for(int t=l;t<r;t++){
            if(f[l][r]==f[l][t]+f[t+1][r]){
                self(self,l,t);
                self(self,t+1,r);
                return;
            }
        }
        if(a[l]%a[r]==0 or a[r]%a[l]==0){
            st[l]=1,st[r]=1;
        }
        self(self,l+1,r-1);
    };

    dfs(dfs,1,n);

    std::vector<int> out;
    for(int i=1;i<=n;i++){
        if(!st[i]) out.pb(i);
    }
    std::cout<<out.size()<<"\n";
    for(auto x:out) std::cout<<x<<" ";
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
