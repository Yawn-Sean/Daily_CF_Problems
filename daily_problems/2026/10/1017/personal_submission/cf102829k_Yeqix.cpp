#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

constexpr long double EPS = 1E-10;

template <typename T>
int sgn(T a) {
    return (a > EPS) - (a < -EPS);
}

template <typename T>
struct Point;

template <typename T>
struct Vector {  // 向量
    T x = 0, y = 0;
    Vector(const Point<T>& p) : x(p.x), y(p.y) {}
    Vector(T x_ = 0, T y_ = 0) : x(x_), y(y_) {}
    template <typename U>
    operator Vector<U>() {
        return Vector<U>(U(x), U(y));
    }
    Vector operator+(const Vector<T>& o) const { return {x + o.x, y + o.y}; }
    Vector operator-(const Vector<T>& o) const { return {x - o.x, y - o.y}; }
    Vector operator*(T f) const { return {x * f, y * f}; }
    Vector operator/(T f) const { return {x / f, y / f}; }
    friend istream& operator>>(istream& is, Vector& p) { return is >> p.x >> p.y; }
    friend ostream& operator<<(ostream& os, Vector p) { return os << "(" << p.x << ", " << p.y << ")"; }
};

template <typename T>
struct Point {  // 点
    T x = 0, y = 0;
    Point(T x_ = 0, T y_ = 0) : x(x_), y(y_) {}
    template <typename U>
    operator Point<U>() {
        return Point<U>(U(x), U(y));
    }
    Point operator+(const Vector<T>& o) const { return {x + o.x, y + o.y}; }
    Vector<T> operator-(const Point<T>& o) const { return {x - o.x, y - o.y}; }
    Point operator-() const { return {-x, -y}; }
    Point operator*(T f) const { return {x * f, y * f}; }
    Point operator/(T f) const { return {x / f, y / f}; }
    friend Point operator*(T f, Point p) { return {p * f}; }
    bool operator==(const Point& o) const { return sgn(x - o.x) == 0 && sgn(y - o.y) == 0; }
    constexpr strong_ordering operator<=>(const Point& o) const {
        if (sgn(x - o.x) == 0) {
            return sgn(y - o.y) <=> 0;
        } else {
            return sgn(x - o.x) <=> 0;
        }
    }
    friend istream& operator>>(istream& is, Point& p) { return is >> p.x >> p.y; }
    friend ostream& operator<<(ostream& os, Point p) { return os << "(" << p.x << ", " << p.y << ")"; }
};

template <typename T>
struct Line {  // 直线
    Point<T> s, t;
    Line() = default;
    Line(Point<T> _s, Point<T> _t) : s(_s), t(_t) {}
};

template <typename T>
struct Seg {  // 线段
    Point<T> s, t;
    Seg() = default;
    Seg(Point<T> _s, Point<T> _t) : s(_s), t(_t) {}
};

template <typename T, typename U>
struct Circle {  // 圆
    Point<T> o;
    U r{};
};

template <typename T>
T dot(const Vector<T>& a, const Vector<T>& b) {  // 向量a和向量b的点积
    return a.x * b.x + a.y * b.y;
}

template <typename T>
T dot(const Point<T>& a, const Point<T>& b, const Point<T>& c) {  // 向量a->b和向量a->c的点积
    return dot(b - a, c - a);
}

template <typename T>
T cross(const Vector<T>& a, const Vector<T>& b) {  // 向量a和向量b的叉积
    return a.x * b.y - a.y * b.x;
}

template <typename T>
T cross(const Point<T>& a, const Point<T>& b, const Point<T>& c) {  // 向量a->b和向量a->c的叉积
    return cross(b - a, c - a);
}

template <typename T>
T len2(const Vector<T>& a) {  // 向量a的模长的平方
    return a.x * a.x + a.y * a.y;
}

template <typename T>
long double len(const Vector<T>& a) {  // 向量a的模长
    return sqrtl(len2(a));
}

template <typename T>
Vector<T> standardize(const Vector<T>& a) {  // 向量a的单位向量
    return a / len(a);
}

template <typename T>
long double angle(Vector<T> a, Vector<T> b) {  // 求两向量夹角[0, pi]
    return fabs(atan2l(cross(a, b), dot(a, b)));
}

