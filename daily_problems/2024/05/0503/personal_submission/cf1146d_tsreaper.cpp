#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;

int K, n, m;
long long ans;

int lim, dis[MAXN * 2 + 10];
long long f[MAXN * 2 + 10];

void dijkstra() {
    memset(dis, -1, sizeof(int) * (lim + 3));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        pii p = pq.top(); pq.pop();
        int sn = p.second;
        if (dis[sn] >= 0) continue;
        dis[sn] = p.first;
        
        auto add = [&](int fn) {
            if (dis[fn] >= 0) return;
            pq.push({max(dis[sn], fn), fn});
        };
        if (sn + n <= lim) add(sn + n);
        if (sn - m >= 0) add(sn - m);
    }
}

int main() {
    scanf("%d%d%d", &K, &n, &m);

    lim = max(n, m) * 2;
    dijkstra();
    f[0] = 1;
    for (int i = 1; i <= lim; i++) if (dis[i] >= 0) f[dis[i]]++;
    for (int i = 1; i <= lim; i++) f[i] += f[i - 1];

    for (int i = 0; i <= lim && i <= K; i++) ans += f[i];
    if (K > lim) {
        long long g = gcd(n, m);
        long long L = (lim + 1) / g, R = K / g;
        if (L == R) ans += L * (K - lim);
        else {
            long long t = (L + 1) * g;
            ans += L * (t - lim - 1);
            t = R * g;
            ans += R * (K - t + 1);
            ans += (L + R) * (R - L - 1) / 2 * g;
        }
        ans += K - lim;
    }

    printf("%lld\n", ans);
    return 0;
}
