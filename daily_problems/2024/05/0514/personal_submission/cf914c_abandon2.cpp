#include<bits/stdc++.h>
using namespace std;
const int N=1010,md=1e9+7;
int cnt[N],sum[N];//表示该数字有多少个0，和需要多少次操作才能变成1
int n,k,a[N];
int f[N][N][2];//当前位置，填了多少个1，有无限制

int lowbit(int x){
	return x&(-x);
}

void init(){
	sum[0]=0;
	for(int i=1;i<=N-5;i++)
		sum[i]=sum[i^lowbit(i)]+1;
	cnt[1]=0;
	for(int i=2;i<=N-5;i++){
		cnt[i]=cnt[sum[i]]+1;
	}
}

int dfs(int u,int c,int limit){
	if(u==0){
		if(c==0)return 0;
		else return (cnt[c]+1==k);//多加一是因为一次操作把一的个数边的少于1000
	}
	auto &v=f[u][c][limit];
	if(~v){
		//cout<<v<<"ss\n";
		return v;
	}
	int res=0;
	if(limit==1){
		if(a[u]==0){//只能填0
			res+=dfs(u-1,c,1);
			res%=md;
		}
		else{
			res+=dfs(u-1,c,0);
			res%=md;
			res+=dfs(u-1,c+1,1);
			res%=md;
		}
	}
	else{
		res+=dfs(u-1,c,0);
		res%=md;
		res+=dfs(u-1,c+1,0);
		res%=md;
	}
	//cout<<res<<"\n";
	return v=res;
}



void solve(){
	memset(f,-1,sizeof f);
	string s;cin>>s;
	cin>>k;
	if(k==0){
		cout<<1<<"\n";return ;
	}
	int n=s.size();s=' '+s;
	for(int i=1;i<=n;i++)
		a[i]=s[n-i+1]-'0';
	int ans=dfs(n,0,1);
	if(k==1)ans--;
	cout<<ans<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	solve();
	return 0;
}
