#include <bits/stdc++.h>

//#define DEBUG
#ifndef  DEBUG
#pragma GCC optimize("O3")
#endif
using namespace std;


using i64 = long long;
using pii = pair<int, int>;
//using u32 = unsigned;
constexpr int inf = INT32_MAX >> 1;
//constexpr i64 inf = INT64_MAX >> 1;
using vi = vector<int>;
using vl = vector<i64>;
using vb = vector<bool>;
#define all(x) (x).begin(),(x).end()
//constexpr int mod = 1e9 + 7;

int interact(int a,int b,int c,int d){
    cout<<"? "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
//    printf("? %d %d %d %d\n",a,b,c,d);
    fflush(stdout);
    int ans;
    cin>>ans;
//    scanf("%d",&ans);
    return ans;
}
void solve() {
    int n; cin>>n;
    int lo , hi ;
    int  x1,y1,x2,y2;
    int x3,y3,x4,y4;
    lo = 1;hi = n;
    while(lo <= hi){
        int mid = (lo + hi )>> 1;
        int ans = interact(1,1,n,mid);
        if(ans) y2 = mid,hi = mid - 1;
        else lo = mid + 1;
    }

    lo = 1;hi = n;
    while(lo <= hi){
        int mid = (lo + hi )>> 1;
        int ans = interact(1,1,mid,y2);
        if(ans) x2 = mid,hi = mid - 1;
        else lo = mid + 1;
    }

    lo = 1;hi = y2;
    while(lo <= hi){
        int mid = (lo + hi )>> 1;
        int ans = interact(1,mid,x2,y2);
        if(ans) y1 = mid,lo = mid + 1;
        else hi = mid - 1;
    }

    lo = 1;hi = x2;
    while(lo <= hi){
        int mid = (lo + hi )>> 1;
        int ans = interact(mid,y1,x2,y2);
        if(ans) x1 = mid, lo = mid + 1;
        else hi = mid - 1;
    }

    lo = 1;hi = n;
    while(lo <= hi){
        int mid = (lo + hi )>> 1;
        int ans = interact(1,1,n,mid);
        if(y2 <= mid) ans--;
        if(ans) y4 = mid,hi = mid - 1;
        else lo = mid + 1;
    }

    lo = 1;hi = n;
    while(lo <= hi){
        int mid = (lo + hi )>> 1;
        int ans = interact(1,1,mid,y4);
        if(y2 <= y4 && x2 <= mid) ans--;
        if(ans) x4 = mid,hi = mid - 1;
        else lo = mid + 1;
    }

    lo = 1;hi = y4;
    while(lo <= hi){
        int mid = (lo + hi )>> 1;
        int ans = interact(1,mid,x4,y4);
        if(y1 >= mid && y2 <= y4 && x2 <= x4) ans--;
        if(ans) y3 = mid,lo = mid + 1;
        else hi = mid - 1;
    }

    lo = 1;hi = x4;
    while(lo <= hi){
        int mid = (lo + hi )>> 1;
        int ans = interact(mid,y3,x4,y4);
        if(x1 >= mid && y1 >= y3 && y2 <= y4 && x2 <= x4) ans--;
        if(ans) x3 = mid,lo = mid + 1;
        else hi = mid - 1;
    }
    cout<<"! "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
}


int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
//    cin >> t;
    t = 1;
    while (t--) {
        solve();
    }

}






