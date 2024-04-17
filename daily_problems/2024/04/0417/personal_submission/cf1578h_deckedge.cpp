#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pi pair<int, int>
#define all(x) (x).begin(), (x).end()

inline int red() {
    int x;
    cin >> x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    stack<int> l;
    stack<pi> r;

    for (int i = 0; i < n; ++i) {
        char x = s[i];
        if (x == '(') {
            l.push(i);
        } else if (x == ')') {
            if (l.top() == i - 1) {
                l.pop();
                r.emplace(i - 1, 0);
            } else {
                auto [pos, v] = r.top();
                r.pop();
                while (!r.empty() && r.top().fi > l.top()) {
                    auto [pos, u] = r.top();
                    r.pop();
                    v = max(v, u + 1);
                }
                r.emplace(l.top(), v);
                l.pop();
            }
        }
    }

    auto [pos, res] = r.top();
    r.pop();
    while (!r.empty()) {
        auto [pos, v] = r.top();
        res = max(res, v + 1);
        r.pop();
    }
    cout << res << '\n';
    return 0;
}

