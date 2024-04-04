/*
两个方向向量夹角为 180 度才能对视
向量 a = (x, y)，先求 g = abs(gcd(x, y))
存一下 (x / g, y / g)，负号给第一个数
查相反的数
题目保证不会出现 0 向量
*/

int T;
int n;
map<PLL, LL> cnt;

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve1() {
    cin >> n;
    cnt.clear();
    LL x, y, u, v;
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> u >> v;
        x = u - x;
        y = v - y;
        LL g = abs(gcd(x, y));
        x /= g;
        y /= g;
        LL goal_x, goal_y;
        if (x > 0 && y < 0) {
            x *= -1;
            y *= -1;
        } else if (x < 0 && y > 0) {
            x *= -1;
            y *= -1;
        } 
        PLL goal = mp(-x, -y);
        if (cnt.count(goal)) {
            res += cnt[goal];
        }
        cnt[mp(x, y)]++;
    }
    cout << res << "\n";
}            