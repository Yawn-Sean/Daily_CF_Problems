#include<bits/stdc++.h>
using namespace std;
typedef long long LL; 
const int N=200005;
vector<int> g[N];
LL a[N], ans=-1e18;
LL dfs(int u, int fa, LL &sum){
//return 以u或u的子孙为跟的最大子树 ; sum 以u为根的子树 
	LL s=-1e18, sz=a[u], sumv;
	for(auto v:g[u]){
		if(v!=fa){
			LL sv=dfs(v, u, sumv);
//			cout<<"v:"<<v<<" sv:"<<sv<<" sumv:"<<sumv<<endl;
			sz+=sumv;
			if(s!=-1e18) ans=max(ans, s+sv);			
			if(sv>=s){
				s=sv;
			}
		}
	}
	sum=sz;
	return max(s, sz);
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++){
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	LL s;
	dfs(1, -1, s);
	if(ans!=-1e18) cout<<ans;
	else cout<<"Impossible";
	return 0;
} 
