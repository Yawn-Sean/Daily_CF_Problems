#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, m, q;
array<long long, 3> A[MAXN + 5];
long long B[MAXN + 5];

void solve() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) scanf("%lld", &A[i][1]);
    for (int i = 1; i <= n; i++) scanf("%lld", &A[i][0]);
    sort(A + 1, A + n + 1);
    for (int i = 1; i <= m; i++) scanf("%lld", &B[i]);

    multiset<long long> ms;
    long long sm = 0, bias = 0;
    for (int i = 1; i <= n; i++) {
        sm += A[i][1];
        A[i][2] = A[i][0] - sm;
        ms.insert(A[i][2]);
    }

    vector<long long> vec;
    sm = 0;
    for (int i = 1, j = 1; i <= m; i++) {
        while (!ms.empty() && *(ms.begin()) + bias - B[i] < 0) {
            sm += A[j][1];
            ms.erase(ms.find(A[j][2]));
            j++;
        }
        sm += B[i];
        bias -= B[i];
        vec.push_back(sm);
    }

    for (int i = 1; i <= q; i++) {
        long long x; scanf("%lld", &x);
        printf("%d%c", upper_bound(vec.begin(), vec.end(), x) - vec.begin(), "\n "[i < q]);
    }
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
