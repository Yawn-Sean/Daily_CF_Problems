/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

#define int long long

constexpr double pi=acos(-1);

struct Point {
    int x, y;
    Point(int x0 = 0,int y0 = 0) : x(x0), y(y0) {}
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

typedef Point Vector;

int Dot(const Point &a, const Point &b){
    return a.x * b.x + a.y * b.y;
}

int Cross(const Point &a, const Point &b){
    return a.x * b.y - a.y * b.x;
}

int Length(const Point &a){
    return Dot(a, a);
}

double PointDistToLine(const Point &P,const Point &A,const Point &B){
    Vector l=B-A,r=P-A;
    double v=Cross(l,r);
    return (v*v)/Length(l);
}
double PointDistToSegment(const Point &P,const Point &A,const Point &B){
	if(A==B) return Length(P-A);
	Vector v1=B-A,v2=P-A,v3=P-B;
	if(Dot(v1,v2)<0) return Length(v2);
	if(Dot(v1,v3)>0) return Length(v3);
	return PointDistToLine(P,A,B);
}

void solve(){
    int n;
    std::cin>>n;
    Point P;
    std::cin>>P.x>>P.y;
    std::vector<Point> pt(n);
    for(auto &x:pt) std::cin>>x.x>>x.y;

    double mi=1e18,mx=0;
    for(auto x:pt) mx=std::max(mx,(double)Length(x-P));
    for(int i=0;i<n;i++){
        int l=(i-1+n)%n,r=i;
        double len=PointDistToSegment(P,pt[l],pt[r]);
        mi=std::min(mi,len);
    }

    std::cout<<std::fixed<<std::setprecision(10)<<(mx-mi)*pi<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
