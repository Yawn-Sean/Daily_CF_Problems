#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 inf = 1e18;
i64 mod = 1e9+9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
        首先双方的最优策略就是拿最大 / 最小 所以可以分开独立考虑

        其次 拿走方块的条件是 它不会影响其它的方块支撑

        find_support 函数用来找到一个方块的支撑数
        check 函数用来判断一个方块是否可以拿走 如果方块上面不存在以当前方块为唯一支撑的方块 则可以拿走
        为什么在弹出的时候多检查一次也是对的 / 没有直接找同层中变为唯一支撑的元素
        
        不会超时是因为 每个错误的方块只会被额外查一次
    */
    int m;
    cin >> m;
    vector<pair<int,int>> pts(m);
    for (auto& [x,y] : pts) cin >> x >> y;

    map<pair<int,int>,int> mp;
    for (int i = 0; i < m; i++) {
        mp[pts[i]] = i;
    }

    vector<int> used(m);
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int> > pq2;

    auto find_support = [&](int x, int y) {
        int cnt = 0;
        for (int dx = -1; dx < 2; dx++) {
            if (mp.find({x + dx, y - 1}) != mp.end()) {
                cnt++;
            }
        }
        return cnt;
    };

    auto check = [&](int x, int y) {
        if (mp.find({x, y}) == mp.end()) return false;
        for (int dx = -1; dx < 2; dx++) {
            if (mp.find({x + dx, y + 1}) != mp.end() && find_support(x + dx, y + 1) == 1) {
                return false;
            }
        }
        return true;
    };

    for (int i = 0; i < m; i++) {
        auto& [x, y] = pts[i];
        if (check(x, y)) {
            pq1.push(i);
            pq2.push(i);
        }
    }

    i64 ans = 0;
    for (int i = 0; i < m; i++) {
        while (1) {
            int u;
            if (i % 2 == 0) {
                while (used[pq1.top()]) pq1.pop();
                u = pq1.top();
                pq1.pop();
            }
            else {
                while (used[pq2.top()]) pq2.pop();
                u = pq2.top();
                pq2.pop();
            }

            auto& [x, y] = pts[u];
            if (check(x, y)) {
                ans = (ans * m + u) % mod;
                used[u] = 1;
                mp.erase(pts[u]);
                for (int dx = -1; dx < 2; dx++) {
                    if (check(x + dx, y - 1)) {
                        int v = mp[{x + dx, y - 1}];
                        pq1.push(v);
                        pq2.push(v);
                    }
                }
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
