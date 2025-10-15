/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

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

void solve(){
    int n;
    Point s,t;
    std::cin>>n>>s.x>>s.y>>t.x>>t.y;

    std::vector<Point> q(n);
    for(int i=0;i<n;i++) std::cin>>q[i].x>>q[i].y;

    auto cmp=[&](Point l,Point r){
        return Dot(l-s,l-s)<Dot(r-s,r-s);
    };

    std::sort(all(q),cmp);

    std::vector<i64> suf(n+2,0);
    for(int i=n-1;i>=0;i--){
        i64 len=Dot(q[i]-t,q[i]-t);
        suf[i]=std::max(suf[i+1],len);
    }

    i64 res=suf[0];

    for(int i=0;i<n;i++){
        i64 len=Dot(q[i]-s,q[i]-s);
        res=std::min(res,len+suf[i+1]);
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
