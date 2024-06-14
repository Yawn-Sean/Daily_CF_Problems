#include <bits/stdc++.h>
#define LIM ((long long) 2e16)
using namespace std;
typedef pair<long long, long long> pll;

long long dis(long long xa, long long ya, long long xb, long long yb) {
    return abs(xa - xb) + abs(ya - yb);
}

int main() {
    long long X, Y, AX, AY, BX, BY, XS, YS, T;
    scanf("%lld%lld%lld%lld%lld%lld", &X, &Y, &AX, &AY, &BX, &BY);
    scanf("%lld%lld%lld", &XS, &YS, &T);
    
    vector<pll> vec;
    vec.push_back({X, Y});
    while (true) {
        X = X * AX + BX;
        Y = Y * AY + BY;
        if (X > LIM || Y > LIM) break;
        vec.push_back({X, Y});
    }

    int n = vec.size(), ans = 0;
    for (int i = 0; i < n; i++) {
        long long d = dis(XS, YS, vec[i].first, vec[i].second);
        if (d > T) continue;
        for (int l = 0; l <= i; l++) for (int r = i; r < n; r++) {
            long long dl = dis(vec[i].first, vec[i].second, vec[l].first, vec[l].second);
            long long dr = dis(vec[i].first, vec[i].second, vec[r].first, vec[r].second);
            if (d + dl * 2 + dr <= T || d + dl + dr * 2 <= T) ans = max(ans, r - l + 1);
        }
    }
    printf("%d\n", ans);
    return 0;
}
