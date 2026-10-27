#include <bits/stdc++.h>
using namespace std;
//#define int long long
//#define endl "\n"
#define fi first 
#define se second 
#define sz(x) (int)(x.size())
using PII=pair<int,int>;
int X[4]={0,0,-1,1};
int Y[4]={-1,1,0,0};
pair<char,char>cur[4]={make_pair('R','L'),make_pair('L','R'),make_pair('D','U'),make_pair('U','D')};

//隔着问就能确定整个图
//多源DFS贪心涂图

void solve() {
	int n,m;
	cin>>n>>m;
	vector<vector<char>>adj(n+1,vector<char>(m+1,'#'));
	int sx=1,sy=1;
	if(n&1){
		++sx;
	}
	if(m&1){
		++sy;
	}
	for(int i=sx;i<=n;i+=2){
		for(int j=sy;j<=m;j+=2){
			cout<<"? "<<i<<" "<<j<<endl;
			cin>>adj[i][j];
			if(adj[i][j]=='R'){
				adj[i][j-1]='L';
			}else if(adj[i][j]=='L'){
				adj[i][j+1]='R';
			}else if(adj[i][j]=='U'){
				adj[i+1][j]='D';
			}else{
				adj[i-1][j]='U';
			}
		}
	}
	auto wk=[&](auto self,PII u,PII v)->void{
		int x=v.fi,y=v.se;
		for(int k=0;k<4;++k){
			int nx=x+X[k],ny=y+Y[k];
			if(nx<1 or nx>n or ny<1 or ny>m or adj[nx][ny]!='#' or make_pair(nx,ny)==u){
				continue;
			}
			self(self,v,make_pair(nx,ny));
			if(adj[nx][ny]=='#'){
				adj[x][y]=cur[k].fi;
				adj[nx][ny]=cur[k].se;
			}
		}
	};
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(adj[i][j]!='#'){
				continue;
			}
			wk(wk,make_pair(-1,-1),make_pair(i,j));
		}
	}
	cout<<"!"<<endl;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cout<<adj[i][j];
		}
		cout<<endl;
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int loop = 1;
	//cin >> loop;
	while (loop--){
		solve();
	}
	return 0;
}