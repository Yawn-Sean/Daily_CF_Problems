//链接：https://codeforces.com/problemset/problem/1292/B

#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<ll,ll> pp;

ll x0,y0,ax,ay,bx,by;
ll stx,sty,t;


void f() {
	vector<pp> g;
	ll t_x=x0, t_y=y0;
	while(1) {
		ll tmp=(t_x-stx)+(t_y-sty);
		if(tmp>t) break;
		g.push_back(pp(t_x,t_y));
		t_x=t_x*ax+bx;
		t_y=t_y*ay+by;
	}

	int ans=0;
	int len=g.size();
	for(int k=0; k<len; k++) {
		for(int i=0; i<=k; i++) {
			for(int j=k; j<len; j++) {
				ll tmp=abs(stx-g[k].x)+abs(sty-g[k].y)+abs(g[i].x-g[j].x)+abs(g[i].y-g[j].y);
				ll tmp_2=min(abs(g[i].x-g[k].x)+abs(g[i].y-g[k].y),
				             abs(g[j].x-g[k].x)+abs(g[j].y-g[k].y));
				            // cout<<tmp+tmp_2<<"\n";
				if(tmp+tmp_2>t) continue;
				ans=max(ans,j-i+1);
			}
		}
	}

	cout<<ans<<"\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>x0>>y0>>ax>>ay>>bx>>by;
	cin>>stx>>sty>>t;

	f();
	return 0;
}

/*

1 1 2 3 1 0
15 27 26


2

*/
