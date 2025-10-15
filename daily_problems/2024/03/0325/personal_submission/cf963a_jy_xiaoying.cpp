#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/963/A

//   等比数列求和 
//

//日期： 2024-3-25
//格式化： ctrl+shift+ a

const int MAX=1e5+10;
typedef long long ll;

ll n,k;
string s;
ll a,b;
const ll mod=1e9+9;

ll q_pow(ll x,ll y){  //x^y
	ll ans=1;
	ll base=x;
	while(y){
		if(y & 1) ans=(ans*base)%mod;
		y/=2;
		base=(base*base)%mod;
	}
	return ans;
}

void f(){
	ll ans=0;
	for(int i=0;i<k;i++){
		ll cnt=(n-i)/k+1;  cnt%=mod;                         //项数 cnt
		ll base=q_pow(a,n-i)*q_pow(b,i)%mod;                 //首项 base  公比：q   base*(1-q^cnt)/(1-q) 
		
		ll q=q_pow(b*q_pow(a,mod-2)%mod,k);  //公比 
		
		ll tmp;
		if(q==1){
			tmp=cnt*base%mod;
		}
		else{                                                	
			tmp=base*((q_pow(q,cnt)-1+mod)%mod) %mod;
			tmp=tmp*q_pow(q-1,mod-2)%mod;
			
		}
		
		ll ops;
		if(s[i]=='+') ops=1;
		else ops=-1;
		
		ans=(ans+ops*tmp+mod)%mod;
	}
	
	cout<<ans<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
   
   cin>>n>>a>>b>>k;
   cin>>s;
   
   f();

	return 0;
}
/*
2 2 3 3
+-+

7

*/

