#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
typedef pair<int, int> pii;

int n, A[MAXN + 10], B[MAXN + 10];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &B[i]);

    long long sm = 0;
    for (int i = 1; i <= n; i++) sm += abs(A[i] - B[i]);

    vector<pii> xn, nx;
    for (int i = 1; i <= n; i++) {
        int mn = min(A[i], B[i]), mx = max(A[i], B[i]);
        xn.push_back(pii(mx, mn));
        nx.push_back(pii(mn, mx));
    }
    sort(xn.begin(), xn.end());
    sort(nx.begin(), nx.end());

    long long ans = sm;
    int mx = 0;
    while (!xn.empty()) {
        while (!nx.empty() && nx.back().first >= xn.back().first) {
            mx = max(mx, nx.back().first);
            nx.pop_back();
        }
        ans = max(ans, sm + 2LL * (mx - xn.back().first));
        xn.pop_back();
    }
    printf("%lld\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
