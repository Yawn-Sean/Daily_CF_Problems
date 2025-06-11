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
    std::vector<std::vector<char>> a(n,std::vector<char> (m));
    for(auto &x:a) for(auto &y:x) std::cin>>y;

    std::vector<std::vector<int>> b(n,std::vector<int> (m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(a[i][j]=='.') b[i][j]=0;
            else if(i==0 or j==0) b[i][j]=1;
            else b[i][j]=std::min(b[i-1][j-1],std::min(b[i-1][j],b[i][j-1]))+1;
        }
    int l=0,r=1e6;

    std::vector<std::vector<int>> c(n,std::vector<int> (m,0));

    auto check=[&](int tm){
        int x=2*tm+1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[i][j]>=x) c[i][j]=x;
                else c[i][j]=0;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i>0) c[i-1][j]=std::max(c[i-1][j],c[i][j]-1);
                if(j>0) c[i][j-1]=std::max(c[i][j-1],c[i][j]-1);
                if(i>0 and j>0) c[i-1][j-1]=std::max(c[i-1][j-1],c[i][j]-1);
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(b[i][j]!=0 and c[i][j]==0) return 0;
            }
        return 1;
    };

    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    std::cout<<l<<"\n";
    int x=2*l+1;
    std::vector<std::vector<char>> res(n,std::vector<char> (m,'.'));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(b[i][j]>=x) res[i-l][j-l]='X';
        }
    }
    for(auto x:res){
        for(auto y:x) std::cout<<y;
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
