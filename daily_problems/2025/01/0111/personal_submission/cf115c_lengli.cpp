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
    int n,m;
    std::cin>>n>>m;
    std::vector<int> r(n,-1),c(m,-1);
    std::vector<int> dx={-1,0,1,1,0};
    std::vector<int> dy={-1,0,0,1,1};

    int cnt=n+m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            std::cin>>ch;
            if(ch!='.'){
                ch=ch-'0';
                int x=dy[ch]^(j&1);
                int y=dx[ch]^(i&1);
                if(r[i]==-1) r[i]=x,cnt--;
                else if(r[i]!=x){
                    std::cout<<0<<"\n";
                    return;
                }
                if(c[j]==-1) c[j]=y,cnt--;
                else if(c[j]!=y){
                    std::cout<<0<<"\n";
                    return;
                }
            }
        }
    }

    i64 res=1,mod=1000003;
    for(int i=0;i<cnt;i++){
        res=(res*2)%mod;
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
