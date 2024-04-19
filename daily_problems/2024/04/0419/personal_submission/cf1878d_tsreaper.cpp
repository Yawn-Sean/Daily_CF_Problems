#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n;
char s[MAXN + 10];

bool flag[MAXN + 10];

void solve() {
    int K; scanf("%d%d%s", &n, &K, s + 1);
    memset(flag, 0, sizeof(bool) * (n + 3));
    vector<int> vec;
    for (int i = 1; i <= K; i++) scanf("%*d");
    for (int i = 1; i <= K; i++) {
        int x; scanf("%d", &x);
        vec.push_back(x);
    }

    int q; scanf("%d", &q);
    while (q--) {
        int x; scanf("%d", &x);
        int idx = lower_bound(vec.begin(), vec.end(), x) - vec.begin();
        int l = (idx == 0 ? 1 : vec[idx - 1] + 1);
        int r = vec[idx];
        int y = l + r - x;
        if (x > y) swap(x, y);
        flag[x] = !flag[x];
        if (y < r) flag[y + 1] = !flag[y + 1];
    }

    bool now = false;
    for (int i = 1, j = 0; i <= n; i++) {
        if (flag[i]) now = !now;
        int l = (j == 0 ? 1 : vec[j - 1] + 1);
        int r = vec[j];
        if (now) printf("%c", s[l + r - i]);
        else printf("%c", s[i]);
        if (i == r) j++, now = false;
    }
    printf("\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
