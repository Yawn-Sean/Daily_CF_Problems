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
    int n,q;
    std::cin>>n>>q;
    std::vector<std::vector<i64>> a(1005,std::vector<i64> (1005,0));
    for(int i=1;i<=n;i++){
        int h,w;
        std::cin>>h>>w;
        a[h][w]+=h*w;
    }

    for(int i=1;i<=1000;i++){
        for(int j=1;j<=1000;j++) a[i][j]+=a[i][j-1];
    }
    for(int j=1;j<=1000;j++){
        for(int i=1;i<=1000;i++) a[i][j]+=a[i-1][j];
    }

    while(q--){
        int lx,ly,rx,ry;
        std::cin>>lx>>ly>>rx>>ry;
        lx++,ly++,rx--,ry--;
        std::cout<<a[rx][ry]-a[lx-1][ry]-a[rx][ly-1]+a[lx-1][ly-1]<<"\n";
    }
    

}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
