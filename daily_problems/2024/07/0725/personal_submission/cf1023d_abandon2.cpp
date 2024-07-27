// Problem: D. Array Restoration
// Contest: Codeforces - Codeforces Round 504 (rated, Div. 1 + Div. 2, based on VK Cup 2018 Final)
// URL: https://codeforces.com/problemset/problem/1023/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,q;cin>>n>>q;
	vector<int>a(n+1);
	int mx=0,mn=1e9;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	vector<int>l(q+1),r(q+1);
	for(int i=1;i<=n;i++){
		if(!l[a[i]]){
			l[a[i]]=i;
		}
	}
	for(int i=n;i>=1;i--){
		if(!r[a[i]]){
			r[a[i]]=i;
		}
	}

	set<int>s;
	
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			if(mx<q){
				mx=q;a[i]=q;
			}
			else if(s.size()){
				a[i]=*s.rbegin();
			}
			else a[i]=1;
		}
		else{
			if(l[a[i]]==i&&l[a[i]]<r[a[i]])s.insert(a[i]);
			if(r[a[i]]==i&&l[a[i]]<r[a[i]])s.erase(a[i]);
			
			if(s.size()&&a[i]<*s.rbegin()){
				cout<<"NO\n";return;
			}
		}
	}
	
	
	if(mx<q){
		cout<<"NO\n";return;
	}
	
	cout<<"YES\n";
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt=1;
	while(tt--)
		solve();
	return 0;
}
