#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],p[N],q[N],h[N];

void solve(){
	int n;cin>>n;
	int mx=-1e9,mnx=-1e9,mxi=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]>mx){
			mnx=mx;
			mx=a[i];
			q[i]++,h[i]++;
			mxi=i;
		}
		else if(a[i]>mnx){
			mnx=a[i];
			p[mxi]++;
		}
	}	

	for(int i=1;i<=n;i++)q[i]+=q[i-1];
	for(int i=n;i>=1;i--)h[i]+=h[i+1];

	int ans=-1e9,pos=0;
	for(int i=1;i<=n;i++){
		int val=q[i-1]+h[i+1]+p[i];
		//cout<<val<<"\n";
		if(val>ans){
			ans=val;
			pos=a[i];
		}
		else if(val==ans){
			pos=min(a[i],pos);
		}
	}
	cout<<pos<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
