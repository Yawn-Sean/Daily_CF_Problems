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

    int res=0;

    std::string s;

    std::vector<std::vector<std::string>> v(1000010);

    auto dfs=[&](auto self,int dep)->bool{
        res=std::max(res,dep);
        std::getline(std::cin,s,',');
        if(s=="") return 0;
        v[dep].pb(s);
        int l;
        std::cin>>l;
        std::cin.ignore();
        for(int i=0;i<l;i++){
            self(self,dep+1);
        }
        return 1;
    };

    while(1){
        auto t=dfs(dfs,0);
        if(!t) break;
    }

    std::cout<<res+1<<"\n";
    for(int i=0;i<=res;i++){
        for(int j=0;j<v[i].size();j++){
            std::cout<<v[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
