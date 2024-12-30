/*
A 和 B 组成一个矩形
直线和矩形无交点，则答案是曼哈顿距离
有交点，则求出交点，然后组合一下走法
如何求交点？直接把四条线段分别和直线联立，算出来范围内的解就是有交点
交点重合了也无所谓，交点不在线段上也无所谓（肯定更差）
ax + by + c = 0
x = (-c - by) / a
y = (-c - ax) / b
*/

int T;
LL a, b, c;
PDD p[3];

double get_dist(PDD o1, PDD o2) {
    return sqrt((o1.x - o2.x) * (o1.x - o2.x) + (o1.y - o2.y) * (o1.y - o2.y));
}

vector<PDD> get_points(double x, double y) {
    vector<PDD> res;
    if (b != 0) {
        res.pb({x, (-c - a * x) / (1.0 * b)});
    }
    if (a != 0) {
        res.pb({(-c - b * y) / (1.0 * a), y});
    }
    return res;
}

void solve1() {
    cin >> a >> b >> c;
    cin >> p[1].x >> p[1].y >> p[2].x >> p[2].y;
    double res = fabs(p[1].x - p[2].x) + fabs(p[1].y - p[2].y);
    for (auto &u : get_points(p[1].x, p[1].y)) {
        for (auto &v : get_points(p[2].x, p[2].y)) {
            res = min(res, get_dist(p[1], u) + get_dist(u, v) + get_dist(v, p[2]));
        }
    }
    cout << setprecision(14) << res << "\n";
}            