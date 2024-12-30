#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;scanf("%d",&n);
	vector<double>a(n*2+2),b(n*2+2);
	int m=0;
	double s=0;
	for(int i=1;i<=n*2;i++){
		scanf("%lf",&a[i]);
		b[i]=(a[i]-(int)a[i])*1000;
		s+=b[i];
		if(b[i]==0)m++;
	}
	
	double mn=1e9;
	for(double x=max(n-m,0)*1000;x<=min(2*n-m,n)*1000;x+=1000){
		
		mn=min(mn,abs(x-s));
	}
	mn/=1000;
	printf("%.3lf\n",mn);
	
	// for(int i=1;i<=n*2;i++){
		// cout<<b[i]<<" ";
	// }
	
}

signed main(){
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	int tt=1;
	while(tt--)
		solve();
	return 0;
}
