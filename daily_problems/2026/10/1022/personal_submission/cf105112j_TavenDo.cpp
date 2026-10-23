#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
using LD=long double;
const LD inf = 1e18;

//推测至少会有一个边跟点点连线完全重合
//枚举然后状压DP

struct P{
	LD x,y;
	P operator+(const P& o) const {
        return {x + o.x, y + o.y};
    }
    P operator-(const P& o) const {
        return {x - o.x, y - o.y};
    }
	LD dot(const P& o) const {
        return x * o.x + y * o.y;
    }
	LD square() const {
        return x * x + y * y;
    }
	P operator*(const LD& v) const {
        return {x * v, y * v};
    }
};
LD dis(P &a,P &b){
	P c=a-b;
	return sqrtl(c.x*c.x+c.y*c.y);
}
struct Line{  //a->b
	P a,b;
	P vec() const {
        return b - a;
    }
	P projection(const P& o) const {
        auto t = 1.L * vec().dot(o - a) / vec().square();
        return P(a) + P(vec()) * t;
    }
};
void solve() {
	int n;
	cin>>n;
	vector<P>a(n);
	LD ans=inf;
	int N=1<<n;
	for(int i=0;i<n;++i){
		cin>>a[i].x>>a[i].y;
	}
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			P v=a[j]-a[i];
			vector<vector<LD>>dp(N,vector<LD>(n,inf));
			for(int k=0;k<n;++k){
				dp[1<<k][k]=0;
			}
			auto wk=[&](int L,int R)->LD{
				auto lp=a[L],rp=a[R];
				Line li={rp,rp+v};
				auto res=li.projection(lp);
				return dis(res,lp)+dis(res,rp);
			};
			for(int msk=1;msk<N;++msk){
				for(int L=0;L<n;++L){
					if((msk>>L)&1){
						for(int R=0;R<n;++R){
							if(((msk>>R)&1) and L!=R){
								dp[msk][R]=min(dp[msk^(1<<R)][L]+wk(L,R),dp[msk][R]);
							}
						}
					}
				}
			}
			for(int k=0;k<n;++k){
				ans=min(ans,dp[N-1][k]);
			}
		}
	}
	cout<<ans<<endl;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout<<fixed<<setprecision(20);
	int loop = 1;
	//cin >> loop;
	while (loop--){
		solve();
	}
	return 0;
}
