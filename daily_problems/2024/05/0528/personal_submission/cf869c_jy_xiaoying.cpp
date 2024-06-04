//连接：https://codeforces.com/problemset/problem/869/C

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=998244353;
int a,b,c;

const int MAX=5010;
ll f[MAX];         // i!(阶乘)

int kjsdf=[](){
	f[0]=1;
	for(int i=1;i<MAX;i++){
		f[i]=(f[i-1]*i)%mod;
	}
	//f[0]=0;
	return 1;
}();

ll quick_pow(ll x,ll n){   //x^n
	ll ans=1;
	ll base=x;
	while(n>0){
		if(n & 1) ans=(ans*base)%mod;
		base=(base*base)%mod;
		n>>=1;
	}
	return ans;
}


ll comb(ll n,ll k){
	if(n==k) return 1;
	
	ll ans=f[n];
	ll tmp=(f[k]*f[n-k])%mod;
	tmp=quick_pow(tmp,mod-2);    //逆元 
	ans=(ans*tmp)%mod;
	return ans;
}

void getAns(){
	ll ans=1;
	ll t=0;
	
	int n=min(a,b);
	for(int i=0;i<=n;i++){
		t+=comb(a,i)*comb(b,i)%mod*f[i]%mod;
		t%=mod;
	}
	ans=(ans*t)%mod;
	
     n=min(a,c);
     t=0;
	for(int i=0;i<=n;i++){
		t+=comb(a,i)*comb(c,i)%mod*f[i]%mod;
		t%=mod;
	}
	ans=(ans*t)%mod;
	
     n=min(c,b);
     t=0;
	for(int i=0;i<=n;i++){
		t+=comb(c,i)*comb(b,i)%mod*f[i]%mod;
		t%=mod;
	}
	ans=(ans*t)%mod;
	
	cout<<ans<<"\n";
}

int main(){
	cin>>a>>b>>c;
	
	getAns();
	//cout<<comb(100,2)<<"\n";
	return 0;
} 
