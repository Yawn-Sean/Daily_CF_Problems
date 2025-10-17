#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int m = 0, q = n;
    while (q) {
        q /= 10;
        m += 1;
    }
    m = max(m, 1);
    set<int> s;
    for (int a = 0; a < 10; a++) {
        for (int b = a; b < 10; b++) {
            auto dfs = [&] (auto&& dfs, int i, long long curr) -> void {
                if (i == m) return;
                if (curr * 10 + a <= n) {
                    s.insert(curr * 10 + a);
                    dfs(dfs, i + 1, curr * 10 + a);
                }
                if (curr * 10 + b <= n) {
                    s.insert(curr * 10 + b);
                    dfs(dfs, i + 1, curr * 10 + b);
                }
            };
            dfs(dfs, 0, 0);
        }
    }
    int ans = 0;
    for (auto& x : s) {
        if (x > n / 2) break;
        if (s.count(n - x) > 0) {
            ans += 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}

