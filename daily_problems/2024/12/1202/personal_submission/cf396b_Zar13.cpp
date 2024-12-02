#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
bool is_prime(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return 0;
	}
	return 1;
}
LL gcd(LL a, LL b){
	return b==0? a:gcd(b, a%b);
}
int main(){
	int T, n;
	cin>>T;
	while(T--){
		cin>>n;
		int v, u;
		v=n;
		while(!is_prime(v)) v--;
		u=n+1;
		while(!is_prime(u)) u++;
		LL a=1LL*v*u-2*u+2*(n-v+1);
		LL b=2LL*v*u;
		LL c=gcd(a, b);
		cout<<a/c<<"/"<<b/c<<endl;
	}
	return 0;
}
