#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=300005;
LL n, a[N], b[N];
LL _s1[2*N], _rs1[2*N], _s2[2*N];
LL s1[2*N], rs1[2*N], s2[2*N];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int j=1;j<=n;j++) cin>>b[j];
	
	for(int i=1;i<=n;i++){
		_s1[i]=_s1[i-1]+a[i];
		_rs1[i]=_rs1[i-1]+b[i];
	}
	for(int i=1;i<=n;i++){
		_s1[i+n]=_s1[i+n-1]+b[n-i+1];
		_rs1[i+n]=_rs1[i+n-1]+a[n-i+1];
	}
	for(int i=1;i<=2*n;i++){
		_s2[i]=_s2[i-1];
		int j=(i+1)/2;
		if(j%2){
			if(i%2) _s2[i]+=a[j];
			else _s2[i]+=b[j];
		}else{
			if(i%2) _s2[i]+=b[j];
			else _s2[i]+=a[j];
		}
	}
	
	for(int i=1;i<=n;i++){
		s1[i]=s1[i-1]+i*a[i];
		rs1[i]=rs1[i-1]+i*b[i];
	}
	for(int i=1;i<=n;i++){
		s1[i+n]=s1[i+n-1]+(i+n)*b[n-i+1];
		rs1[i+n]=rs1[i+n-1]+(i+n)*a[n-i+1];
	}
	for(int i=1;i<=2*n;i++){
		s2[i]=s2[i-1];
		int j=(i+1)/2;
		if(j%2){
			if(i%2) s2[i]+=i*a[j];
			else s2[i]+=i*b[j];
		}else{
			if(i%2) s2[i]+=i*b[j];
			else s2[i]+=i*a[j];
		}
	}
	
	LL ans=s2[2*n]-_s2[2*n];
	
	for(int i=1;i<=n;i++){
		LL res=0;
		if(i%2){
			int j=2*(i-1)+1, jj=2*n-i+1;
			res=s2[j]-_s2[j];
			res+=s1[jj]-s1[i];
			res+=(j-i-1)*(_s1[jj]-_s1[i]);
			ans=max(ans, res);
		}else{
			int j=2*(i-1)+1, jj=2*n-i+1;
			res=s2[j]-_s2[j];
			res+=rs1[jj]-rs1[i];
			res+=(j-i-1)*(_rs1[jj]-_rs1[i]);
			ans=max(ans, res);
		}
	}
	cout<<ans;
	return 0;
}
