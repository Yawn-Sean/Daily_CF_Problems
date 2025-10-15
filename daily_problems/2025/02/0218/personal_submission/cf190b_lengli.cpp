/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr double eps=1e-9;

struct Point {
    double x, y;
    Point(double x0 = 0, double y0 = 0) : x(x0), y(y0) {}
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
    friend Point operator*(const Point &a, double b) {
        return Point(a.x * b, a.y * b);
    }
    friend Point operator/(const Point &a, double b) {
        return Point(a.x / b, a.y / b);
    }
};

typedef Point Vector;

int dcmp(double x, double y) {
	if(fabs(x-y)<eps) return 0;
	if(x<y) return -1;
	return 1;
}

double Dot(const Point &a, const Point &b){
  	return a.x*b.x+a.y*b.y;
}

double Cross(const Point &a, const Point &b){
  	return a.x*b.y-a.y*b.x;
}

double Length(const Point &a){
  	return sqrt(Dot(a, a));
}

struct Circle {
    Point P;
    double r;
    Circle(){};
    Circle(Point a, double r) : P(a), r(r){};
};

void solve(){
    Circle a,b;
    std::cin>>a.P.x>>a.P.y>>a.r;
    std::cin>>b.P.x>>b.P.y>>b.r;
    if(a.r>b.r) std::swap(a,b);

    double dist=Length(a.P-b.P);
    if(a.r+b.r<=dist){
        double res=dist-a.r-b.r;
        res/=2.0;
        std::cout<<std::fixed<<std::setprecision(10)<<res<<"\n";
    }else if(a.r+dist<=b.r){
        double res=b.r-dist-a.r;
        res/=2.0;
        std::cout<<std::fixed<<std::setprecision(10)<<res<<"\n";
    }else{
        std::cout<<0<<"\n";
        return;
    }
    
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
