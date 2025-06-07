#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int main() {
    int n, K, X, Y; scanf("%d%d%d%d", &n, &K, &X, &Y);
    X = min(X, 5 * Y);

    vector<int> vec[5], keys[5];
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        vec[(x % 5 + 5) % 5].push_back(x);
        for (int j = 0; j < 5; j++) {
            int y = x + j;
            keys[(y % 5 + 5) % 5].push_back(y);
        }
    }
    for (int i = 0; i < 5; i++) {
        sort(vec[i].begin(), vec[i].end());
        sort(keys[i].begin(), keys[i].end());
    }

    long long ans = 4e18;
    for (int r = 0; r < 5; r++) {
        int idx[5] = {0};
        priority_queue<long long> pq;
        long long delta = 0, sm = 0;
        for (int i = 0; i < keys[r].size(); i++) {
            if (i > 0) {
                int d = (keys[r][i] - keys[r][i - 1]) / 5;
                delta += 1LL * X * d;
                sm += 1LL * pq.size() * X * d;
            }
            for (int j = 0; j < 5; j++) {
                while (idx[j] < vec[j].size() && vec[j][idx[j]] <= keys[r][i]) {
                    int d = keys[r][i] - vec[j][idx[j]];
                    long long t = 1LL * X * (d / 5) + 1LL * Y * (d % 5);
                    pq.push(t - delta);
                    sm += t;
                    idx[j]++;
                }
            }
            while (pq.size() > K) {
                long long t = pq.top(); pq.pop();
                sm -= t + delta;
            }
            if (pq.size() == K) ans = min(ans, sm);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
