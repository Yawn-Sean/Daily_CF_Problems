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
    int n=s.size();
    int idx=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='B') idx=i;
    }
    if(idx==-1){
        std::cout<<1<<"\n";
        return;
    }
    std::string b="B";
    for(int i=0;i<n;i++) b+=s[(i+idx)%n];

    auto cal=[&](int x){
        std::vector<std::vector<i64>> f(n+2,std::vector<i64> (2,0));
        f[0][x]=1;
        for(int i=0;i<n;i++){
            if(b[i+1]=='B'){
                f[i+1][0]=f[i][0];
            }else if(b[i]=='A'){
                f[i+1][1]=f[i][0]+f[i][1];
                f[i+1][0]=0;
            }else{
                f[i+1][1]=f[i][0]+f[i][1];
                f[i+1][0]=f[i-1][0]+f[i-1][1];
            }
        }
        return f[n][x];
    };

    std::cout<<cal(0)+cal(1)<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
