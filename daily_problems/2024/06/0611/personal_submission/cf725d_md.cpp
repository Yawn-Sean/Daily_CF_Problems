// 0611
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    i64 ballnoon0, weight0;
    cin >> ballnoon0 >> weight0;

    std::vector<std::pair<i64, i64>> teams(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> teams[i].first >> teams[i].second;
    }

    std::sort(begin(teams), end(teams), std::greater<>());    

    std::priority_queue<i64, std::vector<i64>, std::greater<>> top_teams;
    int team_idx = 0;

    auto fill_pq = [&]() {
        while (team_idx < size(teams) && teams[team_idx].first > ballnoon0) {
            top_teams.push(teams[team_idx].second - teams[team_idx].first + 1);
            ++team_idx;
        }
    };

    fill_pq();

    int ret = size(top_teams) + 1;
    while (!empty(top_teams) && ballnoon0 >= top_teams.top()) {
        ballnoon0 -= top_teams.top();
        top_teams.pop();
        fill_pq();

        ret = std::min(ret, 1 + static_cast<int>(size(top_teams)));
    }
    std::cout << ret << "\n";

    return 0;
}