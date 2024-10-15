/*
枚举一条直线，然后看之前枚举的直线的斜率有多少和当前直线不同
斜率还需要考虑是否存在，转化成维护方向向量，使用 gcd 约分化为最简数对
点两两连线，假如两条直线重合，只能算一条直线，所以不止得维护斜率
ax + by + c = 0, 方向向量是 (b, -a), 所以 a, b 确定了，代入一个点求 c 即可
*/

int T;
int n;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve1() {
    cin >> n;
    vector<PII> points(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    set<array<int, 3>> st;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int x = points[i].x - points[j].x, y = points[i].y - points[j].y;
            int g = gcd(x, y);
            if (g != 0) {
                x /= g;
                y /= g;
                if (x < 0 || (x == 0 && y < 0)) {
                    x = -x;
                    y = -y;
                }
            } 
            int a = -y, b = x, c = -(a * points[i].x + b * points[i].y);
            array<int, 3> line = {a, b, c};
            st.insert(line);
        }
    }
    LL res = 0;
    map<PII, int> cnt;
    int cur = 0;
    for (auto &line : st) {
        int x = line[0], y = line[1];
        if (cnt.count({x, y})) {
            res += cur - cnt[{x, y}];
        } else {
            res += cur;
        }
        cur++;
        cnt[{x, y}]++;
    }
    cout << res << "\n";
}                       
