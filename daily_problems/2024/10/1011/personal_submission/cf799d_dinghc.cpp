#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100'000;
int t[N];

int main() {
    int a, b, h, w, n;
    scanf("%d%d%d%d%d", &a, &b, &h, &w, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    sort(t, t + n, greater<int>());
    function<int(int, int)> solve = [&] (int x, int y) {
        map<pair<int, int>, int> cost;
        cost[{x, y}] = 0;
        vector<pair<int, int>> q;
        q.emplace_back(x, y);
        for (int i = 0; i < n; i++) {
            vector<pair<int, int>> nq;
            for (auto& [kx, ky] : q) {
                if (kx == 1 && ky == 1) return cost[{1, 1}];
                int v = cost[{kx, ky}];
                int nx = (kx + t[i] - 1) / t[i];
                int ny = (ky + t[i] - 1) / t[i];
                if (cost.find({nx, ky}) == cost.end()) {
                    cost[{nx, ky}] = v + 1;
                    nq.emplace_back(nx, ky);
                }
                if (cost.find({kx, ny}) == cost.end()) {
                    cost[{kx, ny}] = v + 1;
                    nq.emplace_back(kx, ny);
                }
            }
            q = move(nq);
        }
        return cost.find({1, 1}) == cost.end() ? n + 1 : cost[{1, 1}];
    };
    int ans = min(solve((a + h - 1) / h, (b + w - 1) / w), solve((a + w - 1) / w, (b + h - 1) / h));
    printf("%d\n", ans > n ? -1 : ans);
    return 0;
}

