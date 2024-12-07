/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,k;
    std::cin>>n>>k;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) {
        std::cin>>a[i];
    }
    std::vector<std::vector<int>> f(n+3,std::vector<int> (n+3,-1));

    std::vector<int> yes(n+2),no(n+2);
    for(int i=n;i>=1;i--){
        if(i==n) yes[i]=0,no[i]=1;
        else{
            if(a[i+1]==100 or yes[i+1]) yes[i]=1;
            else yes[i]=0;
            if(a[i+1]==0 and no[i+1]) no[i]=1;
            else no[i]=0;
        }
    }

    std::queue<std::array<int,3>> q;
    q.push({0,1,2});
    while(q.size()){
        auto [d,i,j]=q.front();
        q.pop();
        if(i<=n and j>n+1) continue;
        if(f[i][j]!=-1) continue;
        f[i][j]=d;
        if(i<=n and !yes[j-1] and a[i]!=0) q.push({d+1,i,j+1});
        if(i<=n and !no[j-1] and a[i]!=100) q.push({d+1,j,j+1});
        if(i<=n and !no[j-1] and a[i]!=0) q.push({d+1,j+1,j+2});
    }

    int res=0;
    for(int i=1;i<=n+1;i++){
        for(int j=i+1;j<=n+2;j++){
            if(f[i][j]!=-1){
                res+=f[i][j]<=k;
            }
        }
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
