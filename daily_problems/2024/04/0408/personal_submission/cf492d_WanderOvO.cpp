/*
对于过大的 a[i]，先用 x + y 模一下
求 lcm(x, y)，然后模拟在上面打点
枚举 a[i]，找第一个 >= a[i] 的点，看这个点是谁打的
*/

int T;
unordered_map<LL, LL> d;
LL n, x, y, a[N];
set<LL> attack[3];
PLL b[M];
int idx;

bool cmp(const PLL &a, const PLL &b) {
    return a.y < b.y;
}

void solve1() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > (x + y)) {
            a[i] %= (x + y);
            if (a[i] == 0) {
                a[i] = x + y;
            }
        }
    }
    for (int i = 1; i <= y; i++) {
        d[i * x]++;
        attack[2].insert(i * x);
    }
    for (int i = 1; i <= x; i++) {
        d[i * y]++;
        attack[1].insert(i * y);
    }
    for (auto &it : d) {
        b[++idx] = {it.x, it.y};
    }
    sort(b + 1, b + idx + 1);
    for (int i = 1; i <= idx; i++) {
        b[i].y += b[i - 1].y;
    }
    
    for (int i = 1; i <= n; i++) {
        // cout << a[i] << "\n";
        int pos = lower_bound(b + 1, b + idx + 1, mp(0, a[i]), cmp) - b;
        LL t = b[pos].x;
        // cout << i << " " << b[pos].x << " " << b[pos].y << "\n";
        if (attack[1].count(t) && attack[2].count(t)) {
            cout << "Both\n";
        } else if (attack[1].count(t)) {
            cout << "Vanya\n";
        } else {
            cout << "Vova\n";
        }
    }
}      