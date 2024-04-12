#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; std::cin >> n;
    int sx, sy; cin >> sx >> sy;
    queue<int> same;
    queue<int> diff;
    for (int i = 1; i <= n; ++i) {
        int x, y; cin >> x >> y;
        if ((sx + sy + x + y) % 2 == 0) {
            same.push(i);
        } else {
            diff.push(i);
        }
    }

    deque<bool> used(n + 1, false);
    auto print_list = [&](auto& v1, auto& v2, int is_first) {
        for (int i = 0; i < n; ++i) {
            if (i % 2 == is_first) {
                int x{};
                cin >> x;
                used[x] = true;
            } else {
                while (!empty(v1) && used[v1.front()]) {
                    v1.pop();
                }

                while (!empty(v2) && used[v2.front()]) {
                    v2.pop();
                }

                if (!empty(v1)) {
                    cout << v1.front() << endl;
                    v1.pop();
                } else {
                    cout << v2.front() << endl;;
                    v2.pop();
                }
            }
        }
    };

    if (size(same) >= size(diff)) {
        cout << "First" << endl;
        print_list(diff, same, 1);
    } else {
        cout << "Second" << endl;
        print_list(same, diff, 0);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 0;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}