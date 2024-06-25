#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],d[N];
int n,k;


void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=1e9+10,p=0;
	for(int i=1;i<=n-k;i++){
		if(ans>a[i+k]-a[i]){
			ans=a[i+k]-a[i];
			p=ans/2+a[i];
		}
	}
	cout<<p<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;cin>>t;
	while(t--)
	solve();
	return 0;
}
