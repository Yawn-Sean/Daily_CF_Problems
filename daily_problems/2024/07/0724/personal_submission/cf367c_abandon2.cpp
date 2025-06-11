#include<bits/stdc++.h>
using namespace std;
using LL=long long;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int>c(m+1);
	for(int i=1;i<=m;i++){
		int x;cin>>x;
		cin>>c[i];
	}
	sort(c.begin()+1,c.end(),greater<int>());
	LL ans=0;
	for(int i=1;i<=m;i++){
		int x=0;
		if(i&1){
			x=1+i*(i-1)/2;
		}
		else{
			x=(i-1)*i/2+i/2;
		}
		if(x>n)break;
		ans+=c[i];
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
