#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include<local/dbg.h>
#else
#define dbg(...) 42
#endif

using LL=long long;
#define ai(x) using ai##x=array<int,x>;
ai(2);ai(3);ai(4);ai(5);ai(6);ai(7);ai(8);ai(9);ai(10);ai(26);
#undef ai

#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
template<class T>inline bool updmx(T& x,const T& y){return x<y?x=y,1:0;}
template<class T>inline bool updmn(T& x,const T& y){return y<x?x=y,1:0;}
template<class T>inline void clr(T& x){T().swap(x);}

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
LL rand(LL l,LL r){return rng()%(r-l+1)+l;}

using LD=long long;
//eps不一定是越精度高越好！
constexpr LD eps=1; //精度，可按需要增加至1e-12之类的(?)
constexpr LD pi=numbers::pi;
constexpr int sign(LD x){ //符号函数
	if(fabs(x)<eps) return 0;
	if(x<0) return -1;
	return 1;
}
constexpr int dcmp(LD x,LD y){ //比较函数
	if(fabs(x-y)<eps) return 0;
	if(x<y) return -1;
	return 1;
}

using PDD=pair<LD,LD>;
#define x first
#define y second

//基本运算符重载
constexpr PDD operator +(const PDD& a,const PDD& b){return PDD{a.x+b.x,a.y+b.y};}
constexpr PDD operator -(const PDD& a,const PDD& b){return PDD{a.x-b.x,a.y-b.y};}
constexpr PDD operator *(LD k,const PDD& a){return PDD{k*a.x,k*a.y};}
constexpr PDD operator *(const PDD& a,LD k){return PDD{k*a.x,k*a.y};}
constexpr PDD operator /(const PDD& a,LD k){return PDD{a.x/k,a.y/k};}
constexpr bool operator ==(const PDD& a,const PDD& b){
	return !dcmp(a.x,b.x) && !dcmp(a.y,b.y);
}

constexpr LD dot(const PDD& a,const PDD& b){ //内积
	return a.x*b.x+a.y*b.y;
}

constexpr LD cross(const PDD& a,const PDD& b){ //叉积
	return a.x*b.y-b.x*a.y;
}

//取模（长度）
constexpr LD get_length(const PDD& a){
	return sqrt(dot(a,a));
}

//计算向量夹角
constexpr LD get_angle(const PDD& a,const PDD& b){
	return atan2(fabs(cross(a,b)),dot(a,b));
}

//计算两个向量构成的平行四边形的面积
constexpr LD area(const PDD& a,const PDD& b,const PDD& c){
	return cross(b-a,c-a);
}

//A绕原点**顺时针**旋转angle（弧度制）
constexpr PDD rotate(const PDD& a,LD angle){
	return PDD{a.x*cos(angle) + a.y*sin(angle),
		-a.x*sin(angle) + a.y*cos(angle)};
}

//取直线p+vt, q+wt的交点
//cross(v,w)==0 则两直线平行或者重合，注意特判，这里没加特判
constexpr PDD get_line_inter(const PDD& p, const PDD& v, const PDD& q, const PDD& w){
	PDD u = p - q;
	LD t = cross(w, u) / cross(v, w);
	return p + v * t;
}

//点p; 直线由a, b两点表示
//点到直线的距离
constexpr LD dis2line(const PDD& p, const PDD& a, const PDD& b){
	PDD v1 = b - a, v2 = p - a;
	return fabs(cross(v1, v2) / get_length(v1));
}

//点到线段的距离
constexpr LD dis2seg(const PDD& p, const PDD& a, const PDD& b){
	if (a == b) return get_length(p - a);
	PDD v1 = b - a, v2 = p - a, v3 = p - b;
	if (sign(dot(v1, v2)) < 0) return get_length(v2);
	if (sign(dot(v1, v3)) > 0) return get_length(v3);
	return dis2line(p, a, b);
}

//点在直线上的投影
constexpr PDD get_line_proj(const PDD& p, const PDD& a, const PDD& b){
	PDD v = b - a;
	return a + v * (dot(v, p - a) / dot(v, v));
}

//点是否在线段上
constexpr bool on_seg(const PDD& p, const PDD& a, const PDD& b){
	return sign(cross(p - a, p - b)) == 0 && sign(dot(p - a, p - b)) <= 0;
}

