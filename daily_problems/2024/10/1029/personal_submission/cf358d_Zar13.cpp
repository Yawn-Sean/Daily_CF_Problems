#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int a[N], b[N], c[N], f[N][5];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++){
		f[i][0]=max(f[i-1][2]+a[i], f[i-1][3]+a[i]);
		if(i!=1) f[i][1]=max(f[i-1][0], f[i-1][1])+b[i];
		f[i][2]=max(f[i-1][3], f[i-1][2])+b[i];
		if(i!=1&&i!=n) f[i][3]=max(f[i-1][0], f[i-1][1])+c[i];
	}
	cout<<max({f[n][0], f[n][1], f[n][2]-b[n]+a[n]});
	return 0;
}
