#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define int long long
int a[N],w,l;
int sum[N];

void solve(){
	cin>>w>>l;
	for(int i=1;i<w;i++)
		cin>>a[i];
	for(int i=1;i<w;i++)
		sum[i]=sum[i-1]+a[i];
	int mn=1e9+7;
	for(int i=0;i<w-l;i++){
		int x=sum[i+l]-sum[i];
		mn=min(x,mn);
	}
	cout<<mn<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
