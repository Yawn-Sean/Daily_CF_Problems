#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef long double ldb;

int n, L, V1, V2;
ldb ans[MAXN + 5];

int main() {
    scanf("%d%d%d%d", &n, &L, &V1, &V2);
    ldb len = 1.0 * L * V2 / (V1 + V2);

    vector<ldb> vec, keys;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        vec.push_back(x); vec.push_back(x + 1.0 * L * 2);
        keys.push_back(x);
        ldb t = x - len;
        while (t < 0) t += L * 2;
        keys.push_back(t);
    }
    keys.push_back(0); keys.push_back(L * 2);
    sort(vec.begin(), vec.end());
    sort(keys.begin(), keys.end());

    ldb last = -1;
    for (int i = 1; i < keys.size(); i++) {
        ldb key = keys[i];
        int cnt = lower_bound(vec.begin(), vec.end(), key + len) - lower_bound(vec.begin(), vec.end(), key);
        ans[cnt] += key - keys[i - 1];
    }

    for (int i = 0; i <= n; i++) printf("%.18Lf\n", ans[i] / (L * 2));
    return 0;
}
