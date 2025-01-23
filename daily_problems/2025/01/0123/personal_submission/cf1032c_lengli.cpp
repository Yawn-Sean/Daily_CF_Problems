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
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];

    std::vector<std::vector<int>> f(n+2,std::vector<int> (6,0));
    std::vector<std::vector<int>> la(n+2,std::vector<int> (6,0));

    for(int i=1;i<=5;i++) f[1][i]=1;

    for(int i=2;i<=n;i++){
        for(int j=1;j<=5;j++){
            for(int k=1;k<=5;k++){
                if(a[i]==a[i-1] and k==j) continue;
                if(a[i]<a[i-1] and j>=k) continue;
                if(a[i]>a[i-1] and j<=k) continue;
                if(f[i-1][k]){
                    f[i][j]=1;
                    la[i][j]=k;
                }
            }
        }
    }

    int flag=0;
    for(int i=1;i<=5;i++){
        if(f[n][i]) flag=i;
    }
    if(!flag){
        std::cout<<"-1"<<"\n";
        return;
    }
    std::vector<int> res(n+2);
    
    for(int i=n;i>=1;i--){
        res[i]=flag;
        flag=la[i][flag];
    }
    for(int i=1;i<=n;i++) std::cout<<res[i]<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
