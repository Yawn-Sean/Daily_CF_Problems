// 0524
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, d;
    std::cin >> n >> d;
    vector<int> a(n, 0);
    for (int i = 1; i < n - 1 ; ++i) {
        cin >> a[i];
    }

    vector<pair<int, int>> points;
    points.reserve(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(--x, --y);
    }

    auto calc_cost = [&](int i, int j) {
        return d * (abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second)) - a[i];
    };

    vector<vector<pii>> graph(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            graph[i].emplace_back(j, calc_cost(j, i));
            graph[j].emplace_back(i, calc_cost(i, j));
        }
    }

    vector<int> dist(n, std::numeric_limits<int>::max());
    dist[0] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // {cost, idx}

    deque<bool> visited(n, false);
    while (!empty(pq)) {
        auto [dis, idx] = pq.top();
        pq.pop();

        if (visited[idx] || dist[idx] < dis) {
            continue;
        }

        visited[idx] = true;
        for (auto [next, next_dis] : graph[idx]) {
            auto new_cost = dis + next_dis;
            if (new_cost < dist[next]) {
                dist[next] = new_cost;
                pq.push({dist[next], next});
            }
        }
    }

    cout << dist[n - 1] << endl;

    return 0;
}