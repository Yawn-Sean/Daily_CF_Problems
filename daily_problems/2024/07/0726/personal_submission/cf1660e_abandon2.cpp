#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;cin>>n;
	vector a(n*2+2,vector<int>(n*2+2)),s(n*2+2,vector<int>(n*2+2));
	int num=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			char x;cin>>x;
			a[i][j]=x-'0';
			num+=a[i][j];
		}
	}
	
	for(int i=1;i<=n*2;i++){
		for(int j=1;j<=n*2;j++){
			a[i][j]=a[(i-1)%n+1][(j-1)%n+1];
		}
	}
	
	// for(int i=1;i<=n*2;i++){
		// for(int j=1;j<=n*2;j++){
			// cout<<a[i][j];
		// }
		// cout<<"\n";
	// }
// 	
	
	for(int i=1;i<=n*2;i++){
		for(int j=1;j<=n*2;j++){
			s[i][j]=s[i-1][j-1]+a[i][j];
		}
	}
	
	//cout<<s[n][n+1]-s[0][1]<<"ok\n";
	
	int ans=1e9;
	for(int i=n;i<=n*2;i++){
		for(int j=n;j<=n*2;j++){
			ans=min(ans,num+n-2*(s[i][j]-s[i-n][j-n]));
		}
	}
	cout<<ans<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt=1;
	cin>>tt;
	while(tt--)
		solve();
	return 0;
}
