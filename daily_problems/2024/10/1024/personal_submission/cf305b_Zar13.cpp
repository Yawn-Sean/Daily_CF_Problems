#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL my_gcd(LL a, LL b){
	return b==0? a:my_gcd(b, a%b);
}
int main(){
	LL p, q, n, a, t;
	cin>>p>>q;
	t=my_gcd(p, q);
	p/=t; q/=t;
	cin>>n;
	while(n--){
		cin>>a;
		if(p/a<q){
			cout<<"NO";
			return 0;
		}
		p-=q*a;
		swap(p, q);
	}
	if(q==0) cout<<"YES";//swap
	else cout<<"NO";
}
