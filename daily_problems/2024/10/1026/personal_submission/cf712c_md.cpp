// 1026
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, y;
    std::cin >> x >> y;

    std::priority_queue<int, std::vector<int>, std::greater<>> pq;
    pq.push(y);
    pq.push(y);
    pq.push(y);

    int ret = 0;
    while (pq.top() != x) {
        auto a = pq.top();
        pq.pop();
        auto b = pq.top();
        pq.pop();
        auto c = pq.top();
        pq.pop();

        a = std::min(x, c + b - 1);

        pq.push(a);
        pq.push(b);
        pq.push(c);
        ++ret;
    }

    std::cout << ret << '\n';

    return 0;
}