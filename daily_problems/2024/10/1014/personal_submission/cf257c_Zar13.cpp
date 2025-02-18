#include<bits/stdc++.h>
using namespace std;
const int N=100005;
double a[N];
int main(){
	int n, x, y;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		a[i]=atan2(y, x);
	} 
	double pi=acos(-1);
	sort(a+1, a+1+n);
	double ans=a[1]-a[n]+2*pi;
	for(int i=1;i<n;i++){
		ans=max(ans, a[i+1]-a[i]);
	}
	ans=(2*pi-ans)*180/pi;
	cout<<fixed<<setprecision(10)<<ans;
	return 0;
} 
