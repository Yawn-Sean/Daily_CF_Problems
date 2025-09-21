/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

#define int long long

struct Point {
    i64 x, y, id;
    Point(i64 x0 = 0, i64 y0 = 0, i64 id0 = 0) : x(x0), y(y0), id(id0) {}
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

i64 Cross(Point a,Point b){
    return a.x*b.y-a.y*b.x;
}

std::vector<int> ConvexHull(std::vector<Point> &p){
    int n=p.size();
    std::sort(p.begin(),p.end());
    std::vector<int> res;
    int m=0;
    for(int i=0;i<n;i++){
        while(m>=2 and Cross(p[res[m-1]]-p[res[m-2]],p[i]-p[res[m-2]])<0){
            res.pop_back();
            m--;
        }
        res.push_back(i);m++;
    }
    int k=m;
    for(int i=n-2;i>=0;i--){
        while(m>k and Cross(p[res[m-1]]-p[res[m-2]],p[i]-p[res[m-2]])<0){
            res.pop_back();
            m--;
        }
        res.push_back(i);m++;
    }
    res.pop_back();
    return res;
}

bool check(Point a,Point b,Point c,Point d){
    return Cross(b-a,d-a)>0 and Cross(c-b,d-b)>0 and Cross(a-c,d-c)>0;
}

void solve(){
    int n;
    std::cin>>n;
    std::vector<Point> p(n);
    for(int i=0;i<n;i++){
        p[i].id=i+1;
        std::cin>>p[i].x>>p[i].y;
    }
    std::vector<int> res=ConvexHull(p);
    std::vector<int> st(n+2);
    int m=res.size();
    for(int i=0;i<m;i++) st[p[res[i]].id]=1;
    int pi=-1,v=n+1;
    for(int i=0;i<n;i++){
        if(!st[p[i].id]){
            if(p[i].id<v){
                v=p[i].id;
                pi=i;
            }
        }
    }
    if(pi==-1){
        std::cout<<"-1"<<"\n";
        return;
    }
    for(int i=2;i<m;i++){
        if(check(p[res[0]],p[res[i-1]],p[res[i]],p[pi])){
            std::cout<<p[pi].id<<" "<<p[res[0]].id<<" "<<p[res[i-1]].id<<" "<<p[res[i]].id<<"\n";
            return;
        }
    }
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
