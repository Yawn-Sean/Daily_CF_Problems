#include <bits/stdc++.h>
constexpr int MAXN = 3e5;
using namespace std;

int n, m, A[MAXN + 5];
long long ans;

vector<int> vec[MAXN + 5];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        A[x] = i;
    }
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        x = A[x]; y = A[y];
        if (x > y) swap(x, y);
        vec[y].push_back(x);
    }

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        for (int x : vec[i]) mx = max(mx, x);
        ans += i - mx;
    }
    printf("%lld\n", ans);
    return 0;
}
