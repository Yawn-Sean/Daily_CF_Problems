/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

const int inf=1e9;

void solve(){
    std::string a,b;
    std::cin>>a>>b;
    if(a.size()!=b.size()){
        std::cout<<"-1"<<"\n";
        return;
    }
    std::vector<std::vector<int>> d(30,std::vector<int> (30,inf));
    int m;
    std::cin>>m;
    for(int i=1;i<=m;i++){
        char u,v;
        std::cin>>u>>v;
        int l=u-'a',r=v-'a';
        int w;
        std::cin>>w;
        d[l][r]=std::min(d[l][r],w);
    }
    for(int k=0;k<26;k++){
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(i==j) d[i][j]=0;
                else d[i][j]=std::min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    int res=0;
    for(int i=0;i<a.size();i++){
        int u=a[i]-'a',v=b[i]-'a';
        int ans=inf;
        for(int j=0;j<26;j++){
            if(d[u][j]==inf or d[v][j]==inf) continue;
            if(d[u][j]+d[v][j]<ans){
                ans=d[u][j]+d[v][j];
                a[i]=j+'a';
            }
        }
        if(ans==inf){
            std::cout<<"-1"<<"\n";
            return;
        }
        res+=ans;
    }
    std::cout<<res<<"\n";
    std::cout<<a<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
