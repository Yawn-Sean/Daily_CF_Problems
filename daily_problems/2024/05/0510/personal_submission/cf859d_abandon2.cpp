#include<bits/stdc++.h>
using namespace std;
#define lu u<<1
#define ru u<<1|1
const int N=(2<<6)+4;
double p[N][N],f[N][N],g[N][N];
int n;

void dfs(int u,int l,int r){//当前轮，左端点，右端点
	if(l==r){
		g[u][l]=1;//自己对自己为1
		f[u][l]=0;
		return;
	}
	int mid=l+r>>1;
	dfs(lu,l,mid);
	dfs(ru,mid+1,r);
	//cout<<u<<" "<<l<<" "<<r<<" "<<mid<<"\n";
	for(int i=1;i<=mid;i++){//枚举获胜的
		for(int j=mid+1;j<=n;j++){//枚举失败的人
			g[u][i]+=g[lu][i]*g[ru][j]*p[i][j];//左边节点获胜的概率
			//cout<<g[u][i]<<"\n";
		}
	}
	for(int i=mid+1;i<=n;i++){
		for(int j=1;j<=mid;j++){//左边的人都失败了
			g[u][i]+=g[ru][i]*g[lu][j]*p[i][j];
		}
	}
	for(int i=1;i<=mid;i++){
		for(int j=mid+1;j<=n;j++){
			f[u][i]=max(f[u][i],g[u][i]*(r-l+1)/2+f[lu][i]+f[ru][j]);
		}
	}
	for(int i=mid+1;i<=n;i++){
		for(int j=1;j<=mid;j++){
			f[u][i]=max(f[u][i],g[u][i]*(r-l+1)/2+f[ru][i]+f[lu][j]);
		}
	}
}

void solve(){
	scanf("%d",&n);
	n=(1<<n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			scanf("%lf",&p[i][j]);
			p[i][j]/=100;
		}
	dfs(1,1,n);
	double ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,f[1][i]);
	printf("%.9lf",ans);
}

signed main(){
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	solve();
	return 0;
}
