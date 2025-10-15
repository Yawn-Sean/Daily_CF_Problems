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
    std::string s;
    std::cin>>s;
    std::vector<int> f(n+2,1);
    for(int i=1;i<n;i++){
        char c=s[i-1];
        if(c=='=') f[i]=f[i-1];
        else if(c=='R') f[i]=f[i-1]+1;
        else{
            f[i]=1;
            if(f[i-1]==1){
                f[i-1]=2;
                for(int j=i-1;j>=1;j--){
                    char v=s[j-1];
                    if(v=='=') f[j-1]=f[j];
                    else if(v=='L' and f[j-1]==f[j]) f[j-1]+=1;
                    else break;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        std::cout<<f[i]<<" ";
    }
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
