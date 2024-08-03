#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
typedef pair<long long, int> pli;

long long ans[MAXN + 10];

int main() {
    int n, K, X; scanf("%d%d%d", &n, &K, &X);
    vector<pli> pos, neg;
    int flag = 1;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        if (x >= 0) pos.push_back(pli(x, i));
        else flag = -flag, neg.push_back(pli(-x, -i));
    }

    if (flag == 1) {
        sort(pos.begin(), pos.end(), greater<pli>());
        sort(neg.begin(), neg.end(), greater<pli>());
        if (neg.size() == 0 || (pos.size() > 0 && pos.back().first < neg.back().first)) {
            pli p = pos.back(); pos.pop_back();
            while (K > 0 && p.first >= 0) K--, p.first -= X;
            neg.push_back(pli(-p.first, -p.second));
        } else {
            pli p = neg.back(); neg.pop_back();
            while (K > 0 && p.first >= 0) K--, p.first -= X;
            pos.push_back(pli(-p.first, -p.second));
        }
    }

    priority_queue<pli, vector<pli>, greater<pli>> pq;
    for (pli p : pos) pq.push(p);
    for (pli p : neg) pq.push(p);
    while (K > 0) {
        K--;
        pli p = pq.top(); pq.pop();
        pq.push(pli(p.first + X, p.second));
    }
    while (!pq.empty()) {
        pli p = pq.top(); pq.pop();
        ans[abs(p.second)] = p.first * (p.second > 0 ? 1 : -1);
    }
    for (int i = 1; i <= n; i++) printf("%lld%c", ans[i], "\n "[i < n]);
    return 0;
}
