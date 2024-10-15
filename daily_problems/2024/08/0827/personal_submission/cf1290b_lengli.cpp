/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    std::string s;
    std::cin>>s;
    int q;
    std::cin>>q;
    int n=s.size();
    std::vector<std::vector<int>> f(26,std::vector<int> (n+2,0));
    for(int i=1;i<=n;i++){
        int t=s[i-1]-'a';
        f[t][i]=1;
    }
    for(int i=0;i<26;i++)
        for(int j=1;j<=n;j++) f[i][j]+=f[i][j-1];
    while(q--){
        int l,r;
        std::cin>>l>>r;
        int cnt=0;
        for(int i=0;i<26;i++) cnt+=(f[i][r]-f[i][l-1]>0);
        if(l==r) std::cout<<"Yes"<<"\n";
        else if(s[l-1]!=s[r-1]) std::cout<<"Yes"<<"\n";
        else if(cnt>=3) std::cout<<"Yes"<<"\n";
        else std::cout<<"No"<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
