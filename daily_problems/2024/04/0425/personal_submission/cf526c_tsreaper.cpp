#include <bits/stdc++.h>
#define MAGIC ((int) 4e4)
using namespace std;

int main() {
    long long c, hr, hb, wr, wb; scanf("%lld%lld%lld%lld%lld", &c, &hr, &hb, &wr, &wb);
    long long ans = 0;
    for (int _ = 0; _ < 2; _++) {
        swap(hr, hb); swap(wr, wb);
        for (int i = 0; i <= MAGIC && i * wr <= c; i++)
            ans = max(ans, i * hr + (c - i * wr) / wb * hb);
    }
    printf("%lld\n", ans);
    return 0;
}
