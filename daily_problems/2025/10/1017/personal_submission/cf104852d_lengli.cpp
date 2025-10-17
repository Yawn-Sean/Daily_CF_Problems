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
    std::set<i64> s;

    
    for(int i=0;i<(1<<10);i++){
        if(__builtin_popcount(i)!=2) continue;
        std::vector<int> mask;
        for(int j=0;j<10;j++){
            if(i>>j&1) mask.pb(j);
        }

        auto dfs=[&](auto self,i64 val)->void{
            s.insert(val);
            if(val>1000000000) return;
            if(val){
                for(auto v:mask) self(self,val*10+v);
            }else{ 
                for(auto v:mask) if(v) self(self,val*10+v);
            }
        };

        dfs(dfs,0);
    }

    int res=0,cnt=0;

    for(auto x:s){
        if(s.count(n-x)){
            if(n==2ll*x){
                res++;
            }else{
                cnt++;
            }
        }
    }

    std::cout<<cnt/2+res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
