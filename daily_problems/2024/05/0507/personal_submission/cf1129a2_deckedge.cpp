#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = red(), m = red();
    vector a(n, vector<int>());
    vector<int> b(n);
    rep(i, 0, m) {
        int u = red(), v = red();
        u--, v--;
        a[u].emplace_back(v);
    }

    rep(i, 0, n) {
        rep(j, 0, a[i].size()) {
            int ed = a[i][j];
            if (ed > i) {
                if (!b[i]) {
                    b[i] = ed - i;
                } else {
                    b[i] = min(b[i], ed - i);
                }
            } else {
                if (!b[i]) {
                    b[i] = n - i + ed;
                } else {
                    b[i] = min(b[i], n - i + ed);
                }
            }
        }
    }

    rep(i, 0, n) {
        int res = 0;
        rep(j, 0, n) {
            int cur = 0;
            if (j >= i) {
                cur += j - i;
            } else {
                cur += n - i + j;
            }
            int t = a[j].size();
            if (!t) {
                continue;
            }
            cur += (t - 1) * n + b[j];
            res = max(res, cur);
        }
        cout << res << " \n"[i == n - 1];
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}


/*
对于每一个点，假设当前点为x
如果x上没有糖果，显然不用管
如果x上有k颗糖果，因为每次只能把一颗糖装上车，所以至少经过这个点t次
经过k次则一定已经走完了t-1圈，所以先上车的t-1个糖果肯定已经到达目的地了
那么考虑最后一个糖果，对于点x，最后一个运送的糖果肯定选择目的地距离x最小的
(距离大的优先在前面的t-1圈送掉)，这样能保证总路程最小

dist 表示把糖果从a送到b所需要的距离有两种情况st为出发点ed为糖果的位置当ed > st是 dist = ed - st，负责dist = n - st + ed;
b[a]表示以a为起点的到达终点所需的最小距离(作为运送的最后一颗糖)
ans=dist + n * (t-1) + b[x]
以st为起点送完所有糖的最少时间就是x从0到n-1遍历取得的最大值

*/