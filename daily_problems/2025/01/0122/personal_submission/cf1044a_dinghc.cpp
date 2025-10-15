#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1'000'000'000;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> vs(n);
    for (auto& x : vs) scanf("%d", &x);
    ranges::sort(vs);
    vs.push_back(N);
    vector<int> hs;
    for (int i = 0, x1, x2, y; i < m; i++) {
        scanf("%d%d%d", &x1, &x2, &y);
        if (x1 == 1) hs.push_back(x2);
    }
    ranges::sort(hs);
    int k = hs.size();
    int ans = k;
    for (int i = 0, j = 0; i <= n; i++) {
        while (j < k && hs[j] < vs[i]) j++;
        ans = min(ans, i + k - j);
    }
    printf("%d\n", ans);
    return 0;
}

