#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;

struct node{
    int x1,x2,y1,y2;
    int id;
};

void normalize(node& x){
    if(x.x1 == x.x2){
        if(x.y1 > x.y2) std::swap(x.y1, x.y2);
    } else {
        if(x.x1 > x.x2) std::swap(x.x1, x.x2);
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int d,n,m;
    std::cin>>d>>n>>m;
    std::vector<node> a(d);
    for(int i=0;i<d;i++){
        std::cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
        a[i].id = i+1;
        normalize(a[i]);
    }
    int cntl, cntr, cntt, cntb;
    std::cin>>cntl>>cntr>>cntt>>cntb;
    std::vector<int> minx(d), maxx(d), miny(d), maxy(d);
    for(int i=0;i<d;i++){
        minx[i] = a[i].x1;
        maxx[i] = a[i].x2;
        miny[i] = a[i].y1;
        maxy[i] = a[i].y2;
    }
    std::sort(minx.begin(), minx.end());
    std::sort(maxx.begin(), maxx.end());
    std::sort(miny.begin(), miny.end());
    std::sort(maxy.begin(), maxy.end());

    auto cntless = [&](const std::vector<int>& v, int val){
        return int(std::lower_bound(v.begin(), v.end(), val) - v.begin());
    };
    auto cntgreater = [&](const std::vector<int>& v, int val){
        return int(v.end() - std::upper_bound(v.begin(), v.end(), val));
    };

    int answer = -1;
    for(int i=0;i<d;i++){
        int left = cntless(minx, a[i].x2);
        if(a[i].x1 < a[i].x2) left--; 
        int right = cntgreater(maxx, a[i].x1);
        if(a[i].x1 < a[i].x2) right--;
        int top = cntless(miny, a[i].y2);
        if(a[i].y1 < a[i].y2) top--;
        int bottom = cntgreater(maxy, a[i].y1);
        if(a[i].y1 < a[i].y2) bottom--;

        if(left==cntl && right==cntr && top==cntt && bottom==cntb){
            answer = a[i].id;
            break;
        }
    }

    std::cout<<answer;
    return 0;
}
