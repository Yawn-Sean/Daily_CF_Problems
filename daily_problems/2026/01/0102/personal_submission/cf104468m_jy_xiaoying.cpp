#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/gym/104468/problem/M

//    2026-1-2-(组合数学)- cfgym104468M
//

//日期： 2026-1-2 
//格式化： ctrl+shift+ a

typedef long long ll;

const ll mod=1e9+7;
const int MAX=2e5+10;

int tt;
ll n,k;

int nums[MAX];

ll fac[MAX];
ll inv[MAX];

ll q_pow(ll x,ll n){
	ll ans=1;
	ll base=x;
	while(n){
		if(n & 1) ans=ans*base%mod;
		base=base*base%mod;
		n>>=1;
	}
	return ans;
}

void solve(){
	ll cur=1;
	ll ans=fac[n];
	for(int i=1;i<n;i++){
		if(nums[i]==1) cur+=1;
		else{
			ans=ans*inv[cur]%mod;
			cur=1;
		}
	}
	ans=ans*inv[cur]%mod;  //结算最后一段 
	cout<<ans<<endl;
}

void init(){
	fac[0]=fac[1]=1;
	for(int i=2;i<MAX;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	inv[MAX-1]=q_pow(fac[MAX-1],mod-2);
	for(int i=MAX-2;i>=0;i--){
		inv[i]=inv[i+1]*(i+1)%mod;
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    
    init();
    
    cin>>tt;
    while(tt--){
    	cin>>n>>k;
    	int tmp;
    	fill(nums,nums+n+5,1);
    	
    	for(int i=0;i<k;i++) {
    		cin>>tmp;
    		nums[tmp]=0;
		}
    	solve();
	}
	
    return 0;
}

/*



*/

