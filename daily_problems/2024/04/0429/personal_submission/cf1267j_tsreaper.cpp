#include <bits/stdc++.h>
#define MAXN ((int) 2e6)
using namespace std;

int n, ans;
int cnt[MAXN + 10];

void solve() {
    scanf("%d", &n);
    memset(cnt, 0, sizeof(int) * (n + 3));
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        cnt[x]++;
    }
    vector<int> vec;
    int mn = n;
    for (int i = 1; i <= n; i++) if (cnt[i]) {
        vec.push_back(cnt[i]);
        mn = min(mn, cnt[i]);
    }

    ans = n;
    for (int k = 1; k <= mn; k++) {
        bool ok = true;
        int t = 0;
        for (int x : vec) {
            if (x / k < x % k) { ok = false; break; }
            t += (x + k) / (k + 1);
        }
        if (ok) ans = min(ans, t);
    }
    printf("%d\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
