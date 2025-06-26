#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    int n; scanf("%d", &n);
    priority_queue<pii, vector<pii>, greater<pii>> pq[2];
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        pq[x].push({y, i});
    }

    while (pq[0].size() + pq[1].size() > 1) {
        pii x = pq[0].top(); pq[0].pop();
        pii y = pq[1].top(); pq[1].pop();
        if (x.first < y.first || (x.first == y.first && pq[0].size() > pq[1].size())) {
            printf("%d %d %d\n", x.second, y.second, x.first);
            y.first -= x.first;
            pq[1].push(y);
        } else {
            printf("%d %d %d\n", x.second, y.second, y.first);
            x.first -= y.first;
            pq[0].push(x);
        }
    }
    return 0;
}
