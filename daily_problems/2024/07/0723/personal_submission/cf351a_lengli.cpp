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
    std::vector<std::array<int,2>> q(n*2+2);
    for(int i=1;i<=n*2;i++){
        int a,b;
        char c;
        std::cin>>a>>c>>b;
        q[i]={b,1000-b==1000 ? 0 : 1000-b};
    }
    std::vector<std::vector<int>> f(n*2+2,std::vector<int> (n+2,1e9));
    f[0][0]=0;
    for(int i=1;i<=n*2;i++){
        for(int j=0;j<=std::min(n,i);j++){
            if(!j) f[i][j]=f[i-1][j]-q[i][0];
            else{
                int l=f[i-1][j]-q[i][0];
                int r=f[i-1][j-1]+q[i][1];
                if(abs(l)<abs(r)) f[i][j]=l;
                else f[i][j]=r;
            }
        }
    }
    int res=abs(f[n*2][n]);
    if(res<1000){
        std::cout<<"0."<<std::setw(3)<<std::setfill('0')<<res<<"\n";
    }else{
        int l=res/1000,r=res%1000;
        std::cout<<l<<"."<<std::setw(3)<<std::setfill('0')<<r<<"\n";
    }
    
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
