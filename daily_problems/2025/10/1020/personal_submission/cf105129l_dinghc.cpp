#include <bits/stdc++.h>

using namespace std;
constexpr int A = 50;
constexpr int N = 15;
constexpr int M = 1 << N;
const int pn[] {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        array<int, A + 1> a{};
        for (int i = 0, x; i < n; i++) {
            scanf("%d", &x);
            a[x] = 1;
        }
        long long ans = LONG_LONG_MAX;
        for (int msk = 1; msk < M; msk++) {
            auto b = a;
            for (int i = 0; i < N; i++) if (msk >> i & 1) {
                for (int p = pn[i]; p <= A; p += pn[i]) {
                    b[p] = 0;
                }
            }
            bool valid = true;
            for (int i = 0; i <= A; i++) {
                if (b[i] == 1) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                long long prod = 1;
                for (int i = 0; i < N; i++) if (msk >> i & 1) {
                    prod *= pn[i];
                }
                ans = min(ans, prod);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}

