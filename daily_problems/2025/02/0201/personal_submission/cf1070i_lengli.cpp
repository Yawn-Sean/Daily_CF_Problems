#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;

int E[610][610];
int d[610];
vector<int> bel[1210];
int col[1210];

inline void fake_main(){
	memset(head,-1,sizeof head); cnt=-1;
	s=N-1; t=s-1;
	int n,m,k; cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v; cin>>u>>v;
		E[u][v]=E[v][u]=i;
		adde(n+i,t,1);//边作为右部点，连汇点
		d[u]++; d[v]++;
	}
	int res=0;
	for(int i=1;i<=n;i++){
		bel[i].clear();
		if(d[i]<=k) continue;
		adde(s,i,(d[i]-k)*2); res+=(d[i]-k)*2;//点作为左部点，连源点，因为要匹配 2(d[i]-k) 条边，所以流量就是 2(d[i]-k)
		for(int r=1;r<=n;r++){//左右点之间连边。
			if(i==r) continue;
			if(!E[i][r]) continue;
			adde(i,n+E[i][r],1);
		}
	}
	for(int i=1;i<=n;i++){
		d[i]=0;
		for(int j=1;j<=n;j++){
			E[i][j]=0;
		}
	}
	
	
	int tmp=dinic(); if(tmp!=res){//如果流不满则无解
		for(int i=1;i<=m;i++) cout<<"0 "; cout<<"\n";
		return;
	}
	for(int i=0;i<=cnt;i+=2){//否则构造方案
		if(edge[i].to!=t&&edge[i^1].to!=s){//这个边不连源点或者汇点，也就是左右点之间的边
			if(edge[i].flow==0){//被流过
				int u=edge[i^1].to;
				int v=edge[i].to;
				bel[u].push_back(v-n);//也就是这个边给点 u 做了贡献
			}
		}
	}
	
	res=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<bel[i].size();j+=2){
			col[bel[i][j]]=col[bel[i][j+1]]=++res;//对他做贡献的边，两两染同色
		}
	}
	for(int i=1;i<=m;i++){
		if(col[i]) cout<<col[i]<<" ";
		else cout<<++res<<" ";//其他散边随便染色
	}cout<<"\n";
	for(int i=1;i<=m;i++) col[i]=0;
}

signed main(){
	ios::sync_with_stdio(false);
	int t; cin>>t;
	while(t--) fake_main();
}
