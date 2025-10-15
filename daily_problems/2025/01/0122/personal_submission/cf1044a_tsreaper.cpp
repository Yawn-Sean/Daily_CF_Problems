#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; scanf("%d%d", &n, &m);

    vector<int> V;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        V.push_back(x);
    }
    sort(V.begin(), V.end());
    if (V.empty() || V.back() != 1e9) V.push_back(1e9);

    vector<int> H;
    for (int i = 1; i <= m; i++) {
        int l, r; scanf("%d%d%*d", &l, &r);
        if (l == 1) H.push_back(r);
    }
    sort(H.begin(), H.end());

    int ans = n + m;
    for (int i = 0, j = 0; i < V.size(); i++) {
        while (j < H.size() && H[j] < V[i]) j++;
        ans = min(ans, i + (int) H.size() - j);
    }
    printf("%d\n", ans);
    return 0;
}
