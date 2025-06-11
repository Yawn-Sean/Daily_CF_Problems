#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define debug(x) cerr << #x << ": " << x << '\n';
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const double eps = 1e-8;
const double pi = acos(-1.0);
int sgn(double x) { // 返回x的符号
	if (fabs(x) < eps)return 0;
	else if (x < 0)return -1;
	return 1;
}

struct Point {
	double x, y;
	Point () {}
	Point (double x, double y): x(x), y(y) {}
	Point operator + (Point B) {
		return Point(x + B.x, y + B.y);
	}
	Point operator - (Point B) {
		return Point(x - B.x, y - B.y);
	}
	Point operator * (double k) {
		return Point(x * k, y * k);
	}
	Point operator / (double k) {
		return Point(x / k, y / k);
	}
	bool operator < (Point B) {
		return sgn(x - B.x) < 0 || (sgn(x - B.x) == 0 && sgn(y - B.y) < 0); // 1:横坐标x 2:纵坐标y
	}
	bool operator == (Point B) {
		return sgn(x - B.x) == 0 && sgn(y - B.y) == 0;
	}
	bool operator != (Point B) {
		return !(B == *this);
	}
};

struct Circle {
	Point c;
	double r;
	Circle() {}
	Circle(Point c, double r): c(c), r(r) {}
	Circle(double x, double y, double _r) {
		c = Point(x, y), r = _r;
	}
};
double Distance(Point A, Point B) { // A与B的距离,hyopt()在cmath中
	return hypot(A.x - B.x, A.y - B.y);
}
int Circle_circle_relation(Circle C1, Circle C2) { // 圆和圆的位置关系, 0:相离 1:外切 2:相交 3:内切 4:内含
	double dis = Distance(C1.c, C2.c);
	double D = C1.r + C2.r, d = fabs(C1.r - C2.r);
	if (sgn(dis - D) > 0) return 0;
	if (sgn(dis - D) == 0) return 1;
	if (sgn(dis - d) == 0) return 3;
	if (sgn(dis - d) < 0 )return 4;
	return 2;
}
inline void solve()
{
    int x1, y1, r1;
    cin >> x1 >> y1 >> r1;
    int x2, y2, r2;
    cin >> x2 >> y2 >> r2;
    Circle c1 = Circle(x1, y1, r1);
    Circle c2 = Circle(x2, y2, r2);
    Point o1 = Point(x1, y1);
    Point o2 = Point(x2, y2);
    int rel = Circle_circle_relation(c1, c2);
    if(rel == 0) {
        cout << (Distance(o1, o2) - r1 - r2) / 2.0 << endl;
    } else if(rel == 1 || rel == 2 || rel == 3) {
        cout << 0 << endl;
    } else if(rel == 4) {
        cout << (1.0*abs(r1-r2) - Distance(o1, o2)) / 2.0 << endl;
    }
}
