/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

#define int long long

void solve(){
    int n,l,r;
    std::cin>>n>>l>>r;

    auto get=[&](auto self,int x)->int{
        if(x<=1) return 1;
        int len=1;
        return len+2*self(self,x/2);
    };

    auto dfs=[&](auto self,int x,int l,int r)->int{
        if(x<=1) return x==1;
        auto len=get(get,x/2);
        int ans=x&1;
        if(l<=len and r<=len) ans=self(self,x/2,l,r);
        else if(l<=len){
            ans+=self(self,x/2,l,len);
            if(r>len+1) ans+=self(self,x/2,1,r-(len+1));
        }else{
            ans=(l==len+1 ? x&1 : 0); 
            if(r>len+1) ans+=self(self,x/2,l-(len+1),r-(len+1));
        }
        return ans;
    };

    std::cout<<dfs(dfs,n,l,r);
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
