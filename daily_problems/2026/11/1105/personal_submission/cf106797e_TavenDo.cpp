#include <bits/stdc++.h>
using namespace std;
//#define int long long
//#define endl "\n"
using LD=long double;
//
struct P{
	LD x,y;
	P(LD xx,LD yy):x(xx),y(yy){};
	P operator+(const P &o)const{return P(x+o.x,y+o.y);}
	P operator-(const P &o)const{return P(x-o.x,y-o.y);}
	P operator*(LD k)const{return P(k*x,k*y);}
	P operator/(LD k)const{return P(x/k,y/k);}
	LD dot(const P& o) const {return x * o.x + y * o.y;}
    LD cross(const P& o) const {return x * o.y - y * o.x;}
	LD dis(const P& o) const {return (*this - o).length();}
	LD square() const {return x * x + y * y;}
	LD length() const {return sqrtl(square());}
};
struct L{
	P a,b;
	L(P aa,P bb):a(aa),b(bb){};
	P vec()const{return b-a;}
	P projection(const P& o) const {
        auto t = 1.L * vec().dot(o - a) / vec().square();
        return a+vec()*t;
    }
	double distanceLP(const P& o) const {
        return abs((a - b).cross(a - o)) / (a - b).length();
    }
	P lineIntersection(const L& l) const {
        return a + vec()*((l.b - l.a).cross(a - l.a) / (l.b - l.a).cross(a - b));
    }
};
struct C{
	P c;
	LD r;
	C(P cc,LD rr):c(cc),r(rr){};
	vector<P> intersection(L const& l) const {
        P cp = l.projection(c);
        double d = l.distanceLP(c);
        double k = sqrtl(r * r - d * d);
        P e = l.vec() / l.vec().length();
        return {cp - e * k, cp + e * k};
    }
};
void solve() {
	cout<<"? 1 0"<<endl;
	LD x,y;
	cin>>x;
	cout<<"? 1 1"<<endl;
	cin>>y;
	cout<<"! ";
	LD st=sqrtl(2);
	P a(x,0),b(y/st,y/st);
	L l1(a,b),l2(P(0,x),P(1,x));
	P c=l1.lineIntersection(l2);
	LD p1=x-c.x,p2=c.x,k2=a.dis(c),k1=p1*p2/k2;
	C res(c,k1);
	vector<P>g=res.intersection(l1);
	if(g[0].x>g[1].x){
		swap(g[0],g[1]);
	}
	cout<<llround(2*g[0].square())<<endl;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout<<fixed<<setprecision(20);
	int loop = 1;
	cin >> loop;
	while (loop--){
		solve();
	}
	return 0;
}