#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXS ((int) 4e4)
using namespace std;
typedef pair<int, int> pii;

int n, K, A[MAXN + 5];
long long ans;

bool flag[MAXS + 5];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    if (K == 1) { printf("%lld\n", 1LL * n * (n + 1) / 2); return 0; }

    for (int i = 2; i <= MAXS; i++) if (!flag[i]) for (int j = i * 2; j <= MAXS; j += i) flag[j] = true;
    vector<pii> fac;
    for (int p = 2; p <= MAXS && p <= K; p++) if (!flag[p] && K % p == 0) {
        int cnt = 0;
        while (K % p == 0) K /= p, cnt++;
        fac.push_back({p, cnt});
    }
    if (K > 1) fac.push_back({K, 1});

    int bad = fac.size();
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= n && bad > 0) {
            int x = A[j];
            for (pii &p : fac) {
                while (x % p.first == 0) {
                    x /= p.first;
                    if ((--p.second) == 0) bad--;
                }
            }
            j++;
        }
        if (bad == 0) ans += n + 2 - j;
        int x = A[i];
        for (pii &p : fac) {
            while (x % p.first == 0) {
                x /= p.first;
                if ((++p.second) == 1) bad++;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
