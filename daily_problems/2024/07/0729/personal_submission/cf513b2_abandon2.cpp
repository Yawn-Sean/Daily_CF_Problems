#include<bits/stdc++.h>
using namespace std;
using LL =long long;
void solve(){
	int n;LL k;cin>>n>>k;
	k--;
	vector<int>a(n+1);
	int l=1,r=n;
	for(int i=1;i<n;i++){
		if(k>>(n-i-1)&1){
			a[r--]=i;
		}
		else{
			a[l++]=i;
		}
	}
	a[l]=n;
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt=1;
	// cin>>tt;
	while(tt--)
		solve();
	return 0;
}
