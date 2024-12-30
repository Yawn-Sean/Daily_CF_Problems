// Problem: D. Strange Device
// Contest: Codeforces - Good Bye 2019
// URL: https://codeforces.com/problemset/problem/1270/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

void solve(){
	map<int,int>mp;
	int mx=0;
	int n,k;cin>>n>>k;
	for(int i=1;i<=k+1;i++){
		cout<<"? ";
		for(int j=1;j<=k+1;j++){
			if(i!=j){
				cout<<j<<" ";
			}
		}
		cout<<endl;
		int p,q;cin>>p>>q;
		mp[q]++;
		mx=max(q,mx);//m+1的数字会出现m次
	}
	cout<<"! "<<mp[mx]<<"\n";
	
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int tt=1;
	while(tt--)solve();
}


