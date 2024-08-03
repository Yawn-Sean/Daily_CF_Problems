#include<bits/stdc++.h>
using namespace std;
const int N = 5e3+10;
//等待时间尽可能短->让路程远的先走
//其余的每个都要等一圈（n)
int n,m;
int mini[N],sum[N];
void solve(){
	memset(mini,0x3f,sizeof mini);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		mini[x]=min(mini[x],(y-x+n)%n);
		sum[x]++;
	}
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			if(sum[j]==0) continue;
			int s=(sum[j]-1)*n+mini[j]+(j-i+n)%n;
			ans=max(ans,s);
		}
		cout<<ans<<" ";
	}
}
int main(){
	solve();
}