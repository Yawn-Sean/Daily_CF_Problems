/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back
#define double long double
#define int long long

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

struct Point {
  double x, y;
  Point(double x0 = 0, double y0 = 0) : x(x0), y(y0) {}
  friend bool operator<(Point a, Point b) {
    return a.x != b.x ? a.x < b.x : a.y < b.y;
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

double dis(const Point &a, const Point &b) {
    double xx=a.x-b.x,yy=a.y-b.y;
    return sqrt(xx*xx+yy*yy);
}
double Dot(const Point &a, const Point &b) {
  return a.x * b.x + a.y * b.y;
}
double Cross(const Point &a, const Point &b) {
  return a.x * b.y - a.y * b.x;
}
double Length(const Point &a) {
  return sqrt(Dot(a, a));
}
double getDistToLine(const Point &P, const Point &A,const Point &B) {
  return fabs(Cross(B-A,P-A))/dis(A,B);
}

void solve(){
    int n;
    cin>>n;
    vector<Point> q;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        q.pb(Point(a,b));
    }
    double l=0,r=1e9;

    auto check=[&](double x){
        for(int i=0;i<n;i++){
            if(dis(q[i],q[(i+1)%n])<=2*x) return 1;
            if(getDistToLine(q[i],q[(i-1+n)%n],q[(i+1)%n])<=2*x) return 1;
        }
        return 0;
    };
    while(r-l>1e-10){
        double mid=(l+r)/2.;
        if(check(mid)) r=mid;
        else l=mid;
    }

    cout<<fixed<<setprecision(10)<<l;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
