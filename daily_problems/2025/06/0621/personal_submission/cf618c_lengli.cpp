/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr i64 inf=5e18;

struct Point {
    i64 x, y;
    Point(i64 x0 = 0, i64 y0 = 0) : x(x0), y(y0) {}
    friend bool operator<(Point a, Point b) {
        return a.x != b.x ? a.x < b.x : a.y < b.y;
    }
    friend bool operator==(Point a, Point b) {
        return a.x == b.x and a.y==b.y;
    }
    friend Point operator+(const Point &a, const Point &b) {
        return Point(a.x + b.x, a.y + b.y);
    }
    friend Point operator-(const Point &a, const Point &b) {
        return Point(a.x - b.x, a.y - b.y);
    }
};

i64 Dot(const Point &a, const Point &b){
  	return a.x*b.x+a.y*b.y;
}

i64 Length(const Point &a){
  	return Dot(a, a);
}

i64 Cross(const Point &a, const Point &b){
  	return a.x*b.y-a.y*b.x;
}

typedef Point Vector;

void solve(){
    int n;
    std::cin>>n;
    std::vector<Point> a(n+2);
    for(int i=1;i<=n;i++){
        int x,y;
        std::cin>>x>>y;
        a[i]=Point(x,y);
    }
    int u=1,v=2;
    Vector ans=a[v]-a[u];
    
    for(int i=2;i<=n;i++){
        Vector t=a[i]-a[u];
        if(Length(ans)>Length(t)){
            v=i;
            ans=t;
        }
    }

    int w=-1;
    i64 mi=inf;

    for(int i=2;i<=n;i++){
        if(i==v) continue;
        Vector t=a[i]-a[u];
        i64 S=std::abs(Cross(t,ans));
        if(S>0 and S<mi){
            mi=S;
            w=i;
        }
    }
    std::cout<<u<<" "<<v<<" "<<w<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
