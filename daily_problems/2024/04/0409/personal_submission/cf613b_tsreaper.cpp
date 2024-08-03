#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;
 
int n, A[MAXN + 10];
long long K, c1, c2, m, ans;

vector<pii> vec;
long long f[MAXN + 10];

bool check(int pos, int lim, long long rem) {
    if (pos == 0 || vec[0].first >= lim) return true;
    int head = 0, tail = pos - 1;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (vec[mid].first < lim) head = mid;
        else tail = mid - 1;
    }
    return 1LL * (head + 1) * lim - f[head + 1] <= rem;
}

long long gao(int pos, bool flag) {
    long long t = K * (n - pos) - (f[n] - f[pos]);
    if (t > m) return -1e18;
    int head = 0, tail = K;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (check(pos, mid, m - t)) head = mid;
        else tail = mid - 1;
    }

    if (flag) {
        for (int i = 0; i < pos; i++) A[vec[i].second] = max(head, vec[i].first);
        for (int i = pos; i < n; i++) A[vec[i].second] = K;
    }
    return (n - pos) * c1 + head * c2;
}

int main() {
    scanf("%d%lld%lld%lld%lld", &n, &K, &c1, &c2, &m);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        vec.push_back(pii(x, i));
    }

    sort(vec.begin(), vec.end());
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] + vec[i - 1].first;

    int best = n;
    for (int i = n; i >= 0; i--) {
        long long t = gao(i, false);
        if (t > ans) ans = t, best = i;
    }
    printf("%lld\n", ans);
    gao(best, true);
    for (int i = 1; i <= n; i++) printf("%d%c", A[i], "\n "[i < n]);
    return 0;
}
