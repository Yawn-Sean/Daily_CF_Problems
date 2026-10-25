#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
#define sz(x) (int)(x.size())
using LL=long long;
using LD=long double;
const LL inf = 1e18;

//好像是这周的第三次状压枚举www
//暴力预处理

struct P{
	LD x,y;
	P operator-(const P& o) const {
        return {x - o.x, y - o.y};
    }
};
struct poly{
	vector<P>ps;
	LD mnn=inf,mxn=-inf;
	void init(){
		for(auto &[x,y]:ps){
			mnn=min(mnn,x);
			mxn=max(mxn,x);
		}
		for(auto &[x,y]:ps){
			x-=mnn;
		}
		mxn-=mnn;
		mnn-=mnn;
	}
};
struct Line{
	P a,b;
};

void solve() {
	int n,h;
	cin>>n>>h;
	int N=1<<n;
	vector<poly>a(n);
	LD x,y;
	for(auto &pp:a){
		int l;
		cin>>l;
		while(l--){
			cin>>x>>y;
			pp.ps.push_back({x,y});
		}
		pp.init();
	}
	vector<vector<LD>>adj(n,vector<LD>(n));  //左i右j时右面贡献大小
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(i==j){
				continue;
			}
			adj[i][j]=a[j].mxn;
			auto curi=a[i],curj=a[j];
			for(int k=0;k<sz(curj.ps);++k){
				curj.ps[k].x+=curi.mxn;
			}
			LD MNN=inf;
			for(auto cc:curi.ps){
				for(int k=0;k<sz(curj.ps);++k){
					auto L=curj.ps[(k)%sz(curj.ps)],R=curj.ps[(k+1)%sz(curj.ps)];
					if(L.y>R.y){
						swap(L,R);
					}
					if(L.y<=cc.y and cc.y<=R.y){
						auto s=L,v=R-L;
						LD res;
						if(v.y==0){
							res=min(s.x,s.x+v.x)-cc.x;
						}else{
							res=s.x+v.x*(cc.y-s.y)/v.y-cc.x;
						}
						MNN=min(MNN,res);
					}
				}
			}
			//不仅需要判断左侧的所有顶点，还要判断右侧的所有顶点(硬控我到半夜四点的罪魁祸首。)
			//单纯左顶点符合要求，可能会在右顶点侧突入，导致答案偏小
			//对称写一下即可
			for(auto cc:curj.ps){
				for(int k=0;k<sz(curi.ps);++k){
					auto L=curi.ps[(k)%sz(curi.ps)],R=curi.ps[(k+1)%sz(curi.ps)];
					if(L.y>R.y){
						swap(L,R);
					}
					if(L.y<=cc.y and cc.y<=R.y){
						auto s=L,v=R-L;
						LD res;
						if(v.y==0){
							res=cc.x-max(s.x,s.x+v.x);
						}else{
							res=cc.x-s.x-v.x*(cc.y-s.y)/v.y;
						}
						MNN=min(MNN,res);
					}
				}
			}
			adj[i][j]-=MNN;
		}
	}
	vector<vector<LD>>dp(N,vector<LD>(n,inf));
	for(int i=0;i<n;++i){
		dp[1<<i][i]=a[i].mxn;
	}
	for(int msk=1;msk<N;++msk){
		for(int lst=0;lst<n;++lst){
			if((msk>>lst)&1){
				for(int nxt=0;nxt<n;++nxt){
					if(((msk>>nxt)&1) and nxt!=lst){
						dp[msk][nxt]=min(dp[msk][nxt],dp[msk^(1<<nxt)][lst]+adj[lst][nxt]);
					}
				}
			}
		}
	}
	LD ans=inf;
	for(int i=0;i<n;++i){
		ans=min(ans,dp[N-1][i]);
	}
	cout<<ans<<endl;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int loop = 1;
	cout<<fixed<<setprecision(10);
	//cin >> loop;
	while (loop--){
		solve();
	}
	return 0;
}