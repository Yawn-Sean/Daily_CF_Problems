#include<bits/stdc++.h>
using namespace std;
int dx[]={-1,0,1,0},
	dy[]={0,-1,0,1};

void solve(){
	int n,m,p;cin>>n>>m>>p;
	vector<int>s(p+1);
	for(int i=1;i<=p;i++)
		cin>>s[i];
	vector a(n+1,vector<char>(m+1));
	vector vis(n+1,vector<int>(m+1));
	// vector<vector<array<int,2>>>giv(p+1);
	
	
	queue<array<int,3>>q[p+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]>='1'&&a[i][j]<='9'){
				q[a[i][j]-'0'].push({i,j,0});
				//giv[a[i][j]-'0'].push_back({i,j});
				// q.push({i,j});
				// vis[i][j]=1;
			}
		}
	}
	
	while(1){
		int br=1;
		for(int i=1;i<=p;i++){
			if(!q[i].empty()){
				br=0;
			}
		}
		if(br)break;
		
		for(int now=1;now<=p;now++){
		  if(q[now].size()){
			int t=s[now];
			while(t--){
			  if(q[now].empty())break;
			  int bl=q[now].front()[2];
			//  cout<<bl<<"d\n";
			  while(q[now].size()){
				auto [x,y,col]=q[now].front();
				if(col!=bl)break;
				q[now].pop();
				for(int c=0;c<4;c++){
					int u=x+dx[c],v=y+dy[c];
					if(u<1||u>n||v<1||v>m)continue;
					if(a[u][v]=='.'){
						a[u][v]=a[x][y];
						q[now].push({u,v,col+1});
					}
				}
				// if(col!=bl)break;
						// return;
				}
			  }
					
			}
		  }
	    }
	// return;
	
	vector<int>cnt(p+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cnt[a[i][j]-'0']++;
			// cout<<a[i][j]<<" ";
		}
		// cout<<"\n";
	}
	for(int i=1;i<=p;i++){
		cout<<cnt[i]<<" ";
	}
	cout<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt=1;
	// cin>>tt;
	while(tt--)
		solve();
	return 0;
}
