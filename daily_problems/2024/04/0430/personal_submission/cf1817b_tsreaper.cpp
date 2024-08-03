#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

int n, m;

struct Edge {
    int fn, nxt;
};
vector<Edge> e;
int p[MAXN + 10];

int dis[MAXN + 10];
bool used[MAXN + 10];

void adde(int sn, int fn) {
    int idx = e.size();
    e.push_back({fn, p[sn]}); p[sn] = idx;
    idx = e.size();
    e.push_back({sn, p[fn]}); p[fn] = idx;
}

bool check(int ban) {
    int S = e[ban * 2].fn, T = e[ban * 2 + 1].fn;
    memset(dis, -1, sizeof(int) * (n + 3));
    queue<int> q;
    q.push(S); dis[S] = 0;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int i = p[sn]; i >= 0; i = e[i].nxt) if (i / 2 != ban) {
            int fn = e[i].fn;
            if (dis[fn] >= 0) continue;
            q.push(fn); dis[fn] = dis[sn] + 1;
        }
    }
    if (dis[T] < 0) return false;

    memset(used, 0, sizeof(bool) * (n + 3));
    vector<int> vec;
    for (int sn = T; sn != S; ) {
        used[sn] = true; vec.push_back(sn);
        for (int i = p[sn]; i >= 0; i = e[i].nxt) {
            int fn = e[i].fn;
            if (dis[sn] - dis[fn] == 1) { sn = fn; break; }
        }
    }
    used[S] = true; vec.push_back(S);

    auto gao = [&](int sn) {
        vector<int> tails;
        for (int i = p[sn]; i >= 0; i = e[i].nxt) {
            int fn = e[i].fn;
            if (!used[fn]) tails.push_back(fn);
        }

        if (tails.size() >= 2) {
            printf("YES\n%d\n", vec.size() + 2);
            for (int i = 1; i < vec.size(); i++) printf("%d %d\n", vec[i - 1], vec[i]);
            printf("%d %d\n", S, T);
            for (int i = 0; i < 2; i++) printf("%d %d\n", sn, tails[i]);
            return true;
        }
        return false;
    };

    return gao(S) || gao(T);
}

void solve() {
    scanf("%d%d", &n, &m);
    e.clear();
    memset(p, -1, sizeof(int) * (n + 3));
    for (int i = 0; i < m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        adde(x, y);
    }

    for (int i = 0; i < m; i++) if (check(i)) return;
    printf("NO\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
