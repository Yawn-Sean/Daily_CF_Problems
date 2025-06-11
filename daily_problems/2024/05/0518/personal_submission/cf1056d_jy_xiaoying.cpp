//链接：https://codeforces.com/problemset/problem/1056/D

#include<bits/stdc++.h>
using namespace std;

int n;

const int MAX=1e5+10;
typedef vector<int> vv;


int leaf[MAX];      //以i为头节点的子树的 总节点数量

vector<vv> g(MAX);


void build(){
	for(int i=0;i<=n;i++){
		leaf[i]=0;
		g[i].clear();
	}
} 

void dfs(int x,int fa){
	if(g[x].size()==1 && g[x][0]==fa){           //来到叶节点 
		leaf[x]=1;
		return ;
	}
	
	for(int u:g[x]){
		if(u==fa) continue;
		dfs(u,x);
		leaf[x]+=leaf[u];
	}
}

void f(){
	if(n==1){
		cout<<1<<"\n";                //就一个节点 得特判 
		return ;
	}
	
	dfs(1,0);
	sort(leaf+1,leaf+n+1);           //叶节点: 从小到大排序 
	

	for(int i=1;i<=n;i++){
		cout<<leaf[i]<<" ";
	}
	cout<<"\n";
}

int main(){
	cin>>n;
	int t;
	build();
	for(int i=2;i<=n;i++){
		cin>>t;
		g[i].push_back(t);
		g[t].push_back(i);
	}
	
	f();
	return 0;
} 
