#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int N = 1'000'000;
vector<int> lpf(N + 1, 0);
vector<int> pr;

auto init = [] {
    for (int i = 2; i <= N; ++i) {
        if (lpf[i] == 0) {
            lpf[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lpf[i * pr[j]] = pr[j];
            if (pr[j] == lpf[i]) break;
        }
    }
    return 0;
}();

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    vector<int> a{1};
    auto dfs = [&] (auto&& dfs, int cur, int p_idx) -> void {
        for (int i = p_idx; i < pr.size(); i++) {
            if (1LL* cur * pr[i] > n) break;
            a.push_back(cur * pr[i]);
            dfs(dfs, cur * pr[i], i);
        }
    };
    dfs(dfs, 1, 0);
    for (int i = 0, j; i < q; i++) {
        scanf("%d", &j);
        printf("%d\n", a[j - 1]);
    }
    return 0;
}