template <typename T>
T dis2(const Point<T>& a, const Point<T>& b) {  // 点a和点b距离的平方（防精度损失）
    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

template <typename T>
long double dis(const Point<T>& a, const Point<T>& b) {  // 点a到点b距离
    return sqrtl(dis2(a, b));
}

template <typename T>
long double angle(const Vector<T>& a, const Vector<T>& b) {  // 向量a和向量b的夹角弧度
    return acosl(dot(a, b) / len(a) / len(b));
}

template <typename T>
Vector<T> rotate(const Vector<T>& a) {  // 向量a逆时针旋转pi/2
    return {-a.y, a.x};
}

template <typename T>
Vector<T> rotate(const Vector<T>& a, long double rad) {  // 向量a逆时针旋转rad弧度
    return {a.x * cosl(rad) - a.y * sinl(rad), a.x * sinl(rad) + a.y * cosl(rad)};
}

template <typename T>
Point<T> rotate(const Point<T>& a, const Point<T>& b, long double rad) {  // 点b绕点a逆时针旋转rad弧度
    return {(b.x - a.x) * cosl(rad) - (b.y - a.y) * sinl(rad) + a.x, (b.x - a.x) * sinl(rad) + (b.y - a.y) * cosl(rad) + a.y};
}

template <typename T>
bool intersect(const Seg<T>& a, const Seg<T>& b) {  // 线段a和线段b不严格相交，可以包含端点相交
    return sgn(cross(a.s, a.t, b.s) * cross(a.s, a.t, b.t)) <= 0 && sgn(cross(b.s, b.t, a.s) * cross(b.s, b.t, a.t)) <= 0;
}

template <typename T>
bool intersectStrictly(const Seg<T>& a, const Seg<T>& b) {  // 线段a和线段b严格相交，不包含端点相交
    return sgn(cross(a.s, a.t, b.s) * cross(a.s, a.t, b.t)) < 0 && sgn(cross(b.s, b.t, a.s) * cross(b.s, b.t, a.t)) < 0;
}

template <typename T>
Point<T> getNode(const Line<T>& a, const Line<T>& b) {  // 求直线a与直线b的交点（需要先判断是否相交）
    T dx = cross(a.s, b.s, b.t) / cross(a.t - a.s, b.t - b.s);
    return a.s + (a.t - a.s) * dx;
}

template <typename T>
Point<T> getNode(const Seg<T>& a, const Seg<T>& b) {  // 求线段a与线段b的交点（需要先判断是否相交）
    T dx = cross(a.s, b.s, b.t) / cross(a.t - a.s, b.t - b.s);
    return a.s + (a.t - a.s) * dx;
}

template <typename T>
Line<T> midseg(const Seg<T>& seg) {  // 求线段的垂直平分线
    Point mid = (seg.s + seg.t) / 2;
    return {mid, mid + rotate(seg.t - seg.s)};
}

template <typename T>
Circle<T, long double> getCircle(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3) {  // 求三点所在圆
    Line<T> l1 = midseg(Seg<T>{p1, p2});
    Line<T> l2 = midseg(Seg<T>{p1, p3});
    Point<T> O = getNode(l1, l2);
    return {O, dis(O, p1)};
}

template <typename T>
Circle<T, long double> getCircle(const Point<T>& p1, const Point<T>& p2) {  // 求以两点为直径所在圆
    Point<T> O = (p1 + p2) / 2;
    return {O, dis(O, p1)};
}

template <typename T>
bool onSeg(const Point<T>& p, const Seg<T>& s) {  // 判断点是否在线段上
    if (sgn(cross(s.s, s.t, p)) != 0)
        return false;
    return min(s.s, s.t) <= p && p <= max(s.s, s.t);
}

template <typename T, typename U>
int pointOnCircle(const Point<T>& p, const Circle<T, U>& c) {  // 点和圆的位置关系，-1点在圆外，0点在圆上，1点在圆外，
    return sgn(c.r * c.r - dis2(p, c.o));
}

template <typename T>
vector<Point<T>> andrew(vector<Point<T>> v) {  // Andrew求凸包
    sort(v.begin(), v.end());
    vector<Point<T>> stk;
    for (int i = 0; i < v.size(); ++i) {
        while (stk.size() > 1 && sgn(cross(stk[stk.size() - 2], stk.back(), v[i])) < 0) {
            stk.pop_back();
        }
        stk.push_back(v[i]);
    }
    int t = stk.size();
    for (int i = (int)v.size() - 2; i >= 0; --i) {
        while (stk.size() > t && sgn(cross(stk[stk.size() - 2], stk.back(), v[i])) < 0) {
            stk.pop_back();
        }
        stk.push_back(v[i]);
    }
    stk.pop_back();
    return stk;
};

template <typename T>
vector<Point<T>> graham(vector<Point<T>> v) {  // Graham求凸包
    Point<T> base = *min_element(v.begin(), v.end());
    ranges::sort(v, [&](auto p1, auto p2) -> bool {
        if (sgn(cross(base, p1, p2)) == 0)
            return p1 < p2;
        return sgn(cross(base, p1, p2)) == -1;
    });
    vector<Point<T>> stk;
    for (int i = 0; i < v.size(); ++i) {
        while (stk.size() > 1 && sgn(cross(stk[stk.size() - 2], stk.back(), v[i])) >= 0) {
            stk.pop_back();
        }
        stk.push_back(v[i]);
    }
    return stk;
}

template <typename T>
vector<Line<T>> halfcut(vector<Line<T>> lines) {  // 半平面交，默认左侧
    sort(lines.begin(), lines.end(), [&](const auto& l1, const auto& l2) -> bool {
        auto v1 = l1.t - l1.s, v2 = l2.t - l2.s;
        auto a1 = atan2(v1.y, v1.x), a2 = atan2(v2.y, v2.x);
        if (sgn(a1 - a2) != 0)
            return sgn(a1 - a2) == -1;
        return sgn(cross(l1.s, l1.t, l2.t)) < 0;
    });
    int l = 0, r = -1;
    vector<Line<T>> ls(lines.size());
    for (const auto& line : lines) {
        if (r >= l && sgn(cross(line.t - line.s, ls[r].t - ls[r].s)) == 0)
            continue;
        while (r > l && sgn(cross(line.s, line.t, intersection(ls[r], ls[r - 1]))) == -1)
            r--;
        while (r > l && sgn(cross(line.s, line.t, intersection(ls[l], ls[l + 1]))) == -1)
            l++;
        ls[++r] = line;
    }
    while (r > l + 1 && sgn(cross(ls[l].s, ls[l].t, intersection(ls[r], ls[r - 1]))) == -1)
        r--;
    return vector<Line<T>>(ls.begin() + l, ls.begin() + r + 1);
}

template <typename T>
vector<Point<T>> linesToPoints(const vector<Line<T>>& lines) {  // 直线式凸包转为点凸包
    vector<Point<T>> v;
    for (int i = 0; i < lines.size(); ++i) {
        v.push_back(intersection(lines[i], lines[(i + 1) % lines.size()]));
    }
    return v;
};

template <typename T>
long double area(const vector<Point<T>>& v) {  // 求凸包面积
    long double ans = 0;
    for (int i = 1; i + 1 < v.size(); ++i) {
        ans += cross(v[0], v[i], v[i + 1]);
    }
    ans /= 2;
    return ans;
}

template <typename T>
T diameter2(const vector<Point<T>>& v) {  // 旋转卡壳求凸包直径的平方
    int n = v.size();
    T res = 0;
    for (int i = 0, j = 1; i < n; ++i) {
        while (sgn(cross(v[i], v[(i + 1) % n], v[j]) - cross(v[i], v[(i + 1) % n], v[(j + 1) % n])) <= 0) {
            j = (j + 1) % n;
        }
        res = max({res, dis2(v[i], v[j]), dis2(v[(i + 1) % n], v[j])});
    }
    return res;
}

template <typename T>
long double diameter(const vector<Point<T>>& v) {  // 旋转卡壳求凸包直径
    return sqrtl(diameter2(v));
}

template <typename T>
long double mindistance(vector<Point<T>> v) {  // 平面最近点对O(nlog(n))
    sort(v.begin(), v.end());
    long double d = 1E18;
    auto cmp = [](const Point<T>& a, const Point<T>& b) { return a.y < b.y; };
    multiset<Point<T>, decltype(cmp)> st;
    for (int i = 0, j = 0; i < v.size(); ++i) {
        while (j < i && sgn(v[j].x - v[i].x + d) <= 0) {
            st.erase(v[j]);
            ++j;
        }
        for (auto it = st.lower_bound({v[i].x, v[i].y - T(d)}); it != st.end() && sgn(it->y - v[i].y - T(d + 1)) <= 0; ++it) {
            d = min(d, dis(v[i], *it));
        }
        st.insert(v[i]);
    }
    return d;
}

template <typename T>
long double grith(const vector<Point<T>>& v) {  // 求凸包周长
    long double ans = 0;
    for (int i = 0; i < v.size(); ++i) {
        ans += dis(v[i], v[(i + 1) % v.size()]);
    }
    return ans;
}

template <typename T>
long double vectordis(const Point<T>& p, const Point<T>& a, const Point<T>& b) {
    return abs(cross(a, b, p)) / hypot(b.x - a.x, b.y - a.y);
}

constexpr int md = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<array<i64, 2>> f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> f[i][0] >> f[i][1];
    }

    vector<i64> pw2(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        pw2[i] = pw2[i - 1] * 2 % md;
    }

    auto cross = [&](int i, int j, int k) -> i64 {
        auto [a, b] = f[i];
        auto [c, d] = f[j];
        auto [e, g] = f[k];

        return (c - a) * (g - b) - (d - b) * (e - a);
    };

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            i64 L = 0;
            for (int k = 1; k <= n; k++) {
                if (k != i && k != j && cross(i, k, j) < 0) {
                    L++;
                }
            }

            ans = (ans + (pw2[L] + pw2[n - 2 - L]) % md) % md;
        }
    }

    cout << ans + n;
    return 0;
}