#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int mn[N];//距离该点最近的点是什么
int sum[N];
void solve(){
	int n,m;cin>>n>>m;
	memset(mn,0x3f,sizeof mn);
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		mn[x]=min(mn[x],(y-x+n)%n);
		sum[x]++;//这个点有多少个
	}
	for(int i=1;i<=n;i++){
		//cout<<mn[i]<<"\n";
		int ans=0;
		for(int j=1;j<=n;j++){
			if(sum[j]==0)continue;
			//cout<<mn[j]<<"\n";
			ans=max(ans,(j-i+n)%n+(max(sum[j]-1,0)*n)+mn[j]);//先到j点，然后j点转完之后到j带你最近的一个
		}
		cout<<ans<<" ";
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
