#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/gym/106094/problem/C

//    2026-1-1-(质因数分解+数学)- cfgym106094C 
//

//日期： 2026-1-1 
//格式化： ctrl+shift+ a

typedef long long ll;

int ct;

const int MAX=2e5+100;
int tmp[MAX];
int prime[MAX/2];
int cnt;

ll x,k;

void init(){
	for(int i=1;i<MAX;i++){
		tmp[i]=i;
	}
	
	cnt=0;
	
	for(int i=2;i<MAX;i++){
		if(tmp[i]==i){
			prime[cnt++]=i;
		}
		
		for(int j=0;j<cnt;j++){
			if(prime[j]*i>=MAX) break;
			
			tmp[prime[j]*i]=prime[j];
			
			if(i%prime[j]==0) break;
		}
	}
}

void solve(){  // 2^11  3^2  6
	vector<ll> arr;
	while(x>1){
		int p=tmp[x];
		ll c=0;
		while(x%p==0){
			c++;
			x/=p;
		}
		arr.push_back(c);
	}
	

	ll ans=0,cur=2;
	for(int i=1;i<=62;i++,cur*=2){
		ll res=0;
		for(ll &v:arr){
			ll base=(v+cur-1)/cur;
			res+=base*cur-v;
		}
		if(res>k) break;
		ans=i;
	}
	cout<<ans<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
   
    init();
    cin>>ct;
    while(ct--){
    	cin>>x>>k;
    	solve();
	}

	return 0;
}
/*



*/

