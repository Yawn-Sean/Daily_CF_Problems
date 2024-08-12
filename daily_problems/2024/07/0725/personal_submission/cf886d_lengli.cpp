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
    std::vector<std::string> s(n);
    std::vector<std::vector<int>> eg(26),reg(26);
    std::vector<int> rd(26,0);
    std::vector<int> st(26,1),in(26,0);
    for(auto &x:s) {
        std::cin>>x;
        for(int j=0;j<x.size()-1;j++) {
            eg[x[j]-'a'].pb(x[j+1]-'a');
            reg[x[j+1]-'a'].pb(x[j]-'a');
            rd[x[j+1]-'a']++;
        }
        for(auto c:x) st[c-'a']=0;
    }

    std::vector<std::vector<int>> res;
    bool flag=1;
    auto dfs=[&](auto self,int u,std::vector<int> &q)->void{
        if(in[u] or !flag) {
            flag=0;
            return;
        }
        if(st[u]) return;
        q.pb(u);
        in[u]=1;
        st[u]=1;
        for(auto x:eg[u]){
            self(self,x,q);
        }
        in[u]=0;
    };

    for(int i=0;i<26 and flag;i++){
        if(rd[i]==0 and !st[i]){
            std::vector<int> ans;
            dfs(dfs,i,ans);
            if(flag) res.pb(ans);
        }
    }
    for(int i=0;i<26;i++) {
        if(!st[i]) flag=0;
        sort(all(reg[i]));
        reg[i].erase(unique(all(reg[i])),reg[i].end());
        sort(all(eg[i]));
        eg[i].erase(unique(all(eg[i])),eg[i].end());
        if(reg[i].size()>=2 or eg[i].size()>=2) flag=0;
    }
    if(!flag) std::cout<<"NO"<<"\n";
    else{
        std::vector<std::string> str;
        for(auto x:res){
            std::string s="";
            for(auto y:x) s+=y+'a';
            str.pb(s);
        }
        sort(all(str));
        for(auto x:str) std::cout<<x;
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