//判断两线段是否相交
constexpr bool seg_inter(const PDD& a1, const PDD& a2, const PDD& b1, const PDD& b2){
	LD c1 = cross(a2-a1, b1-a1), c2 = cross(a2-a1, b2-a1);
	LD c3 = cross(b2-b1, a1-b1), c4 = cross(b2-b1, a2-b1);
	// 有if则允许线段在端点处相交，无if则不允许，根据需要添加
	if(!sign(c1) && !sign(c2) && !sign(c3) && !sign(c4)){
		bool f1 = on_seg(b1, a1, a2);
		bool f2 = on_seg(b2, a1, a2);
		bool f3 = on_seg(a1, b1, b2);
		bool f4 = on_seg(a2, b1, b2);
		bool f = (f1|f2|f3|f4);
		return f;
	}
	return (sign(c1)*sign(c2) < 0 && sign(c3)*sign(c4) < 0);
}


//计算**任意**多边形面积（不一定凸）
LD polygon_area(vector<PDD>p){
	LD s = 0;
	for (int i = 1; i + 1 < p.size(); i ++ )
		s += cross(p[i] - p[0], p[i + 1] - p[i]);
	return s / 2;
}

//三点求圆，如果flag=1，则只对非钝角三角形求，对锐角三角形返回R=-1
constexpr pair<PDD,LD>circle_three(const PDD& A,const PDD& B,const PDD& C,const bool flag=1){
	LD x=get_length(A-B);
	LD y=get_length(B-C);
	LD z=get_length(C-A);
	if(flag){
		if(sign(x*x+y*y-z*z)<=0 || sign(x*x+z*z-y*y)<=0 || sign(y*y+z*z-x*x)<=0){
			return {PDD{},-1};
		}
	}
	LD p=(x+y+z)/2;
	LD s=sqrt(p*(p-x)*(p-y)*(p-z));
	LD R=x*y*z/(s*4);
	auto F=[&](LD a1,LD a2,LD a3,LD b1,LD b2,LD b3,LD c1,LD c2,LD c3)->LD {
		return	a1*b2*c3 +b1*c2*a3 +c1*a2*b3
				-a3*b2*c1 -b3*c2*a1 -c3*a2*b1;
	};
	LD X=
	F(
		1,1,1,
		dot(A,A),dot(B,B),dot(C,C),
		A.y,B.y,C.y
	)/
	F(
		1,1,1,
		A.x,B.x,C.x,
		A.y,B.y,C.y
	);
	LD Y=
	F(
		1,1,1,
		A.x,B.x,C.x,
		dot(A,A),dot(B,B),dot(C,C)
	)/
	F(
		1,1,1,
		A.x,B.x,C.x,
		A.y,B.y,C.y
	);
	return {PDD{X,Y}/2,R};
}

constexpr bool cmpPDD(const PDD& A,const PDD& B){
	if(dcmp(A.y,B.y)==0) return dcmp(A.x,B.x)==-1;
	return dcmp(A.y,B.y)==-1;
}

// counter-clockwise
vector<PDD> Andrew(vector<PDD>& a){
	sort(all(a),cmpPDD);
	a.erase(unique(all(a)),a.end());
	const int n=a.size();
	vector<PDD>b={a[0]};
#define sb (int)(b.size())
	for(int i=1;i<n;++i){
		while(sb>1 && sign(area(b[sb-2],b[sb-1],a[i]))<=0)
			b.pop_back();
		b.push_back(a[i]);
	}
	const int m=sb;
	for(int i=n-2;i>=0;--i){
		while(sb>m && sign(area(b[sb-2],b[sb-1],a[i]))<=0)
			b.pop_back();
		b.push_back(a[i]);
	}
#undef sb
	b.pop_back();
	return b;
}

int calc(const PDD& p,const PDD& q){
	return max(abs(p.x-q.x),abs(p.y-q.y))-1;
}

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n; cin>>n;
	vector<PDD>a; a.reserve(n*4);
	bool samex=1,samey=1,offset=1;
	{
		vector<PDD>_a(n);
		for(int i=0,x,y;i<n;++i){
			cin>>x>>y;
			_a[i]=PDD{x,y};
			samex&=(x==_a[0].x);
			samey&=(y==_a[0].y);
			a.emplace_back(x-1,y);
			a.emplace_back(x+1,y);
			a.emplace_back(x,y-1);
			a.emplace_back(x,y+1);
		}
		if(!samex && !samey){
			for(int i=2;i<n;++i){
				offset&=(!sign(area(_a[0],_a[1],_a[i])));
			}
		}
		else offset=0;
		if(offset){
			PDD d=_a[0]-_a[1];
			const int g=__gcd(d.x,d.y);
			d.x/=g,d.y/=g;
			if(abs(d.x)==1 && abs(d.y)==1);
			else offset=0;
		}
	}

	const auto b=Andrew(a);
	const int m=(int)(b.size());
	int ans=m+calc(b[0],b[m-1]);
	for(int i=1;i<m;++i) ans+=calc(b[i],b[i-1]);
	cout<<(ans+offset);
	return 0;
}
