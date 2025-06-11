#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    int n; scanf("%d", &n);
    vector<pii> vec;
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        vec.push_back({x, y});
    }
    sort(vec.begin(), vec.end(), [&](pii &a, pii &b) {
        double pa = 0.01 * a.second, pb = 0.01 * b.second;
        return (1 - pa) * pb * b.first < (1 - pb) * pa * a.first;
    });
    double ans = 0, sm = 0;
    for (pii p : vec) {
        double w = 0.01 * p.second;
        ans += p.first + (1 - w) * sm;
        sm += w * p.first;
    }
    printf("%.12f\n", ans);
    return 0;
}
