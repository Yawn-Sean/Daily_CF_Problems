#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXQ ((int) 1e5)
using namespace std;

int n, q;
long long A[MAXN + 10], ans[MAXQ + 10];
array<long long, 3> QRY[MAXQ + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &A[i]);

    sort(A + 1, A + n + 1);
    vector<long long> vec;
    for (int i = 1; i < n; i++) vec.push_back(A[i + 1] - A[i]);
    sort(vec.begin(), vec.end(), greater<long long>());

    scanf("%d", &q);
    for (int i = 1; i <= q; i++) scanf("%lld%lld", &QRY[i][0], &QRY[i][1]), QRY[i][2] = i;
    sort(QRY + 1, QRY + q + 1, [&](array<long long, 3> &a, array<long long, 3> &b) {
        return a[1] - a[0] < b[1] - b[0];
    });

    long long sm = 0;
    for (int i = 1; i <= q; i++) {
        long long len = QRY[i][1] - QRY[i][0];
        while (!vec.empty() && vec.back() <= len) {
            sm += vec.back();
            vec.pop_back();
        }
        ans[QRY[i][2]] = sm + (vec.size() + 1) * (len + 1);
    }

    for (int i = 1; i <= q; i++) printf("%lld%c", ans[i], "\n "[i < q]);
    return 0;
}
