#include <bits/stdc++.h>
#define MAXN ((int) 4e5)
#define INF ((int) 1e9)
using namespace std;
typedef pair<int, int> pii;

int n;
char s[MAXN + 5];

pii f[MAXN + 5], g[26];

int main() {
    scanf("%d%s", &n, s + 1);

    for (int i = 0; i < 26; i++) g[i] = pii(-INF, -INF);
    g[s[1] - 'a'] = pii(0, 0);
    f[1] = pii(-INF, -INF);
    for (int i = 2; i <= n; i++) {
        pii p = g[s[i] - 'a'];
        p.first++;
        f[i] = p;
        g[s[i] - 'a'] = max(g[s[i] - 'a'], pii(f[i - 1].first, i - 1));
    }

    if (f[n].first < 0) printf("-1\n");
    else {
        printf("%d\n", f[n].first);
        vector<int> vec;
        for (int i = n; i > 0; i = f[i].second) vec.push_back(i - f[i].second);
        reverse(vec.begin(), vec.end());
        for (int x : vec) printf("%d ", x);
        printf("\n");
    }
    return 0;
}
