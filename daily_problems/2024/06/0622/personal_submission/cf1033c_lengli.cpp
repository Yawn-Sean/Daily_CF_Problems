/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    std::vector<int> sg(n+2,-1);

    auto dfs=[&](auto self,int idx)->int{
        if(sg[idx]!=-1) return sg[idx];
        int flag=0,st=0;
        int d=a[idx];
        for(int i=idx+d;i<=n;i+=d) {
            if(a[i]<=a[idx]) continue;
            st++;
            flag+=self(self,i);
        }
        for(int i=idx-d;i>=1;i-=d) {
            if(a[i]<=a[idx]) continue;
            st++;
            flag+=self(self,i);
        }
        if(st){
            if(flag==st) sg[idx]=0;
            else sg[idx]=1;
        }else sg[idx]=0;
        return sg[idx];
    };
    for(int i=1;i<=n;i++){
        if(sg[i]==-1) dfs(dfs,i);
    }
    for(int i=1;i<=n;i++){
        std::cout<<(sg[i] ? "A" : "B");
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
