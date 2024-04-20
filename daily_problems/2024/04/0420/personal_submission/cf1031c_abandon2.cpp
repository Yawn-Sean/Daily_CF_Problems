// Problem: C. Cram Time
// Contest: Codeforces - Technocup 2019 - Elimination Round 2
// URL: https://codeforces.com/problemset/problem/1031/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define int long long
void solve(){
	int x,y;cin>>x>>y;
	int t=x+y;
	vector<int>v(N);
	int tot=0;
	int sum=0;
	if(t>=1){
		for(int i=1;;i++){
			v[++tot]=i;
			sum+=i;
			if(sum+i+1>x+y){
				break;
			}
		}
	}
	map<int,int>mp;
	
	int q=0,cnt=0;
	for(int i=tot;i>=1;i--){
		if(q+v[i]<=x){
			q+=v[i];mp[i]=1,cnt++;
		}
	}
	cout<<cnt<<"\n";
	for(int i=1;i<=tot;i++)
		if(mp[i]!=0)
			cout<<v[i]<<" ";
	cout<<"\n";
	cout<<tot-cnt<<"\n";
	for(int i=1;i<=tot;i++){
		if(mp[i]==0)
			cout<<v[i]<<" ";
	}
	
	
	//cout<<p-v.size()<<"\n";
	// for(int i=1;i<=p;i++){
		// if(!mp.count(i))
			// cout<<i<<" ";
	// }
	
	
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int tt=1;
	while(tt--)solve();
}


