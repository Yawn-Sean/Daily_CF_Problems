#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXQ ((int) 2e5)
using namespace std;
typedef pair<int, int> pii;

int n, q, A[MAXN + 10], ans[MAXQ + 10];
array<int, 3> qry[MAXQ + 10];

int tree[MAXN + 10];

int lb(int x) { return x & (-x); }

void add(int pos) {
    for (; pos <= n; pos += lb(pos)) tree[pos]++;
}

int gao(int K) {
    int pos = 0;
    for (int p = __lg(n), sm = 0; p >= 0; p--) {
        int nxt = pos + (1 << p);
        if (nxt <= n && sm + tree[nxt] < K) pos = nxt, sm += tree[nxt];
    }
    return A[pos + 1];
}

int main() {
    scanf("%d", &n);
    vector<pii> vec;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        vec.push_back({-A[i], i});
    }
    sort(vec.begin(), vec.end());

    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        scanf("%d%d", &qry[i][0], &qry[i][1]);
        qry[i][2] = i;
    }
    sort(qry + 1, qry + q + 1);

    for (int i = 1, j = 0; i <= q; i++) {
        while (j < qry[i][0]) add(vec[j].second), j++;
        ans[qry[i][2]] = gao(qry[i][1]);
    }
    for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
    return 0;
}
