#include<bits/stdc++.h>
using namespace std;
int x[1000005];
int main(){
	int n, ans=0, p, qx=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p;
		ans^=p;
		qx^=i-1;
		x[i-1]=qx;
		for(int j=1;j<=n/i;j++) ans^=qx;
		if(n%i) ans^=x[n%i];
	}
	cout<<ans;
	return 0;
}
