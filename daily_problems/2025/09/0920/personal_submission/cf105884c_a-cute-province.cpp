#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6+10;
const int mod = 1e9 + 7;
struct Point{
	int x;
	int y;
	Point() : x{0}, y{0} {}
	Point(int x_, int y_) : x{x_}, y{y_} {}
    bool operator<(const Point& other) const {
    return x < other.x || (x == other.x && y < other.y);
}
};
int dot(Point a, Point b){
	return a.x * b.y + a.y * b.y;
}
int cross(Point a, Point b, Point c){
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
Point operator+(Point a, Point b){
	return Point(a.x + b.x, a.y + b.y);
}
Point operator-(Point a, Point b){
	return Point(a.x - b.x, a.y - b.y);
}
vector<Point> convex_hull(vector<Point> pts) {
    sort(pts.begin(), pts.end());
    vector<Point> up, down;

    for (auto &pt: pts) {
        while (up.size() > 1) {
            auto v1 = up[up.size() - 2], v2 = up[up.size() - 1];
            if (cross(v1, v2,  pt) >= 0) up.pop_back();
            else break;
        }
        up.emplace_back(pt);
    }

    for (auto &pt: pts) {
        while (down.size() > 1) {
            auto v1 = down[down.size() - 2], v2 = down[down.size() - 1];
            if (cross(v1, v2, pt) <= 0) down.pop_back();
            else break;
        }
        down.emplace_back(pt);
    }

    down.pop_back();
    down.insert(down.end(), up.rbegin(), up.rend());
    down.pop_back();
    return down;
}
void solve()
{
    int n;
    cin >> n;
    vector<Point> p(n);
    for(int i = 0; i <n; i ++){
        int x, y;
        cin >> x >> y;
        p[i] = Point(x, y);
    }
    auto all = convex_hull(p);
    set<Point> chosen(all.begin(), all.end());
    //用叉积判断点是否在三角形中
    auto check = [&] (int x1, int y1, int x2, int y2, int x3, int y3) -> bool {
        int dx1 = x2 - x1, dy1 = y2 - y1;
        int dx2 = x3 - x1, dy2 = y3 - y1;
        return dx1 * dy2 > dx2 * dy1;
    };
    map<Point, int> pos;
    for(int i = 0 ; i < n; i ++)pos[p[i]] = i;
    if(all.size() == n){
        cout << -1 << '\n';
    }
    else{
        for(int i = 0 ; i < n; i ++){
            if(chosen.find(p[i]) == chosen.end()){
                auto [x, y] = p[i];

            for(int j = 2; j < all.size(); j ++){
                auto [x1, y1] = all[0];
                auto [x2, y2] = all[j-1];
                auto [x3, y3] = all[j];
                if (check(x1, y1, x2, y2, x, y) &&
                    check(x2, y2, x3, y3, x, y) &&
                    check(x3, y3, x1, y1, x, y)) {
                    cout << i + 1 << ' ' << pos[Point(x1, y1)] +1 << ' ' << pos[Point(x2, y2)] +1 << ' ' <<pos[Point(x3, y3)] +1 << '\n';
                    break;
                }
            }
            break;
            }

        }
    }
}
signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    //t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
