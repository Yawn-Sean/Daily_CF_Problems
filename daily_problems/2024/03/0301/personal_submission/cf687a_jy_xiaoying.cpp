#include<bits/stdc++.h> 

using namespace std;

//链接：https://codeforces.com/problemset/problem/687/A
//日期： 2024-3-1 
//格式化： ctrl+shift+ a

const int MAX=1e5+10;
typedef long long ll;
typedef vector<int> vv;
int n,m; 
int color[MAX];
int vis[MAX];
bool ans=1;
queue<int> q;

vector<vv> g;

void dfs(int x,int fa){
	vis[x]=1;
	for(int y:g[x]){
		if(y==fa) continue;
		
		if(color[y]==0){
			color[y]=-color[x];
		}
		else{
			if(color[y]==color[x]){
				ans=0;
				break;
			}
		}
	}
	
	for(int y:g[x]){
		if(y==fa) continue;
		if(!vis[y]) q.push(y);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	g=vector<vv>(n+3,vv(0));
	int a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		q.push(i);
		color[i]=1;
		while(!q.empty()){
			int x=q.front();
			q.pop();
			dfs(x,-1);
			if(ans==0) break;
		}
		if(ans==0) break;
	}
	
	if(ans==0){
		cout<<"-1"<<endl;
		return 0;
	}
	
	vv a1;
	vv b1;
	for(int i=1;i<=n;i++){
		if(color[i]==1) a1.push_back(i);
		else if(color[i]==-1) b1.push_back(i);
	}
	
	cout<<a1.size()<<endl;
	for(int x1:a1) cout<<x1<<" ";
	cout<<endl;
	
	cout<<b1.size()<<endl;
	for(int x1:b1) cout<<x1<<" ";
	cout<<endl;

	return 0;
}


