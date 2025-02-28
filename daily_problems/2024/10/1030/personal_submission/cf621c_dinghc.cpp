#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, p;
    scanf("%d%d", &n, &p);
    vector<int> ls(n), rs(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &ls[i], &rs[i]);
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
        int l1 = ls[i], r1 = rs[i];
        int l2 = ls[(i + 1) % n], r2 = rs[(i + 1) % n];
        long long de = 1LL * (r1 - l1 + 1) * (r2 - l2 + 1);
        long long nu = de - 1LL * (r1 - l1 + 1 - r1 / p + (l1 - 1) / p) * (r2 - l2 + 1 - r2 / p + (l2 - 1) / p);
        ans += static_cast<double>(nu) / de;
    }
    printf("%.12f\n", ans * 2000);
    return 0;
}

