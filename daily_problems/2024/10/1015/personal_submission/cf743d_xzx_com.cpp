#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define l128 __int128
using namespace std;
const int N=5e5+10,inf=1e18;
int e[N],ne[N],h[N],a[N],idx,ans[N],d[N],ans1;
vector<int>ma;
void add(int a,int b){
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
bool st[N];
int dfs(int u){
	st[u]=1;
	d[u]=a[u];
	ans[u]=-inf;
	int m1=-inf,m2=-inf;
	for(int i=h[u];~i;i=ne[i]){
		int j=e[i];
		if(!st[j]){
			st[j]=1;
			d[u]+=dfs(j);
			int tmp=ans[j];
			ans[u]=max(ans[u],ans[j]);
			if(m1<tmp)swap(m1,tmp);
			if(m2<tmp)swap(m2,tmp);
		}
	}
	if(m2>-inf)ans1=max(ans1,m1+m2);
	ans[u]=max(ans[u],d[u]);
	return d[u];
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin >> t;
    while (t--) {
       int n;cin>>n;
       memset(h,-1,sizeof h);
	   for(int i=1;i<=n;i++)cin>>a[i];
	   for(int i=1;i<=n-1;i++){
	   		int a,b;cin>>a>>b;
	   		add(a,b);add(b,a);
	   }
	   ans1=-inf;
	   dfs(1); 
		if(ans1!=-inf)cout<<ans1<<'\n';
		else cout<<"Impossible"<<'\n';
    }
    return 0;
}
