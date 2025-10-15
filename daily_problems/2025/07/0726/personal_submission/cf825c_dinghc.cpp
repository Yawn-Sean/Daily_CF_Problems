#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a(n);
    for (auto& x : a) {
        scanf("%d", &x);
    }
    ranges::sort(a);
    int ans = 0, u = k << 1;
    for (auto& x : a) {
        while (u < x) {
            u <<= 1;
            ans += 1;
        }
        u = max(u, x << 1);
    }
    printf("%d\n", ans);
    return 0;
}

