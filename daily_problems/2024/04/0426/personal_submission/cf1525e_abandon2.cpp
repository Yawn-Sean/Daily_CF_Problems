// Problem: E. Assimilation IV
// Contest: Codeforces - Educational Codeforces Round 109 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1525/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10,md=998244353;
#define int long long
int a[N][30],fac[30];
int n,m;

int qsm(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%md;
		a=a*a%md;
		b>>=1;
	}
	return res;
}

void solve(){
	cin>>n>>m;
	fac[0]=1LL;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%md;
	int fc=qsm(fac[n],md-2);
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=m;j++){
			int x;cin>>x;
			a[j][x]++;
		}
	}
	
	int ans=0;
	for(int j=1;j<=m;j++){
		int sum=0,tmp=1;
		for(int i=n;i>=1;i--){
			sum+=a[j][i+1];sum%=md;
			tmp=tmp*sum%md;sum--;
		}
		ans=(ans+1-1LL*fc%md*tmp%md+md)%md;
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int tt=1;
	while(tt--)solve();
}


