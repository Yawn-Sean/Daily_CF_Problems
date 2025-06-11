/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

using i64=long long;

void solve(){
    i64 h,n;
    std::cin>>h>>n;
    
    i64 res=0;

    auto dfs=[&](auto self,i64 high,i64 k,int flag)->void{
        res++;
        if(high==0) return;
        i64 cnt=(1ll<<(high-1));
        i64 sum=(1ll<<high)-1;
        
        if(k<=cnt){
            if(flag){
                res+=sum;
                self(self,high-1,k,1);
                return;
            }else{
                self(self,high-1,k,1);
                return;
            }
        }else{
            if(!flag){
                res+=sum;
                self(self,high-1,k-cnt,0);
                return;
            }else{
                self(self,high-1,k-cnt,0);
                return;
            }
        }
        return;
    };

    dfs(dfs,h,n,0);

    std::cout<<res-1<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
