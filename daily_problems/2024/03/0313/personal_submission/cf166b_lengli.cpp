/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=200010;

struct Point {
    double x, y;
    int id;
    Point(double x0 = 0, double y0 = 0 ,int id = 0) : x(x0), y(y0) ,id(id){}
    friend bool operator<(Point a, Point b) {
        return a.x != b.x ? a.x < b.x : a.y!=b.y ? a.y < b.y : a.id > b.id;
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

double Cross(const Point &a, const Point &b){
    return a.x * b.y - a.y * b.x;
}
int ConvexHull(Point *p, int n, Point *ch){
    sort(p + 1, p + n + 1); 
    int m = 0;
    for (int i = 1; i <= n; i++) {
        while (m > 1 && Cross(ch[m] - ch[m - 1], p[i] - ch[m - 1]) < 0) m--;
        ch[++m] = p[i];
    }
    int k = m;
    for (int i = n - 1; i; i--) {
        while (m > k && Cross(ch[m] - ch[m - 1], p[i] - ch[m - 1]) < 0) m--;
        ch[++m] = p[i];
    }
    if (n > 1) m--;
    return m;
}

Point a[N],res[N];
int idx;

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        a[++idx]=Point(x,y,0);
    }

    int m;
    cin>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        a[++idx]=Point(x,y,1);
    }
    int len=ConvexHull(a,idx,res);
    for(int i=1;i<=len;i++)
        if(res[i].id==1) {
            cout<<"NO"<<endl;
            return;
        }

    cout<<"YES"<<endl;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
