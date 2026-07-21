#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#define int long long
#define rg register
#define INF 0x7f7f7f7f
#define endl '\n'
#define pi 3.1415926
// #define OI_DEBUG
#define _IOFAST
using namespace std;
const int N=2e5+10,mod=998244353;
struct node{
	int to,val;
};
int t,m,ans[N],fa[N],n;
vector<node> edge[N];
inline int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
inline int fpow(int x,int y){
	int now=1,base=x;
	while(y){
		if(y&1) now=(now*base)%mod;
		base=(base*base)%mod;
	}
	return x;
}
inline void dfs(int now,int last){
	for(auto &temp : edge[now]){
		if(temp.to==last) continue;
		if(ans[now]+temp.val<ans[temp.to]){
			ans[temp.to]=(ans[now]+temp.val)%mod;
			dfs(temp.to,now);
		}
	}
	return;
}
signed main(){
	#ifdef _IOFAST
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#endif
	#ifdef OI_DEBUG
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	#endif
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) fa[i]=i,ans[i]=INF,edge[i].clear();
		int val=1;
		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
			int fax=find(x),fay=find(y);
			if(fax!=fay){
				edge[x].emplace_back(node{y,val});
				edge[y].emplace_back(node{x,val});
				fa[fax]=fay;
			}
			val=(val*2)%mod;
		}
		ans[1]=0;
		dfs(1,0);
		for(int i=2;i<=n;i++){
			if(ans[i]==INF) cout<<-1<<" ";
			else cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}