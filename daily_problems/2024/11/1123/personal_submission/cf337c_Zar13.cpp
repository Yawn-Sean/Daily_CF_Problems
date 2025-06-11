#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=1e9+9;
LL n, m, k, ans;
LL qmi(int a, int b, int p){
    LL res = 1 % p;
    while (b){
        if (b & 1) res = res * a % p;
        a = a * (LL)a % p;
        b >>= 1;
    }
    return res;
}
int main(){
	cin>>n>>m>>k;
	if(n-m>=n/k){
		cout<<m;
	}else{
		int c=n/k-(n-m);
		ans+=(qmi(2, c+1, mod)-2+mod)%mod*k%mod;
		ans=(ans+m-c*k+mod)%mod;
		cout<<ans;
	}
	return 0;
}
