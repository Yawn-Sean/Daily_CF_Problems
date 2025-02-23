#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/fenwicktree"
// #include "atcoder/lazysegtree"
// #include "atcoder/math"
// #include "atcoder/maxflow"
// #include "atcoder/mincostflow"
// #include "atcoder/modint"
// #include "atcoder/scc"
// #include "atcoder/segtree"
// #include "atcoder/string"
// #include "atcoder/twosat"
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

array<int, 2> direction(array<int, 2> x1, array<int, 2> x2) {return {x2[0] - x1[0], x2[1] - x1[1]};}
bool sgn(array<int, 2> x) {return x[0] > 0 || (x[0] == 0 && x[1] > 0);}
__int128_t cross(array<int, 2> x1, array<int, 2> x2) {return 1ll * x1[0] * x2[1] - 1ll * x1[1] * x2[0];}
__int128_t dot(array<int, 2> x1, array<int, 2> x2) {return 1ll * x1[0] * x2[0] + 1ll * x1[1] * x2[1];}

long double fcheck(long double a, long double b, long double c, vector<array<int, 2>> &pts) {
    int n = pts.size() - 2;

    vector<int> flg(n + 2, 0);
    for (int i = 0; i <= n + 1; i ++)
        if (a * pts[i][0] + b * pts[i][1] + c >= 0) flg[i] = 1;
    
    __int128_t up_area = 0, up_gravity_x = 0, up_gravity_y = 0;
    __int128_t down_area = 0, down_gravity_x = 0, down_gravity_y = 0;

    long double up_area1 = 0, up_gravity_x1 = 0, up_gravity_y1 = 0;
    long double down_area1 = 0, down_gravity_x1 = 0, down_gravity_y1 = 0;

    for (int i = 1; i <= n; i ++) {
        if (flg[i] ^ flg[i - 1]) {
            if (flg[i]) {
                if (flg[i - 1] == flg[i + 1]) {
                    long double t1 = -(a * pts[i][0] + b * pts[i][1] + c) / (a * (pts[i - 1][0] - pts[i][0]) + b * (pts[i - 1][1] - pts[i][1]));
                    long double t2 = -(a * pts[i][0] + b * pts[i][1] + c) / (a * (pts[i + 1][0] - pts[i][0]) + b * (pts[i + 1][1] - pts[i][1]));
                    long double area = t1 * t2 * cross(direction(pts[i - 1], pts[i]), direction(pts[i], pts[i + 1]));
                    up_area1 += area;
                    up_gravity_x1 += area * (t1 * (pts[i - 1][0] - pts[i][0]) + t2 * (pts[i + 1][0] - pts[i][0]) + 3ll * pts[i][0]);
                    up_gravity_y1 += area * (t1 * (pts[i - 1][1] - pts[i][1]) + t2 * (pts[i + 1][1] - pts[i][1]) + 3ll * pts[i][1]);
                }
                else {
                    int j = i + 1;
                    while (true) {
                        if (j >= n) j -= n;
                        if (flg[j] != flg[j + 1]) break;
                        __int128_t area = cross(direction(pts[i], pts[j]), direction(pts[i], pts[j + 1]));
                        up_area += area;
                        up_gravity_x += area * (0ll + pts[i][0] + pts[j][0] + pts[j + 1][0]);
                        up_gravity_y += area * (0ll + pts[i][1] + pts[j][1] + pts[j + 1][1]);
                        j ++;
                    }
                    long double t1 = -(a * pts[i][0] + b * pts[i][1] + c) / (a * (pts[i - 1][0] - pts[i][0]) + b * (pts[i - 1][1] - pts[i][1]));
                    long double t2 = -(a * pts[j][0] + b * pts[j][1] + c) / (a * (pts[j + 1][0] - pts[j][0]) + b * (pts[j + 1][1] - pts[j][1]));
                    long double x1 = t1 * (pts[i - 1][0] - pts[i][0]) + pts[i][0];
                    long double y1 = t1 * (pts[i - 1][1] - pts[i][1]) + pts[i][1];
                    long double x2 = t2 * (pts[j + 1][0] - pts[j][0]) + pts[j][0];
                    long double y2 = t2 * (pts[j + 1][1] - pts[j][1]) + pts[j][1];

                    long double area1 = (-x1 + pts[i][0]) * (-y1 + pts[j][1]) - (-x1 + pts[j][0]) * (-y1 + pts[i][1]);
                    long double area2 = (-x1 + pts[j][0]) * (-y1 + y2) - (-x1 + x2) * (-y1 + pts[j][1]);

                    up_area1 += area1 + area2;
                    up_gravity_x1 += area1 * (x1 + pts[i][0] + pts[j][0]) + area2 * (x1 + pts[j][0] + x2);
                    up_gravity_y1 += area1 * (y1 + pts[i][1] + pts[j][1]) + area2 * (y1 + pts[j][1] + y2);
                }
            }
            else {
                if (flg[i - 1] == flg[i + 1]) {
                    long double t1 = -(a * pts[i][0] + b * pts[i][1] + c) / (a * (pts[i - 1][0] - pts[i][0]) + b * (pts[i - 1][1] - pts[i][1]));
                    long double t2 = -(a * pts[i][0] + b * pts[i][1] + c) / (a * (pts[i + 1][0] - pts[i][0]) + b * (pts[i + 1][1] - pts[i][1]));
                    long double area = t1 * t2 * cross(direction(pts[i - 1], pts[i]), direction(pts[i], pts[i + 1]));
                    down_area1 += area;
                    down_gravity_x1 += area * (t1 * (pts[i - 1][0] - pts[i][0]) + t2 * (pts[i + 1][0] - pts[i][0]) + 3ll * pts[i][0]);
                    down_gravity_y1 += area * (t1 * (pts[i - 1][1] - pts[i][1]) + t2 * (pts[i + 1][1] - pts[i][1]) + 3ll * pts[i][1]);
                }
                else {
                    int j = i + 1;
                    while (true) {
                        if (j >= n) j -= n;
                        if (flg[j] != flg[j + 1]) break;
                        __int128_t area = cross(direction(pts[i], pts[j]), direction(pts[i], pts[j + 1]));
                        down_area += area;
                        down_gravity_x += area * (0ll + pts[i][0] + pts[j][0] + pts[j + 1][0]);
                        down_gravity_y += area * (0ll + pts[i][1] + pts[j][1] + pts[j + 1][1]);
                        j ++;
                    }
                    long double t1 = -(a * pts[i][0] + b * pts[i][1] + c) / (a * (pts[i - 1][0] - pts[i][0]) + b * (pts[i - 1][1] - pts[i][1]));
                    long double t2 = -(a * pts[j][0] + b * pts[j][1] + c) / (a * (pts[j + 1][0] - pts[j][0]) + b * (pts[j + 1][1] - pts[j][1]));
                    long double x1 = t1 * (pts[i - 1][0] - pts[i][0]) + pts[i][0];
                    long double y1 = t1 * (pts[i - 1][1] - pts[i][1]) + pts[i][1];
                    long double x2 = t2 * (pts[j + 1][0] - pts[j][0]) + pts[j][0];
                    long double y2 = t2 * (pts[j + 1][1] - pts[j][1]) + pts[j][1];

                    long double area1 = (-x1 + pts[i][0]) * (-y1 + pts[j][1]) - (-x1 + pts[j][0]) * (-y1 + pts[i][1]);
                    long double area2 = (-x1 + pts[j][0]) * (-y1 + y2) - (-x1 + x2) * (-y1 + pts[j][1]);

                    down_area1 += area1 + area2;
                    down_gravity_x1 += area1 * (x1 + pts[i][0] + pts[j][0]) + area2 * (x1 + pts[j][0] + x2);
                    down_gravity_y1 += area1 * (y1 + pts[i][1] + pts[j][1]) + area2 * (y1 + pts[j][1] + y2);
                }
            }
        }
    }
    up_area1 += up_area;
    up_gravity_x1 += up_gravity_x;
    up_gravity_y1 += up_gravity_y;

    down_area1 += down_area;
    down_gravity_x1 += down_gravity_x;
    down_gravity_y1 += down_gravity_y;

    long double gx1 = up_gravity_x1 / up_area1 / 3, gy1 = up_gravity_y1 / up_area1 / 3;
    long double gx2 = down_gravity_x1 / down_area1 / 3, gy2 = down_gravity_y1 / down_area1 / 3;

    long double v1 = abs(a * gx1 + b * gy1 + c), v2 = abs(a * gx2 + b * gy2 + c);
    return (v1 - v2) / max((long double)1, v1 + v2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    long double pi = acosl(-1);
    cout << fixed << setprecision(25);

    while (t --) {
        int n, xp, yp;
        cin >> n >> xp >> yp;
        vector<array<int, 2>> pts(n);
        for (int i = 0; i < n; i ++)
            cin >> pts[i][0] >> pts[i][1];
        
        pts.emplace_back(pts[0]);
        pts.emplace_back(pts[1]);

        bool f = (fcheck(1, 0, -xp, pts) > 0);
        long double l = 0, r = pi;

        while (true) {
            long double m = (l + r) / 2;
            long double a = cosl(m), b = sinl(m), c = -a * xp - b * yp;
            long double v = fcheck(a, b, c, pts);
            if (abs(v) < 1e-7) break;
            if ((v > 0) == f) l = m;
            else r = m;
        }

        long double m = (l + r) / 2;
        long double a = cosl(m), b = sinl(m), c = -a * xp - b * yp;
        cout << a << ' ' << b << ' ' << c << '\n'; 
    }

    return 0;
}