#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
#define MOD ((int) 1e9 + 7)
using namespace std;
typedef pair<int, int> pii;

int n, K, A[MAXN + 10];
long long m, ans;

pii B[MAXN + 10];
long long f[MAXN + 10];

int main() {
    scanf("%d%lld%d", &n, &m, &K);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        B[i] = {A[i], i};
    }
    sort(B, B + n);

    for (int i = 0; i < n; i++) f[i] = 1;
    for (int r = 1; r < K; r++) {
        long long sm = 0;
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && B[j].first <= B[i].first) {
                sm = (sm + f[(r - 1) * n + j]) % MOD;
                j++;
            }
            f[r * n + i] = sm;
        }
    }

    for (int r = 0; r < K; r++) {
        long long sm = 0;
        for (int i = 0; i < n ; i++) sm = (sm + f[r * n + i]) % MOD;
        long long cnt = max(0LL, m / n - r) % MOD;
        ans = (ans + sm * cnt) % MOD;
    }

    vector<int> vec;
    for (int i = 0; i < n; i++) if (B[i].second < m % n) vec.push_back(i);
    for (int x : vec) {
        long long lim = (m + n - 1) / n;
        for (int r = 0; r < K && r < lim; r++) ans = (ans + f[r * n + x]) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
