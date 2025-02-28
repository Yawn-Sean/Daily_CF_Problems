#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
constexpr int64 INF = 10'000'000'000'000'000LL;
constexpr int N = 400'000;
constexpr int LOG_N = 20;
int64 w[N + 1];
int up[LOG_N][N + 1];
int64 up_sum[LOG_N][N + 1];

int main() {
    int Q;
    scanf("%d", &Q);
    int last = 0;
    int cnt = 1;
    w[0] = INF;
    for(int i = 0; i < LOG_N; i++) up_sum[i][1] = INF;
    while (Q--) {
        int t;
        int64 p, q;
        scanf("%d%lld%lld", &t, &p, &q);
        p ^= last;
        q ^= last;
        if (t == 1) {
            w[++cnt] = q;
            if (w[p] >= q) {
                up[0][cnt] = p;
            } else {
                int curr = p;
                for (int i = LOG_N - 1; i >= 0; i--) {
                    if (w[up[i][curr]] < q) {
                        curr = up[i][curr];
                    }
                }
                up[0][cnt] = up[0][curr];
            }
            up_sum[0][cnt] = up[0][cnt] == 0 ? INF : w[up[0][cnt]];
            for (int i = 1; i < LOG_N; i++) {
                up[i][cnt] = up[i - 1][up[i - 1][cnt]];
                up_sum[i][cnt] = up[i][cnt] == 0 ? INF : up_sum[i - 1][cnt] + up_sum[i - 1][up[i - 1][cnt]];
            }
        } else {
            int ans = 0;
            if (w[p] <= q) {
                ans += 1;
                q -= w[p];
                for (int i = LOG_N - 1; i >= 0; i--) {
                    if (up_sum[i][p] <= q) {
                        q -= up_sum[i][p];
                        p = up[i][p];
                        ans += 1 << i;
                    }
                }
            }
            printf("%d\n", ans);
            last = ans;
        }
    }
    return 0;
}

