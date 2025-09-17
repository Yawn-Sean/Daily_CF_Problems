/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define f128 long double

struct Point {
    f128 x, y;
    Point(f128 x0 = 0, f128 y0 = 0) : x(x0), y(y0) {}
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
    friend Point operator*(const Point &a, f128 b) {
        return Point(a.x * b, a.y * b);
    }
};

typedef Point Vector;

f128 Cross(const Point &a, const Point &b){
  	return a.x*b.y-a.y*b.x;
}

f128 PolygonArea(std::vector<Point> &p,std::vector<int> &cvx){
    int n=cvx.size();
    f128 res=0;
    for(int i=1;i<n-1;i++) res+=Cross(p[cvx[i]]-p[cvx[0]],p[cvx[i+1]]-p[cvx[0]]);
    return res;
}

void solve(){
    int n;
    std::cin>>n;
    std::vector<Point> p(n);
    for(int i=0;i<n;i++){
        int x,y;
        std::cin>>x>>y;
        p[i]=Point(x,y);
    }
    std::vector<int> cvx(n);
    for(int i=0;i<n;i++) cvx[i]=i;
    
    f128 area=PolygonArea(p,cvx);

    std::vector<Point> pre(n);
    Point sum=Point(0,0);
    for(int i=0;i<n;i++){
        pre[i]=p[i]*i-sum;
        sum=sum+p[i];
    }
    std::vector<Point> suf(n);
    sum=Point(0,0);
    for(int i=n-1;i>=0;i--){
        suf[i]=sum-p[i]*(n-1-i);
        sum=sum+p[i];
    }

    f128 res=0;
    for(int i=0;i<n-1;i++){
        res+=Cross(pre[i],suf[i]);
    }

    f128 ans=(f128)res/(f128)area;
    std::cout<<std::fixed<<std::setprecision(10)<<ans<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
