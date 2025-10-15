#include <bits/stdc++.h>

using namespace std;

template<typename T>
T f(const array<T, 3>& a, const array<T, 3>& b, T v) {
    return sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]) + (a[2] - b[2]) * (a[2] - b[2])) / v;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<array<double, 3>> tr(n + 1);
    for (int i = 0; i <= n; i++) {
        scanf("%lf%lf%lf", &tr[i][0], &tr[i][1], &tr[i][2]);
    }
    double vp, vs;
    scanf("%lf%lf", &vp, &vs);
    array<double, 3> pos;
    scanf("%lf%lf%lf", &pos[0], &pos[1], &pos[2]);
    if (pos == tr[0]) {
        printf("YES\n");
        printf("%.10lf\n", 0);
        printf("%.10lf %.10lf %.10lf\n", pos[0], pos[1], pos[2]);
        return 0;
    } else {
        double curr = 0;
        for (int i = 1; i <= n; i++) {
            double t = f(tr[i - 1], tr[i], vs);
            if (f(pos, tr[i], vp) <= curr + t) {
                auto& src = tr[i - 1];
                auto& dest = tr[i];
                array<double, 3> target;
                double lo = 0, hi = 1;
                for (int i = 0; i < 100; i++) {
                    double mid = (lo + hi) / 2;
                    double tx = src[0] + (dest[0] - src[0]) * mid;
                    double ty = src[1] + (dest[1] - src[1]) * mid;
                    double tz = src[2] + (dest[2] - src[2]) * mid;
                    target = array<double, 3> {tx, ty, tz};
                    if (f(src, target, vs) + curr >= f(pos, target, vp)) {
                        hi = mid; 
                    } else {
                        lo = mid;
                    }
                }
                printf("YES\n");
                printf("%.10lf\n", curr + t * lo);
                printf("%.10lf %.10lf %.10lf\n", target[0], target[1], target[2]);
                return 0;
            }
            curr += t;
        }
    }
    printf("NO\n");
    return 0;
}

