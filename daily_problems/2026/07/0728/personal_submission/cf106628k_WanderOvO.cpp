/*
直观的想法是，肯定是删除本来就比较远的一些点
我们把曼哈顿距离转切比雪夫距离
|a| + |b| = max(|a + b|, |a - b|)
a = x1 - x2
b = y1 - y2
|x1 - x2| + |y1 - y2| = max(|(x1 - x2) + (y1 - y2)|, |(x1 - x2) - (y1 - y2)|)
= max(|(x1 + y1) - (x2 + y2)|, |(x1 - y1) - (x2 - y2)|)
如果令 u = x + y, v = x - y
则 A = (x1, y1) 到 B = (x2, y2) 的曼哈顿距离
其实就是变换后的 C = (x1 + y1, x1 - y1) 到 D = (x2 + y2, x2 - y2) 的切比雪夫距离
即看 C 和 D 的横纵坐标差距的较大值
那么显然，应该从横纵坐标最小和最大的点里选
我要删除 2 个点，那么我大概要选横坐标前 8 小的点，前 8 大的点
纵坐标前 8 小的点，前 8 大的点
去重，然后两两枚举，算结果
*/ 

const int N = 2e5 + 10;

struct Point {
    LL x, y, id;
};

int n;
Point p[N];

bool cmp1(const Point &o1, const Point &o2) {
    return o1.x < o2.x;
}

bool cmp2(const Point &o1, const Point &o2) {
    return o1.y < o2.y;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        p[i].x = x + y;
        p[i].y = x - y;
        p[i].id = i;
    }

    if (n <= 2) {
        cout << "0\n";
        return;
    }

    vector<int> candidates;
    sort(p + 1, p + n + 1, cmp1);
    for (int i = 1; i <= min(n, 8); i++) {
        candidates.push_back(p[i].id);
    }
    for (int i = n; i > 0 && i > n - 8; i--) {
        candidates.push_back(p[i].id);
    }

    sort(p + 1, p + n + 1, cmp2);
    for (int i = 1; i <= min(n, 8); i++) {
        candidates.push_back(p[i].id);
    }
    for (int i = n; i > 0 && i > n - 8; i--) {
        candidates.push_back(p[i].id);
    }

    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

    LL ans = 5e9;
    for (int i = 0; i < candidates.size(); i++) {
        for (int j = i + 1; j < candidates.size(); j++) {
            vector<int> nodes;
            for (int k = 1; k <= n; k++) {
                if (p[k].id != candidates[i] && p[k].id != candidates[j]) {
                    nodes.push_back(k);
                }
            }

            LL mxx = p[nodes[0]].x, mnx = mxx;
            LL mxy = p[nodes[0]].y, mny = mxy;
            LL res = 0;
            for (int k = 1; k < nodes.size(); k++) {
                int id = nodes[k];
                LL d1 = abs(mxx - p[id].x), d2 = abs(mnx - p[id].x);
                LL d3 = abs(mxy - p[id].y), d4 = abs(mny - p[id].y);
                res = max({res, d1, d2, d3, d4});
                mxx = max(mxx, p[id].x);
                mnx = min(mnx, p[id].x);
                mxy = max(mxy, p[id].y);
                mny = min(mny, p[id].y);
            }

            ans = min(ans, res);
        }
    }

    cout << ans << "\n";
}
