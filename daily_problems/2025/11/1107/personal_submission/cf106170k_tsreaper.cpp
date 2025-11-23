#include <bits/stdc++.h>
#define MAXN ((int) 1e3)
using namespace std;

int n, m, A[MAXN + 5];
long long B[MAXN + 5][4];

vector<int> e[MAXN + 5];
vector<long long> v[MAXN + 5];

bool inq[MAXN + 5];
long long dis[MAXN + 5];
int cnt[MAXN + 5];

bool check(long long K) {
    for (int i = 0; i <= n; i++) e[i].clear(), v[i].clear();
    for (int i = 1; i <= n; i++) {
        e[i - 1].push_back(i); v[i - 1].push_back(A[i] + K);
        e[i].push_back(i - 1); v[i].push_back(-max(1LL, A[i] - K));
    }
    for (int i = 1; i <= m; i++) {
        e[B[i][0] - 1].push_back(B[i][1]); v[B[i][0] - 1].push_back(B[i][3]);
        e[B[i][1]].push_back(B[i][0] - 1); v[B[i][1]].push_back(-B[i][2]);
    }

    for (int i = 0; i <= n; i++) inq[i] = false, dis[i] = 1e18, cnt[i] = 0;
    queue<int> q;
    q.push(0); inq[0] = true; dis[0] = 0; cnt[0] = 0;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        inq[sn] = false;
        for (int i = 0; i < e[sn].size(); i++) {
            int fn = e[sn][i];
            long long d = dis[sn] + v[sn][i];
            if (dis[fn] <= d) continue;
            dis[fn] = d; cnt[fn] = cnt[sn] + 1;
            if (cnt[fn] > n) return false;
            if (inq[fn]) continue;
            q.push(fn); inq[fn] = true;
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= m; i++) for (int j = 0; j < 4; j++) scanf("%lld", &B[i][j]);

    if (!check(1e12)) { printf("-1\n"); return 0; }
    long long head = 0, tail = 1e12;
    while (head < tail) {
        long long mid = (head + tail) >> 1;
        if (check(mid)) tail = mid;
        else head = mid + 1;
    }
    printf("%lld\n", head);
    return 0;
}
