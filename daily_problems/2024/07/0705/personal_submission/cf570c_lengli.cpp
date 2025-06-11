/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::string s;
    std::cin>>s;
    int res=0;
    for(int i=1;i<n;i++){
        if(s[i]=='.' and s[i-1]=='.') res++;
    }
    for(int i=1;i<=m;i++){
        int x;
        char c;
        std::cin>>x>>c;
        x--;
        if(s[x]=='.' and c=='.') {
            std::cout<<res<<"\n";
        }else if(islower(s[x]) and islower(c)){
            s[x]=c;
            std::cout<<res<<"\n";
        }else if(c=='.'){
            int flag=(x-1>=0 and s[x-1]=='.') + (x+1<n and s[x+1]=='.');
            res+=flag;
            s[x]=c;
            std::cout<<res<<"\n";
        }else{
            int flag=(x-1>=0 and s[x-1]=='.') + (x+1<n and s[x+1]=='.');
            res-=flag;
            s[x]=c;
            std::cout<<res<<"\n";
        }
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
