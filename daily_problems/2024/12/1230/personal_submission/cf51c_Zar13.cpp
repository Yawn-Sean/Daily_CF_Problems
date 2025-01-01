#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const double eps=1e-6;
int n, a[N];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1, a+1+n);
	double l=0, r=1e9;
	while(r-l>eps){
		double mid=(l+r)/2;
		double r1=a[1]+mid;
		int idx=1;
		while(idx<n&& a[idx]<=r1) idx++;
		double r2=a[idx]+mid;
		while(idx<n&& a[idx]<=r2) idx++;
		if(a[idx]+mid>=a[n]){
			r=mid;
		}else{
			l=mid;
		}
	}
	cout<<fixed<<setprecision(6)<<r/2<<endl;
	cout<<fixed<<setprecision(6)<<r/2+a[1]<<" ";
	int idx=1;
	double r1=a[1]+r;
	while(idx<n&& a[idx]<=r1) idx++;
	cout<<fixed<<setprecision(6)<<r/2+a[idx]<<" ";
	double r2=a[idx]+r;
	while(idx<n&& a[idx]<=r2) idx++;
	cout<<fixed<<setprecision(6)<<r/2+a[idx]<<" ";
	return 0;
}
