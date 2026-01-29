#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/gym/105198/problem/K

//    2026-1-29-(组合数学)- cfgym105198K 
//

//日期： 2026-1-29 
//格式化： ctrl+shift+ a

typedef long long ll;
const int MAX=2e6+10;

const ll mod=1e9+7;
ll inv[MAX];
ll fac[MAX];

int b,g,x,y;

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

void init(){
	fac[0]=1;
	for(int i=1;i<MAX;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	inv[MAX-1]=q_pow(fac[MAX-1],mod-2);
	for(int i=MAX-2;i>=0;i--){
		inv[i]=inv[i+1]*(i+1)%mod;
	}
}

ll CC(int x,int y){
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}


void solve(){
	ll ans=CC(b+g,g);
	ans=(ans+mod-CC(x+y-1+b,x+y-1))%mod;
	
	cout<<ans<<endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 

    init();
    int tt;
    cin>>tt;
    
    
    while(tt--){
    	cin>>b>>g>>x>>y;
    	if(x+y>g) cout<<"0"<<endl;
    	else{
    		solve();
		}
	}
    return 0;
}

/*



*/

