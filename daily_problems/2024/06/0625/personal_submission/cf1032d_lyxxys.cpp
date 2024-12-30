#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6+5, inf = 1e9;

void solve(){
    double a, b, c, x1, y1, x2, y2;
    cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;
    double res = (double)(abs(x1-x2)+abs(y1-y2));

    vector<array<double,2>> p1, p2;
    // 暴力找最近点
    int r = 10;
    if (b) {
        for (int i = x1 - r; i <= x1 + r; ++ i) {
            double x = i;
            p1.push_back({x, -(a*x+c)/b});
        }
        for (int i = x2 - r; i <= x2 + r; ++ i) {
            double x = i;
            p2.push_back({x, -(a*x+c)/b});
        }
    }
    if (a){
        for (int i = y1-r; i <= y1 + r; ++ i){
            double y = i;
            p1.push_back({-(b*y+c)/a, y});
        }
        for (int i = y2-r; i <= y2 + r; ++ i){
            double y = i;
            p2.push_back({-(b*y+c)/a, y});
        }
    }

    auto todis1 = [&](array<double, 2> &a, array<double, 2> &b)->double{
        return fabs(a[0]-b[0]) + fabs(a[1]-b[1]);
    };
    auto todis2 = [&](array<double, 2> &a, array<double, 2> &b)->double{
        return hypot(a[0]-b[0], a[1]-b[1]);
    };
    // O(r^2) 枚举
    array <double,2> u = {x1, y1}, v = {x2, y2};
    for (auto &A : p1){
        for (auto &B : p2){
            double dis = todis1(u, A) + todis2(A, B) + todis1(B, v);
            res = min(res, dis);
        }
    }

    cout << res << "\n";
}
