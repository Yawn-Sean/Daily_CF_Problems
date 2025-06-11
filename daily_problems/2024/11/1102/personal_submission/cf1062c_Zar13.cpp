#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005, mod=1e9+7;
int a[N], sa[N], c[N], sc[N], ssc[N];
int main(){
	int n, q, l, r;
	cin>>n>>q;
	char z;
	for(int i=1;i<=n;i++){
		cin>>z;
		a[i]=z-'0';
		sa[i]=sa[i-1]+a[i];
		if(i==1||i==2) c[i]=1;
		else c[i]=c[i-1]*2%mod;	
	}
	for(int i=1;i<=n;i++){
		sc[i]=(sc[i-1]+c[i])%mod;
		ssc[i]=(ssc[i-1]+sc[i])%mod;
	}
	while(q--){
		cin>>l>>r;
		int rr=r-l+1, ll=rr-(sa[r]-sa[l-1]);
		cout<<(ssc[rr]-ssc[ll]+mod)%mod<<endl;
	}
}
