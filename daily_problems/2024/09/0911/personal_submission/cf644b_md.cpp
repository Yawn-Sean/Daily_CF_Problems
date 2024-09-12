// 0911
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, b;
    std::cin >> n >> b;
    std::vector<std::pair<int, int>> tasks(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> tasks[i].first >> tasks[i].second;
    }
    
    std::deque<int> jobs;
    std::vector<int> ret(n, -1);
    for (int i = 0; i < n; ++i) {
        auto[st, dur] = tasks[i];
    
        while (!empty(jobs) && jobs.front() <= st) {
            jobs.pop_front();
        }

        if (size(jobs) <= b) {
            if (empty(jobs)) {
                ret[i] = st + dur;
                jobs.push_back(ret[i]);
            } else {
                ret[i] = jobs.back() + dur;
                jobs.push_back(ret[i]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << ret[i] << " \n"[i == n - 1];
    }

    return 0;
}