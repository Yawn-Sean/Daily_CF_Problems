/*
每个瓶子都得扔到垃圾桶，所以每个瓶子都得算和垃圾桶的距离
考虑 A 和 B 第一次分别拿哪个

*/

int T;
double pre_d1[N], suf_d1[N], d[N], d1[N], d2[N];
double ax, ay, bx, by, tx, ty;
int n;
double x[N], y[N];

double get_dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void solve1() {
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        d[i] = get_dist(tx, ty, x[i], y[i]);
    }
    for (int i = 1; i <= n; i++) {
        d1[i] = get_dist(ax, ay, x[i], y[i]);
        d2[i] = get_dist(bx, by, x[i], y[i]);
    }
    
    pre_d1[0] = INF;
    for (int i = 1; i <= n; i++) {
        pre_d1[i] = min(pre_d1[i - 1], d1[i] - d[i]);
    }
    suf_d1[n + 1] = INF;
    for (int i = n; i > 0; i--) {
        suf_d1[i] = min(suf_d1[i + 1], d1[i] - d[i]);
    }
    
    double res = 0;
    for (int i = 1; i <= n; i++) {
        res += 2 * d[i];
    }
    double min_add = INF;
    for (int i = 1; i <= n; i++) {
        min_add = min({min_add, d1[i] - d[i], d2[i] - d[i]});
        min_add = min(min_add, d2[i] - d[i] + min(pre_d1[i - 1], suf_d1[i + 1]));
    }
    
    cout << setprecision(15) << res + min_add << "\n";
}    