// Problem: B. Fish Graph
// Contest: Codeforces - Codeforces Round 869 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1817/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int N=2010;
vector<int>e[N*2];
int col[N],stk[N],top;
int vis[N],deg[N];
int n,m,flag;

void dfs(int u,int fa,int b){//b代表应该回到的点
	if(flag)return;
	vis[u]=1;
	stk[++top]=u;//入栈
	for(int v:e[u]){
		if(v==fa)continue;
		if(v==b){//回到了当前的点
			memset(col,0,sizeof col);//标记数组
			for(int i=1;i<=top;i++)
				col[stk[i]]=1;//标记环上的顶点
			int cnt=0;
			for(int x:e[v]){
				if(!col[x]){
					cnt++;
				}
			}
			if(cnt<2||flag)continue;//
			cout<<"YES\n";
			flag=1;
			vector<pair<int,int>>ans;
			for(int i=2;i<=top;i++){
				ans.push_back({stk[i],stk[i-1]});
			}
			ans.push_back({v,stk[top]});
			cnt=0;
			for(int x:e[v]){
				if(!col[x]&&cnt<2){
					cnt++;
					ans.push_back({v,x});
				}
			}
			cout<<ans.size()<<"\n";
			for(auto[x,y]:ans){
				cout<<x<<" "<<y<<"\n";
			}
			return;
		}
		else if(!vis[v])dfs(v,u,b);//上面不用一定是标记过了所以不需要判断
	}
	top--;//退栈
}


void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)e[i].clear(),deg[i]=0,vis[i]=0;
	flag=0;
	
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		e[u].push_back(v),e[v].push_back(u);
		deg[u]++,deg[v]++;
	}
	for(int i=1;i<=n;i++){
		if(deg[i]>=4){
			top=0;flag=0;
			//cout<<i<<"ss\n";
			memset(vis,0,sizeof vis);
			dfs(i,0,i);
			if(flag){
				return;
			}
		}
	}
	cout<<"NO\n";
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int tt;cin>>tt;
	while(tt--)solve();
}


