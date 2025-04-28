#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;
typedef pair<long long, int> pli;

int n, m, X, Y;
vector<pii> ans;

int root[MAXN + 5];
long long sm[MAXN + 5];

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

bool solve() {
    scanf("%d%d%d%d", &n, &m, &X, &Y);
    for (int i = 1; i <= n; i++) root[i] = i;
    for (int i = 1; i <= m; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        x = findroot(x); y = findroot(y);
        if (x != y) root[y] = x, sm[x] += sm[y];
        sm[x] += z;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) if (i == findroot(i)) cnt++;
    if (cnt < Y) return false;
    if (cnt == n && Y == n && X > 0) return false;
    if (cnt - X > Y) return false;

    priority_queue<pli, vector<pli>, greater<pli>> pq;
    for (int i = 1; i <= n; i++) if (i == findroot(i)) pq.push({sm[i], i});
    while (cnt > Y) {
        pli a = pq.top(); pq.pop();
        pli b = pq.top(); pq.pop();
        ans.push_back({a.second, b.second});
        root[b.second] = a.second;
        sm[a.second] += sm[b.second];
        sm[a.second] += min((long long) 1e9, sm[a.second] + 1);
        pq.push({sm[a.second], a.second});
        cnt--; X--;
    }

    for (int i = 1; i <= n; i++) if (i == findroot(i) && sm[i] > 0) {
        for (int j = 1; j <= n; j++) if (i != j && findroot(i) == findroot(j)) {
            while (X > 0) {
                ans.push_back({i, j});
                X--;
            }
            return true;
        }
    }
    return true;
}

int main() {
    if (solve()) {
        printf("YES\n");
        for (pii p : ans) printf("%d %d\n", p.first, p.second);
    } else {
        printf("NO\n");
    }
    return 0;
}
