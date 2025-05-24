#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int64 f(int64 m) {
    int64 res = 0;
    int64 u = 1LL;
    int l = 1;
    while (u * 10LL <= m) {
        res += (u * 10LL - u) * l;
        u *= 10LL;
        l += 1;
    }
    return res + (m - u + 1) * l;
}

int main() {
    int64 w, m;
    int k;
    scanf("%I64d%I64d%d", &w, &m, &k);
    int64 a = f(m - 1);
    int64 lo = m, hi = 2e16;
    while (lo <= hi) {
        int64 mid = (hi - lo) / 2 + lo;
        // f * k > w ==> f * k > (w / k) * k + w % k ==> f - w / k > 0
        if ((f(mid) - a) > w / k) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    printf("%I64d\n", hi - m + 1);
    return 0;
}

