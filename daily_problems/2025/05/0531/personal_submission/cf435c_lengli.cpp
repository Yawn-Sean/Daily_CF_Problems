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


    std::vector<std::array<int,2>> pt;

    int sx=0,sy=0;
    pt.pb({sx,sy});

    int ma_x=0,mi_y=0,ma_y=0;

    for(int i=1;i<=n;i++){
        sx+=a[i];
        sy+=(i&1 ? -a[i] : a[i]);
        ma_x=std::max(ma_x,sx);
        ma_y=std::max(ma_y,sy);
        mi_y=std::min(mi_y,sy);
        pt.pb({sx,sy});
    }

    std::vector<std::vector<char>> res(ma_y-mi_y+5,std::vector<char> (ma_x+5,' '));

    sx=0,sy=-mi_y;

    for(auto [xx,yy]:pt){
        yy-=mi_y;
        while(sx<xx){
            if(sy<yy) res[sy][sx]='\\',sy++;
            else res[sy-1][sx]='/',sy--;
            sx++;
        }
    }
    for(int i=0;i<ma_y-mi_y;i++){
        for(int j=0;j<ma_x;j++){
            std::cout<<(res[i][j]);
        }
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
