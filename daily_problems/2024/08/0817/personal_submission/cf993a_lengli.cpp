/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr int N=100010;

Point a[N],b[N];
Point l[N],r[N];

void solve(){
    for(int i=1;i<=4;i++){
        int x,y;
        std::cin>>x>>y;
        a[i]={x,y};
    }        
    for(int i=1;i<=4;i++){
        int x,y;
        std::cin>>x>>y;
        b[i]={x,y};
    }
    ConvexHull(a,4,l);
    ConvexHull(b,4,r);
    bool flag=0;
    for(int i=-100;i<=100;i++){
        for(int j=-100;j<=100;j++){
            if(isPointInPolygon(Point(i,j),l,4)==1 and isPointInPolygon(Point(i,j),r,4)==1) flag=1;
        }
    }
    std::cout<<(flag ? "YES" : "NO")<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
