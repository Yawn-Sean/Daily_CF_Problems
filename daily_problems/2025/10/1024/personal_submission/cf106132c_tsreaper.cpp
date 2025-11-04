#include <bits/stdc++.h>
using namespace std;

int n, M, K;
unordered_map<int, int> cnt, to, deg;

int main() {
    scanf("%d%d%d", &n, &M, &K);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        cnt[x]++;
    }
    for (auto &p : cnt) {
        int x = p.first;
        int y = (K - 1LL * x * x % M + M) % M;
        if (cnt.count(y)) to[x] = y, deg[y]++;
    }

    int key = -1;
    for (auto &p : cnt) if (deg[p.first] == 0) {
        if (key == -1) key = p.first;
        else { printf("NO\n"); return 0; }
    }
    if (key == -1) {
        key = cnt.begin()->first;
        for (int now = key, i = 0; i <= n * 2; now = to[now], i++) {
            int nxt = to[now];
            if (cnt[nxt] > cnt[now] && cnt[nxt] >= cnt[key]) key = nxt;
        }
    }

    vector<int> ans;
    for (int now = key; cnt[now] > 0; ) {
        cnt[now]--;
        ans.push_back(now);
        if (!to.count(now)) break;
        now = to[now];
    }
    reverse(ans.begin(), ans.end());

    if (ans.size() < n) printf("NO\n");
    else {
        printf("YES\n");
        for (int i = 0; i < n; i++) printf("%d%c", ans[i], "\n "[i + 1 < n]);
    }
    return 0;
}
