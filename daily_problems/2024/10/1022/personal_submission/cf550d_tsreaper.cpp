#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    int n; scanf("%d", &n);
    if (n % 2 == 0) { printf("NO\n"); return 0; }
    vector<pii> vec;
    auto gao = [&](int base) {
        for (int i = 1; i < n; i++) vec.push_back({base, base + i});
        for (int i = 1; i < n; i++) for (int j = 1; j < n; j++) vec.push_back({base + i, base + n - 1 + j});
        for (int j = 1; j < n; j += 2) vec.push_back({base + n - 1 + j, base + n + j});
    };
    gao(1); gao(n * 2);
    vec.push_back({1, n * 2});
    printf("YES\n%d %d\n", 4 * n - 2, vec.size());
    for (pii p : vec) printf("%d %d\n", p.first, p.second);
    return 0;
}
