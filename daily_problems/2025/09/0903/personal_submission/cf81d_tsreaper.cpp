#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;
typedef pair<int, int> pii;

int n, m, ans[MAXN + 5];

int main() {
    scanf("%d%d", &n, &m);

    int tot = 0;
    vector<pii> vec;
    for (int i = 1; i <= m; i++) {
        int x; scanf("%d", &x);
        x = min(x, n / 2);
        tot += x;
        vec.push_back({x, i});
    }
    if (tot < n) { printf("-1\n"); return 0; }
    sort(vec.begin(), vec.end(), greater<pii>());
    
    vector<int> ord;
    for (int i = 1; i <= n; i += 2) ord.push_back(i);
    for (int i = 2; i <= n; i += 2) ord.push_back(i);

    int idx = 0;
    for (pii p : vec) for (int i = 1; i <= p.first && idx < n; i++, idx++)
        ans[ord[idx]] = p.second;
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
    return 0;
}
