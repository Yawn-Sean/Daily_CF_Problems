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

/*
max-1/8-area: sqrt(2)/4*x*x
a=fmin(a,maxa);
side-length:
	calc vertex angle: arcsin((2*a)/(x*x))
	sqrt(2*x*x-2*x*x*cos(angle))=x*sqrt(2*(1-cos(angle)))
*/

using D=double;
constexpr D pi=numbers::pi_v<D>;

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	D a,x;
	cin>>a>>x;
	a/=D(8);
	D mxa=sqrt(D(2))/D(4)*x*x;
	dbg(mxa);
	a=fmin(a,mxa);
	D angle=asin((a*D(2))/(x*x)); // vertex-angle
	dbg(angle,angle/pi*D(180));
	D len=x*sqrt(D(2)*(D(1)-cos(angle))); // side length of regular octagon
	D height=len/D(2)/tan(pi/D(8));
	D ans=len*height*D(4);
	dbg(len,height);
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}
