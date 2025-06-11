#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;

int n, K, A[MAXN + 10];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    if (n == 2) {
        printf("0\n1 1\n");
        return 0;
    }

    vector<pii> vec;
    for (int i = 1; i <= n; i++) vec.push_back({A[i], i});
    sort(vec.begin(), vec.end());
    int ans1 = vec[n - 1].first + vec[n - 2].first;
    ans1 -= vec[0].first + vec[1].first;
    int ans2 = vec[n - 1].first + max(vec[n - 2].first, vec[0].first + K);
    ans2 -= vec[1].first + min(vec[2].first, vec[0].first + K);

    if (ans1 < ans2) {
        printf("%d\n", ans1);
        for (int i = 1; i <= n; i++) printf("1%c", "\n "[i < n]);
    } else {
        printf("%d\n", ans2);
        for (int i = 1; i <= n; i++) printf("%d%c", i == vec[0].second ? 1 : 2, "\n "[i < n]);
    }
    return 0;
}
