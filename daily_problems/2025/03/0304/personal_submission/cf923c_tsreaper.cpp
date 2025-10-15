#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
#define MAXP 30
using namespace std;

int n, A[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    unordered_map<int, int> cnt[MAXP];
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        for (int p = MAXP - 1; p >= 0; p--) cnt[p][x >> p]++;
    }

    for (int i = 1; i <= n; i++) {
        int x = 0;
        for (int p = MAXP - 1; p >= 0; p--) {
            x = (x << 1) | (A[i] >> p & 1);
            if (cnt[p].count(x) == 0) x ^= 1;
            int t = --cnt[p][x];
            if (t == 0) cnt[p].erase(x);
        }
        printf("%d%c", A[i] ^ x, "\n "[i < n]);
    }
    return 0;
}
