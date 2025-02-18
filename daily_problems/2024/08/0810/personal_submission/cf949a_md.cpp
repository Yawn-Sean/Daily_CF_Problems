// 0810
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    std::stack<int> end1;
    std::stack<int> end0;
    std::vector<std::vector<int>> ret;

    for (int i = 0; i < ssize(s); ++i) {
        if (s[i] == '0') {
            if (!empty(end1)) {
                end0.push(end1.top());
                end1.pop();
                ret[end0.top()].push_back(i);
            } else {
                end0.push(size(ret));
                ret.push_back({i});
            }
        } else {
            if (empty(end0)) {
                std::cout << "-1\n";
                return 0;
            } else {
                end1.push(end0.top());
                end0.pop();
                ret[end1.top()].push_back(i);
            }
        }
    }

    if (!empty(end1)) {
        std::cout << "-1\n";
        return 0;
    }

    std::cout << size(ret) << '\n';
    for (auto &v : ret) {
        std::cout << size(v) << ' ';
        for (auto &x : v) {
            std::cout << x + 1 << ' ';
        }
        std::cout << '\n';
    }


    return 0;
}