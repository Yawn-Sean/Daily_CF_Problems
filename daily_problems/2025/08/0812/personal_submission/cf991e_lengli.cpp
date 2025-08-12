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
    std::string s;
    std::cin>>s;
    std::vector<int> cnt(10,0);
    for(auto x:s){
        cnt[x-'0']++;
    }

    std::vector<i64> f(20,1);
    for(int i=1;i<20;i++) f[i]=i*f[i-1];

    std::vector<int> q(10,0);

    i64 res=0;

    auto dfs=[&](auto self,int pos)->void{
        if(pos==10){
            i64 ans=1,k=1,t=0;
            for(int i=0;i<10;i++){
                k*=f[q[i]];
                t+=q[i];
            }  
            ans=f[t]/k;
            if(q[0]>=1){
                i64 p=f[t-1];
                p/=f[q[0]-1];
                for(int i=1;i<10;i++){
                    p/=f[q[i]];
                }
                ans-=p;
            }
            res+=ans;
            return;

        }
        for(int i=1;i<=cnt[pos];i++){
            q[pos]=i;
            self(self,pos+1);
        }
        if(!cnt[pos]) self(self,pos+1);
    };

    dfs(dfs,0);

    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
