#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e4+10;
#define int long long
struct node {
	LL x,y,r;
}a[N];
vector<int>e[N];
int cnt[N],col[N];

void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int x,y,r;cin>>x>>y>>r;
		a[i]={x,y,r};
	}	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			LL dis=(LL)(a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
			LL r=(a[i].r+a[j].r)*(a[i].r+a[j].r);
			if(dis==r){
				e[i].push_back(j);
				e[j].push_back(i);							
			}
		}
	}
	int ok=1;
	auto dfs=[&](auto &&dfs,int u,int w)->void{
		col[u]=w;cnt[w]++;
		for(int v:e[u]){
			if(!col[v]){
				dfs(dfs,v,3-w);
			}
			else if(col[v]==w){
				ok=0;
			}
		}
	};
	
	for(int i=1;i<=n;i++){
		if(!col[i]){
			ok=1;
			cnt[1]=cnt[2]=0;
			dfs(dfs,i,1);
			if(ok&&cnt[1]!=cnt[2]){
				cout<<"YES\n";return;
			}
		}
	}
	cout<<"NO\n";return;
	


}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
