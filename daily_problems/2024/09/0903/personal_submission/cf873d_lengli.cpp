/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,k;
    std::cin>>n>>k;
    if(k%2==0){
        std::cout<<(-1)<<"\n";
        return;
    }
    std::vector<int> res(n);
    for(int i=0;i<n;i++) res[i]=i+1;

    auto dfs=[&](auto self,int l,int r){
        if(l==r-1) return;
        int mid=(l+r)/2;
        if(k>1){
            k-=2;
            std::swap(res[mid-1],res[mid]);
        }
        self(self,l,mid);
        self(self,mid,r);
    };
    dfs(dfs,0,n);
    if(k==1) for(auto x:res) std::cout<<x<<" ";
    else std::cout<<"-1"<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
