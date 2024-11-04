#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n;
    cin >> n;
    ld sx,sy;
    cin >> sx >> sy;
    vector <ld> xs, ys;
    ld Max = 0, Min = 1e18;
    for (int i = 0, x,y; i < n; ++ i){
        cin >> x >> y;
        x -= sx, y -= sy;
        xs.push_back(ld(x));
        ys.push_back(ld(y));
        ld d = (ld)x*x + (ld)y*y;
        if (d > Max) Max = d;
        if (d < Min) Min = d;
    }

    auto L2 = [&](ld x)->ld{
        return x*x;
    };

    for (int i = 0; i < n; ++ i){
        ld x1 = xs[i], y1 = ys[i];
        ld x2 = xs[(i+1)%n], y2 = ys[(i+1)%n];
        ld v1 = L2(x1) + L2(y1), v2 = L2(x2) + L2(y2);
        ld v = L2(x1-x2) + L2(y1-y2);
        if (v1+v > v2 && v2+v > v1){
            ld xv = L2(x1*y2 - x2*y1);
            ld ans = xv / v;
            if (ans < Min) Min = ans;
        }
    }

    cout << fixed << setprecision(10) << Pi * (Max - Min) << "\n";
}
