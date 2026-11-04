#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
using LL=long long;

//

const LL MOD=998244353;
LL qpow(LL x,LL y){
	LL res=1;
	while(y){
		if(y&1)res=res*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return res;
}

void solve() {
	int n;
	cin>>n;
	if(n<=3){
		cout<<1<<endl;
		return;
	}
	n-=2;
	if(n%3==0){
		cout<<qpow(3,n/3)<<endl;
	}else if(n%3==1){
		cout<<qpow(3,(n-4)/3)*4%MOD<<endl;
	}else{
		cout<<qpow(3,n/3)*2%MOD<<endl;
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int loop = 1;
	//cin >> loop;
	while (loop--){
		solve();
	}
	return 0;
}