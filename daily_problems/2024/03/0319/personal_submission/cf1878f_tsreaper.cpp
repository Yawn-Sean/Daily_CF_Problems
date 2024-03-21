#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;
typedef pair<int, int> pii;

int n, q;

int bad, f[MAXN + 10], g[MAXN + 10];
vector<int> history;

vector<pii> fac[MAXN + 10];

void add(int x, int y, int k) {
    for (auto &p : fac[x]) {
        history.push_back(p.first);
        int old = f[p.first];
        f[p.first] += y * p.second * k;
        if (old < 0 && f[p.first] >= 0) bad--;
        if (old >= 0 && f[p.first] < 0) bad++;
    }
}

void gao(int v) {
    for (auto &p : fac[v]) {
        int x = p.first, y = p.second, z = g[x];
        add(z + 1, 1, 1); add(z + y + 1, 1, -1);
        add(x, y, 1); g[x] += y;
    }
}

void clean() {
    for (int h : history) f[h] = g[h] = 0;
    bad = 0;
    history.clear();
}

void solve() {
    scanf("%d%d", &n, &q);
    clean(); gao(n);

    while (q--) {
        int op; scanf("%d", &op);
        if (op == 1) {
            int v; scanf("%d", &v);
            gao(v);
            if (bad == 0) printf("YES\n");
            else printf("NO\n");
        } else {
            clean(); gao(n);
        }
    }
}

int main() {
    for (int i = 2; i <= MAXN; i++) if (fac[i].empty()) for (int j = i; j <= MAXN; j += i) {
        int cnt = 0;
        for (int x = j; x % i == 0; x /= i) cnt++;
        fac[j].push_back(pii(i, cnt));
    }

    int tcase; scanf("%d", &tcase);
    while (tcase--) {
        solve();
        if (tcase) printf("\n");
    }
    return 0;
}
