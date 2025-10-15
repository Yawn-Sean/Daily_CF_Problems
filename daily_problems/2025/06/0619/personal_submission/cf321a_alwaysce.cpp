#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    map<char, pair<int,int>> mp;
    mp['U'] = {0, 1};
    mp['D'] = {0, -1};
    mp['L'] = {-1, 0};
    mp['R'] = {1, 0};

    i64 a, b;
    cin >> a >> b;

    i64 dx = 0, dy = 0;
    string s;
    cin >> s;
    for (char c : s) {
        dx += mp[c].first;
        dy += mp[c].second;
    }

    i64 cur_x = 0, cur_y = 0;

    auto check = [&]() {
        i64 step = 0;
        if (dx) {
            step = (a - cur_x) / dx;
        }
        if (dy) {
            step = (b - cur_y) / dy;
        }
        return cur_x + step * dx == a && cur_y + step * dy == b && step >= 0;
    };

    for (int i = 0; i < (int)s.size(); i++) {
        if (check()) {
            cout << "Yes\n";
            return 0;
        }
        cur_x += mp[s[i]].first;
        cur_y += mp[s[i]].second;
    }

    cout << "No\n";
    return 0;
}
