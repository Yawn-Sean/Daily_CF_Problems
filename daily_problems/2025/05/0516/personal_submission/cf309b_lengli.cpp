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
    int n,r,c;
    std::cin>>n>>r>>c;
    std::vector<std::string> s(n);
    for(auto &x:s) std::cin>>x;

    std::vector<int> ne(n,-1);

    for(int i=0,j=-1,len=0;i<n;i++){
        if(s[i].size()>c){
            j=i;
            len=0;
            continue;
        }
        while(j+1<n and len+s[j+1].size()+j+1-i<=c){
            len+=s[j+1].size();
            j++;
        }
        ne[i]=j+1;
        len-=s[i].size();
    }

    //for(int i=0;i<n;i++) std::cout<<ne[i]<<" ";

    std::vector<std::vector<int>> eg(n+2);

    for(int i=0;i<n;i++){
        if(ne[i]!=-1){
            int u=i,v=ne[i];
            eg[u].pb(v);
            eg[v].pb(u);
        }
    }

    std::vector<int> path;

    int st=-1;
    int cnt=0;

    std::vector<int> flag(n+2);

    auto dfs=[&](auto self,int u,int fa)->void{
        path.pb(u);
        flag[u]=1;
        int len=path.size();
        {
            int t=path[std::max(len-r-1,0)];
            int k=t-path.back();
            if(k>cnt){
                cnt=k;
                st=path.back();
            }
        }
        for(auto x:eg[u]){
            if(x==fa) continue;
            self(self,x,u);
        }
        path.pop_back();
    };

    for(int i=n;i>=0;i--){
        if(flag[i]) continue;
        if(eg[i].empty()) continue;
        dfs(dfs,i,-1);
    }

    if(st==-1) return;

    std::vector<std::string> res;
    std::string tmp="";
    for(int i=st;i<st+cnt;i++){
        if(tmp.size()+s[i].size()<=c){
            tmp+=s[i];
        }else{
            tmp.pop_back();
            res.pb(tmp);
            tmp=s[i];
        }
        tmp+=" ";
    }
    tmp.pop_back();
    res.pb(tmp);
    
    for(auto x:res) std::cout<<x<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
