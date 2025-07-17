/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr i64 inf=1e18;

void solve(){
    int n,m,x;
    std::cin>>n>>m>>x;
    std::vector<std::vector<int>> h(n+2,std::vector<int> (m+2));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            std::cin>>c;
            h[i][j]=c-'0';
        }
    }

    auto qmi=[&](int a,int b)->int{
        int res=1;
        while(b){
            if(b&1) res*=a;
            a*=a;
            b>>=1;
        }
        return res;
    };

    auto dis=[&](int xx,int yy,int aa,int bb)->int{
        int l=h[xx][yy],r=h[aa][bb];
        return qmi(l-r,x);
    };

    bool flag=1;
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            int len=dis(i,j,i,j+1)+dis(i,j+1,i+1,j+1)+dis(i+1,j+1,i+1,j)+dis(i+1,j,i,j);
            if(len) flag=0;
        }
    }

    std::vector<std::vector<i64>> d(n+2,std::vector<i64> (m+2,inf));

    d[1][1]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1 and j==1) continue;
            if(i==1) d[i][j]=d[i][j-1]+dis(i,j-1,i,j);
            else d[i][j]=d[i-1][j]+dis(i-1,j,i,j);
        }
    }

    int q;
    std::cin>>q;
    while(q--){
        std::vector<int> qr(4);
        for(auto &x:qr) std::cin>>x;
        if(!flag){
            std::cout<<"INVALID"<<"\n";
            continue;
        }

        std::cout<<d[qr[2]][qr[3]]-d[qr[0]][qr[1]]<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
