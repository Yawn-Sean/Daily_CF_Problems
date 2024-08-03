// Problem: C. Maximal Intersection
// Contest: Codeforces - Codeforces Round 506 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1029/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+10,inf=1e10+5;
int mxl[N],hmxl[N],mnr[N],hmnr[N],l[N],r[N];

void solve(){
	int n;cin>>n;
	
	mnr[0]=inf;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
		mxl[i]=max(mxl[i-1],l[i]);//前缀最大的l
		mnr[i]=min(mnr[i-1],r[i]);
	}
	if(n==1){
		cout<<r[1]-l[1]<<"\n";
		return;
	}
	hmnr[n+1]=inf;
	for(int i=n;i>=1;i--){
		hmnr[i]=min(hmnr[i+1],r[i]);
		hmxl[i]=max(hmxl[i+1],l[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		//cout<<mxl[i]<<" "<<hmxl[i]<<" "<<mnr[i]<<" "<<hmnr[i]<<"\n";
		int x=max(mxl[i-1],hmxl[i+1]),y=(i==1?hmnr[i+1]:min(mnr[i-1],hmnr[i+1]));
		//cout<<x<<" "<<y<<"\n";
		ans=max(ans,y-x);
	}
	cout<<ans<<"\n";
	
		
	
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int tt=1;
	while(tt--)solve();
}


