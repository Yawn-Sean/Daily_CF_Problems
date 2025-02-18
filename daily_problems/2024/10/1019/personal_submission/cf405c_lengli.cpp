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
    std::vector<std::vector<int>> a(n+2,std::vector<int> (n+2,0));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) std::cin>>a[i][j];

    int res=0;
    for(int i=1;i<=n;i++){
        res+=a[i][i];
    }


    int q;
    std::cin>>q;
    while(q--){
        int op;
        std::cin>>op;
        if(op!=3){
            int x;
            std::cin>>x;
            res-=a[x][x];
            a[x][x]^=1;
            res+=a[x][x];
        }else std::cout<<res%2;
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
