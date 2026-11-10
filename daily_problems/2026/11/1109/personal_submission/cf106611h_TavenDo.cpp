//Through thorns, to the stars.
//Raven ascends, never yielding, to meet a better self.
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
#define lowbit(x) ((x)&(-x))
#define fi first 
#define se second 
#define sz(x) (int)(x.size())
using LL=long long;using ll=long long;
using ULL=unsigned long long;using ull=unsigned long long;
using i128=__int128;
using u128=unsigned __int128;
using LD=long double;
using PII=pair<int,int>;
using PLL=pair<LL,LL>;
const LL inf = 1e18;
const LD eps = 1e-12;
LL gcd(LL a, LL b) {return b ? gcd(b, a % b) : a;}
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

//
LD pi=acos(-1);

void solve() {
	LL hx,hy,cx,cy;
	cin>>hx>>hy>>cx>>cy;
	LL k=(hx-cx)*(hx-cx)+(hy-cy)*(hy-cy);
	if(k<=1){
		cout<<1<<endl;
		return;
	}
	LD a=atan2(hy-cy,hx-cx),b=asin((LD)1/sqrtl(k));  //[a-b,a+b]
	LD D,U;
	cin>>D>>U;
	LD d=D/180*pi,u=U/180*pi;    //[d-u,d+u]
	LD res=0;
	for(int i=-2;i<=2;++i){
		LD L=a-b+2*i*pi,R=a+b+2*i*pi;
		L=max(L,d-u),R=min(R,d+u);
		res+=max(LD(0),R-L);
	}
	cout<<res/(2*u)<<endl;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int loop = 1;
	cout<<fixed<<setprecision(20);
	//cin >> loop;
	while (loop--){
		solve();
	}
	return 0;
}

/*
Take a picture, don’t forget her.
Let it linger in your view.
The formula for finding magic.
One plus one, just me and you.
                 <<Magic Theorem>>

自分自身を 知るための旅路
ひとりのようで ひとりじゃなかった
観測上で
成り立つ 存在X
研究対象です！
				<<アイデン貞貞メルトダウン>>

The lone tale is no more
As a breeze brushes by
As the days drift on by
Found a steady shore of trust
In this vast world
As we walk side by side
The script is fading away
And the frozen dawn streams forth
Into the new
				<<Innocence>>
*/