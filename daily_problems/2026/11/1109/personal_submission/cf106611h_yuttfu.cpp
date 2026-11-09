#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using db = double;
const double PI = acos(-1);

struct Point{
    db x = 0,y = 0;
};

void solve(){
    Point H,C;
    db D,U;
    cin >> H.x >> H.y >> C.x >> C.y >> D >> U;
    db dx = H.x - C.x;
    db dy = H.y - C.y;
    db r = hypot(dx,dy);
    if(r <= 1){
        cout << 1 << '\n';
        return;
    }
    db phi = atan2(dy,dx) * 180.0 / PI;
    db theta = asin(1.0 / r) * 180.0 / PI;
    db L = D - U,R = D + U;
    db ans = 0.0;
    for(int k = -2;k <= 2;k++){
        db ll = phi - theta + 360.0 * k;
        db rr = phi + theta + 360.0 * k;
        db len = max(0.0,min(R,rr)-max(L,ll));
        ans += len;
    }
    cout << fixed << setprecision(12) << ans / (2.0 * U) << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T --){
        solve();
    }
    return 0;
}
