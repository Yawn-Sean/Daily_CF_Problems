// Problem: B. Graph Coloring
// Contest: Codeforces - CROC 2016 - Final Round [Private, For Onsite Finalists Only]
// URL: https://codeforces.com/problemset/problem/662/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int u[N],v[N],w[N],f[N],vis[N],siz[N];
int n,m;

int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}

void merge(int a,int b){
	a=find(a),b=find(b);
	if(a==b)return;
	siz[b]+=siz[a];
	f[a]=b;
}

bool check(vector<int>&ans){
	for(int i=1;i<=n*2;i++){
		vis[i]=0;
		f[i]=i;siz[i]=(i<=n);//siz前n项设成一，为了说明是需要操作的，n+1后说明不需要操作
	}
	for(int i=1;i<=m;i++){
		if(w[i])merge(u[i],v[i]),merge(u[i]+n,v[i]+n);//是蓝色说明要么全改变要么不改变
		else merge(u[i],v[i]+n),merge(u[i]+n,v[i]);
	}
	for(int i=1;i<=n;i++)
		if(find(i)==find(i+n))return false;//选了的同时又没选这是不合法的
	for(int i=1;i<=n;i++){
		int u=find(i),v=find(i+n);//选了和不选所在的连通块
		if(!vis[u]&&!vis[v]){
			if(siz[u]<siz[v]){//siz来源于选了
				vis[u]=1;
			}
			else vis[v]=1;
		}
		if(vis[u]){
			ans.push_back(i);
		}
	}
	return 1;
}


void solve(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		char c;cin>>u[i]>>v[i]>>c;
		if(c=='B')w[i]=1;
		else w[i]=0;
	}
	vector<int>a[2];
	int f1=check(a[0]);
	for(int i=1;i<=m;i++)w[i]^=1;//另外的情况
	int f2=check(a[1]);
	
	if(!f1&&!f2){
		cout<<"-1\n";return;
	}
	if(f1&&f2){
		if(a[0].size()<a[1].size()){
			cout<<a[0].size()<<"\n";
			for(auto x:a[0])
				cout<<x<<" ";
		}
		else{
			cout<<a[1].size()<<"\n";
			for(auto x:a[1])
				cout<<x<<" ";
		}
		return;
	}
	if(f1){
		cout<<a[0].size()<<"\n";
		for(auto x:a[0])
			cout<<x<<" ";
	}
	else{
		cout<<a[1].size()<<"\n";
		for(auto x:a[1])
			cout<<x<<" ";
	}
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int tt=1;
	while(tt--)solve();
}


