#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);

    long long ans = 0;
    vector<array<int, 3>> vec;
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        ans = max(ans, 1LL * x * y);
        vec.push_back({x, y, i});
        vec.push_back({y, x, i});
    }

    sort(vec.begin(), vec.end());
    vector<vector<int>> idx(n + 1);
    for (int i = 0; i < vec.size(); i++) idx[vec[i][2]].push_back(i);

    multiset<int> ms;
    for (int i = 0; i < vec.size(); i++) ms.insert(vec[i][1]);
    for (int i = 0; i < vec.size(); i++) {
        ms.erase(ms.find(vec[i][1]));
        int which = vec[i][2];
        int j = idx[which][0] + idx[which][1] - i;
        if (j > i) ms.erase(ms.find(vec[j][1]));
        if (ms.size() > 0) {
            int t = min(vec[i][1], *prev(ms.end()));
            ans = max(ans, 2LL * vec[i][0] * t);
        }
        if (j > i) ms.insert(vec[j][1]);
    }

    if (ans % 2 == 0) printf("%lld.0\n", ans / 2);
    else printf("%lld.5\n", ans / 2);
    return 0;
}
