// Problem: B. Bear and Blocks
// Contest: Codeforces - Codeforces Round 318 [RussianCodeCup Thanks-Round] (Div. 1)
// URL: https://codeforces.com/problemset/problem/573/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;cin>>n;
	vector<int>a(n+2);
	for(int i=1;i<=n;i++)cin>>a[i];
	a[1]=a[n]=1;
	for(int i=2;i<=n;i++){
		a[i]=min(a[i],a[i-1]+1);//需要靠左边的删除
	}
	for(int i=n-1;i>=1;i--){
		a[i]=min(a[i],a[i+1]+1);
	}
	// for(auto x:a){
		// cout<<x<<" ";
	// }
	cout<<*max_element(a.begin(),a.end())<<"\n";
	
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int tt=1;
	while(tt--)solve();
}


