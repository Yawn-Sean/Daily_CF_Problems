// 0509
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    map<int, multiset<int>> votes;
    for (int i = 0; i < n; ++i) {
        int p, c;
        cin >> p >> c;
        --p;
        votes[p].insert(c);
    }

    auto upb_votes = ssize(votes[0]);

    i64 ret = numeric_limits<i64>::max();
    for (int ticket = 1; ticket <= n; ++ticket) {
        i64 cost = 0;
        int cur_ticket = upb_votes;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto&[idx, voter] : votes) {
            if (idx == 0) {
                continue;
            }
            int residual = ssize(voter);
            for (auto v : voter) {
                if (residual >= ticket) {
                    cost += v;
                    ++cur_ticket;
                    --residual;
                } else {
                    pq.push(v);
                }
            }
        }

        while (cur_ticket < ticket) {
            cost += pq.top();
            pq.pop();
            ++cur_ticket;
        }
        ret = min(ret, cost);
    }

    std::cout << ret << endl;

    return 0;
}