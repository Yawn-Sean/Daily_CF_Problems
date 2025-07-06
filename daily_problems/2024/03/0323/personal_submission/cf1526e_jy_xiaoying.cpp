#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1526/E

//   sa数组 + 组合数学 
//

//日期： 2024-3-23
//格式化： ctrl+shift+ a

const int MAX=2e6+10;
typedef long long ll;

const ll mod=998244353;
int sa[MAX];
int pos[MAX];
ll n,k;

ll q_pow(ll x,ll y){  // x^y
	ll ans=1;
	ll base=x;
	while(y){
		if(y & 1){
			ans=(ans*base)%mod;
		}
		base=(base*base)%mod;
		y>>=1;
	}
	return ans;
}

ll comb(ll n,ll m){   //C(n,m) :n个中选m个 
	if(m>n) return 0;
	if(n==m || m==0) return 1;
	
	ll ans=1;
	for(ll i=2;i<=n;i++) ans=(ans*i)%mod;
	
	ll fen_mu1=1;
	for(ll i=2;i<=m;i++) fen_mu1=(fen_mu1*i)%mod;
	fen_mu1=q_pow(fen_mu1,mod-2);
	ans=(ans*fen_mu1)%mod;
	
	ll fen_mu2=1;
	for(ll i=2;i<=n-m;i++) fen_mu2=(fen_mu2*i)%mod;
	fen_mu2=q_pow(fen_mu2,mod-2);
	ans=(ans*fen_mu2)%mod;
	
	return ans;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>k;
	for(ll i=0;i<MAX;i++) pos[i]=-1;
	for(ll i=0; i<n; i++) {
		cin>>sa[i];
		pos[sa[i]]=i;
	}
	
	ll cnt=0;
	for(int i=0;i<n-1;i++){
		int id1=sa[i]+1;
		int id2=sa[i+1]+1;
		if(pos[id1]<pos[id2]) cnt++;
	}
	
	cout<<comb(k+cnt,n)<<endl;

	return 0;
}
/*


*/

