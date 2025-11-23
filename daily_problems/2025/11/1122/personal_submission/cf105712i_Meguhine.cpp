#ifdef __FUCK_GCC
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("inline","fast-math","unroll-loops")
#endif
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
template<typename T>inline bool updmx(T& x,const T& y){return x<y?x=y,1:0;}
template<typename T>inline bool updmn(T& x,const T& y){return y<x?x=y,1:0;}
template<typename T>inline void clr(T& x){T().swap(x);}

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
LL rand(LL l,LL r){return rng()%(r-l+1)+l;}

int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void solve(){
	int n,m;
	cin>>n>>m;
	auto fuck=[&](auto&& s,auto&& ans)->void{
		vector pre(n,vector<int>(m));
		auto bfs=[&](int sx,int sy,int tx,int ty)->void{
			if(sx==tx && sy==ty) return;
			dbg(sx,sy,s[sx][sy]);
			dbg(tx,ty,s[tx][ty]);
#ifdef LOCAL
			for(int i=0;i<n;++i){
				dbg(s[i]);
			}
#endif
			assert(s[sx][sy]=='#' && s[tx][ty]=='.');
			queue<ai2>p;
			pre.assign(n,vector<int>(m,-1));
			p.push({sx,sy});
			while(p.size()){
				auto [x,y]=p.front();
				p.pop();
				for(int i=0;i<4;++i){
					int nx=x+dir[i][0];
					int ny=y+dir[i][1];
					if(nx<0 || ny<0 || nx==n || ny==m) continue;
					if(pre[nx][ny]!=-1 || s[nx][ny]=='#') continue;
					pre[nx][ny]=i;
					if(nx==tx && ny==ty) return;
					p.push({nx,ny});
				}
			}
			assert(pre[tx][ty]!=-1);
		};
		auto dfs=[&](auto&& self,int x,int y,int sx,int sy)->void{
			if(x==sx && y==sy) return;
			int i=pre[x][y];
			int px=x-dir[i][0];
			int py=y-dir[i][1];
			self(self,px,py,sx,sy);
			ans.push_back({px+1,py+1,x+1,y+1});
		};
		int x=0,y=0;
		auto add=[&]()->void{
			if(x&1){
				if(--y<0){
					++y;
					++x;
				}
			}
			else{
				if(++y==m){
					--y;
					++x;
				}
			}
		};
		for(int i=0;i<n;++i){
			int sj=0,ej=m,aj=1;
			if(i&1) sj=m-1,ej=-1,aj=-1;
			for(int j=sj;j!=ej;j+=aj){
				if(s[i][j]=='.') continue;
				bfs(i,j,x,y);
				dfs(dfs,x,y,i,j);
				swap(s[i][j],s[x][y]);
				add();
			}
		}
	};
	vector<string>a(n),b(n);
	for(int i=0;i<n;++i){
		cin>>a[i];
		for(int j=0;j<m;++j){
			if((i+j)&1){
				a[i][j]^=('#'^'.');
			}
		}
	}
	for(int i=0;i<n;++i){
		cin>>b[i];
		for(int j=0;j<m;++j){
			if((i+j)&1){
				b[i][j]^=('#'^'.');
			}
		}
	}
	int cnta=0,cntb=0;
	for(int i=0;i<n;++i) for(int j=0;j<m;++j){
		cnta+=a[i][j]=='#';
		cntb+=b[i][j]=='#';
	}
	if(cnta!=cntb){
		cout<<"-1\n";
		return;
	}
	vector<ai4>ansa,ansb;
	fuck(a,ansa);
	dbg("");
	fuck(b,ansb);
	int tot=(int)(ansa.size()+ansb.size());
	assert(tot<=200*(n*m));
	cout<<tot<<'\n';
	for(auto& [i,j,k,l]:ansa){
		cout<<i<<' '<<j<<' '<<k<<' '<<l<<'\n';
	}
	reverse(all(ansb));
	for(auto& [i,j,k,l]:ansb){
		cout<<i<<' '<<j<<' '<<k<<' '<<l<<'\n';
	}
}

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
