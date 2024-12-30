#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10, Pi = acos(-1.0);
// 卡精度，设成 1e-11后会超时
struct dot {
	double x, y;
    dot(){}
    dot(double x, double y):x(x), y(y){}
};
typedef dot Vector;

int sgn(double x){
	if (fabs(x) < eps) return 0;
	return x < 0 ? -1 : 1;
}
Vector operator - (dot a, dot b){
	return {a.x-b.x, a.y-b.y};
}
Vector operator + (dot a, dot b){
	return {a.x+b.x, a.y+b.y};
}
Vector operator * (dot a, double t){
	return {t*a.x, t*a.y};
}
double operator * (Vector a, Vector b){
	return a.x*b.y - a.y*b.x;
}
double operator & (Vector a, Vector b){
    return a.x*b.x + a.y*b.y;
}
double Len(Vector a){
    return sqrt(a&a);
}
double Dis(dot a, dot b){
    return hypot(a.x-b.x, a.y-b.y);
}
double Angle(Vector a, Vector b){
    return acos((a&b)/Len(a)/Len(b));
}

struct Line {
	dot c;
	Vector v;
	double angle;
	Line(dot cs, Vector vs, double angles){
        c = cs, v = vs, angle = angles;
    }
	Line(dot c, Vector v): c(c), v(v){
		angle = atan2(v.y, v.x);
	}
    Line rotate(double rad){
        Vector vs = {v.x*cos(rad) + v.y*sin(rad), -v.x*sin(rad) + v.y*cos(rad)};
        double gs = atan2(vs.y, vs.x);
        return {c, vs, gs};
    }
    double pDis(dot p){
        double ag = Angle(p-c, v);
        return Dis(p, c) * sin(ag);
    }
};

void solve(){
    dot b;
    double y1, y2, yw, r;
    cin >> y1 >> y2 >> yw >> b.x >> b.y >> r;
    double pl = 0, pr = b.x;

    while (sgn(pr-pl)){
        double mid = (pl+pr) / 2;
        dot p(mid, yw-r);
        Line L1(p, p-b);  // 反弹前的直线, 角度是 φ
        Line L2 = L1.rotate(2*L1.angle - Pi);  // 绕点 p 顺时针 旋转得到，反弹后的直线
        double y = L2.c.y - (L2.v.y/L2.v.x)*L2.c.x;  // 与x=0 的 交点
        int f1 = -1, f2 = -1;
        // f1: 隐藏条件， 可以让右下半部分 撞到杆 (包括正下面)后 
        f1 = (sgn(y-y1-r) >= 0) ? 1 : 0;
        if (sgn(y-y1)==1 && sgn(y-y2)==-1){
            double dis2 = L2.pDis({0,y2});
            f2 = (sgn(dis2-r) == 1) ? 1 : 0;
        }
        if (f2==1 && f1==1){
            cout << mid << "\n";
            return;
        }
        // 如果 y 小于下界 或者 y 大于下界 足球与下界擦边  越往左，y越大
        if (f1==0){
            pr = mid;
        } else {
            pl = mid;
        }
    }

    cout << int(-1) << "\n";
}
