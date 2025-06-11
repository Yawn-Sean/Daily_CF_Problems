#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,md=1e9+7;
typedef long long LL;
#define int long long
LL c[N],a[N],s[N],vis[N],f[N];
int n;

int lowbit(int x){
	return x&(-x);
}

void add(int k,int x){
	for(int i=k;i<=N;i+=lowbit(i)){
		c[i]+=x;c[i]%=md;c[i]+=md;c[i]%=md;
	}
}

LL ask(int k){
	LL res=0;
	for(int i=k;i>=1;i-=lowbit(i)){
		res+=c[i];res%=md;
	}
	return res;
}


void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		f[i]=(ask(a[i])+1)*a[i]%md;
		if(vis[a[i]]){
			add(a[i],-f[vis[a[i]]]);
			f[vis[a[i]]]=0;
		}
		vis[a[i]]=i;
		add(a[i],f[i]);
	}
	LL ans=0;
	for(int i=1;i<=n;i++){
		ans+=f[i];ans%=md;
	}
	cout<<(ans%md+md)%md<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
