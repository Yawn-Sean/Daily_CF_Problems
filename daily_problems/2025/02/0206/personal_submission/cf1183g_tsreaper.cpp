#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, cnt[MAXN + 5][2];
long long ans1, ans2;

vector<int> vec[MAXN + 5];

void solve() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) cnt[i][0] = cnt[i][1] = 0;
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        cnt[x][y]++;
    }

    for (int i = 1; i <= n; i++) vec[i].clear();
    for (int i = 1; i <= n; i++) if (cnt[i][0] + cnt[i][1] > 0) vec[cnt[i][0] + cnt[i][1]].push_back(cnt[i][0]);

    ans1 = ans2 = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    int bias = 0;
    for (int i = n; i > 0; i--) {
        for (int x : vec[i]) pq.push(x - bias);
        if (!pq.empty()) {
            ans1 += i;
            ans2 += i - max(0, pq.top() + bias);
            pq.pop();
            bias--;
        }
    }
    printf("%lld %lld\n", ans1, ans2);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
