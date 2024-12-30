#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve(){
	int n,k;
	string a,b;
	cin>>n>>k>>a>>b;
	
	int res=0,l=1;
	for(int i=0;i<n;i++){
		if(l>k){
			res+=k;
			continue;
		}
		l<<=1;
		l-=(a[i]=='b')+(b[i]=='a');
		res+=min(l,k);
	}
	cout<<res;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int T;
	T=1;
	while(T--) solve();
	
	return 0;
}
