// LUOGU_RID: 114813855
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[101],ans;
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (n==1||n%2==0) {cout<<-1;return 0;}
	for (int i=n;i>=1;i--){
		if (a[i]<=0) continue;
		if (i%2==0) ans+=a[i],a[i+1]-=a[i],a[i/2]-=a[i],a[i]=0;
		else ans+=a[i],a[i-1]-=a[i],a[i/2]-=a[i],a[i]=0;
	}
	cout<<ans;
	return 0;
}
