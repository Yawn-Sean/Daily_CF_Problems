#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
typedef pair<int, int> pii;

int n, K;

map<int, set<pii>> X, Y;
int root[MAXN + 10], mn[MAXN + 10];

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

void merge(int x, int y) {
    x = findroot(x); y = findroot(y);
    root[y] = x;
    mn[x] = min(mn[x], mn[y]);
}

void prepare(map<int, set<pii>> &X) {
    for (auto &p : X) {
        auto &st = p.second;
        for (auto it = st.begin(); next(it) != st.end(); it++) {
            auto &now = *it, &nxt = *next(it);
            if (nxt.first - now.first <= K) merge(now.second, nxt.second);
        }
    }
}

bool check(int lim) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) if (findroot(i) == i)
        if (mn[i] > lim) cnt++;
    return cnt <= lim + 1;
}

void solve() {
    scanf("%d%d", &n, &K);
    X.clear(); Y.clear();
    for (int i = 1; i <= n; i++) root[i] = i;
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d%d", &x, &y, &mn[i]);
        X[x].insert({y, i});
        Y[y].insert({x, i});
    }
    prepare(X); prepare(Y);

    int head = 0, tail = n;
    while (head < tail) {
        int mid = (head + tail) >> 1;
        if (check(mid)) tail = mid;
        else head = mid + 1;
    }
    printf("%d\n", head);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
