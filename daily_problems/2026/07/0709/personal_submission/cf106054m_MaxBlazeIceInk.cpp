#include<bits/stdc++.h>
using namespace std;

#define MAXN 4005
#define mod 998244353
#define INF (int)1e9

int n,m,k,f[MAXN][MAXN],dis[MAXN],vis[MAXN],fac[MAXN],inv[MAXN],ifac[MAXN];
vector<int>E[MAXN];

inline int C(int n,int m){
	return n>=0&&m>=0&&n>=m?1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod:0;
}

inline int star_bar(int x,int y){
	if(!x&&!y)return 1;
	return C(x+y-1,y-1);
}

inline void chkadd(int&x,int k){x+=k;if(x>=mod)x-=mod;}

struct node{
	int x,dis;
	inline bool operator<(const node&b)const{
		return b.dis<dis;
	}
};

priority_queue<node>Q;

signed main(){
	fac[0]=inv[1]=ifac[0]=1;
	for(int i=1;i<MAXN;i++)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=2;i<MAXN;i++)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<MAXN;i++)ifac[i]=1ll*ifac[i-1]*inv[i]%mod;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		E[u].emplace_back(v),E[v].emplace_back(u);
	}
	for(int i=1;i<=n;i++)dis[i]=INF,vis[i]=0;
	priority_queue<node>Q;Q.push(node{1,dis[1]=0});
	while(!Q.empty()){
		int x=Q.top().x;Q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int v:E[x]){
			if(dis[v]>dis[x]+1){
				dis[v]=dis[x]+1;
				if(!vis[v])Q.push(node{v,dis[v]});
			}
		}
	}
	if(!vis[2]){puts("0");return 0;}
	int ans=(dis[2]+k-1)/k;
	f[1][0]=1;
	for(int i=1;i<=ans*k;i++)
		for(int u=1;u<=n;u++)
			for(int v:E[u])
				chkadd(f[v][i],f[u][i-1]);
	int Ans=0;
	for(int i=dis[2];i<=ans*k;i++){
		int V=f[2][i],res=0;
		//cerr<<i<<""<<V<<""<<ans<<"\n";
		for(int j=0,coef=1;j<=ans;j++){
			chkadd(res,1ll*coef*star_bar(i-j*k-ans,ans)%mod*C(ans,j)%mod);
			coef=mod-coef;
		}
		//cerr<<res<<"\n";
		chkadd(Ans,1ll*res*V%mod);
	}
	printf("%d\n",Ans);
	return 0;
}