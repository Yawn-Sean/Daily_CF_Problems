#include<bits/stdc++.h>
using namespace std;
using LL=long long;

void solve(){
	int n;cin>>n;
	vector<LL>a(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a.begin()+1,a.end());
	// for(int i=1;i<=n;i++){
		// cout<<a[i]<<" ";
	// }
	// cout<<"\n";
	vector<LL>d(n+1),s(n+1);
	LL mx=0;
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1]-1;
		mx=max(mx,d[i]+1);
		if(d[i]==-1)d[i]=0;
	}	
	sort(d.begin()+1,d.end());
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+d[i];
	}
	//cout<<mx<<"mx\n";
	int q;cin>>q;
	for(int i=1;i<=q;i++){
		LL l,r;
		cin>>l>>r;
		LL ans=a[n]-a[1]+r-l+1;
		//cout<<ans<<" ans\n";
		if(mx<r-l+1){
			cout<<ans<<" ";
		}
		else{
			auto it=lower_bound(d.begin()+2,d.end(),r-l+1)-d.begin()-1;
			//cout<<it<<"\n";
			ans-=s[n]-s[it]-(r-l)*(n-it);
			cout<<ans<<" ";
		}
	}
	
	// for(int i=1;i<=n;i++){
		// cout<<d[i]<<" ";
	// }
	
	// cout<<"\n";
// 	
	// for(int i=1;i<=n;i++){
		// cout<<s[i]<<" ";
	// }
	// cout<<"\n";
	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt=1;
	while(tt--)
		solve();
	return 0;
}
