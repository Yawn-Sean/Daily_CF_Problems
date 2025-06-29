#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/263/D

//   dfs+dfn时间戳 
//   

//日期： 2024-3-16 
//格式化： ctrl+shift+ a

const int MAX=1e5+10;
int n,m,k;

typedef vector<int> vv;

vector<vv> g;
vector<int> ans;
int vis[MAX];
int times;
int flag=0; 

void dfs(int x){
	vis[x]=times++;
	for(int child:g[x]){
		
		if(vis[child]==0){
			dfs(child);
			break;
		}
		
		if(vis[x]-vis[child]>=k){
			ans.push_back(x);
			flag=child;
			return ;
		}
	}
	
	if(flag!=-1) ans.push_back(x);  //利用dfs回退找环 
	if(flag==x) flag=-1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin>>n>>m>>k;
    g=vector<vv>(n+5,vv());
    int a,b;
    
    for(int i=0;i<m;i++){
    	cin>>a>>b;
    	g[a].push_back(b);
    	g[b].push_back(a);
	}
	
	times=1;
	dfs(1);
	
	cout<<ans.size()<<endl;
	for(int x:ans) cout<<x<<" ";
	cout<<endl;
	
	return 0;
}
/*


*/

