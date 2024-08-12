#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
	int n;cin>>n;
	vector<LL>a(n+1);
	LL g=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		g=__gcd(g,a[i]);
		
	}
	cout<<"YES\n";
	if(g>1){
		cout<<0<<"\n";return;
	}
	LL ans=0;
	for(int i=2;i<=n;i++){
		if(a[i]%2&&a[i-1]%2){
			auto &x=a[i-1],&y=a[i];
			while(x%2||y%2){
				int c=x,d=y;
				x=c-d,y=c+d;
				ans++;
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(!(a[i]%2)&&!(a[i-1]%2))
		continue;
		auto &x=a[i-1],&y=a[i];
		while(x%2||y%2){
			int c=x,d=y;
			x=c-d,y=c+d;
			ans++;
		}
	}
	
	
	
	cout<<ans<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt=1;
	while(tt--)
		solve();
	return 0;
}
