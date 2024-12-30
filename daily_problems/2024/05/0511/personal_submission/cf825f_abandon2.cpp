#include<bits/stdc++.h>
using namespace std;
const int N=1e6+300;
typedef long long LL;
LL n,m,a,q,md;
LL fac[N],inv[N];
LL c[N],ans[N];

LL ksm(LL a,LL b,LL md){
	LL res=1;
	while(b){
		if(b&1)res=res*a%md;
		a=a*a%md;
		b>>=1;
	}
	return res;
}

void init(){
	fac[0]=1;
	int n=N-5;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%md;
		inv[i]=ksm(fac[i],md-2,md);
	}
	
	// inv[n]=ksm(fac[n],md-2,md);
// 	
	// for(int i=n;i>=1;i--){
		// inv[i-1]=inv[i]*i%md;
	// }
}

int C(int n,int m){
	if(m>n)return 0;
	if(m==n)return 1;
	return fac[n]*inv[m]%md*inv[n-m]%md;
}

void solve(){

	cin>>n>>m>>a>>q;
	md=1;
	while(1){
		if(ksm(a,md,q)==1){
			break;
		}
		md++;
	}
	init();
	//cout<<md<<"\n";
	//cout<<fac[3]<<"\n";
	LL res=1;
	c[0]=1;
	for(int i=1;i<n;i++){
		//cout<<C(m,i)<<"\n";
		res+=C(m,i);res%=md;
		c[i]=res;
	}
	for(int i=0;i<n;i++){
		ans[i]=ksm(a,c[i],q);
	}
	for(int i=n-1;i>=0;i--){
		cout<<ans[i]<<" ";
	}

}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
